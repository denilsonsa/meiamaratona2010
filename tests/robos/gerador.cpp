#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX 1000

char mat[MAX+1][MAX+1];

char sample[][20] = 
{"7 11",
"###########",
"#..I...#.$#",
"#.###..$..#",
"#.#.###.$.#",
"#.#.#.$.$.#",
"#.....#.#.#",
"###########",
"7 13",
"#############",
"#$$#........#",
"####..#####.#",
"#.I.$.#.$.#.#",
"####..#####.#",
"#$$#........#",
"#############",
"0 0"
};

int randab(int a, int b)
{
	return rand()%(b-a+1) + a;
}

void exemplo()
{
	int i;
	for (i=0; ; i++)
	{
		if (sample[i][0] == '0')
		{
			break;
		}
		printf("%s\n", sample[i]);
	}
}

void caso1()
{
	int m, n;
	int i, j;

	m = n = MAX;
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			mat[i][j] = '#';	
		}
		mat[i][MAX+1] = '\0';
	}

	mat[MAX/2][MAX/2] = 'I';

	for (i=0; i<m; i++)
	{
		mat[i][n] = '\0';
	}
	printf("%d %d\n", m, n);
	for (i=0; i<m; i++)
	{
		printf("%s\n", mat[i]);
	}
}

void caso2()
{
	int m, n;
	int i, j;

	m = n = MAX;
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			mat[i][j] = '.';
		}
	}

	for (i=0; i<m; i++)
	{
		mat[i][0] = '#';
		mat[i][n-1] = '#';
		mat[0][i] = '#';
		mat[m-1][i] = '#';
	}
	for (i=0; i<50; i++)
	{
		mat[randab(1,MAX-2)][randab(1,MAX-2)] = '$';
	}
	mat[randab(1,MAX-2)][randab(1,MAX-2)] = 'I';

	
	for (i=0; i<m; i++)
	{
		mat[i][n] = '\0';
	}
	
	printf("%d %d\n", m, n);
	for (i=0; i<m; i++)
	{
		printf("%s\n", mat[i]);
	}
}

void caso3()
{
	int m, n;
	int i, j;

	m = n = MAX;
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			mat[i][j] = '.';
		}
	}

	for (i=0; i<m; i++)
	{
		mat[i][0] = '#';
		mat[i][n-1] = '#';
		mat[0][i] = '#';
		mat[m-1][i] = '#';
	}

	for (i=2; i<m; i+=4)
	{
		for (j=0; j<=n-3; j++)
		{
			mat[i][j] = '#';
		}
	}

	for (i=4; i<m; i+=4)
	{
		for (j=2; j<=n-1; j++)
		{
			mat[i][j] = '#';
		}
	}


	mat[1][1] = '$';
	for (i=0; i<50; i++)
	{
		mat[randab(1,MAX-2)][randab(1,MAX-2)] = '$';
	}
	mat[randab(1,MAX-2)][randab(1,MAX-2)] = 'I';
	
	for (i=0; i<m; i++)
	{
		mat[i][n] = '\0';
	}
	
	printf("%d %d\n", m, n);
	for (i=0; i<m; i++)
	{
		printf("%s\n", mat[i]);
	}
}

void caso4()
{
	int m, n;
	int i, j;

	m = n = MAX;
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			mat[i][j] = '$';
		}
	}

	for (i=0; i<m; i++)
	{
		mat[i][0] = '#';
		mat[i][n-1] = '#';
		mat[0][i] = '#';
		mat[m-1][i] = '#';
	}

	mat[randab(1,MAX-2)][randab(1,MAX-2)] = 'I';

	for (i=0; i<m; i++)
	{
		mat[i][n] = '\0';
	}

	printf("%d %d\n", m, n);
	for (i=0; i<m; i++)
	{
		printf("%s\n", mat[i]);
	}
}


void aleat(int qt)
{
	int m, n;
	int i, j;
	int qt_tesouro, qt_obst;

	while (qt)
	{
		qt--;

		m = randab(3, MAX);
		n = randab(3, MAX);


		for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				mat[i][j] = '.';
			}
		}

		qt_tesouro = randab(1, (m+n+(m-2)*(n-2))/2 );
		qt_obst = randab(1, (m-2)*(n-2));

		
		for (i=0; i<qt_obst; i++)
		{
			mat[randab(1,m-2)][randab(1,n-2)] = '#';
		}

		for (i=0; i<qt_tesouro; i++)
		{
			mat[randab(1,m-2)][randab(1,n-2)] = '$';
		}

		for (i=0; i<m; i++)
		{
			mat[i][0] = '#';
			mat[i][n-1] = '#';
		}

		for (j=0; j<n; j++)
		{
			mat[0][j] = '#';
			mat[m-1][j] = '#';
		}

		mat[randab(1,m-2)][randab(1,n-2)] = 'I';

		for (i=0; i<m; i++)
		{
			mat[i][n] = '\0';
		}

		printf("%d %d\n", m, n);
		for (i=0; i<m; i++)
		{
			printf("%s\n", mat[i]);
		}
	}
}

int main()
{
	// Sample
	exemplo();

	// Casos grandes
	caso1();
	caso2();
	caso3();
	caso4();

	// Casos aleatórios, o parâmetro é a quantidade
	aleat(10);

	printf("0 0\n");

	return 0;
}
