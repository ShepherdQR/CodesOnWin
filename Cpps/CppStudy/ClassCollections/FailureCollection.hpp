/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-24 23:42:58
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-02-11 20:50:07
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/




// [T00007] using. Failed test.
class AutoRelease20210703{
    public:
    void display(){std::cout << "Hello." << std::endl;}
    ~AutoRelease20210703(){std::cout << "Release" << std::endl;}
};
void testUSING20210703()
{
    // using (AutoRelease20210703 pClassTemp = new AutoRelease20210703)
	// {
	// 	if(pClassTemp)
	// 	{
	// 		pClassTemp->display();
	// 	}
	// }
}



// [T0001] no idea 
void testFunction20220131(){
//    template<class Head, class... T>
//     [=]<class Head, class... T>(const int Today,
//         std::function<void (Head iHead, T... args) >iFunc
//     ){
//         iFunc(2022, 1, Today);

   

//     [=] (const int Today,
//         std::function<void (Head iHead, T... args) >iFunc
//     ){
//         iFunc(2022, 1, Today);

//     }<(31, funTemplate);

   
//     auto f = [=]<class T> ( int Today,
//         std::function<void (T) >iFunc
//     ){
//         iFunc( Today);

//     };//(31, funTemplate1)

//     f<int> (31,funTemplate1 );

//    funTemplate(2022, 1, 31);

// }
}




void func20220424_DEFINE(){

    bool b = true;

    class A{
        bool _;
    public:
        A(bool ib){_ = ib;}

    };
    // if(b){
    //     else{
    //         cout << "false" << endl;
    //     }
    //     cout << "true" << endl;
    // }

}
