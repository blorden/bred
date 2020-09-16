#ifndef BLORDEN_LENIB_SORTER
#define BLORDEN_LENIB_SORTER

#include <stddef.h>

int msort (void *l, void *r, 
			size_t bsz, 
			int (*cmp)(void *f, void *s));

#endif //BLORDEN_LENIB_SORTER