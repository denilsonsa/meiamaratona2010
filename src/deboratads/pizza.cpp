/*
 * pizza.cpp
 *
 *  Created on: 05/04/2010
 *      Author: Debora
 */

#include <algorithm>

#include <stdio.h>
#include <math.h>

#define MAX 1024

int pz[MAX], pt[MAX];
double fat;

using namespace std;

bool cabe(int ipz, int ipt) {
	return (pt[ipt]*fat >= pz[ipz]);
}

int main() {
	int m, n, r, nf;
	fat = 2*cos(acos(-1)/8);
	while(1) {
		scanf("%d%d", &m, &n);
		if (!m && !n) break;

		for (int i = 0; i < m; ++i) {
			scanf("%d", &pz[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &pt[i]);
		}
		sort(pz, pz+m);
		sort(pt, pt+n);
		r = 0;
		nf = 8;
		int i = 0, j = 0;
		while (i < m && j < n) {
			if (cabe(i, j)) {
				nf--;
				if (nf == 0) {
					nf = 8;
					i++;
				}
				j++;
				r++;
			} else {
				j++;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}
