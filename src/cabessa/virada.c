#include <stdio.h>
#include <string.h>
#include <assert.h>

int main()
{
	int n;
	int t, i, a;

	while (1)
	{
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		assert(n>=1 && n<=100000);
		a = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			assert(t>=0 && t<=1);
			a+=t;
		}
		printf("%d\n", a%2);
	}

	return 0;
}
