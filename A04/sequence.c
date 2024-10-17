#include <stdio.h>
#include <stdlib.h>

int compute_next_value(int x, int m, int c) {
	return m * x + c;
}


int main(int argc, char* argv[]) {
	if (argc != 5) {
		printf("Number of arguments is not 5\n");
		exit(1);
	}

	int n = atoi(argv[1]);
    int x0 = atoi(argv[2]);
    int m = atoi(argv[3]);
    int c = atoi(argv[4]);

    // Check that n is a positive integer
    if (n <= 0) {
        printf("Error: n must be a non-zero positive number.\n");
        return 1;
    }

    // Print the sequence
    int current_value = x0;
    printf("%d", current_value);

    for (int i = 1; i < n; i++) {
        current_value = compute_next_value(current_value, m, c);
        printf(",%d", current_value);
    }

    printf("\n");
    return 0; // Return 0 for success
}
