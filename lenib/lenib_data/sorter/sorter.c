/*cp1251*/

#include "sorter.h"

#include <stdlib.h>
#include <stddef.h> 
#include <stdio.h>
#include <assert.h>

//this function write bsz bytes from->to
void wb (void *to, const void *from,
            const size_t bsz)
{
    for (int i = 0; i < bsz; ++i)
        *((char**)to + i) = *((char**)from + i);
}

//return codes for cmp
enum cmp_code
{
    FIRST_LOWER,
    SECOND_LOWER,
    EQU,
    NOT_CMP
};

//macros, for writing bytes from tmid
#define fmid                          \
                                      \
    wb(ttop, tmid, bsz);              \
    ttop += sizeof(void*);            \
    tmid += sizeof(void*);  

//macros, for writing bytes from tl
#define fl                            \
                                      \
    wb(ttop, tl, bsz);                \
    ttop += sizeof(void*);            \
    tl   += sizeof(void*);              

//=============================================================

int msort (void const *l, void const *r, 
            const size_t bsz, 
            int (*cmp)(const void *f, const void *s))
{

    if (r - l <= sizeof(void*))
        return 0;

    if (l == NULL || r == NULL)
        return 1;

    if (bsz == 0)
        return 1;

    size_t mid = (size_t)((r - l) / sizeof(void*) / 2);

    assert(l + mid * sizeof(void*) <= r);

    if (msort(l, l + mid * sizeof(void*), bsz, cmp) || 
            msort(l + mid * sizeof(void*), r, bsz, cmp))
        return 1;

    //temp-array
    void *temp = (void*) malloc((r - l + 1) * sizeof(void*));

    //temp left pointer, temp "mid pointer" (rigther then tl, but start from mid of array)
    void *tl = l, *tmid = l + mid * sizeof(void*);

    //pointer to top uninitialisation memory of temp array
    void *ttop = temp;

    while (tl != l + mid * sizeof(void*) || tmid != r)
    {

        assert((l + mid * sizeof(void*)) - l >= 0);
        assert((r - tmid) >= 0);

        if (tmid == r)
        {
            fl
            continue;   
        }

        if (tl == l + mid * sizeof(void*))
        {
            fmid
            continue;               
        }

        //returned cmp code
        int rcc = cmp((*(char**)tl), (*(char**)tmid));

        if (rcc == NOT_CMP)
            return 1;

        if (rcc == FIRST_LOWER || rcc == EQU)
        {
            fl
            continue;
        }

        if (rcc == SECOND_LOWER)
        {
            fmid;
            continue;
        }

        if (rcc == NOT_CMP)
            return 1;
    }


    tl = l;
    ttop = temp;


    while (tl != r)
    {
        assert(tl < r);

        wb(tl, ttop, bsz);
        ttop += sizeof(void*);
        tl   += sizeof(void*);
    }


    free(temp); 
    return 0;
}           

//=============================================================

