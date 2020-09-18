#ifndef BLORDEN_LENIB_SORTER
#define BLORDEN_LENIB_SORTER

#include <stddef.h>

int msort (void const *l,  void const *r, 
            const size_t bsz, 
            int (*cmp)(const void *f, const void *s));

#endif //BLORDEN_LENIB_SORTER