#include "testlib.h"
#include <iostream>

const int MIN_N = 2;
const int MAX_N = 100;

int main() {
	registerValidation();

	int n = inf.readInt(MIN_N, MAX_N, "n");
	inf.readEoln();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			inf.readToken("[a-z]{1,10}");
			inf.readEoln();
		}
	}

	inf.readEof();

	return 0;
}
