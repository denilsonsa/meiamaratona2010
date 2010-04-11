#include <stdio.h>
#include <string.h>

#define MAX 8
#define MAXM 128

char buff[MAX];
char s[MAXM];
char resp[2*MAX];


char cod[10][2][8] = 
{
	{"0001101", "1110010"},
	{"0011001", "1100110"},
	{"0010011", "1101100"},
	{"0111101", "1000010"},
	{"0100011", "1011100"},
	{"0110001", "1001110"},
	{"0101111", "1010000"},
	{"0111011", "1000100"},
	{"0110111", "1001000"},
	{"0001011", "1110100"}
};

void rev()
{
	int i;
	char c;

	for (i=0; i<95/2; i++)
	{
		c = s[i];
		s[i] = s[94-i];
		s[94-i] = c;
	}
}

int pode()
{
	int erro, i, j;

	erro = 0;

	rev();

	for (i=0; i<12; i++)
	{
		resp[i] = '.';
	}

	sscanf(s, "%3s", buff);
	buff[3] = 0;
	if (strcmp(buff, "101"))
	{
		erro = 1;
	}


	buff[7] = 0;
	for (i=0; i<6; i++)
	{
		sscanf(s+3+7*i, "%7s", buff);
		for (j=0; j<10; j++)
		{
			if (!strcmp(buff, cod[j][0]))
			{
				resp[i] = '0' + j;
				break;
			}
		}
		if (j==10)
		{
			erro = 1;
		}
	}


	sscanf(s+45,"%5s", buff);
	buff[5] = 0;
	if (strcmp(buff, "01010"))
	{
		erro = 1;
	}

	buff[7] = 0;
	for (i=0; i<6; i++)
	{
		sscanf(s+50+7*i,"%7s", buff);
		for (j=0; j<10; j++)
		{
			if (!strcmp(buff, cod[j][1]))
			{
				resp[i+6] = '0' + j;
				break;
			}
		}
		if (j==10)
		{
			erro = 1;
		}
	}

	sscanf(s+92, "%3s", buff);
	buff[3] = 0;
	if (strcmp(buff, "101"))
	{
		erro = 1;
	}

	return !erro;
}


int main()
{
	int n, erro, i, j;
	scanf("%d", &n);

	while (n--)
	{
		erro = 0;
		s[0] = '\0';

		for (i=0; i<12; i++)
		{
			resp[i] = '.';
		}

		scanf("%3s", buff);
		strcat(s, buff);
		buff[3] = 0;
		if (strcmp(buff, "101"))
		{
			erro = 1;
		}


		buff[7] = 0;
		for (i=0; i<6; i++)
		{
			scanf("%7s", buff);
			strcat(s, buff);
			for (j=0; j<10; j++)
			{
				if (!strcmp(buff, cod[j][0]))
				{
					resp[i] = '0' + j;
					break;
				}
			}
			if (j==10)
			{
				erro = 1;
			}
		}


		scanf("%5s", buff);
		strcat(s, buff);
		buff[5] = 0;
		if (strcmp(buff, "01010"))
		{
			erro = 1;
		}

		buff[7] = 0;
		for (i=0; i<6; i++)
		{
			scanf("%7s", buff);
			strcat(s, buff);
			for (j=0; j<10; j++)
			{
				if (!strcmp(buff, cod[j][1]))
				{
					resp[i+6] = '0' + j;
					break;
				}
			}
			if (j==10)
			{
				erro = 1;
			}
		}

		scanf("%3s", buff);
		strcat(s, buff);
		buff[3] = 0;
		if (strcmp(buff, "101"))
		{
			erro = 1;
		}
		
		if (!erro)
		{
			resp[12] = 0;
			printf("%s\n", resp);
		}
		else
		{
			if (pode())
			{
				resp[12] = 0;
				printf("%s\n", resp);
			}
			else
				printf("XXXXXXXXXXXX\n");

		}
	}


	return 0;
}
