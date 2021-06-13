/// remove_reference
template<typename _Tp>
struct remove_reference
{ typedef _Tp   type; };

template<typename _Tp>
struct remove_reference<_Tp&> //匹配左值类型，然后删除左值引用
{ typedef _Tp   type; };

template<typename _Tp>
struct remove_reference<_Tp&&> //匹配右值类型，然后删除右值引用
{ typedef _Tp   type; };

/**
   *  @brief  Convert a value to an rvalue.
   *  @param  __t  A thing of arbitrary type.
   *  @return The parameter cast to an rvalue-reference to allow moving it.
  */
template<typename _Tp>
constexpr typename remove_reference<_Tp>::type&&
move(_Tp&& __t) noexcept //通过引用折叠来实现匹配所有类型 T, T&, const T&, T&&
{ return static_cast<typename remove_reference<_Tp>::type&&>(__t); }

class Person{
    int age = 0;
};

int main(int argc, const char* argv[]){
    Person p;
    Person& plr = p;
    const Person& pclr = Person();
    move(p);
    move(plr);
    move(pclr);
    move(Person());
}