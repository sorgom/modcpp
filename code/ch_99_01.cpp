#include "coding.h"

#include <algorithm>

template <typename ... Ts>
constexpr auto max_sizeof = std::max({sizeof(Ts)...});

struct S1
{
    int data;
};

struct S2
{
    int data[2];
};

struct S3
{
    int data[3];
};

using BYTE = unsigned char;
using Buffer = BYTE[max_sizeof<S1, S2, S3>];

void test()
{
    std::cout << "sizeof(Buffer): " << sizeof(Buffer) << std::endl;
}

// void ch_99_01()
// {
//     chap(99.1);
//     Buffer b;
//     cout 
//         << "max size: " << sm << endl
//         << "S2  size: " << sizeof(S2) << endl
//         << "S3  size: " << sizeof(S3) << endl
//         << "double  : " << sizeof(double) << endl
//         << "Buffer 1: " << sizeof(Buffer) << endl
//         << "Buffer 2: " << sizeof(b) << endl
//     ;
// }
