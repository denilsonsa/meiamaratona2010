#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXK 20
#define MAXM 100000000
#define MAXP 1000000

int p[MAXP], qp;
char mp[MAXP];

#define MASK 0x80000000
int meurand()
{
	return ((rand()<<16) + rand()) & (~MASK);
}

void crivo()
{
	int i, j;

	memset(mp, 1, sizeof(mp));

	mp[0] = mp[1] = 0;

	for (i=2; i*i<MAXP; i++)
	{
		for (j=i*i; j<MAXP; j+=i)
		{
			mp[j] = 0;
		}
	}

	qp = 0;
	for (i=2; i<MAXP; i++)
	{
		if (mp[i])
		{
			p[qp] = i;
			qp++;
		}
	}
}

void sample()
{
	printf("5 10 2");
	printf("2 3 5 7 13");
	printf("5 30 2");
	printf("2 3 5 7 13");
}

void grande()
{
	printf("5 10 2");
	printf("2 3 5 7 13");
	printf("5 30 2");
	printf("2 3 5 7 13");
	printf("3 30 1");
	printf("2 3 5");
	printf("5 120 2");
	printf("2 3 5 7 13");
	printf("10 100000000 2");
	printf("2 3 5 7 11 13 17 19 23 29");
	printf("20 100000000 2");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 3");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 4");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 5");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 6");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 7");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 8");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 9");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 10");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 11");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 12");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 13");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 14");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 15");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 16");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 17");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 18");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 19");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
	printf("20 100000000 20");
	printf("2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71");
}

int randab(int a, int b)
{
	return meurand()%(b-a+1) + a;
}


void aleat(int qt)
{
	int k, m, n;
	int i, t, temp;


	while (qt--)
	{
		k = randab(2, MAXK);
		m = randab(1, MAXM);
		n = randab(1, k);
		
		for (i=0; i<k; i++)
		{
			t = meurand()%(qp-i);
			temp = p[qp-i-1];
			p[qp-i-1] = p[t];
			p[t] = temp;
		}

		printf("%d %d %d\n", k, m, n);
		for (i=0; i<k; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", p[qp-i-1]);
		}
		putchar('\n');
	}
}

int main()
{
	crivo();

	sample();
	grande();
	aleat(50);
	printf("0 0 0\n");

	return 0;
}
