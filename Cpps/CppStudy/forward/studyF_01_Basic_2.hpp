/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-09-03 21:20:32
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-10-22 23:56:02
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <bitset>
#include <cstddef>//std::to_integer<T>(b)
// #include "./Library/fmt-9.0.0/include/fmt/core.h" //https://fmt.dev/latest/index.html
// #include "./Library/fmt-9.0.0/include/fmt/format.h"
// #include "./Library/fmt-9.0.0/include/fmt/format-inl.h"

#include <cmath>
#include <compare>
#include <algorithm>
#include <map>
#include <optional>


namespace Basic{


    auto func_998(){

        /* ===========
        msvc _MSC_VER
        clang __clang__
        gcc __GNUC__

        */

    }

    namespace P0588R1{

        template<bool B>
        auto f(int n)->void{
            [=](auto a){
                if constexpr(B && sizeof(a)>4){
                    (void)n;
                }
            }(0);//// captures n regardless of the value of B and sizeof(int)
        }
    }

    namespace P0315R4_4{
        //static decltype([]{}) f();//declared ‘static’ but never defined [-Wunused-function]
        //static decltype([]{}) g();//declared ‘static’ but never defined [-Wunused-function]
        //static decltype(g()) g();//declared ‘static’ but never defined [-Wunused-function]
        [[maybe_unused]] static void h(decltype([]{})*){}
        [[maybe_unused]] static void h(decltype([]{})*){}
        //h(nullptr);//error: expected constructor, destructor, or type conversion before ‘(’ token
        
        using A = decltype([]{});
        static auto i(A*)->void;
        [[maybe_unused]] static auto i(A*)->void{}
        //static void i(A*){}//error: redefinition
        //i(nullptr);//error: expected constructor, destructor, or type conversion before ‘(’ token

        template<typename T>
        using B = decltype([]{});
        [[maybe_unused]] static void j(B<char16_t>*){}
        [[maybe_unused]] static void j(B<char32_t>*){}
        //j(nullptr);//error: expected constructor, destructor, or type conversion before ‘(’ token

        template<int N> static void k(decltype([]{return 0;}()));
        template<int N> static void k(decltype([]{return 0;}()));
        template<int N> static void k(int);

        struct lambda{auto operator()()const{return 0;}};
        template<int N> static void k(decltype(lambda{}()));
        template<int N> static void k(decltype(lambda{}()));
        template<int N> static void k(int);

        template <auto> struct foo{};
        extern foo<+[](){}>  x;

        [[maybe_unused]] void f(int i) {
            [[maybe_unused]] auto lambda = [=]{ return i; }; // captures i
            static_assert(sizeof(int) == sizeof([=]{ return i; }));
        }

        [[maybe_unused]] auto ff(int i) -> decltype([ii = i](auto g) { return g(ii); });

        template<typename T>
        void f(T t) requires requires{
            []{typename T::invalid foo;};
        };

        template<typename T>
        void f(T t) requires requires{
            [](auto a){typename decltype(a)::invalid foo;}(t);
        };

    }

    namespace P1091R3{

        //template <auto Var> constexpr auto[x1,y1] = Var; // ill formed. //error: expected unqualified-id before ‘[’ token
    }


