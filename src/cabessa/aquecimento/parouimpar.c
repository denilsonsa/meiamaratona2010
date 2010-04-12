#include <stdio.h>
#include <assert.h>

int main()
{
	int n;
	int a, c;

	scanf("%d", &n);

	c = 0;

	while (n--)
	{
		scanf("%d", &a);
		assert(a>0 && a <= 1000000000);

		if (a%2 == 0)
		{
			c++;
		}
	}

	printf("%d\n", c);

	return 0;
}
