#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MASK 0x80000000
int meurand()
{
	return ((rand()<<16) + rand()) & (~MASK);
}
int randab(int a, int b)
{
	return meurand()%(b-a+1) + a;
}

	
void sample()
{
	printf("2 10\n");
	printf("5 5\n");
	printf("3 3 5 5 5 5 5 5 5 5\n");
	printf("2 10\n");
	printf("50 5\n");
	printf("3 3 5 5 5 5 5 5 5 5\n");
	// As linhas seguintes nao sao sample, mas pegaram um bug no codigo do
	// Denilson
	printf("2 12\n");
	printf("5 10\n");
	printf("1 1 1 1 2 2 2 2 3 3 3 3\n");
}

#define MAXM 1000000
#define MAXN 1000000
#define MAXR 10000

void grande()
{
	int m, n;
	int i;

	m = MAXM;
	n = MAXN;

	printf("%d %d\n", m, n);

	for (i=0; i<m; i++)
	{
		if (i)
		{
			putchar(' ');
		}
		printf("%d", randab(1, MAXR));
	}
	putchar('\n');
	for (i=0; i<n; i++)
	{
		if (i)
		{
			putchar(' ');
		}
		printf("%d", randab(1, MAXR));
	}
	putchar('\n');

}



void aleat2(int qt)
{
	int m, n;
	int i;

	while (qt--)
	{
		n = randab(MAXN/100, MAXN/10);
		m = randab(n/3, n);

		printf("%d %d\n", m, n);

		for (i=0; i<m; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", randab(1, MAXR));
		}
		putchar('\n');
		for (i=0; i<n; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", randab(1, MAXR));
		}
		putchar('\n');
	}
}

void aleat3(int qt)
{
	int m, n;
	int i;

	while (qt--)
	{

		m = randab(1, MAXM/1000);
		n = randab(1, MAXN/100);

		printf("%d %d\n", m, n);

		for (i=0; i<m; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", randab(1, MAXR));
		}
		putchar('\n');
		for (i=0; i<n; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", randab(1, MAXR));
		}
		putchar('\n');
	}
}

int main()
{
	sample();
	grande();
	aleat2(10);
	aleat3(40);

	printf("%d %d\n", 0, 0);

	return 0;
}
