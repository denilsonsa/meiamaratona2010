#include <stdio.h>

#define MAX   1000000000
#define PASSO 145925
#define ALEAT 59321

int main()
{
	int i, t;

	printf("4005\n");

	printf("99999998\n");
	printf("3\n");
	printf("53\n");
	printf("2\n");

	printf("1\n");


	for (i=0, t=10; i<1000; i++, t++)
	{
		printf("%d\n", t);
	}

	for (i=0, t=ALEAT; i<1000; i++, t+=PASSO)
	{
		printf("%d\n", t);
	}

	for (i=0, t=MAX; i<1000; i++, t--)
	{
		printf("%d\n", t);
	}

	for (i=0, t=MAX; i<1000; i++, t-=PASSO)
	{
		printf("%d\n", t);
	}

	return 0;
}
