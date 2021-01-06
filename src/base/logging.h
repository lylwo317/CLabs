#ifndef LOGGING_H
#define LOGGING_H

#include "logstream.h"
#include <type_traits>

namespace kx {
class Logging
{
public:
    enum LogLevel{
        TRACE,
        DEBUG,
        INFO,
        WARN
    };
    Logging();
    ~Logging();
    Logstream& stream(){
        return stream_;
    }

//    using OutPutFunc = void (*)(const char* msg, int len);
    using OutPutFunc = std::add_pointer<void (const char* msg, int len)>::type;
    using FlushFunc = std::add_pointer<void ()>::type;

private:
    Logstream stream_;
};
}

#endif // LOGGING_H
