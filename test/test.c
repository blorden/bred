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

const int SIZE = 2;

int main ()
{

    char* arr[] = {"cccc", "bbb"};

    msort(arr, arr + SIZE, sizeof(char*), cmp);

    printf("OK\n");

    for (int i = 0; i < SIZE; ++i)
    {
        assert(0 <= i && i < SIZE);

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

        assert(i < lna);
        assert(i < lnb);

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