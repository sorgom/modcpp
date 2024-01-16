//  ============================================================
//  chapter 4.2
//  ============================================================

#include "coding.h"

#include <unordered_map>

template <class T>
void show(const T& m)
{
    for( const auto & n : m)
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]" << endl;
}

void ch_04_02()
{
    chap(4.2);

    std::unordered_map<int, std::string> u = {
        {1, "- 1 -"},
        {3, "- 3 -"},
        {2, "- 2 -"}
    };

    show(u);

    auto fnd = u.find(2);
    if (fnd != u.end())
        cout << "found: " << fnd->first << ", " << std::quoted(fnd->second) << endl;

}    