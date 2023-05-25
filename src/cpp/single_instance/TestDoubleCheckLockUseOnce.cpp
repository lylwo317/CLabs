#include <mutex>

class MySingleton {
public:
    static MySingleton * GetInstance() {
        std::call_once(
            m_flag,
            [] () { m_instance = new MySingleton(); }
        );
        
        return m_instance;
    }

private:
    static MySingleton * m_instance;
    static std::once_flag m_flag;
};

int main(int argc, char const *argv[])
{
    MySingleton* single = MySingleton::GetInstance();
    return 0;
}
