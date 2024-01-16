//  ============================================================
//  chapter 2.6
//  ============================================================

#include "coding.h"

#include <functional>
#include <map>

class Base
{
public:
    const int value1;
    const int value2;
    Base(const int value = 2): 
        value1(1),
        value2(value)
    {}

    virtual void show() const {}
};

class Subclass : public Base 
{
public:
    using Base::Base; // inheritance constructor

    virtual void show() const override
    {
        cout << value1 << ", " << value2 << endl;
    }
};


enum class wumpel : unsigned char 
{
    w0,
    w1,
    w2
};

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value>& m, F foo) 
{
    for (auto& it : m)
    {
        it.second = foo(it.first);
    }
}


void ch_02_06()
{
    chap(2.6);
    Subclass s1;
    s1.show();
    Subclass s2(444);
    s2.show();

    cout << "hash" << endl;

    std::string str = "Meet the new boss...";
    std::size_t str_hash = std::hash<std::string>{}(str);
    cout << "hash(" << std::quoted(str) << ") =\t" << str_hash << endl;

    cout << "hash lamda" << endl;
    std::map<std::string, std::size_t> m {
        {"a", 1},
        {"b", 2},
        {"c", 3}
    };
    
    update(m, [](std::string key) {
        return std::hash<std::string>{}(key);
    });

    for (auto&& [key, value] : m)
        cout << key << ": " << value << endl;
}