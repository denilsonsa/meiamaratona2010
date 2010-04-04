/**/

#include <stdio.h>
#include <string.h>
#include <assert.h>


int main()
{
	int n;
	int a, b, c, d;

	scanf("%d", &n);	

	assert(n>0);

	while (n--)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);

		assert(a >= 1 && a <= 100);
		assert(b >= 1 && b <= 100);
		assert(c >= 1 && c <= 100);
		assert(d >= 1 && d <= 100);

		if (a*d == b*c)
		{
			printf("SIM\n");
		}
		else
		{
			printf("NAO\n");
		}

	}
	return 0;
}
