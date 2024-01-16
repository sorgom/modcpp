//  ============================================================
//  simple coding
//  ============================================================

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;


void showcont(const auto& v)
{
    for (const auto& it : v)
    {
        cout << it << endl;
    }
}

void chap(const auto& nr)
{
    cout << endl << "### chapter " << nr << endl;
}