#include <algorithm>
#include <new>
#include "coding.h"

struct S
{
    int32_t m1;
    int32_t m2;
};

using BYTE = unsigned char;
using SBuffer = BYTE[sizeof(S)];

void show(const S* ptr)
{
    cout << ptr->m1 << ", " << ptr->m2 << endl;
}

void test_swap()
{
    SBuffer b1, b2;
    S* s1 = new (b1) S { 1, 2};
    S* s2 = new (b2) S { 2, 3};

    show(s1);
    show(s2);

    std::swap(b1, b2);
    show(s1);
    show(s2);

}