//  ============================================================
//  chapter 2.3
//  ============================================================

#include "coding.h"
#include <type_traits>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>


template<typename T, typename U>
auto add3(T x, U y)
{
    return x + y;
}

auto add4(const auto x, const auto y)
{
    return x + y;
}

void test_auto()
{
    cout << "test auto" << endl;
    cout << "template" << endl;
    const auto r1 = add3(1, 2.0);
    cout << "r1: " << r1 << endl;
    cout << std::is_same<decltype(r1), const double>::value << endl;

    cout << "all auto" << endl;
    const auto r2 = add4(1.0, 2);
    cout << "r2: " << r2 << endl;
    cout << std::is_same<decltype(r2), const double>::value << endl;
}

void ch_02_03()
{
    chap(2.3);
    test_auto();
}