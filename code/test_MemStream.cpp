#include "coding.h"

#include "MemStream.h"


void test_MemStream()
{
    struct S1
    {
        int m1;
        int m2;
        int m3;
    };

    S1 s1 {111, 222, 333};
    MemStream str(&s1, sizeof(S1));

    int i1 = 0, i2 = 0, i3 = 0;
    str.read((char*) &i1, sizeof(int));
    str.read((char*) &i2, sizeof(int));
    str.read((char*) &i3, sizeof(int));

    cout << i1 << endl;
    cout << i2 << endl;
    cout << i3 << endl;

}