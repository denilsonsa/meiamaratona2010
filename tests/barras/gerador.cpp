#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	printf("10101101110110001010111100010110100011011110101010101110011001101011100111001010010001110100101\n");
	printf("10101101110110001010111100010110100011011110100010111110011001101111100111001000010001110100101\n");
	printf("10100101110001001010011100111010110011001110101010101111011000101101000111101010001101110110101\n");
}

char cod[][8] = {
"0001101", "1110010",
"0011001", "1100110",
"0010011", "1101100",
"0111101", "1000010",
"0100011", "1011100",
"0110001", "1001110",
"0101111", "1010000",
"0111011", "1000100",
"0110111", "1001000",
"0001011", "1110100"
};

void aleat(int qt)
{
	int i;
	while (qt--)
	{
		for (i=0; i<95; i++)
		{
			putchar('0'+randab(0,1));
		}
		putchar('\n');
	}
}

void certos(int qt)
{
	int i;
	while (qt--)
	{
		printf("101");
		for (i=0; i<6; i++)
		{
			printf("%s", cod[2*randab(0,9)]);
		}
		printf("01010");
		for (i=0; i<6; i++)
		{
			printf("%s", cod[1+2*randab(0,9)]);
		}
		printf("101\n");
	}
}
void tricky()
{
	int i;
	printf("101");
	for (i=0; i<6; i++)
	{
		printf("%s", cod[2*randab(0,9)]);
	}
	printf("01000");
	for (i=0; i<6; i++)
	{
		printf("%s", cod[1+2*randab(0,9)]);
	}
	printf("101\n");

	printf("101");
	for (i=0; i<6; i++)
	{
		printf("%s", cod[2*randab(0,9)]);
	}
	printf("01010");
	for (i=0; i<6; i++)
	{
		printf("%s", cod[1+2*randab(0,9)]);
	}
	printf("100\n");

	printf("100");
	for (i=0; i<6; i++)
	{
		printf("%s", cod[2*randab(0,9)]);
	}
	printf("01010");
	for (i=0; i<6; i++)
	{
		printf("%s", cod[1+2*randab(0,9)]);
	}
	printf("101\n");
}

void printinv(char *s)
{
	int i;
	for (i=6; i>=0; i--)
	{
		putchar(s[i]);
	}
}

void invertidos(int qt)
{
	int i;
	while (qt--)
	{
		printf("101");
		for (i=0; i<6; i++)
		{
			printinv(cod[1+2*randab(0,9)]);
		}
		printf("01010");
		for (i=0; i<6; i++)
		{
			printinv(cod[2*randab(0,9)]);
		}
		printf("101\n");
	}
}



int main()
{
	printf("%d\n", 66);
	sample();//3
	certos(10);
	aleat(10);
	invertidos(10);
	tricky();//3
	certos(10);
	aleat(10);
	invertidos(10);

	return 0;
}
