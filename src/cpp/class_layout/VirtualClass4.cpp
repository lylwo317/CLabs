//
// Created by kevin on 2022/4/24.
//

#include <cstdio>

//多继承 有覆盖 虚继承
struct BaseA {
    BaseA() = default;
    // BaseA(){
    //     _vtp = (Vtable for 'BaseA' + 16);
    // }

    virtual ~BaseA() = default;

    void Func() {}

    virtual void FuncA() { printf("BaseA FuncA\n"); }

    int a;
    int b;
};

struct BaseB {
    BaseB() = default;
    // BaseB(){
    //     _vtp = (Vtable for 'BaseB' + 16);
    // }

    virtual ~BaseB() = default;

    void Func() {}

    virtual void FuncB() { printf("BaseB FuncB\n"); }

    int a;
    int b;
};

struct Driver : public virtual BaseA{
    void FuncA() override{
        printf("Driver FuncA\n");
    }

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
*** Dumping AST Record Layout
         0 | struct BaseA
         0 |   (BaseA vtable pointer)
         8 |   int a
        12 |   int b
           | [sizeof=16, dsize=16, align=8,
           |  nvsize=16, nvalign=8]

*** Dumping AST Record Layout
         0 | struct BaseB
         0 |   (BaseB vtable pointer)
         8 |   int a
        12 |   int b
           | [sizeof=16, dsize=16, align=8,
           |  nvsize=16, nvalign=8]

*** Dumping AST Record Layout
         0 | struct Derive
         0 |   struct BaseA (primary base)
         0 |     (BaseA vtable pointer)
         8 |     int a
        12 |     int b
        16 |   struct BaseB (base)
        16 |     (BaseB vtable pointer)// offset_to_top (-16)
        24 |     int a
        28 |     int b
           | [sizeof=32, dsize=32, align=8,
           |  nvsize=32, nvalign=8]
 */

/*
Vtable for 'BaseB' (5 entries).
   0 | offset_to_top (0)
   1 | BaseB RTTI
       -- (BaseB, 0) vtable address --
   2 | BaseB::~BaseB() [complete]
   3 | BaseB::~BaseB() [deleting]
   4 | void BaseB::FuncB()

VTable indices for 'BaseB' (3 entries).
   0 | BaseB::~BaseB() [complete]
   1 | BaseB::~BaseB() [deleting]
   2 | void BaseB::FuncB()

Vtable for 'Driver' (11 entries).
   0 | offset_to_top (0)
   1 | Driver RTTI
       -- (BaseA, 0) vtable address --
       -- (Driver, 0) vtable address --
   2 | Driver::~Driver() [complete]
   3 | Driver::~Driver() [deleting]
   //BaseA* a1 = new Driver(); a1->FuncA();
   //Driver* a2 = new Driver(); a2->FuncA();
   4 | void Driver::FuncA()
   //Driver* a = new Driver(); a->FuncB();
   5 | void Driver::FuncB()
   6 | offset_to_top (-16)
   7 | Driver RTTI
       -- (BaseB, 16) vtable address --
   8 | Driver::~Driver() [complete]
       [this adjustment: -16 non-virtual]
   9 | Driver::~Driver() [deleting]
       [this adjustment: -16 non-virtual]
   //BaseB* a = new Driver(); a->FuncB();
  10 | void Driver::FuncB()
       [this adjustment: -16 non-virtual]

Thunks for 'Driver::~Driver()' (1 entry).
   0 | this adjustment: -16 non-virtual

Thunks for 'void Driver::FuncB()' (1 entry).
   0 | this adjustment: -16 non-virtual

VTable indices for 'Driver' (4 entries).
   0 | Driver::~Driver() [complete]
   1 | Driver::~Driver() [deleting]
   2 | void Driver::FuncA()
   3 | void Driver::FuncB()

Vtable for 'BaseA' (5 entries).
   0 | offset_to_top (0)
   1 | BaseA RTTI
       -- (BaseA, 0) vtable address --
   2 | BaseA::~BaseA() [complete]
   3 | BaseA::~BaseA() [deleting]
   4 | void BaseA::FuncA()

VTable indices for 'BaseA' (3 entries).
   0 | BaseA::~BaseA() [complete]
   1 | BaseA::~BaseA() [deleting]
   2 | void BaseA::FuncA()
 */

int main() {
    // BaseA a;
    BaseA* d = new Driver();
    d->FuncA();
    delete d;
    return 0;
}
