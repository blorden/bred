/*cp1251*/

#include "../lenib/lenib.h"
#include <stdio.h>
#include <string.h>

int min (int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int cmp (char *a, char *b)
{
	int lna = strlen(a);
	int lnb = strlen(b);

	for (int i = 0; i < min(lna, lnb); ++i)
	{
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

int main ()
{

	char* arr[] = {"cccc", "bbb", "aaaaa", "zzzz", "kkkkk", "MMmmMM"};

	msort(arr, arr + 6, sizeof(char*), cmp);

	for (int i = 0; i < 6; ++i)
		printf("%s\n", arr[i]);

	return 0;
}