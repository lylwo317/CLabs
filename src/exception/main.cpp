#include <iostream>
#include <string>
using namespace std;

class MyExcept
{
public:
    explicit MyExcept(string err) : errmsg(err) {}
    string getErrMsg() const { return errmsg; }
private:
    string errmsg;
};

class Demo
{
public:
    void except_test()
    {
        throw MyExcept("Throw exception in member function");
    }
    Demo () {}
    ~Demo()
    {
        cout << "Will destructor be called? " << endl;
    }
};

int main(int argc, char* argv[])
{
    try
    {
        Demo d;
        d.except_test();
    }
    catch (const MyExcept& e)
    {
        cout << e.getErrMsg() << endl;
    }
    return 0;
}
