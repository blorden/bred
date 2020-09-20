/*cp1251*/

/* for test sorter.c */

#include "../lenib/lenib.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

//this function return minimal of two int
int min (const int a, const int b);

//compare for msort
int cmp (const char *a, const char *b);

//=============================================================

int main ()
{

    char* arr[] = {"cccc", "bbb"};
    size_t sz = 2;

    msort(arr, arr + 2, sizeof(char*), cmp);

    printf("OK\n");

    for (int i = 0; i < sz; ++i)
    {
        assert(arr + i < arr + sz);
        printf("%s\n", arr[i]);
    }


    return 0;
}

//=============================================================

int min (const int a, const int b)
{
    if (a < b)
        return a;
    return b;
}

//=============================================================

int cmp (const char *a, const char *b)
{
    int lna = strlen(a);
    int lnb = strlen(b);

    for (int i = 0; i < min(lna, lnb); ++i)
    {

        assert(a + i < a + lna);
        assert(b + i < b + lnb);

        if (a[i] < b[i])
            return 0;

        if (a[i] > b[i])
            return 1;

    }

    if (lna == lnb)
        return 2;

    if (lna < lnb)
        return 0;

    return 1;
}

//=============================================================