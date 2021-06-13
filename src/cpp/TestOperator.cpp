//
// Created by kevin on 2021/6/12.
//
#include <iostream>

using namespace std;

class Point{
    friend std::ostream &operator<<(std::ostream &strm, const Point &point);
    friend std::istream &operator>>(std::istream &strm, Point &point);
private:
    int x = 0;
    int y = 0;
public:
    Point() = default;

    Point(int x, int y) : x(x), y(y) {

    }
    const Point operator + (const Point& other) const{
        return Point(x + other.x, y + other.y);
    }

    //重载减号
    const Point operator - (const Point& other) const{
        return Point(x - other.x, y - other.y);
    }
    //重载负号
    const Point operator - () const{
        return Point(-x, -y);
    }

    Point &operator+=(const Point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

//    int a = 10;
//    ++a = 20;//相当于 a += 1; a = 20;
    //a++ = 20;//错误，相当于 10 = 20; a+=1;

    //++p，前置++能被赋值
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }

    //p++，后置++不能被赋值
    const Point operator++(int/*表示是后置++*/) {
        Point old(x, y);
        x++;
        y++;
        return old;
    }

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point &other) const {
        return x != other.x || y != other.y;
    }

    /**
     * 重载赋值运算符
     * @param other
     */
    Point &operator=(const Point &other) {
        x = other.x;
        y = other.y;
        return *this;
    }


};

class Sum{
public:
    //仿函数:将一个对象当作一个函数一样来使用
    //特点：可以访问成员变量，成员函数，调用看起来像函数。
    // 由于可以访问成员变量，保存函数的执行结果存储到成员变量上
    //其实如果你不需要让使用者感觉这个是一个函数对象，其实直接定义成普通的成员函数就行了，没必要搞成这样。
    int operator()(int a, int b){
        return a + b;
    }
};

//类似Java toString()
std::ostream &operator<<(std::ostream &strm, const Point &point) {
    return strm << "(" << point.x << "," << point.y << ")";
}

std::istream &operator>>(std::istream &strm, Point &point) {
    strm >> point.x >> point.y;
    return strm;
}

int main(int argc, const char* argv[]){
    Sum sum;
    cout << sum(10, 20) << endl;
    int a = 10;
    ++a = 20;//相当于 a += 1; a = 20;
    //a++ = 20;//错误，相当于 10 = 20; a+=1;
    const Point p1(10,23);
    const Point p2(10,23);
    Point p3(10,20);
    Point p4 = p1 + p2 + p3;
    p4 += p1;
//    p1 + p2 = p2;
    cout << "p1 " << p1 << endl;
    cout << "-p1 " << -(-p1) << endl;
    cout << "++p3 " << ++p3 << endl;
    cout << "p3++ " << p3++ << endl;
    cout << "p1 + p2 " << p1 + p2 << endl;
    cout << "p4 " << p4 << endl;
    cout << "p1  == p2 " << (p1 == p2) << endl;
    cout << "p1  != p2 " << (p1 != p2) << endl;
    cin >> p3;
    cout << "p3 " << p3 << endl;
    getchar();
    return 0;
}

