#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

int main() { 
    std::vector<int> vec;
    std::istream_iterator<int> in(std::cin), eof;
    copy(in, eof, std::back_inserter(vec));

    std::ostream_iterator<int> out(std::cout, " ");//用空格分割
    copy(vec.begin(), vec.end(), out);
    return 0;
}