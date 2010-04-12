#include <stdio.h>
#include <assert.h>

int main()
{
	int a, b;

	while (1)
	{
		scanf("%d %d", &a, &b);

		if (!a)
		{
			assert(b==0);
			break;
		}

		assert(a >= 1 && a <= 1000);
		assert(b >= 1 && b <= 1000);

		printf("%d\n", a + b);
	}

	return 0;
}
