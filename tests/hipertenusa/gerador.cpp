/*
 * gen_input_hipertenusa.cpp
 *
 *  Created on: 30/03/2010
 *      Author: Debora
 *		Edited by: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000
#define MAXT 1000000
int v[MAX];

#define MASK 0x80000000
int meurand()
{
	return ((rand()<<16) + rand()) & (~MASK);
}


int main(void) {
	int temp, t;
	for (int i = 1; i <= MAX; ++i) {
		v[i-1] = i;
	}

	for (int i=MAX-1; i>0; i--)
	{
		t = meurand()%(i+1);
		temp = v[i];
		v[i] = v[t];
		v[t] = temp;
	}

	v[0] = 37;
	v[1] = 43;
	v[2] = 50;
	v[3] = 51;
	v[4] = 9999996;
	v[5] = 9999997;
	v[6] = 9999998;
	v[7] = 9999999;
	v[8] = 10000000;
	v[9] = 9999995;
	v[10] = 9999994;
	v[11] = 9999993;
	v[12] = 9999992;
	v[13] = 9999991;
	v[14] = 9999990;

	printf("%d\n", MAXT);

	for (int i = 0; i < MAXT; ++i) {
		printf("%d\n", v[i]);
	}
	return EXIT_SUCCESS;
}

