/**/

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXK 20
#define MAXN (1<<20)

char primos[MAXN];

void crivo()
{
	int i, j;

	memset(primos, 1, sizeof(primos));

	primos[0] = primos[1] = 0;

	for (i=2; i*i < MAXN; i++)
	{
		if (!primos[i])
		{
			continue;
		}
		for (j=i*i; j<MAXN; j+=i)
		{
			primos[j] = 0;
		}
	}

}

int primo(int i)
{
	return (int) primos[i];
}

int m, n, k;

int p[MAXK];
int marca[MAXK];

int calc()
{
	int i;
	int prod=1;
	
	for (i=0; i<k; i++)
	{
		if (marca[i])
		{
			if (m/p[i] < prod)
			{
				return 0;
			}
			prod *= p[i];
		}
	}

/*	printf ("com");
	for (i=0; i<k; i++)
	{
		if (marca[i])
		{
			printf(" %d", p[i]);
		}
	}
	printf(", %d\n", m/prod);
*/

	return m/prod;
}

int bt(int p, int q)
{
	int resp;
	if (p==k)
	{
		if (q < n)
		{
			return 0;
		}
		if ((n-q)%2)
		{
			return -calc();
		}
		else
		{
			return calc();
		}

	}

	marca[p] = 0;
	resp = bt(p+1, q);
	marca[p] = 1;
	resp += bt(p+1, q+1);

	return resp;
}

void solve()
{
	printf("%d\n",bt(0, 0));
}

int main()
{
	int i;

	crivo();

	while (1)
	{
		scanf("%d %d %d", &k, &m, &n);
		if (k==0)
		{
			assert(m==0);
			assert(n==0);
			break;
		}

		assert(k>=2 && k<=20);
		assert(m>=1 && m<=100000000);
		assert(n>=1 && n<=k);

		for (i=0; i<k; i++)
		{
			scanf("%d", &p[i]);
			assert(p[i]>=2 && p[i]<=1000000);
			assert(primo(p[i]));
		}
	
		solve();

	}

	return 0;
}
