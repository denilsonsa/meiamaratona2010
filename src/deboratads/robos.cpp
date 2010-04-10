/*
 * robos.cpp
 *
 *  Created on: 05/04/2010
 *      Author: Debora
 */

#include <queue>

#include <stdio.h>
#include <math.h>

using namespace std;

#define MAX 1024

int nl, nc, nt, nr;
char mapa[MAX][MAX];

struct Pos {
	int l, c;

	Pos(int lv, int cv) {
		l = lv;
		c = cv;
	}
};

void insert(queue<Pos>* queue, int l, int c) {
	if (mapa[l][c] == '#') {
		return;
	}
	if (mapa[l][c] == '$') {
		nr++;
	}
	mapa[l][c] = '#';
	queue->push(Pos(l, c));
}

void busca(int li, int ci) {
	queue<Pos> queue;
	insert(&queue, li, ci);
	while (!queue.empty()) {
		Pos p = queue.front();
		queue.pop();
		insert(&queue, p.l - 1, p.c);
		insert(&queue, p.l + 1, p.c);
		insert(&queue, p.l, p.c - 1);
		insert(&queue, p.l, p.c + 1);
	}
}

int main() {
	int li, ci;
	while(1) {
		scanf("%d%d\n", &nl, &nc);
		if (!nl && !nc) break;

		nt = nr = 0;
		memset(mapa, '#', sizeof(mapa));
		for (int i = 1; i <= nl; ++i) {
			gets(mapa[i]+1);
			for (int j = 1; j <= nc; ++j) {
				if (mapa[i][j] == '$') {
					nt++;
				} else if (mapa[i][j] == 'I') {
					ci = j;
					li = i;
				}
			}
		}
		busca(li, ci);
		printf("%d/%d\n", nr, nt);
	}
	return 0;
}
