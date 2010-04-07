/*
 * gen_input_hipertenusa.cpp
 *
 *  Created on: 30/03/2010
 *      Author: Debora
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main(void) {
	for (int i = 1; i <= MAX; ++i) {
		printf("%d\n", i);
	}
	printf("0\n");
	return EXIT_SUCCESS;
}

