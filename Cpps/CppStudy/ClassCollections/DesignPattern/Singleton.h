/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-22 22:47:40
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-09-09 21:10:47
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

/**================================================================

You need to have one and only one object of a type in system
你需要系统中只有唯一一个实例存在的类的全局变量的时候才使用单例。

如果使用单例，应该用什么样子的
How to create the best singleton:

The smaller, the better. I am a minimalist
Make sure it is thread safe
Make sure it is never null
Make sure it is created only once
Lazy or system initialization? Up to your requirements
Sometimes the OS or the JVM creates singletons for you (e.g. in Java every class definition is a singleton)
Provide a destructor or somehow figure out how to dispose resources
Use little memory
越小越好，越简单越好，线程安全，内存不泄露

*/




class SingletonA{
public:
    //typedef std::shared_ptr<SingletonA> Ptr;
    static std::shared_ptr<SingletonA> getInstance();

    ~SingletonA();
    SingletonA(SingletonA&)=delete;
    SingletonA& operator=(const SingletonA&)=delete;

private:
    SingletonA();
    static std::shared_ptr<SingletonA> m_instance_ptr;
    static std::mutex m_mutex;
    
};


class SingletonB{
public:
    static SingletonB& getInstance();

    ~SingletonB();
    SingletonB(const SingletonB&)=delete;
    SingletonB& operator=(const SingletonB&)=delete;

private:
    SingletonB();
};


// Not good. one instance is always created, even when we do not use it.
class SingletonC{
public:
    static SingletonC& getInstance(){return _singlentonC;}

    ~SingletonC();
    SingletonC(const SingletonC&)=delete;
    SingletonC& operator=(const SingletonC&)=delete;

private:
    SingletonC();
    static SingletonC _singlentonC;
};



////////////////////////////////////////////////////////////////
// brief: a singleton base class offering an easy way to create singleton
//CRTP 奇异递归模板模式实现
#include <iostream>

template<typename T>
class Singleton{
public:
    static T& get_instance(){
        static T instance;
        return instance;
    }
    virtual ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    Singleton(const Singleton&)=delete;
    Singleton& operator =(const Singleton&)=delete;
protected:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }

};
/********************************************/
// Example:
// 1.friend class declaration is requiered!
// 2.constructor should be private


class DerivedSingle:public Singleton<DerivedSingle>{
   // !!!! attention!!!
   // needs to be friend in order to
   // access the private constructor/destructor
   friend class Singleton<DerivedSingle>;
public:
   DerivedSingle(const DerivedSingle&)=delete;
   DerivedSingle& operator =(const DerivedSingle&)= delete;
private:
   DerivedSingle()=default;
};

int main(int argc, char* argv[]){
    DerivedSingle& instance1 = DerivedSingle::get_instance();
    DerivedSingle& instance2 = DerivedSingle::get_instance();
    return 0;
}






/////////////////////////
/**
精髓在于使用一个代理类 token，子类构造函数需要传递token类才能构造，但是把 token保护其起来， 然后子类的构造函数就可以是公有的了，这个子类只有 Derived(token)的这样的构造函数，这样用户就无法自己定义一个类的实例了，起到控制其唯一性的作用。
 * */
// brief: a singleton base class offering an easy way to create singleton
#include <iostream>

template<typename T>
class Singleton{
public:
    static T& get_instance() noexcept(std::is_nothrow_constructible<T>::value){
        static T instance{token()};
        return instance;
    }
    virtual ~Singleton() =default;
    Singleton(const Singleton&)=delete;
    Singleton& operator =(const Singleton&)=delete;
protected:
    struct token{}; // helper class
    Singleton() noexcept=default;
};


/********************************************/
// Example:
// constructor should be public because protected `token` control the access


class DerivedSingle:public Singleton<DerivedSingle>{
public:
   DerivedSingle(token){
       std::cout<<"destructor called!"<<std::endl;
   }

   ~DerivedSingle(){
       std::cout<<"constructor called!"<<std::endl;
   }
   DerivedSingle(const DerivedSingle&)=delete;
   DerivedSingle& operator =(const DerivedSingle&)= delete;
};

int main(int argc, char* argv[]){
    DerivedSingle& instance1 = DerivedSingle::get_instance();
    DerivedSingle& instance2 = DerivedSingle::get_instance();
    return 0;
}