    auto f_func_49_1(int&)       -> int{return 42;};
    auto f_func_49_1(int const&) -> double{return 3.14;};
    auto func_49(){
        // https://en.cppreference.com/w/cpp/compiler_support

        {   // [23:1/3] [P1102R2] [Make () more optional for lambdas]

            std::string strCur {"abc"};
            auto noSean = [sLocal = std::move(strCur)] mutable {
                sLocal += "d";
                std::cout << sLocal << '\n'; 
            };
            noSean();

        }

        {   // [23:2/3] [P2036R3] [Change scope of lambda trailing-return-type][no compiler support yet]

            //This paper proposes that name lookup in the trailing-return-type of a lambda first consider that lambda’s captures before looking further outward. 
            //That is, treat the trailing-return-type like the function body rather than treating it like a function parameter.


            //  Today, both lambdas return int.
            {
                //auto f_func_49_1(int&)       -> int{return 42;};
                //auto f_func_49_1(int const&) -> double{return 3.14;};
                int i{};

                auto should_capture = [=]() -> decltype(f_func_49_1(i)) {
                    return f_func_49_1(i);
                };
                auto should_not_capture = [=]() -> decltype(f_func_49_1(i)) {
                    return 42;
                };
                std::cout << should_capture() << std::endl; //3 [should return 3.14]
                std::cout << should_not_capture() << std::endl; //42 [ill-formed]
            }
        }

        {   // [23:3/3] [P2173R1][Attributes on lambdas]

            auto l=[][[nodiscard]]{return 42;};
            //l(); //warning: ignoring return value
            auto fetch = l();
            std::cout << fetch << std::endl;
            
        }

        {   // [20:1/7] [P0409R2][Allow lambda-capture [=, this]]
            // [=, *this] by value
            // [=, this] by reference

            struct A{
                int _a{};
            public:
                A(){
                    auto l = [=,*this]mutable{printf("%d\n",++_a);};   
                    l();                                //1
                    l();                                //2
                    printf("%d\n",_a);                  //0
                    [=,this]{printf("%d\n",++_a);}();   //1
                    printf("%d\n",_a);                  //1
                }
            } _;
        }

        {   // [20:2/7] [P0428R2][template-parameter-list for generic lambdas]
            /* ===========
                []<typename T>(T x) {  }
                []<typename T>(T* p) {  }
                []<typename T, int N>(T (&a)[N]) {  }
            */

            std::cout << "20:2" << std::endl;
            // There 3 reasons
            {   // 1. to simply "pattern matching"

                auto f_old = [](auto ivec){
                    using T = typename decltype(ivec)::value_type;
                    std::cout << (std::is_same<T, int>::value) << std::endl;
                };

                f_old(std::vector<int>{});
                f_old(std::vector<double>{});

 
                auto f_New = []<typename T>(std::vector<T> ivec){
                    std::cout << (std::is_same<T, int>::value) << std::endl;
                };

                f_New(std::vector<int>{});
                f_New(std::vector<double>{});                            
            }

            {   // 2. retrieve the type of the parameter of a generic lambda
                [[maybe_unused]] auto f_Old = [](auto const& x,
                    typename std::decay_t<decltype(x)>::difference_type n){
                    using T = std::decay_t<decltype(x)>;
                    T copy = x;
                    T::static_function();
                    using It [[maybe_unused]] = typename T::iterator;
                };

                [[maybe_unused]] auto f_New = []<typename T>(T const& x,
                    typename T::difference_type n){
                    T copy = x;
                    T::static_function();
                    using It [[maybe_unused]] = typename T::iterator;
                };
            }

            {   // 3. perfect forwarding also needs to use decltype
                [[maybe_unused]] auto f_Old = [](auto&& ...args){
                    return foo(std::forward<decltype(args)>(args)...);
                };

                [[maybe_unused]] auto f_New = []<typename ...T>(T&& ...args){
                    return foo(std::forward<T>(args)...);
                };

            }
		
        }

        {   // [20:3/7] [P0315R4][Lambdas in unevaluated contexts]

            // 1. a concern is that lambda-expressions might then be able to appear in the signature of functions with external linkage, which would require implementations to generate a name for the associated closure type.

            {   // 2. Another similar problem is that of lambda-expressions appearing in the signature of function templates. There are two ways this could happen. First, a lambda expression could appear not by itself, but indirectly, by being part of an expression which references a template parameter.  The other situation we would like to avoid is for implementations to have to figure out that the two following expressions are equivalent, either for linkage purposes (in different translation units) or for redeclaration purposes (in the same translation unit).
                [[maybe_unused]] auto l = []<int N>(const char (*s)[([]{},N)]){};

            }

            {   // 3.
                /* ===========
                // the inline function calls func with a closure type that is supported to be unique.
                // foo and bar modify the same cnt variable.
                // a.h
                template<typename T>
                int func(){
                    static int cnt = 0;
                    return cnt++;
                }
                inline int f(){ return func<decltype([]{})>();}

                // translation unit 1:
                #include "a.h"
                int foo(){return f();}

                // translation unit 2:
                #include "a.h"
                int bat(){return f();}
                */

                [[maybe_unused]] auto l = []<typename T>{
                    static int cnt = 0;
                    return cnt++;
                };
            }

            {   // 4.
                using namespace P0315R4_4;
                /* ===========
                // foo.h
                template <auto> struct foo{};
                //In both cases, this should be an ODR violation.
                extern foo<+[](){}>  x1;
                inline foo<+[](){}>  x2;
                

                // translation unit 1:
                #include "a.h"
                                
                // translation unit 2:
                #include "a.h"

                */
                
            }

        }

        {   // [20:4/7] [P0588R1][DR: Simplifying implicit lambda capture]

            [[maybe_unused]] auto l1 = []{
                float x{0.0};
                [[maybe_unused]] float&r = x;
                [[maybe_unused]] auto l2 = [=]{ 
                    decltype(x) y1{1};
                    ++y1;
                    decltype((x)) y2{2}; // l2 is not mutable, so y2 is const float&
                    //++y2;//error: increment of read-only reference ‘y2’

                    decltype(r) r1{y1};//[P0588R1]says r1 has type float&
                    r1 = y2;

                    decltype((r)) r2{y1};//[P0588R1]says r2 has type float const&
                    r2 = y2;
                };
            };

            using namespace P0588R1;

            {   // error: odr-use of non-odr-usable structured binding y
                int arr[2]{1,2};
                [[maybe_unused]] auto [y,z] = arr;
                struct local{
                    [[]]
                    std::optional<int> p(){
                        //return y;// error: use of local variable with automatic storage from containing function
                        return std::nullopt;
                    }
                };
            }
        }

        {   // [20:5/7] [P0624R2][Default constructible and assignable stateless lambdas]
            // Louis Dionne, Member of the C++ Standards Committee, Boost, and author of Hana.
	
            auto greater1 = [](auto x, auto y){return x>y;};
            std::map<std::string, int, decltype(greater1)> map1,map2;
            map1 = map2;
            
        }

        {   // [20:6/7] [P0780R2][Pack expansion in lambda init-capture]
            // move all parameters in a parameter pack in lambda init-capture, c++17 needs to use the help of tuple.
            // this proposal simplify the codes by including [...args = std::move(args)]{...}

            [[maybe_unused]]auto f1 = []<typename F, typename... Args>
            (F f, Args... args){
                [[maybe_unused]]auto g1 = [f, args...]{
                    return std::invoke(f, args...);
                };
                [[maybe_unused]] auto g2 = [f = std::move(f), ...args = std::move(args)]{
                    return std::invoke(f, args...);
                };
                [[maybe_unused]] auto g3 = [f = std::move(f), tup = std::make_tuple(std::move(args)...)]{
                    return std::apply([&f](const auto&... args){
                        return f(args...);
                    }, tup);
                };

                [[maybe_unused]]auto g31 = [f = std::move(f), tup = std::make_tuple(std::move(args)...)]{
                    return std::apply([&f](const auto&... args){
                        return f(args...);
                    }, tup);
                };

                [[maybe_unused]]auto g4 = [f= std::move(f), ...args = std::move(args) ]{
                    return std::apply(f, args...);
                };
            };
        
        }

        {   // [20:7/7] [P1091R3, P1381R1][Lambda capture and storage class specifiers of structured bindings]

            {   //P1091R3
                // linkage, extern, static and thread_local, inline, constexpr, lambda captures, [[maybe_unused]], template, impact
                int arr[]{1,2};
                [[maybe_unused]]auto[x,y] = arr;// the object has a name like _ZDC1x2yE

                //constexpr auto[a1] = std::tuple<int>(1);//error: structured binding declaration cannot be ‘constexpr’

                [[maybe_unused]]constexpr auto a2 = std::tuple<int>(1);
                //constexpr const int& a3 = std::get<0>(a2);/// ill-formed today, 20221022 msvc, gcc, clang, the latest version of theses compliers do not support constexpr structured bingding.

                const int var1{1};
                [[maybe_unused]]const int& ref1{var1};
                //static_assert(ref1 == 1);// error: non-constant condition for static assertion

                constexpr int var2{2};
                [[maybe_unused]]const int& ref2{var2};
                //static_assert(ref2 == 2);// error: non-constant condition for static assertion

            }
                        
            {   //P1381R1
                //auto [a] = []{return 1;}();// error: cannot decompose non-array non-class type ‘int’
                struct A{int a{};};
                auto [a] = A();
                [[maybe_unused]] auto l=[a]{};//captures 'a'

                {   // capture structed bingdings by reference has some problems
                    struct A{int a:1{1};};
                    [[maybe_unused]] auto [a] = A();
                    //std::cout << [&a]{return a;}() << std::endl;//error: cannot bind bit-field ‘a’ to ‘int&’
                }
                {
                    struct Foo { int a : 1; };
                    [[maybe_unused]] auto f = [](int&){};
                    [[maybe_unused]] Foo foo;
                    //f(foo.a); // ill-formed, reference to bit-field // error: cannot bind bit-field ‘foo.Basic::func_49()::Foo::a’ to ‘int&’
                }
                
                {
                    struct Foo { int a : 1; int b; };
                    auto[a, b] = Foo();

                    {   //cannot bind bit-field ‘a’ to ‘int&’
                        //auto f1 = [&] { return a; };      // still ill-formed with this proposal 
                        //auto f2 = [&a = a] { return a; }; // always was ill-formed; no change
                        //auto f3 = [&a] { return a; };     // still ill-formed with this proposal
                    }

                    [[maybe_unused]] auto g1 = [&] { return b; };      // previously ill-formed; well-formed with this proposal
                    [[maybe_unused]] auto g2 = [&b = b] { return b; }; // always was well-formed; no change
                    [[maybe_unused]] auto g3 = [&b] { return b; };     // previously ill-formed; well-formed with this proposal
                }
                
            }
        	
        }
        
        {   // [17:1/2] [P0018R3][Lambda capture of *this]
        			
        }   

        {   // [17:2/2] [P0170R1][constexpr lambda expressions]
        			
        }

        {   // [14:1/2] [N3648][Initialized/Generalized lambda captures (init-capture)]
        	
        }   

        {   // [14:2/2] [N3649][Generic lambda expressions]
        
        }

        {   // [11:1/1] [N2550, N2658, N2927][Lambda expressions]
        	
        }

    }

