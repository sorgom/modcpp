//  ============================================================
//  simple coding
//  ============================================================

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

template <typename T>
void showcont(const T& v)
{
    for (const auto& it : v)
    {
        cout << it << endl;
    }
}

template <typename T>
void chap(const T nr)
{
    cout << endl << "### chapter " << nr << endl;
}