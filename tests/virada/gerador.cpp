#include <cstdio>
#include <cstdlib>

#define MAX 100000

int randab(int a, int b)
{
	return rand()%(b-a+1) + a;
}

void sample()
{
	printf("7\n");
	printf("1 0 1 1 0 1 1\n");
	printf("1\n");
	printf("1\n");
	printf("2\n");
	printf("0 0\n");
}


void aleatgrande(int qt)
{
	int i;
	while (qt--)
	{
		printf("%d\n", MAX);
		for (i=0; i<MAX; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", rand()%2);
		}
		putchar('\n');
	}
}

void aleat(int qt)
{
	int i, n;
	while (qt--)
	{
		n = randab(1, MAX);

		printf("%d\n", n);
		for (i=0; i<n; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", rand()%2);
		}
		putchar('\n');
	}
}

int main()
{
	sample();
	aleatgrande(3);
	aleat(40);
	
	printf("0\n");
	return 0;
}

