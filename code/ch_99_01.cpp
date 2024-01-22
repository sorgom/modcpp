#include "coding.h"

#include <algorithm>

// template <typename T1, typename ... TS>
// struct MaxSize
// {
//     constexpr static size_t value()
//     {
//         if constexpr (sizeof...(TS) > 0)
//             return std::max(sizeof(T1), MaxSize<TS ...>::value());
//         else
//             return sizeof(T1);
//     } 
// };

template <typename ... Ts>
constexpr size_t max_sizeof = std::max({sizeof(Ts)...});

struct S1
{
    int i1;
};

#include "packBegin.h"

struct S2
{
    int i1;
    int i2;
    int i3;
    double d;
};

#include "packEnd.h"

struct alignas(4) S3
{
    char c;
    int i;
};

constexpr size_t sm = max_sizeof<S1, S2, S3, int>;

using Buffer = unsigned char[max_sizeof<S1, S3, int, bool, double, S2, S3>];

void ch_99_01()
{
    chap(99.1);
    Buffer b;
    cout 
        << "max size: " << sm << endl
        << "S2  size: " << sizeof(S2) << endl
        << "S3  size: " << sizeof(S3) << endl
        << "double  : " << sizeof(double) << endl
        << "Buffer 1: " << sizeof(Buffer) << endl
        << "Buffer 2: " << sizeof(b) << endl
    ;
}