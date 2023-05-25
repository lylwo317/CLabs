#include <atomic>
#include <mutex>

// Singleton.h
class Singleton {
public:
    static Singleton* GetInstance();

private:
    Singleton() = default;

};

static std::atomic<Singleton*> s_instance;
static std::mutex s_mutex;

Singleton* Singleton::GetInstance() {
    Singleton* tmp = s_instance;
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(s_mutex);
        tmp = s_instance.load();
        if (tmp == nullptr) {
            tmp = new Singleton();
            s_instance.store(tmp);
        }
    }
    return tmp;
}


int main(int argc, char const *argv[])
{
    Singleton* singleton = Singleton::GetInstance();
    return 0;
}
