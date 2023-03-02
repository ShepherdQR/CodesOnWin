/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-06-14 22:43:42
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-03-02 22:17:13
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

// for example [T00019] thread //[good]
//              number  brief      describation
#pragma once

#include <numeric>
#include <vector>
#include <ctime>
#include <thread>
#include <functional>
#include <tuple>

using namespace std;

namespace func20220605{


    template<typename... Ts>
    class B{
        public:
        B(Ts... args){
            cout << sizeof...(args) << endl;
        }
    };
    auto func_3(){
        B<int, vector<int>> b1(1,{0,1});//2
        B<> b2;//0
    }


    template<typename T, typename U>
    class A{
        public:
        T t;
        U u;
    };

    template<typename T>
    using A1 = A<std::vector<T>, std::string>;

    auto func_2(){
        A1<bool> a{{false, false}, "hi"};
        cout << a.t[1] << endl;
    }




    auto func20220605_1(){
    //template class std::vector<bool>; // force instantiation
    //extern template class std::vector<double>; // should not instantiation in current file

    }

}




std::string func20220604_5A(){return {};}
std::string& func20220604_5B(){static std::string str; return str;}
decltype(auto) func20220604_5AA(){
    return func20220604_5A();
}
decltype(auto) func20220604_5BB(){
    return func20220604_5B();
}

// TEST auto add(auto x, auto y)
namespace func20220604_4{

    struct AA{
        auto add(auto x, auto y){
            return x+y;
        }
    };

    struct BB: AA{
        auto add(auto x, auto y){
            return x+y+y;
        }
    };

    template<typename T, typename U>
    auto add2(T t, U u) ->decltype(t+u){
        return t+u;
    }

    template<typename T, typename U>
    auto add3(T t, U u){
        return t+u;
    }

    auto add(auto x, auto y){
        return x+y;
    }

    auto func20220604_4(){
        cout << add(1,2) << endl;//[3]
        cout << add(1.1,2.2) << endl;//[3.3]

        struct A{
            int val = 0;
            A(int iVal):val(iVal){}
            A operator+(const A& ia){
                return A(val + ia.val);
            }
        };

        cout << BB().AA::add(A(1),A(2)).val << endl;//[3]
        cout << add2(A(1),A(2)).val << endl;//[3]
        cout << add3(A(1),A(2)).val << endl;//[3]
    }
}

auto func20220604_3(){
    auto [x,y,z] = []{return std::make_tuple(1,3.14,"hi");}();
    cout << x << " " << y << " " << z << endl;

    auto arr = new auto(10);
    cout <<typeid(arr).name() << *arr << endl;
    delete arr;

    // struct A{
    //     int add(auto x, auto y){
    //         return x+y;
    //     }
    // };


}






auto func20220604_1(){
    //1. char* str = "hello";//warning: ISO C++ forbids converting a string constant to 'char*'
    //std::cout << str << std::endl;

    //2. use static_cast, reinterpret_cast, const_cast

    //3. 
    auto lambdaAdd = [](int a, int b){ return a + b; };
    [_ = std::ref(std::cout << lambdaAdd(1,2))]{
        _.get()<< std::endl;
    }();

    std:cout << std::is_same<decltype(NULL), decltype(nullptr)>::value << std::endl;//0
    cout << std::is_same<decltype(NULL), decltype(0)>::value << std::endl;//0
    cout << std::is_same<decltype(NULL), decltype((void*)0)>::value << std::endl;//0

    int a = 2;
    int p[a];
    for(auto cur:{0,1,2}){
        p[cur] = cur;
    }
    for(auto cur:{0,1,2,3,4}){
        cout << p[cur] << endl;
    }
}


#include <random>
auto func20220603(){
    default_random_engine e(time(0));
    for(auto t:{1,2,3,4,5}){
        cout << e()%10<< endl;
    }
}




auto func20220530_a(int i=6){
    struct f{
        f(){
            if(pf) delete[] pf;
            pf = new f(_i);
            []{printf("Repete.\n");}();
            //cout <<"Repete i times." << endl;
        }

    
        f(int i):_i(i){
            if(pf) delete pf;
            pf = new f[_i]();
            
        }
        f* pf = nullptr;
        int _i = 0;
        
    } _(i);
}



// auto func20220530_1(int i=6){
//     struct f{
//         f(){
//             delete[] pf;
//             pf = new f(_i, nullptr);
//             //[]{printf("Repete.\n");}();
//             //cout <<"Repete i times." << endl;
//         }

    
//         f(int& i,  std::function<void(void)> iif):_i(i),ff(iif){
//             delete pf;
//             cout << "hh" << endl;
//             pf = new f[_i]();
            