    class A_func_48{
    public:
        static  constexpr int a[2]{1,2};
        int b[2]{};
        int c[a[1]]{3,4};
        double d[4] = {1,2};
        double e[4] = {1,2.0};
        std::array<int,3> f{1,2,3};
        std::vector<int> g{1,2,3};
    };
    auto func_48(){

        auto l = [](const auto& t){std::cout << t << "\t";};
        A_func_48 a;
        std::ranges::for_each(a.a,l);std::cout << std::endl;
        std::ranges::for_each(a.b,l);std::cout << std::endl;
        std::ranges::for_each(a.c,l);std::cout << std::endl;
        std::ranges::for_each(a.d,l);std::cout << std::endl;
        std::ranges::for_each(a.e,l);std::cout << std::endl;
        std::ranges::for_each(a.f,l);std::cout << std::endl;
        std::ranges::for_each(a.g,l);std::cout << std::endl;
        /* ===========
            1       2
            0       0
            3       4
            1       2       0       0
            1       2       0       0
            1       2       3
            1       2       3
        */
    }

    auto func_47(){
        union f{
            auto g(int i)->void{printf("%d\n", i);}
        };
        //f::g(42);
    }

    auto func_46_1(int i){
        puts("hi");
    }

    auto func_46(){
        // no warning at all using my compailer

        std::cout << 
        [](auto l1, [[maybe_unused]] auto l2){
            return 42;
        }(1,"hi") << std::endl;

        struct A{
            static void f(int i1, [[maybe_unused]] int i2){
                puts("hi");
            }
        };
        A::f(1,2);
        A::f(1,22);

        func_46_1(42);


    }

