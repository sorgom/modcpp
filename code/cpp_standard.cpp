//  ============================================================
//  compiler macros C++ standard
//  ============================================================


    // C++ pre-C++98: __cplusplus is 1.
    // C++98: __cplusplus is 199711L.
    // C++98 + TR1: This reads as C++98 and there is no way to check that I know of.
    // C++11: __cplusplus is 201103L.
    // C++14: __cplusplus is 201402L.
    // C++17: __cplusplus is 201703L.
    // C++20: __cplusplus is 202002L.




#include "coding.h"

void cpp_standard()
{
constexpr auto standard = 
#if   __cplusplus == 199711L
    "98"
#elif __cplusplus == 201103L
    "11"
#elif __cplusplus == 201402L
    "14"
#elif __cplusplus == 201703L
    "17"
#elif __cplusplus == 202002L
    "20"
#else
    "unknown"
#endif
    ;

    cout << "cpp standard: " << standard << " (" << (__cplusplus / 100) % 100 << ')' << endl;
}