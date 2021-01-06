#ifndef LOGSTREAM_H
#define LOGSTREAM_H
#include <string>
#include <cstring>
#include "noncopyable.h"
#include "Types.h"

namespace kx {

const int kSmallBuffer = 4000;

template<int SIZE>
class FixedBuffer
{
public:
    FixedBuffer():cur_(data_) {}
    //在类的头文件中定义函数带有inline
    void append(const char* buf, size_t len){
        if(implicit_cast<size_t>(avail()) > len){
            std::memcpy(data_, buf, len);
            cur_ += len;
        }
    }
    int avail() const{
        return static_cast<int>(end() - data_);
    }

    const char* data() const {
        return data_;
    }

    int length() const {
        return cur_ - data_;
    }

    char* current(){
        return cur_;
    }

    void add(size_t len){
        cur_ += len;
    }

    void reset(){
        cur_ = data_;
    }

    void bzero(){
        std::memset(data_, 0, sizeof (data_));
    }

    std::string toString() const {
        return std::string(data_, length());
    }
private:
    const char* end() const {
        return data_ + sizeof (data_);
    }
    char data_[SIZE];
    char* cur_;
};

//char *strrev(char *str)
//{
//    char *st,*et;
//    char tmpCh;
//    st=et=str;
//    while(*et!='\0') ++et;
//    --et;
//    for(;st<et;++st,--et)
//    {
//        tmpCh=*st;
//        *st=*et;
//        *et=tmpCh;
//    }
//    return str;
//}

//int itoa(int num, char* str, int len, int base)
//{
//    int sum = num;
//    int i = 0;
//    int digit;
//    if (len == 0)
//        return -1;
//    do
//    {
//        digit = sum % base;
//        if (digit < 0xA)
//            str[i++] = '0' + digit;
//        else
//            str[i++] = 'A' + digit - 0xA;
//        sum /= base;
//    }while (sum && (i < (len - 1)));
//    if (i == (len - 1) && sum)
//        return -1;
//    str[i] = '\0';
//    strrev(str);
//    return 0;
//}

class Logstream : noncopyable
{
public:
    using Buffer = FixedBuffer<kSmallBuffer>;
    using self = Logstream;
    Logstream();
    self& operator<<(bool val){
        buffer_.append(val ? "1" : "0", 1);
        return *this;
    }

    const Buffer& buffer() const {
        return buffer_;
    }

    self &operator<<(short);
    self &operator<<(unsigned short);
    self& operator<<(int);
    self& operator<<(unsigned int);
    self& operator<<(long);
    self& operator<<(unsigned long);
    self& operator<<(long long);
    self& operator<<(unsigned long long);

private:
    Buffer buffer_;

    void formatInteger(long long v);
};

}

#endif // LOGSTREAM_H
