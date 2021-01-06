#include "logging.h"

namespace kx{

void defaultOutput(const char* msg, int len){
    size_t s = fwrite(msg,1,len,stdout);
}

void defaultFlush(){
    fflush(stdout);
}

Logging::OutPutFunc g_output = defaultOutput;
Logging::FlushFunc g_flush = defaultFlush;

Logging::Logging()
{

}

Logging::~Logging(){
    const Logstream::Buffer& buffer = stream_.buffer();
    g_output(buffer.data(),buffer.length());
}

}
