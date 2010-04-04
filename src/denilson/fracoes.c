#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	int a, b, c, d;

	scanf("%d", &n);
	if( n<1 )
		printf("AVISO: n<1\n");
	while(n--)
	{
		if( scanf("%d%d%d%d", &a, &b, &c, &d) != 4 ) 
			printf("AVISO: scanf retornou diferente de 4");

		if( a*b*c*d == 0 )
			printf("AVISO: ZERO DETECTADO!\n");

		if( a*d == b*c )
			printf("SIM\n");
		else
			printf("NAO\n");
	}

	return 0;
}
