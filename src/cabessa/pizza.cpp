/**/

/* Igualdade:
r raio da pizza
R raio do prato

r <= 2*R*cos(pi/8)
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>

int cmp(const void *e1, const void *e2)
{
	double a1,a2;

	a1 = *((double*)e1);
	a2 = *((double*)e2);

	if (a1 < a2)
	{
		return -1;
	}
	if (a1 > a2)
	{
		return 1;
	}
	return 0;
}

#define MAXN (1<<20)

double pizza[MAXN];
double prato[MAXN];
double pi;

int cabe(int a, int b)
{
	if (pizza[a] <= 2*prato[b]*cos(pi/8))
	{
		return 1;
	}
	return 0;
}


int main()
{
	int m, n;
	int i, j, k;
	int resp;

	pi = acos(-1);

	while (1)
	{
		scanf("%d %d", &m, &n);
		if (m == 0)
		{
			assert (n==0);
			break;
		}

		for (i=0; i<m; i++)
		{
			scanf("%lf", &pizza[i]);
		}
		for (i=0; i<n; i++)
		{
			scanf("%lf", &prato[i]);
		}

		qsort(pizza, m, sizeof(pizza[0]), cmp);
		qsort(prato, m, sizeof(prato[0]), cmp);

		i = 0;
		j = 0;
		k = 0;
		resp = 0;

		while (i <= m && j <= n)
		{
			if (k == 8)
			{
				k = 0;
				i++;
				continue;
			}

			if (cabe(i, j))
			{
				j++;
				k++;
				resp++;
			}
			else
			{
				j++;
			}

		}
		printf("%d\n", resp);
	}


	return 0;
}
