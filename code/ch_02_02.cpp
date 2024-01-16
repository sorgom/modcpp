//  ============================================================
//  chapter 2.2
//  ============================================================

#include "coding.h"
#include <type_traits>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>

void checkvec()
{
    cout << "new if style" << endl;
    std::vector<int> vec = {1, 2, 3, 4};
    if (auto it = std::find(vec.begin(), vec.end(), 3); it != vec.end()) 
    {
        *it = 4;
    }
    showcont(vec);
}

void ini_list()
{
    cout << "initializer_list" << endl;
    class MagicFoo 
    {
    public:
        const std::vector<int> vec;
        MagicFoo(std::initializer_list<int> list):
            vec(list)
        {}
    };
    MagicFoo mf {1, 2, 3, 4, 5};
    showcont(mf.vec);
}

std::tuple<int, double, std::string> tpf() 
{
    return std::make_tuple(1, 2.3, "456");
}

void mk_tpl()
{
    cout << "tuple" << endl;
    auto [x, y, z] = tpf();
    cout << x << ", " << y << ", " << z << endl;
}

void ch_02_02()
{
    chap(2.2);
    checkvec();
    ini_list();
    mk_tpl();
}