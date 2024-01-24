//  ============================================================
//  chapter 2.3
//  ============================================================

#include "coding.h"
#include <type_traits>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>


template <typename T1, typename T2>
auto add(const T1 x, const T2 y)
{
    return x + y;
}

void test_auto()
{
    cout << "test auto" << endl;
    cout << "template" << endl;
    const auto r1 = add(1, 2.0);
    cout << "r1: " << r1 << endl;
    cout << std::is_same<decltype(r1), const double>::value << endl;
}

void ch_02_03()
{
    chap(2.3);
    test_auto();
}