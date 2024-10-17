#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	if (argc < 3) {
		printf("Usage: cla_sequence start_integer end_integer where start is less than end\n");
		return 0;
	}		

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	if (b < a) {
		printf("Usage: cla_sequence start_integer end_integer where start is less than end\n");
		return 0;	
	}

	for (int i = a; i < b + 1; i++) {
		if (i == b) {
			printf("%i", i);
			printf("\n");
		} else {
		printf("%i,", i);
		};
	};
	return 0;
};


