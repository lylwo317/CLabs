#include "logstream.h"
#include <algorithm>
namespace kx {
const char digits[] = "9876543210123456789";
const char* zero = digits + 9;
static_assert(sizeof(digits) == 20, "wrong number of digits");

template<typename T>
size_t convert(char buf[], T value)
{
  T i = value;
  char* p = buf;

  do
  {
    int lsd = static_cast<int>(i % 10);
    i /= 10;
    *p++ = zero[lsd];
  } while (i != 0);

  if (value < 0)
  {
    *p++ = '-';
  }
  *p = '\0';
  std::reverse(buf, p);

  return p - buf;
}

Logstream::Logstream()
{

}

void Logstream::formatInteger(long long v){
    if(buffer_.avail() > 64){
        size_t len = convert(buffer_.current(), v);
        buffer_.add(len);
    }
}

Logstream& Logstream::operator<<(short v){
    formatInteger(v);
    return *this;
}
Logstream &Logstream::operator<<(unsigned short v){
    formatInteger(v);
    return *this;
}
Logstream& Logstream::operator<<(int v){
    formatInteger(v);
    return *this;
}
Logstream& Logstream::operator<<(unsigned int v){
    formatInteger(v);
    return *this;
}

Logstream& Logstream::operator<<(long v){
    formatInteger(v);
    return *this;
}

Logstream& Logstream::operator<<(unsigned long v){
    formatInteger(v);
    return *this;
}

Logstream& Logstream::operator<<(long long v){
    formatInteger(v);
    return *this;
}

Logstream& Logstream::operator<<(unsigned long long v){
    formatInteger(v);
    return *this;
}

}
