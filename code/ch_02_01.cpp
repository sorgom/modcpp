//  ============================================================
//  chapter 2.1
//  ============================================================

#include "coding.h"
#include <type_traits>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>

void foo(const char*) {
    cout << "foo(char*) is called" << endl;
}
void foo(const int i) {
    cout << "foo(int) is called" << endl;
}

constexpr int fibonacci1(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci1(n-1) + fibonacci1(n-2);
}

constexpr int fibonacci2(const int n) {
    if(n == 1) return 1;
    if(n == 2) return 1;
    return fibonacci2(n-1) + fibonacci2(n-2);
}

void ch_02_01()
{
    chap(2.1);
    if (std::is_same<decltype(NULL), decltype(0)>::value)
    cout << "NULL == 0" << endl;
    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
    cout << "NULL == (void *)0" << endl;
    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
    cout << "NULL == nullptr" << endl;
    foo(0); // will call foo(int)
    // foo(NULL); // doesn't compile
    foo(nullptr); // will call foo(char*)

    cout << "fibonacci1(10): " << fibonacci1(10) << endl;
    cout << "fibonacci2(10): " << fibonacci2(10) << endl;

}