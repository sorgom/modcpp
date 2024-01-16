//  ============================================================
//  chapter 6.2
//  ============================================================

#include "coding.h"
#include <regex>

void show(const std::smatch& mo)
{
    cout << "match:";
    for (auto ms : mo) cout << ' ' << ms;
    cout << endl;
}

void ch_06_02()
{
    chap(6.2);

    std::string fnames[] = {"foo.txt", "bar.txt", "test.txt2", "a0.txt", "AAA.txt"};

    std::regex rx("^([a-z]+)\\.txt$");
    std::smatch mo;

    for(const auto& fname: fnames)
    {
        if (std::regex_match(fname, mo, rx))
        {
            show(mo);
        }
    }

}    