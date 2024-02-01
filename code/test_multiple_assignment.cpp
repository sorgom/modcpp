#include "coding.h"

#include <cstring>

void test_multiple_assignment()
{
    int arr[4] = { 1, 2, 3, 4 };

    union
    {
        char buf[4 * sizeof(int)];
        int vals[4];
    } data;
    
    memcpy(data.buf, arr, sizeof(data.buf));

    const auto [ i1, i2, i3, i4 ] = data.vals;
    cout 
        << i1 << ", "
        << i2 << ", "
        << i3 << ", "
        << i4 << endl;

}