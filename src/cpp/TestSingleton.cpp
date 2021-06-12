//
// Created by kevin on 2021/6/12.
//

#include <iostream>

using namespace std;

class Rocket{
private:
    int weight = 1000;
public:
    Rocket(){

    }
};

/*
class  Singleton {
public:
    // 注意返回的是引用。
    static Singleton& getInstance(){
        static Singleton m_instance;  //局部静态变量
        return m_instance;
    }

private:
    Singleton() = default; //私有构造函数，不允许使用者自己生成对象
    Singleton(const Singleton& other) = delete;
    virtual ~Singleton() = default;//构造函数私有的话，那么析构函数也要私有化
    const Singleton operator=(const Singleton &other) const = delete;
};
*/

template<typename T>
class Singleton
{
public:
    static T& getInstance() {
        static T value_; //静态局部变量
        return value_;
    }

private:
    Singleton() = default; //私有构造函数，不允许使用者自己生成对象
    Singleton(const Singleton& other) = delete;
    virtual ~Singleton() = default;//构造函数私有的话，那么析构函数也要私有化
    const Singleton operator=(const Singleton &other) const = delete;
};

int main(int argc, char const *args[]){
    cout << &Singleton<Rocket>::getInstance() << endl;
    cout << &Singleton<Rocket>::getInstance() << endl;
    return 0;
}