/**/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAXN 10000000

int v[MAXN+1];

int main()
{
	int t, n;
	int i, j, m;

	memset(v, 0, sizeof(v));

	m = sqrt(MAXN-1+0.0001);

	for (i=1; i<=m; i++)
	{
		for (j=1; j<=i && i*i+j*j<=MAXN; j++)
		{
			v[i*i+j*j]++;
		}
	}

	scanf("%d", &t);

	assert(t>=0 && t <= 1000000);

	for (i=0; i<t; i++)
	{
		scanf("%d", &n);
		assert(n>=1 && n <= 10000000);
		if (v[n] >= 2)
		{
			printf("sim\n");
		}
		else
		{
			printf("nao\n");
		}
	}

	return 0;
}
