#ifndef NOCOPYABLE_H
#define NOCOPYABLE_H

namespace kx {

class noncopyable
{
public:
    noncopyable(const noncopyable&) = delete;
    void operator =(const noncopyable&) = delete;
protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

}


#endif // NOCOPYABLE_H
