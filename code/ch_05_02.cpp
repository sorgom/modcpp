//  ============================================================
//  chapter 5.2
//  ============================================================

#include "coding.h"
#include <memory>

using iptr = std::shared_ptr<int>;

void showcnt(iptr& p)
{
    cout << "use count: " << p.use_count() << endl;
}


void usetmp(iptr& p)
{
    cout << ">> tmp" << endl;
    auto pointer2 = p;
    showcnt(p);
    showcnt(pointer2);

    auto pointer3 = pointer2;
    showcnt(p);

    pointer2.reset();
    showcnt(p);
    showcnt(pointer2);

    pointer3.reset();
    showcnt(p);

    cout << "<< tmp" << endl;
}

struct Foo {
    Foo() { cout << "Foo::Foo" << endl; }
    ~Foo() { cout << "Foo::~Foo" << endl; }
    void foo() { cout << "Foo::foo" << endl; }
};

using fooptr = std::unique_ptr<Foo>;


void show(const char* name, const fooptr& p)
{
    cout << name << ": " << p.get() << endl;
}

#define SHOWP(NAME) show(#NAME, NAME);

void ch_05_02()
{
    chap(5.2);

    cout << "## shared pointer" << endl;

    iptr ip = std::make_shared<int>(10);
    showcnt(ip);

    usetmp(ip);

    showcnt(ip);

    cout << "## unique pointer" << endl;

    fooptr p1(std::make_unique<Foo>());

    if (p1) p1->foo();
    SHOWP(p1)

    fooptr p2(std::move(p1));

    SHOWP(p1)
    SHOWP(p2)

    if(p1) p1->foo();
}    