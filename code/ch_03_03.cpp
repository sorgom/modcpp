//  ============================================================
//  chapter 3.3
//  ============================================================

#include "coding.h"

#include <vector>
#include <utility>

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
        cout << endl;
    }
};

A return_rvalue(bool test)
{
    cout << "return_rvalue" << endl;
    A a(11), b(22);

    if(test) return a; // equal to static_cast<A&&>(a);
    else return b; // equal to static_cast<A&&>(b);
}

void reference(int& v) {
    cout << "lvalue reference" << endl;
}
void reference(int&& v)
{
    cout << "rvalue reference" << endl;
}

template <typename T>
void pass(T&& v) 
{
    cout << "          normal param passing: ";
    reference(v);
    cout << "       std::move param passing: ";
    reference(std::move(v));
    cout << "    std::forward param passing: ";
    reference(std::forward<T>(v));
    cout << "static_cast<T&&> param passing: ";
    reference(static_cast<T&&>(v));
}


void ch_03_03()
{
    chap(3.3);
    A obj = return_rvalue(false);
    cout << "obj" << endl;
    obj.show();

    std::vector<A> v;

    cout << "pushback" << endl;
    v.push_back(obj);

    cout << "pushback move" << endl;
    v.push_back(std::move(obj));


    std::cout << "rvalue pass:" << std::endl;
    pass(1);

    std::cout << "lvalue pass:" << std::endl;
    int l = 1;
    pass(l);
}