//             ff();
//             std::invoke(iif);
//             iif();
//         }
//         f* pf;
//         int _i;

//         std::function<void(void)> ff;
        
//     } _(i, std::move([]{printf("Repete.\n");}));
// }



/*----------------------------------------------------------------

    std::unique_ptr<struct f{f(int i){
            cout << i << endl;
            func20220412_function_2();
        }
    } f[]{1,2};>
*/


void g( int i = 10){

    []{
        int rris = 10;
        cout <<"[01] " <<  &rris << endl;
    }();


    struct f{
        void tt(){}
        f(int& i){
            cout << i  << endl;
            if(i)g(--i);
        }
    } f(i);

    // struct ff{
    //     fg(int*  ii =  (int*)((void*) &ff::fg  )){
    //         cout << ii  << "---";
    //         cout << (int*)((void*) &fg  ) << "---";
    //     }
    // } _;
    // _.fg();

    // cout << (int*)((void*) &f::tt  ) << "---";

    int rri = 10;
    cout << &rri << endl;
}



void func20220412_function_1(){

    struct _{
            virtual void f(int i)=0;
        };

    struct __: public _{
        virtual void f(int i){ 
            func20220412_function_1();
            cout << i << endl;
        }
        
    };

    // void __::f(int i)
    //     {
    //         cout << i << endl;
    //     } 

    __().f(1);
}





#include<queue>
void func20220411_queue_5(){
    class pcb{
    public:
        pcb(int i){_=i;}
        int _ = 0;
    };

    // function<bool(pcb*, pcb*)>
    // auto f = [](pcb* a, pcb* b){ 
    //     return a->_ < b->_;
    // };

   
    //auto 
    function<bool(pcb*, pcb*)>
    f = [](const pcb* a, const pcb* b){ 
        return a->_ < b->_;
    };

    struct greater{
        bool operator() (pcb* a, pcb* b) const {
            bool bt =  a->_ < b->_;
            //cout <<"bt" << bt << endl;
                return bt;
            }
    };

    pcb* _data[5];
    vector<pcb> data{3,1,4,5,2};
    int i(0);
    for(auto _:data){
        _data[i++] = new pcb(_);//&_;
        cout << _._ << endl;
    }
    std::priority_queue<pcb*, vector<pcb*>,greater> p(_data, _data+5);
    while(!p.empty()){
        cout << p.top()->_; 
        delete p.top();
        p.pop();
    }
    cout << endl << "========" << endl;

    vector<pcb*> vecInit;
    std::priority_queue<pcb*, vector<pcb*>,decltype(f)> pp{f,vecInit};

    for(auto _:data){
        pp.push(new pcb(_));//&_
        cout << _._ << endl;
    }

    while(!pp.empty()){
        cout << pp.top()->_;
        delete pp.top();
        pp.pop();
    }
 cout << endl << "========" << endl;


    std::priority_queue<pcb*, vector<pcb*>,decltype(f)> ppp{f};
    for(auto& _:data){
        ppp.push(&_);
        cout << _._ << endl;
    }

     while(!ppp.empty()){
        cout << ppp.top()->_;
        ppp.pop();
    }




    for(auto _:vecInit){
        cout << _->_ << endl;
    }




    //decltype(f)
    // for(auto _:data){
    //     p.push(&_);
    //     cout << _._ << endl;
    // }
    


}





class A;
class B{
    std::unique_ptr<A> _;
public: B();
};

class A{
    int _=10;
    friend  B::B();
};

B::B():_(new A()){
    cout <<A()._ << _->_ << endl;
}

void func20220411_friend_4(){
    B();
}



void func20220411_invoke_3(){
    class A{
    public:
        void f(const bool i){ std::cout << !i << std::endl;}
    };
    std::invoke((&A::f), A(), 0);
    std::apply((&A::f), std::make_pair(A(), 1));
}


template<class Func, typename ... Args>
void call(Func f, Args... args){
    std::invoke(f, args...);
}
void func20220411(int i){ std::cout << i << std::endl;}

void func20220411_invoke_2(){
    class A{
        void ff(int i){ std::cout << ++i << std::endl;}
    public:
        A(int i){ std::cout << --i << std::endl;}
        void f(int i){ std::cout << ++i << std::endl;}
    };
    std::invoke(&func20220411, 10);
    std::invoke((&A::f), A(3), 2);
    cout << "========" << endl;
    call(&func20220411, 10);
    call((&A::f), A(3), 2);
    std::apply((&A::f), std::make_pair(A(10), 2));
    //std::invoke((void (A::*)(int))(&A::f), A(), 10);
    //std::invoke((&A::ff), A(), 2);//error: declared private
    //std::invoke((&A::A), A(2), 3);//error: taking address of constructor
}






