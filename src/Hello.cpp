#include <iostream>

using namespace std;

extern "C" {

}

void fun(long i) {
  cout << "fun()" << endl;
}

void fun(int i = 10) {
  cout << "fun(int i)" << endl;
}

int main(int argc, char const *argv[])
{
    int i = 0;

    if (i != 1)
    {

    }
    
    cout << "Hello cpp" << endl;
    fun();
    fun(10L);
    return 0;
}
