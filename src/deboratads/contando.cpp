/*
 * contando.cpp
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
long long comb[MAX+1][MAX+1];
long long fat[MAX+1];

void calcula_comb() {
	fat[0] = 1;
	for (long long i = 1; i <= MAX; i++) {
		fat[i] = fat[i-1] * i;
	}
	for (int i = 0; i <= MAX; ++i) {
		for (int j = 0; j <= i; j++) {
			comb[i][j] = (fat[i] / fat[j])/fat[i-j];
		}
	}
}

void bt(int pat, int nat, long long mat) {
	if (pat == k) {
		if (mat <= m) {
			if (nat >= n) {
				r += (((nat-n) % 2) ? -1 : 1) * comb[nat][n] * (m/mat);
			}
		}
		return;
	}
	if (m/mat >= p[pat]) {
		bt(pat+1, nat+1, mat * p[pat]);
	}
	bt(pat+1, nat, mat);
}

int main() {
	calcula_comb();
	while (true) {
		scanf("%d %d %d", &k, &m, &n);
		if (!k && !m && !n) {
			break;
		}
		for (int i = 0; i < k; ++i) {
			scanf("%d", &p[i]);
		}
		r = 0;
		sort(p, p+k);
		bt(0, 0, 1);
		//printf("%I64d\n", r);
		printf("%lld\n", r);
	}
	return 0;
}

