#include <stdio.h>
#include <assert.h>

int main()
{
	int n;
	int i, s, a, b;
	while (1)
	{
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		assert(n >=1 && n <= 98);

		s = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d %d", &a, &b);
			assert(a>=3 && a<=100);
			assert(b >=1 && b <= 1000);
			s += a*b;
		}
		assert(s%2 == 0);
		printf("%d\n", s/2);
	}
	return 0;
}
