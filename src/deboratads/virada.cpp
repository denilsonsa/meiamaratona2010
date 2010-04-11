/*
 * virada.cpp
 *
 *  Created on: 10/04/2010
 *      Author: Debora
 */

#include <stdio.h>

int main() {
	int n;
	int v;
	bool par = true;

	while (true) {
		scanf("%d", &n);
		if (!n) break;

		for (int i = 0; i < n; ++i) {
			scanf("%d", &v);
			if (v == 1) {
				par = !par;
			}
		}
		printf("%d\n", par ? 1 : 0);
	}
	return 0;
}



