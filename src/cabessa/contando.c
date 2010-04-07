/**/

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXK 20
#define MAXN (1<<20)

char primos[MAXN];
int comb[MAXK+1][MAXK+1];

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

void combinacao()
{
	int i, j;

	for (i=0; i<=MAXK; i++)
	{
		comb[i][0] = 1;
		comb[i][i] = 1;
	}

	for (i=2; i<=MAXK; i++)
	{
		for (j=1; j<i; j++)
		{
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
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

long long calc()
{
	int i;
	long long prod=1;
	
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

	return m/prod;
}

long long bt(int p, int q)
{
	long long resp;
	if (p==k)
	{
		if (q < n)
		{
			return 0;
		}
		if ((n-q)%2)
		{
			return -comb[q][n]*calc();
		}
		else
		{
			return comb[q][n]*calc();
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
	printf("%d\n",(int)bt(0, 0));
}

int main()
{
	int i;

	crivo();
	combinacao();

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
