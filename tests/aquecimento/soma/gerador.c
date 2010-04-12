#include <stdio.h>

#define MAX 1000

int main()
{
	int i, j;

	for(i=1; i<= MAX; i++)
	{
		for (j=1; j<=MAX; j++)
		{
			printf("%d %d\n", i, j);
		}
	}
	printf("0 0\n");

}