    auto func_45(){
        // three-way comparison operator

        for(const auto& cur: {0,1,2,3}){
            const int base{1};

            // std::strong_ordering, std::weak_ordering

            std::strong_ordering result{cur<=>base};
            if (result == std::strong_ordering::less) { std::cout << "less" << std::endl; }
            if (result == std::strong_ordering::greater) { std::cout << "greater" << std::endl; }
            if (result == std::strong_ordering::equal) { std::cout << "equal" << std::endl; }
            
            std::cout << "<<<\t " << cur << " VS " << base << std::endl;
            std::cout << "std::is_lt(result)\t" << std::is_lt(result) << std::endl;
            std::cout << "std::is_lteq(result)\t" << std::is_lteq(result) << std::endl;
            std::cout << "std::is_eq(result)\t" << std::is_eq(result) << std::endl;
            std::cout << "std::is_gt(result)\t" << std::is_gt(result) << std::endl;
            std::cout << "std::is_gteq(result)\t" << std::is_gteq(result) << std::endl;
             std::cout << "\t\t>>>"<< std::endl;

            // switch(int i{};result){//error: switch quantity not an integer
            //     using std::strong_ordering;
            //     case less : ++i;
            //     case greater : ++i;
            //     case equal : printf("%d\n", ++i);
            // }
        }
    }

