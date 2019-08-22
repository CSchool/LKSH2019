#include "testlib.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>

// S ::= T | TIS
// I ::= <a>S</a>

char alph[28] = "qwertyuiopasdfghjklzxcvbnm ";
bool lastSpace = false;

int gen(int);

int gentext(int len) {
	for (int i = 0; i < len; i ++) {
		char out = alph[rnd.next(0, 26 - lastSpace)];
		lastSpace = false;
		putchar(out);
	}
	return len;
}

int gentag(int len) {
	char ch = alph[rnd.next(0, 25)];
	printf("<%c>", ch);
	lastSpace = false;
	len = gen(len - 7);
	printf("</%c>", ch);
	lastSpace = false;
	return len;
}

int gen(int len) {
	if (len < 7) {
		gentext(len);
		return 0;
	}

	if (!rnd.next(0, len / 50)) {
		return len - gentext(rnd.next(0, len));
	}
	else {
//		len -= gentext(rnd.next(0, std::min(len - 7, len / 4)));
		int child = rnd.next(0, len);
		len -= child;
		child = gentag(child);
		return gen(len + child);
	}
}

int main (int argc, char * argv[]) {
	registerGen(argc, argv, 1);

	int len = rnd.next(atoi(argv[2]), atoi(argv[3]));

	len -= gentext(rnd.next(0, std::min(len, 100)));
	gen(len);

	printf("\n");

	return 0;
}
