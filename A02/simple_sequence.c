#include <stdio.h>

int main(void) {
	for (int i = 1; i < 11; i++) {
		if (i == 10) {
			printf("%i", i);
			printf("\n");
		} else {
		printf("%i,", i);
		};
	};
};
