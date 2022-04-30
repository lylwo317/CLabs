//
// Created by kevin on 2022/4/24.
//

#include <cstdio>
/*
*** Dumping AST Record Layout
         0 | struct Driver
         0 |   struct BaseA (primary base)
         0 |     struct Base (primary base)
         0 |       (Base vtable pointer)
         8 |       int a
        12 |       int b
        16 |     int a
        20 |     int b
        24 |   struct BaseB (base)
        24 |     struct Base (primary base)
        24 |       (Base vtable pointer)
        32 |       int a
        36 |       int b
        40 |     int a
        44 |     int b
           | [sizeof=48, dsize=48, align=8,
           |  nvsize=48, nvalign=8]

*** Dumping AST Record Layout
         0 | struct Driver
         0 |   struct BaseA (primary base)
         0 |     (BaseA vtable pointer)
         8 |     int a
        12 |     int b
        16 |   struct BaseB (base)
        16 |     (BaseB vtable pointer)
        24 |     int a
        28 |     int b
        32 |   struct Base (virtual base)
        32 |     (Base vtable pointer)
        40 |     int a
        44 |     int b
           | [sizeof=48, dsize=48, align=8,
           |  nvsize=32, nvalign=8]

 */



//多继承 有覆盖 虚继承
struct Base {
    Base() = default;

    virtual void FuncA() { printf("BaseA FuncA\n"); }

    int a;
    int b;
};

struct BaseA : public virtual Base{
    BaseA() = default;

    virtual ~BaseA() = default;

    virtual void FuncA() { printf("BaseB FuncB\n"); }

    int a;
    int b;
};

struct BaseB : public virtual Base{
    BaseB() = default;

    virtual ~BaseB() = default;

    virtual void FuncB() { printf("BaseB FuncB\n"); }

    int a;
    int b;
};

struct Driver : public BaseA, public BaseB{

//    void FuncB() override{
//        printf("Driver FuncB\n");
//    }

    virtual void FuncInDriver(){

    }
    // Derive(): BaseA(), BaseB(){
    //     BaseA::_vtp = (Vtable for 'Derive' + 16);
    //     BaseB::_vtp = (Vtable for 'Derive' + 56);
    // }
};

/*
Vtable for 'BaseA' (10 entries).
   0 | vbase_offset (16)
   1 | offset_to_top (0)
   2 | BaseA RTTI
       -- (BaseA, 0) vtable address --
   3 | BaseA::~BaseA() [complete]
   4 | BaseA::~BaseA() [deleting]
   5 | void BaseA::FuncA()
   6 | vcall_offset (-16)
   7 | offset_to_top (-16)
   8 | BaseA RTTI
       -- (Base, 16) vtable address --
   9 | void BaseA::FuncA()
       [this adjustment: 0 non-virtual, -24 vcall offset offset]

Virtual base offset offsets for 'BaseA' (1 entry).
   Base | -24

Thunks for 'void BaseA::FuncA()' (1 entry).
   0 | this adjustment: 0 non-virtual, -24 vcall offset offset

VTable indices for 'BaseA' (3 entries).
   0 | BaseA::~BaseA() [complete]
   1 | BaseA::~BaseA() [deleting]
   2 | void BaseA::FuncA()

Vtable for 'Driver' (17 entries).
   0 | vbase_offset (32)
   1 | offset_to_top (0)
   2 | Driver RTTI
       -- (BaseA, 0) vtable address --
       -- (Driver, 0) vtable address --
   3 | Driver::~Driver() [complete]
   4 | Driver::~Driver() [deleting]
   5 | void BaseA::FuncA()
   6 | void Driver::FuncInDriver()
   7 | vbase_offset (16)
   8 | offset_to_top (-16)
   9 | Driver RTTI
       -- (BaseB, 16) vtable address --
  10 | Driver::~Driver() [complete]
       [this adjustment: -16 non-virtual]
  11 | Driver::~Driver() [deleting]
       [this adjustment: -16 non-virtual]
  12 | void BaseB::FuncB()
  13 | vcall_offset (-32)
  14 | offset_to_top (-32)
  15 | Driver RTTI
       -- (Base, 32) vtable address --
  16 | void BaseA::FuncA() //Base vptr
        //这里只是调整this指针的位置为this -= 32;
       [this adjustment: 0 non-virtual, -24 vcall offset offset]//表示根据[Base vptr - 24 == (13 | vcall_offset (-32))]中的值调整this指针位置，然后调用BaseA::FuncA()

Virtual base offset offsets for 'Driver' (1 entry).
   Base | -24

Thunks for 'Driver::~Driver()' (1 entry).
   0 | this adjustment: -16 non-virtual

VTable indices for 'Driver' (3 entries).
   0 | Driver::~Driver() [complete]
   1 | Driver::~Driver() [deleting]
   3 | void Driver::FuncInDriver()

Construction vtable for ('BaseA', 0) in 'Driver' (10 entries).
   0 | vbase_offset (32)
   1 | offset_to_top (0)
   2 | BaseA RTTI
       -- (BaseA, 0) vtable address --
   3 | BaseA::~BaseA() [complete]
   4 | BaseA::~BaseA() [deleting]
   5 | void BaseA::FuncA()
   6 | vcall_offset (-32)
   7 | offset_to_top (-32)
   8 | BaseA RTTI
       -- (Base, 32) vtable address --
   9 | void BaseA::FuncA()
       [this adjustment: 0 non-virtual, -24 vcall offset offset]

Construction vtable for ('BaseB', 16) in 'Driver' (10 entries).
   0 | vbase_offset (16)
   1 | offset_to_top (0)
   2 | BaseB RTTI
       -- (BaseB, 16) vtable address --
   3 | BaseB::~BaseB() [complete]
   4 | BaseB::~BaseB() [deleting]
   5 | void BaseB::FuncB()
   6 | vcall_offset (0)
   7 | offset_to_top (-16)
   8 | BaseB RTTI
       -- (Base, 32) vtable address --
   9 | void Base::FuncA()

Vtable for 'Base' (3 entries).
   0 | offset_to_top (0)
   1 | Base RTTI
       -- (Base, 0) vtable address --
   2 | void Base::FuncA()

VTable indices for 'Base' (1 entries).
   0 | void Base::FuncA()

Vtable for 'BaseB' (10 entries).
   0 | vbase_offset (16)
   1 | offset_to_top (0)
   2 | BaseB RTTI
       -- (BaseB, 0) vtable address --
   3 | BaseB::~BaseB() [complete]
   4 | BaseB::~BaseB() [deleting]
   5 | void BaseB::FuncB()
   6 | vcall_offset (0)
   7 | offset_to_top (-16)
   8 | BaseB RTTI
       -- (Base, 16) vtable address --
   9 | void Base::FuncA()

Virtual base offset offsets for 'BaseB' (1 entry).
   Base | -24

VTable indices for 'BaseB' (3 entries).
   0 | BaseB::~BaseB() [complete]
   1 | BaseB::~BaseB() [deleting]
   2 | void BaseB::FuncB()
 */

int main() {
    // BaseA a;
    BaseA* d = new Driver();
    d->FuncA();
    delete d;
    return 0;
}
