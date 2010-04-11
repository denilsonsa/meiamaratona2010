#include <stdio.h>
#include <cstdlib>

#define MAX 100

int v[MAX+1];
int v2[MAX+1];

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
	printf("4\n");
	printf("3 1\n");
	printf("4 23\n");
	printf("10 2\n");
	printf("9 1\n");
	printf("1\n");
	printf("4 6\n");
}

void aleat(int qt)
{
	int i, n, cnt, t, soma, soma2;


	while (qt--)
	{
		n = randab(1, 98);
		cnt = 0;

		for (i=1; i<=MAX; i++)
		{
			v[i] = 0;
		}

		for (i=0; i<n; i++)
		{
			t = randab(3, 100);
			if (v[t] == 0)
			{
				v2[cnt] = t;
				cnt++;
				v[t] = randab(1, 1000);
			}
		}

		soma = 0;
		soma2 = 0;
		for (i=0; i<cnt; i++)
		{
			soma+=v[v2[i]]*v2[i];
			soma2 += v[v2[i]];
		}

		if (soma%2) // garantindo q a soma é divisivel por 2
		{
			t = randab(2,50);
			t = 2*t-1; //escolhe um tamanho impar
			if (v[t]==0) //se não tem nenhum deles
			{
				v2[cnt] = t;
				cnt++;
				v[t] = 1;
			}
			else
			{
				if (v[t] == 1000) // se já tá no máximo
				{
					v[t]--;
				}
				else //senão
				{
					v[t]++;
				}
			}
		}

		if (soma2 < 4)
		{
			qt++;
			continue;
		}

		printf("%d\n", cnt);
		for (i=0; i<cnt; i++)
		{
			printf("%d %d\n", v2[i], v[v2[i]]);
		}
	}
}

void caso1()
{
	int i;
	printf("98\n");
	for (i=3; i=100; i++)
	{
		printf("%d %d\n", i, 1000);
	}
}

int main()
{
	sample();
	aleat(50);
	caso1();
	printf("0\n");
}
