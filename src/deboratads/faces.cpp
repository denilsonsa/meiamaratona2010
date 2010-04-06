/*
 * faces.cpp
 *
 *  Created on: 06/04/2010
 *      Author: Debora
 */

#include <stdio.h>
#include <assert.h>

int main() {
	int n;
	int ne, nl, np, nf;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		ne = 0;
		nf = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &nl, &np);
			ne += nl * np;
			nf += np;
		}
		assert(ne % 2 == 0);
		assert(nf > 3);
		printf("%d\n", ne/2);
	}
}
