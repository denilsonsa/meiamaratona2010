/*
 * barras.cpp
 *
 *  Created on: 11/04/2010
 *      Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESQ 0
#define DIR 1

#define MAX 100
#define SIZE 95
#define LEFT_START 3
#define RIGHT_START 50
#define NUM_DIGITS_GROUP 6
#define NUM_CHARS_DIGIT 7
char code_read[MAX];
char decoded[MAX];
char error[] = "XXXXXXXXXXXX";

char codes[][2][8] = {
		{ "0001101", "1110010" },
		{ "0011001", "1100110" },
		{ "0010011", "1101100" },
		{ "0111101", "1000010" },
		{ "0100011", "1011100" },
		{ "0110001", "1001110" },
		{ "0101111", "1010000" },
		{ "0111011", "1000100" },
		{ "0110111", "1001000" },
		{ "0001011", "1110100" },
};

bool eq(char* l, char* r, int size) {
	for (int i = 0; i < size; ++i) {
		if (l[i] != r[i]) return false;
	}
	return true;
}

bool decode_any(char* src, char* dst, int idx) {
	bool ok;
	for (int i = 0; i < NUM_DIGITS_GROUP; ++i) {
		ok = false;
		for (int j = 0; j <= 9; ++j) {
			if (eq(src + i * NUM_CHARS_DIGIT, codes[j][idx], NUM_CHARS_DIGIT)) {
				dst[i] = '0' + j;
				ok = true;
				break;
			}
		}
		if (!ok) {
			return false;
		}
	}
	return true;
}

bool decode_left(char* src, char* dst) {
	return decode_any(src, dst, ESQ);
}

bool decode_right(char* src, char* dst) {
	return decode_any(src, dst, DIR);
}

bool check_control(char* full) {
	if (strlen(full) != SIZE) return false;
	// checking start and end
	if (full[0] != '1' || full[SIZE-1] != '1') return false;
	if (full[1] != '0' || full[SIZE-2] != '0') return false;
	if (full[2] != '1' || full[SIZE-3] != '1') return false;
	// checking middle
	int middle = SIZE/2;
	if (full[middle] != '0') return false;
	if (full[middle+1] != '1' || full[middle-1] != '1') return false;
	if (full[middle+2] != '0' || full[middle-2] != '0') return false;
	return true;
}

void inv(char* str) {
	int middle = SIZE/2;
	for (int i = 0; i <= middle; i++) {
		char t = str[i];
		str[i] = str[SIZE - 1 - i];
		str[SIZE - 1 - i] = t;
	}
}

bool decode() {
	if (!check_control(code_read)) {
		return false;
	}
	memset(decoded, 0, sizeof(decoded));
	if (decode_left(code_read + LEFT_START, decoded) && decode_right(code_read + RIGHT_START, decoded + NUM_DIGITS_GROUP)) {
		return true;
	}
	inv(code_read);
	memset(decoded, 0, sizeof(decoded));
	if (decode_left(code_read + LEFT_START, decoded) && decode_right(code_read + RIGHT_START, decoded + NUM_DIGITS_GROUP)) {
		return true;
	}
	return false;
}

int main() {
	int n;
	int v;
	bool par = true;

	scanf("%d", &n);
	while (n) {
		n--;
		scanf("%s", code_read);
		bool ok = decode();
		printf("%s\n", ok ? decoded : error);
	}
	return 0;
}
