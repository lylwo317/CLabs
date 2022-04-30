//
// Created by kevin on 2022/4/24.
//

#include <cstdio>

//多继承 无覆盖
struct BaseA {
    BaseA() = default;
    // BaseA(){
    //     _vtp = (Vtable for 'BaseA' + 16);
    // }

    virtual ~BaseA() = default;

    void Func() {}

    virtual void FuncB() { printf("BaseA FuncB\n"); }

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

    virtual void FuncC() { printf("BaseB FuncC\n"); }

    int a;
    int b;
};

struct Driver : public BaseA, public BaseB {
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
Vtable for 'BaseA' (5 entries).
   0 | offset_to_top (0)
   1 | BaseA RTTI
       -- (BaseA, 0) vtable address --
   2 | BaseA::~BaseA() [complete]
   3 | BaseA::~BaseA() [deleting]
   4 | void BaseA::FuncB()

VTable indices for 'BaseA' (3 entries).
   0 | BaseA::~BaseA() [complete]
   1 | BaseA::~BaseA() [deleting]
   2 | void BaseA::FuncB()

Vtable for 'Derive' (10 entries).
   0 | offset_to_top (0)
   1 | Derive RTTI
       -- (BaseA, 0) vtable address --
       -- (Derive, 0) vtable address --
   2 | Derive::~Derive() [complete]
   3 | Derive::~Derive() [deleting]
   4 | void BaseA::FuncB()
   5 | offset_to_top (-16) //到Derive顶部的距离
   6 | Derive RTTI
       -- (BaseB, 16) vtable address --
   7 | Derive::~Derive() [complete]
       [this adjustment: -16 non-virtual]
   8 | Derive::~Derive() [deleting]
       [this adjustment: -16 non-virtual]
   9 | void BaseB::FuncC()

Thunks for 'Derive::~Derive()' (1 entry).
   0 | this adjustment: -16 non-virtual

VTable indices for 'Derive' (2 entries).
   0 | Derive::~Derive() [complete]
   1 | Derive::~Derive() [deleting]

Vtable for 'BaseB' (5 entries).
   0 | offset_to_top (0)
   1 | BaseB RTTI
       -- (BaseB, 0) vtable address --
   2 | BaseB::~BaseB() [complete]
   3 | BaseB::~BaseB() [deleting]
   4 | void BaseB::FuncC()

VTable indices for 'BaseB' (3 entries).
   0 | BaseB::~BaseB() [complete]
   1 | BaseB::~BaseB() [deleting]
   2 | void BaseB::FuncC()
 */

int main() {
    BaseA a;
    Driver d;
    return 0;
}
