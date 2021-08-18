/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-06-14 22:43:42
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-18 22:43:54
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

// for example [T00019] thread //[good]
//              number  brief      describation

#include <numeric>
#include <vector>
#include <ctime>
#include <thread>
using namespace std;


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


// [T00020] vector
void testFunc20210811(){
    	int size =6;
	vector<int> vecOut(size);
	for(int& cur:vecOut)
	cout << cur << endl;
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


// [T00009] const
void testFuncAdd20210718_2()
{
    const int a = 10;
	int* pConstModifier = (int*)&a;
	const int  *q = &a;
	{
		*pConstModifier = 20;
	}
	std::cout <<a <<std::endl;//10
	std::cout <<*pConstModifier <<std::endl;//20
	std::cout << (&a == pConstModifier ) <<std::endl;//1
	std::cout << (q == pConstModifier ) <<std::endl;//1
}


// [T00008] sum
int funcAdd(const int& iNumFirst, const int& iNumSecond)
{
    return iNumFirst + iNumSecond;
}
void testFuncAdd20210718()
{
    int numA(0), numB(0);
    numA = 10;
    numB = 20;
    
    int sum(0);
    sum = funcAdd(numA, numB);
    std::cout << sum << std::endl;
}


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


// [T00006] The return type of static_cast
class ChildOne;
class Parent{
    public:
    Parent(){cout << "Parent" << endl;}
    // friend void operator=(Parent* ipParent, ChildOne* ipChildOne){ipParent = ipChildOne; }
};
class ChildOne: public Parent{
     public:
    ChildOne(){cout << "ChildOne" << endl;}
};
class ChildTwo: public Parent{
     public:
    ChildTwo(){cout << "ChildTwo" << endl;}
};
void funcTest20210702(){
    Parent* pParent = nullptr;
    ChildOne* pChildOne = nullptr;
    (pChildOne = static_cast<ChildOne*>(pParent))= new ChildOne;
    //std::move(

    int *p = 0;
    p+=5;
    cout << p << endl;
}


// [T00005] Test a class type that defined into one class.
class MyClass20210618  
{  
public: 
    MyClass20210618():_pMyPrivateClass(nullptr){};
    MyClass20210618(int iNum):_pMyPrivateClass(new MyPrivateClass(iNum)){};
    ~MyClass20210618();

    class MyPrivateClass{
    public:
        MyPrivateClass(){_flag = 10;}
        MyPrivateClass(int);
        int _flag;
        static int _flagStatic;
        void funcBold(){
            std::cout<<"funcBold" << std::endl;
        }  
        static void funcStatic(){ 
            std::cout<<"funcStatic: " <<_flagStatic << std::endl; 
        }  
    };
    MyPrivateClass* _pMyPrivateClass;
}; 
int MyClass20210618::MyPrivateClass::_flagStatic = 2;
MyClass20210618::MyPrivateClass::MyPrivateClass(int iNum){_flag = iNum;}
MyClass20210618::~MyClass20210618()
{
    if(_pMyPrivateClass){
        delete _pMyPrivateClass;
        _pMyPrivateClass = nullptr;
    }
}
void testFunc20210618()
{
    MyClass20210618 myClass1(6), myClass2;
    std::cout << myClass1._pMyPrivateClass->_flag<< std::endl;
    myClass1._pMyPrivateClass->funcBold();
    myClass1._pMyPrivateClass->funcStatic();

    std::cout << myClass2._pMyPrivateClass->_flagStatic<< std::endl;
    myClass2._pMyPrivateClass->funcBold();
    myClass2._pMyPrivateClass->funcStatic();
}


// [T00004] Failed test. I wanted to transfer a pointer of a class
//          into a pointer of function.
class Void;
class Void{
public:
    int* _pArrayNum;
    Void(int(*ipFunc)(int*));
    ~Void();
};

Void::Void(int (*ipFunc)(int*))
{
    *this=*(Void*)ipFunc;
    _pArrayNum = nullptr;
    _pArrayNum = new int(0);
}
Void::~Void(){
    if(_pArrayNum){
        delete _pArrayNum;
        _pArrayNum = nullptr;
    }
}
int funcJudger(int* iNum)
{
    int* uiNum = new int(1);
    return *iNum<5?1:0;
}
void funcRefactoring20210617()
{
    Void myFunc(funcJudger);

    int (*myJudge)(int*) = funcJudger;
    int numSize = 20;
    //Void myFunc(myJudge);

    for(size_t i=0;i<numSize;++i)
        std::cout << *myFunc._pArrayNum<< std::endl;
}


// [T00003] Refactor. Finding the missing number.
int funcShotOne20210615(std::vector<int>* ipVec){
  return (ipVec->size()-1)*ipVec->size()/2 - accumulate(ipVec->begin(),ipVec->end(),0); 
}
void testFuncShotOne20210615()
{
    int numSize = 100;
    std::vector<int> vecNum;
    for(int i = 0; i<numSize; ++i)
        vecNum.push_back(i);
    vecNum[11] = 0;

    srand(time(0));
    for(int i = 0; i < numSize; ++i)
        swap(vecNum[ i + rand()%(numSize-i) ], vecNum[i]);

    for(int i = 0; i<numSize; ++i)
            std::cout << vecNum[i] << "\t";

    std::cout << "\nThe missing number is: " << funcShotOne20210615(&vecNum)  << std::endl;
}


// [T00002] Refactor. Using array of pointers. //[good]
void funcRun(void*)
{
    std::cout << "Game Starts..." << std::endl;
}
void funcEnd(void*)
{
    std::cout << "Game Ends..." << std::endl;
}
void funcIn(void*)
{
    char *pStrChoices[4] =
        {(char*)"Game Starts.", (char*)"Game Ends.", (char*)"Invalid Number, try again."};
    void(*pFunc[3])(void*) = {funcRun, funcEnd, funcIn};
    char input(0);

    if (std::cin >> input){
        input = ((input >= 48) && (input <= 50)) ? input - 48 : 2;
        std::cout << "Your choice: " << pStrChoices[input] << std::endl;
        (*pFunc[input])(nullptr);
    }
}
void funcRefactoring20210614()
{
    funcIn(nullptr);
}


// [T00001] Test IO 
void funcTestVector20210614()
{
    vector<vector<int>> matrix;
	int valX(0), valY(0);

	while(cin>>valX >> valY){
		vector<int> vectorTemp;
		vectorTemp.push_back(valX);
		vectorTemp.push_back(valY);
		matrix.push_back(vectorTemp);
	}

	for(auto vectorCur:matrix)
		cout << vectorCur[0] << "\t" << vectorCur[1] << endl;
}