/*cp1251*/

#include "sorter.h"

#include <stdlib.h>
#include <stddef.h>	
#include <stdio.h>

//this function write bsz bytes from->to
void wb (void *to, void *from,
						size_t bsz)
{
	for (int i = 0; i < bsz; ++i)
		*((char*)to + i) = *((char*)from + i);
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
#define fmid 						  \
									  \
	wb(ttop, tmid, bsz);			  \
	ttop = (void*)((char*)ttop + bsz);\
	tmid = (void*)((char*)tmid + bsz);

//macros, for writing bytes from tl
#define fl 							  \
									  \
	wb(ttop, tl, bsz);				  \
	ttop = (void*)((char*)ttop + bsz);\
	tl	 = (void*)((char*)tl   + bsz);
									

int msort (void *l, void *r, 
			const size_t bsz, 
			int (*cmp)(void *f, void *s))
{

	printf("%d\n", (char*)r - (char*)l + 1);

	if ((char*)r - (char*)l <= 1)
		return 0;

	if (l == NULL || r == NULL)
		return 1;

	if (bsz == 0)
		return 1;

	size_t mid = (size_t)((char*)l + ((char*)r - (char*)l) / 2);

	if (msort(l, (char*)l + mid, bsz, cmp) || msort((char*)l + mid, r, bsz, cmp))
		return 1;

	//temp-array
	void *temp = (void*) malloc(((char*)r - (char*)l + 1) * bsz);

	//temp left pointer, temp "mid pointer" (rigther then tl, but start from mid of array)
	void *tl = l, *tmid = (char*)l + mid;

	//pointer to top uninitialisation memory of temp array
	void *ttop = temp;

	printf("OK\n");

	while (tl != (char*)l + mid || tmid != r)
	{
		if (tmid == r)
		{
			fl
			continue;	
		}

		if (tl == (char*)l + mid)
		{
			fmid
			continue;				
		}

		//returned cmp code
		int rcc = cmp(tl, tmid);

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

	free(temp);	
	return 0;
}			