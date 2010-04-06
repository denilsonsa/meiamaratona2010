/*
 * hipertenusa.cpp
 *
 *  Created on: 31/03/2010
 *      Author: Debora
 */

#include <ext/hash_map>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX 3170
#define MAXHIP 10000001

int psq[MAX];
char hip[MAXHIP];

int main(void) {
	int n;
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
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		if (hip[n] > 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return EXIT_SUCCESS;
}
