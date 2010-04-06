/*
 * fracoes.cpp
 *
 *  Created on: 05/04/2010
 *      Author: Debora
 */

#include <stdio.h>

int main() {
	int n;
	int a, b, c, d;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%s\n", a*d == b*c ? "SIM" : "NAO");
	}
}
