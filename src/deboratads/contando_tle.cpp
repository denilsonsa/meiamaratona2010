/*
 * contando_tle.cpp
 *
 *  Created on: 04/04/2010
 *      Author: Debora
 */

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX 20

int p[MAX];

int k, n, m;
long long r;

int main() {
	int nm;
	while (true) {
		scanf("%d %d %d", &k, &m, &n);
		if (!k && !m && !n) {
			break;
		}
		for (int i = 0; i < k; ++i) {
			scanf("%d", &p[i]);
		}
		fflush(stdout);
		r = 0;
		for (int i = 1; i <= m; ++i) {
			nm = 0;
			for (int j = 0; j < k; ++j) {
				if (i%p[j] == 0) {
					nm++;
				}
			}
			if (nm == n) {
				r++;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}