void func20220411_invoke_1(){
    std::invoke([](auto i){cout << i << endl;}, 1);
}




// [T00021] a problem
void testFunc20210817()
{	
	for(int i=1;i<200;++i){
		double cur =  (i*2)/(i-2.);
		double cur2 =  (2)/(1-4./i);
		cout <<cur2 << endl;
	}
    //std::cout << sin(30./180*3.14) << std::endl;
}





// [T00019] thread //[good]
class class20210804{
public:
    class20210804(void(*ipfFunc)(int*), int* ipVal);

private:
    std::thread* _pThread;
};
class20210804::class20210804(void(*ipfFunc)(int*), int* ipVal)
:_pThread(nullptr)
{
    _pThread = new std::thread(ipfFunc, ipVal);
    if(_pThread){
        //_pThread->detach();
        _pThread->join();
        delete _pThread;
        _pThread = nullptr;
    }
}
void testFunc20210804(){
    int num = 6;
    auto funcTemp = [](int *ipNumber){
	for (int i = 0; i < 6; ++i)
	cout <<"Number " << i << ": " << *ipNumber << endl; };
    class20210804 tempClass(funcTemp, &num);
}


// [T00018] bad to return a reference
class class20210802{
    int* _pNumberTest = nullptr;
public:
    int*& retriveNumber(){return _pNumberTest;}
    class20210802(){
        _pNumberTest = new int(10);
    }
    ~class20210802(){//:class20210802()
        if(_pNumberTest){
            delete _pNumberTest;
            _pNumberTest = nullptr;
        }
    }
};
void funTest20210802(){
    using namespace std;
    int* pNumber(nullptr);
    {
        class20210802 myClass;
        pNumber = myClass.retriveNumber();
    }
    cout << pNumber << endl;
}


// [T00017] IEEE float vs double. Failed test.
void funTest20210801(){
    // double num;
	// scanf("%f", &num);
	// printf("%d", &num);

	// int a = 0xab;
	// std::cout << std::hex << "a: " << a  << std::dec << std::endl;

	 float* pInputNum = new float(64.25);
	// double* pInputNum2 = new double(*pInputNum);

	// std::cout << std::oct;
	 double* numCur =(double*) (void*)(pInputNum) ;
	// float* numCur2 =(float*) (void*)(pInputNum2) ;

	// cout << *pInputNum << endl;
	 cout << *numCur << endl;
	// cout << *numCur2 << endl;
	
	// std::cout << std::dec;
	if(pInputNum){
		delete pInputNum;
		pInputNum  = nullptr;
	}
	// if(pInputNum2){
	// 	delete pInputNum2;
	// 	pInputNum2  = nullptr;
	// }
}


// [T00016] bind static or dynamic
class Base20210725{
protected:
   // int _num;
public:
    virtual void printVar(){
        //_num = 10;
        //cout << _num << endl;
        cout << "10" << endl;
    }
};
class Derived20210725 : public Base20210725{
public:
    void printVar(){
        //_num = 20;
        //cout << _num << endl;

        const int _num =[]{return 20;}();
        cout << _num << endl;
    }
};
void testClass20210725() {
    Base20210725* pBase(nullptr);
    Base20210725 myBase;
    Derived20210725 myDer;

    for(int i=0;i<20;++i){
        srand(unsigned(time(0)*2+i));
        int number = rand()%20;
        //cout << number << endl;
        if(number>10){
                pBase = &myBase;
        }else{
            pBase = &myDer;
        }
        pBase->printVar();
            pBase->Base20210725::printVar();
   //pBase->Derived20210725::printVar();
    }

    //pBase->printVar();
    //pBase->Base20210725::printVar();
    //pBase->Derived20210725::printVar();
}


// [T00015] null
void testConst20210721()
{
    string:
	int* pNULL = NULL;
	int* qNULL = NULL;
	std::cout << pNULL <<" " << qNULL << std::endl;//0 0
}


// [T00014] const
void testConst20210720()
{
    const int i = 10;
	int* pI = (int*)&i;
	cout << &i << ", " << i << endl;
	cout << pI << ", " << *pI << endl;

	*pI = 20;
	cout << &i << ", " << i << endl;
	cout << pI << ", " << *pI << endl;
}


