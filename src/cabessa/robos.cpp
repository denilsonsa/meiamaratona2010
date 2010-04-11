#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX 1024

char mapa[MAX][MAX];
char mrc[MAX][MAX];

int m, n;


int vai(int a, int b)
{
	int resp = 0;

	if (mrc[a][b])
	{
		return 0;
	}

	if (mapa[a][b] == '#')
	{
		return 0;
	}

	mrc[a][b] = 1;


	resp += vai(a, b+1);
	resp += vai(a, b-1);
	resp += vai(a+1, b);
	resp += vai(a-1, b);

	if (mapa[a][b] == '$')
	{
		resp++;
	}


	return resp;

}

int main()
{
	int i, j, a, b, tes;

	while (1)
	{
		scanf("%d %d", &m, &n);

		if (!m)
		{
			assert(!n);
			break;
		}

		assert(m>=3 && m<=1000);
		assert(n>=3 && n<=1000);

		for (i=0; i<m; i++)
		{
			scanf("%s", mapa[i]);
			assert((int)strlen(mapa[i]) == n);
		}

		for (i=0; i<m; i++)
		{
			assert(mapa[i][0]=='#');
			assert(mapa[i][n-1]=='#');
		}

		for (i=0; i<n; i++)
		{
			assert(mapa[0][i]=='#');
			assert(mapa[m-1][i]=='#');
		}

		tes = 0;

		a = -1;

		for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				if (mapa[i][j] == 'I')
				{
					assert(a==-1);
					a = i;
					b = j;
				}							
				if (mapa[i][j] == '$')
				{
					tes++;
				}							
			}
		}

		memset(mrc, 0, sizeof(mrc));

		printf("%d/%d\n",vai(a, b), tes);



	}

	return 0;
}
