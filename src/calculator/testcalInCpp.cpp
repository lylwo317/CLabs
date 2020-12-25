#include <iostream>
#include <map>
#include <string>
#include "cal.h"
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, string> map;
    map["Name"] = "Kevin Xie";
    map["Age"] = "100";
    cout << map["Name"] << endl;
    cout << endl;
    int result = add(10, 23);
    printf("result = %d\n", result);
    return 0;
}
