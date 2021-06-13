//
// Created by kevin on 2021/6/13.
//
#include <iostream>

using namespace std;

class Person{
    int age = 0;

public:
    virtual ~Person() = default;
};

class Student: public Person{
public:
//    virtual ~Student() override = default;
};

class Car{

};

void testConst_cast(){
    //const_cast
    //一般用于去除const属性,将const转换成非const。与C语言强转方式没区别，唯一的优点应该是可读性更强
    //一看就知道是为了去除const限制
    const Person *p1 = new Person();
    //C++方式
    Person *p2 = const_cast<Person *>(p1);
    //C方式
    Person *p3 = (Person *) p1;
    delete p1;
}

void testDynamic_cast(){
    //dynamic_cast
    //一般用于多态类型的转换,有运行时安全检测
    Person *p5 = new Person();
    Person *p6 = new Student();

    //通过_dynamic_cast检测对比发现p5不是Student或者其子类，所以这里stu1 = nullptr;
    Student *stu1 = dynamic_cast<Student *>(p5);//nullptr

    //这里检测发现p6是Student或者其子类，顺利赋值给stu2。stu2 = p6;
    Student *stu2 = dynamic_cast<Student *>(p6);

    cout << "stu1 = " << stu1 << endl;//stu1 = 0
    cout << "stu2 = " << stu2 << endl;//stu2 = 0x12345

    delete p5;
    delete p6;
    //总的来说，这个转换肯定是有性能消耗的，如果能自己判断类型。就没有必要使用dynamic_cast来转换
}

/**
 * 相比dynamic_cast，static_cast在编译时就检测出两个类是否是同一继承体系。而dynamic_cast要在运行时才能检测
 */
void testStatic_cast(){
    Person *p1 = new Person();
    Car *c1 = new Car();
    //1. 不能交叉转换(不是同一继承体系的,无法转换)
    //p1 = static_cast<Person *>(c1);//编译报错，不可转换
    //p1 = (Person *) c1;//可以转换

    //2. 基本数据类型的转换
    int a = 10;
    double b = a;
    //上面其实会执行static_cast隐式转换，等同于下面。一般不需要这样写，多此一举
    double c = static_cast<double>(a);

    //3. 非const转const
    const Person *p2 = p1;
//    const Person *p2 = static_cast
}

/**
 * 比较底层的强制转换,没有任何类型检查和格式转换,仅仅是简单的二进制数据拷贝
 */
void testReinterpret_cast(){
    int a = 10;
    double c = a;
    /*
        mov     eax, DWORD PTR [rbp-20]   # a.7_1, a
        cvtsi2sd        xmm0, eax       # tmp84, a.7_1
        movsd   QWORD PTR [rbp-8], xmm0       # c, tmp84
     */

    double b = reinterpret_cast<double &>(a);
    //注意这里只拷贝了4个字节，因为sizeof(int) = 4，而sizeof(double) = 8;
    /*
        lea     rax, [rbp-12]     # a.7_1,
        movsd   xmm0, QWORD PTR [rax] # tmp83, MEM[(double &)a.7_1]
        movsd   QWORD PTR [rbp-8], xmm0       # b, tmp83
     */
}

int main(int argc, const char *argv[]){
    testConst_cast();
    testDynamic_cast();
    testStatic_cast();
    testReinterpret_cast();
    return 0;
}