// [T00013] const
int funcTestConst20210720_2_2()
{
    return 100;
}
constexpr int funcTestConst20210720_2_2Const()
{
    return 3;
}
int* funcTestConst20210720_2()
{
    int* pTemp = new int(4);
    return pTemp;
}
void testConst20210720_2()
{
    const int i = 1;//1,1,1,20//
    //const int i =[]{return 2;}();//2,2,20,20
    //const int i =funcTestConst20210720_2_2Const();//3,3,3,20
    /*
    int* pTemp(nullptr);
    pTemp = funcTestConst20210720_2();//4,4,20,20
    const int i =*pTemp;
    if(pTemp){
        delete pTemp;
        pTemp = nullptr;
    }
    */
	int* pI = (int*)&i;
	cout << &i << ", " << i << endl;
	cout << pI << ", " << *pI << endl;

	*pI = 20;
	cout << &i << ", " << i << endl;
	cout << pI << ", " << *pI << endl;
}


// [T00012] size of the default stack
void testStack20210720(int &iIndex)
{
    int arrayBig[1024*1024/4-1024*4];
    std::cout << "Is ok, round " << iIndex << std::endl;
    if(iIndex>0){
        return testStack20210720(--iIndex);
    }  
}
void testtestStack20210720()
{
    int times(1);
	testStack20210720(times);
}


// [T00011] sizeof
void testFunc20210719()
{
    int arrayNum[] = {1,2};
	cout << (sizeof arrayNum) / (sizeof arrayNum[0]) << endl;
}


// [T00010] const
class MyClassForTestConst
{
public:
    int _num;
    MyClassForTestConst(const int &iNum = 0){_num = iNum;}
    void resetNum(const int &iNum = 0){_num = iNum;}
    void display(){std::cout << "Normal:" << _num << std::endl;}
    void display()const{std::cout <<"Const:" << _num << std::endl;}
    ~MyClassForTestConst(){}
    void funcP(MyClassForTestConst* iMyClassForTestConst)
    {   //This can modify iMyClassForTestConst
        iMyClassForTestConst->_num = 1;
        iMyClassForTestConst->display();
    }

    void funcConstP(const MyClassForTestConst* iMyClassForTestConst)
    {   //This can modify iMyClassForTestConst
        MyClassForTestConst* pClassModifier = (MyClassForTestConst*)iMyClassForTestConst;
        pClassModifier->_num = 1;
        iMyClassForTestConst->display();
        pClassModifier->display();
    }

    void funcPConst( MyClassForTestConst*const iMyClassForTestConst)
    {   //This can modify iMyClassForTestConst
        MyClassForTestConst* pClassModifier = (MyClassForTestConst*)iMyClassForTestConst;
        pClassModifier->_num = 1;
        iMyClassForTestConst->display();
        pClassModifier->display();
    }

    void funcConstPConst(const MyClassForTestConst*const iMyClassForTestConst)
    {   //This can modify iMyClassForTestConst
        MyClassForTestConst* pClassModifier = (MyClassForTestConst*)iMyClassForTestConst;
        pClassModifier->_num = 1;
        iMyClassForTestConst->display();
        pClassModifier->display();
    }

};
void releaseMyClassForTestConst(MyClassForTestConst* &iMyClassForTestConst)
{
    if(iMyClassForTestConst){
        delete iMyClassForTestConst;
        iMyClassForTestConst = nullptr;
    }
}
void funTestMyClassForTestConst20210718()
{
    int Num = 0;
    MyClassForTestConst* pMyClass = new MyClassForTestConst(Num);
    //MyClassForTestConst* pMyClassParam = new MyClassForTestConst(Num);
    MyClassForTestConst* pMyClassParamReal = new MyClassForTestConst(Num);
    MyClassForTestConst*const pMyClassParam = pMyClassParamReal;

    std::cout << "\n\t" << "funcP:" << std::endl;
    pMyClassParam->resetNum(Num);
    pMyClassParam->display();
    pMyClass->funcP(pMyClassParam);
    pMyClassParam->display();


    std::cout << "\n\t" << "funcConstP:" << std::endl;
    pMyClassParam->resetNum(Num);
    pMyClassParam->display();
    pMyClass->funcConstP(pMyClassParam);
    pMyClassParam->display();


    std::cout << "\n\t" << "funcPConst:" << std::endl;
    pMyClassParam->resetNum(Num);
    pMyClassParam->display();
    pMyClass->funcPConst(pMyClassParam);
    pMyClassParam->display();

    std::cout << "\n\t" << "funcConstPConst:" << std::endl;
    pMyClassParam->resetNum(Num);
    pMyClassParam->display();
    pMyClass->funcConstPConst(pMyClassParam);
    pMyClassParam->display();


    releaseMyClassForTestConst(pMyClass);
    releaseMyClassForTestConst(pMyClassParamReal);
}

