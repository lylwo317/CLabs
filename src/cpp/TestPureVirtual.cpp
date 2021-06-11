#include <iostream>
using namespace std;
//       虚函数，纯虚函数
//相当于
// Java：抽象类、接口
struct Animal {
    //含有纯虚函数，不能构建
    virtual void speak() = 0;
    virtual void run() = 0;
    virtual ~Animal() = default;
};

struct Dog : Animal {
    void run() override {//添加override，这样表明run是重写了父类的虚函数或者纯虚函数。当父类调整了纯虚函数后，这个方法就会报错。
        cout << "Dog::run()" << endl;
    }
};

struct Hashiqi : Dog {
    void speak() override {
        cout << "Hashiqi::speak()" << endl;
    }
};

int main() {
    Animal *animal = new Hashiqi;
    delete animal;
    getchar();
    return 0;
}
