#include <stdio.h>
#include <string.h>

char digit_table[10][8] = {
	"0001101",  /* 0 */
	"0011001",  /* 1 */
	"0010011",  /* 2 */
	"0111101",  /* 3 */
	"0100011",  /* 4 */
	"0110001",  /* 5 */
	"0101111",  /* 6 */
	"0111011",  /* 7 */
	"0110111",  /* 8 */
	"0001011"   /* 9 */
};

char control_middle[] = "01010";
char control_border[] = "101";

void convert_chars_to_binary(char * buf, int len)
{
	while(len--)
	{
		*buf -= '0';
		buf++;
	}
}

int match(char **bp, char *pattern, int len, char XOR)
{
	while(len--)
	{
		if( ((**bp) ^ XOR) != *pattern )
			return 0;
		(*bp)++;
		pattern++;
	}
	return 1;
}

char find_match(char **bp, char XOR)
{
	int i;
	char *tmp;
	for(i=0; i<10; i++)
	{
		tmp = *bp;
		if( match(&tmp, digit_table[i], 7, XOR) )
		{
			*bp = tmp;
			return i+'0';
		}
	}
	return 0;
}

void reverse_buf(char *buf, int len)
{
	int i;
	char tmp;
	/* i   < len-i-1 */
	/* 2*i < len-1 */
	/* 2*i < len-1 */
	/* i   < (len-1)/2   divisao fracionaria */
	/* i   < (len)/2     divisao inteira */
	for(i=0; i < len/2; i++)
	{
		tmp = buf[i];
		buf[i] = buf[len-i-1];
		buf[len-i-1] = tmp;
	}
}

int decode_barcode(char *bp, char *digits)
{
	int i;

	if( ! match(&bp, control_border, 3, 0) ) return 0;
	for(i=0; i<6; i++)
	{
		digits[i] = find_match(&bp, 0);
		if( ! digits[i] ) return 0;
	}
	if( i<6 ) return 0;
	if( ! match(&bp, control_middle, 5, 0) ) return 0;
	for(   ; i<12; i++)
	{
		digits[i] = find_match(&bp, 1);
		if( ! digits[i] ) return 0;
	}
	if( i<12 ) return 0;
	if( ! match(&bp, control_border, 3, 0) ) return 0;
	digits[i] = '\0';

	return 1;
}


int main(int argc, char *argv[])
{
	int N;
	int i;
	char buf[100];
	char digits[20];

	for(i=0; i<10; i++)
		convert_chars_to_binary(digit_table[i], 7);
	convert_chars_to_binary(control_middle, 5);
	convert_chars_to_binary(control_border, 3);

	scanf("%d", &N);
	while(N--)
	{
		if( scanf(" %[01]", buf) != 1)
		{
			printf("ERRO NA LEITURA\n");
			continue;
		}
		if( strlen(buf) != 95 )
		{
			printf("ERRO: Foram lidos %d caracteres, em vez de 95.\n", (int) strlen(buf));
			continue;
		}
		convert_chars_to_binary(buf, 95);

		if( ! decode_barcode(buf, digits) )
		{
			reverse_buf(buf, 95);
			if( ! decode_barcode(buf, digits) )
			{
				printf("XXXXXXXXXXXX\n");
				continue;
			}
		}
		printf("%s\n", digits);
	}

	return 0;
}
