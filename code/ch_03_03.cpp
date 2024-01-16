//  ============================================================
//  chapter 3.3
//  ============================================================

#include "coding.h"

class A {
public:
    const int *pointer;
    A(int v = 1):
        pointer(new int(v))
    {
        cout << "construct" << endl;
        show();
    }
    A(const A& a):
        pointer(new int(*a.pointer))
    {
        cout << "copy: " << &a << endl;
        show();
    }
    A(A&& a):
        pointer(a.pointer) 
    {
        cout << "move: " << &a << endl;
        a.pointer = nullptr;
        show();
    }
    ~A()
    {
        cout << "destruct" << endl;
        show();
        delete pointer;
    }
    void show() const
    {
        cout 
            << "this: " << this << endl 
            << "ptr : " << pointer << endl
        ;
        if (pointer != nullptr)
            cout << "val : " << *pointer << endl;
    }
};

A return_rvalue(bool test)
{
    cout << "return_rvalue" << endl;
    A a(11), b(22);

    if(test) return a; // equal to static_cast<A&&>(a);
    else return b; // equal to static_cast<A&&>(b);
}

void ch_03_03()
{
    chap(3.3);
    A obj = return_rvalue(false);
    cout << "obj" << endl;
    obj.show();
}