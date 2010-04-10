/*
 * hipertenusa.cpp
 *
 *  Created on: 31/03/2010
 *      Author: Debora
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX 3170
#define MAXHIP 10000001

int psq[MAX];
char hip[MAXHIP];

int main(void) {
	int n, v;
	int s;
	memset(hip, 0, sizeof(hip));
	for (int i = 1; i < MAX; ++i) {
		psq[i] = i*i;
	}
	for (int i = 1; i < MAX; ++i) {
		for (int j = i; j < MAX; ++j) {
			s = psq[i] + psq[j];
			if (s < MAXHIP) {
				hip[s] += (hip[s] > 1) ? 0 : 1;
			}
		}
	}
	scanf("%d", &n);
	while (n) {
		n--;
		scanf("%d", &v);
		if (hip[v] > 1) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
	}
	return 0;
}