    auto func_44(){
        enum class A{a, b, c, d};
        A a1{A::b};
        switch(a1){
            using enum A;
            case a: a1 = b; break;
            case b: a1 = c; [[fallthrough]];
            case c: a1 = d; break;
            default:break;
        }
        if(auto l=[](A&& ia){
            printf("\t%d\n", static_cast<int>(ia));
        };a1 == A::d){
            l(std::move(a1)); // 3
        }
    }

    auto func_43(){
        //fmt::print("hi{}", 42);
        auto f = 3.141'5926'54f;
        std::byte b{42};
        std::cout << std::to_integer<int>(b)  << ", " << sizeof(b) << std::endl;//42,1
        printf("dd%f\n", f);

        std::cout << std::numeric_limits<int>::max() << std::endl;
        std::cout << std::numeric_limits<int>::min() << std::endl;

        float myINF{static_cast<float>(1.0/0.0)};
        std::cout << std::isnan(myINF) << std::endl; //0
        std::cout << std::isinf(myINF) << std::endl; //1
        std::cout << (myINF>0.0) << std::endl; //1
        std::cout << (myINF<0.0) << std::endl; //0
        std::cout << (myINF== std::numeric_limits<float>::infinity()) << std::endl; //1

    }

    auto func_42(){

        // use of a->b && a->b->c, only on idempotent function
        // idempotent function: f(f(x)) == f(x)

        struct A{
             std::unique_ptr<int> f(){
                ++a;
                return std::make_unique<int>(1);
            }
            int a{11};
        };

        if(A a, *a1{&a};a1 && a1->f() && *(a1->f()) == 1){
            printf("%d\n", a1->a);
        }
    }

    auto func_41(){
        struct A1{
            char a;
            int b;
            double c;
            long long d;
        };

        struct  alignas(max_align_t)   A2{
            char a;
            int b;
            double c;
            long long d;
        };

        std::cout << alignof(A1) << std::endl;//8
        std::cout << alignof(A2) << std::endl;//16


    }

    std::string operator"" _wow1(const char* ipchar, size_t len){
        return std::string{ipchar} + "_ww1";
    }
    std::string operator"" _wow2(unsigned long long l){
        return std::to_string(l) + "_ww2";
    }

    auto func_40(){
        std::string str{R"(c\t\t\t)"};
        std::cout << str << std::endl;//c\t\t\t

        auto str1 = "abc"_wow1;
        auto str2 = 2_wow2;
        std::cout << str1 << std::endl; // abc_ww1
        std::cout << str2 << std::endl; // 2_ww2


    }



    auto func_39_1_Throw(){throw true;}
    auto func_39_1_Throw_NO() noexcept {}
    auto func_39(){

        auto lambdaThrow = []{
            func_39_1_Throw();
        };
        auto lambdaThrow_NO = []noexcept{
            func_39_1_Throw_NO();
        };

        {


            std::cout << noexcept(func_39_1_Throw()) << std::endl; //0
            std::cout << noexcept(func_39_1_Throw_NO()) << std::endl; //1
            std::cout << noexcept(lambdaThrow()) << std::endl; //0
            std::cout << noexcept(lambdaThrow_NO()) << std::endl; //1
        }

        {

            auto l = [i{0}](std::function<void(void)> iFunc)mutable{
                ++i; 
                try{
                    iFunc();
                } catch(...){
                    std::cout << "Throw: " << i << std:: endl;
                }
            };

            l(func_39_1_Throw); //Throw: 1
            l(func_39_1_Throw_NO); // no catch
            l(lambdaThrow); //Throw: 3
            l(lambdaThrow_NO); // no catch

        } 
        



    }


    auto func_37(){
        
        std::packaged_task<int()> task([](){return 20220903;});
      
        std::future<int> result = task.get_future();
        std::thread(std::move(task)).detach();
        
        puts("waiting...") ;

        result.wait(); // block until future has arrived
        // output result
        std::cout << "done!" << std:: endl << "future result is " << result.get() << std::endl;
    }



    int func_36_value{1};

    auto func_36_1(int iv){
        static std::mutex m;
        //std::lock_guard<std::mutex> lock(m);
        //func_36_value = iv;
        std::unique_lock<std::mutex> lock(m);
        func_36_value = iv;
        std::cout << func_36_value << std::endl;
        lock.unlock();

        lock.lock();
        func_36_value +=1;
        std::cout << func_36_value << std::endl;

    }

    auto func_36(){

        std::thread t([]{std::cout << "hi" << std::endl;});
        t.join();

        std::thread t1(func_36_1,2), t2(func_36_1,3);
        t1.join();// 2,3
        t2.join();//3,4

    }


}