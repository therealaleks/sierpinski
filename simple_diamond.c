#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("ERROR: Wrong number of arguments. One required. \n");
		return;
	}
	int h = atoi(argv[1]);
	if (h % 2 == 0 | h < 0 ) {
		printf("ERROR: Bad argument. Height must be positive odd integer. \n");
	}else {
		//upper half of diamond
		for (int i = 1; i < (h/2)+2; i++) {
			int Space = (h / 2) + 1 - i;
			int row = (2*i) - 1;
			
			for (int z = 1; z < Space+1; z++){
				printf(" ");
			}

			for (int z = 1; z < row + 1; z++) {
				printf("*");
			}

			for (int z = 1; z < Space + 1; z++) {
				printf(" ");
			}

			printf("\n");
		}
		//lower half of diamond
		for (int i = 1; i < (h / 2) + 1; i++) {
			int Space2 = i;
			int row2 = h - (2*i);

			for (int z = 1; z < Space2 + 1; z++) {
				printf(" ");
			}

			for (int z = 1; z < row2 + 1; z++) {
				printf("*");
			}

			for (int z = 1; z < Space2 + 1; z++) {
				printf(" ");
			}

			printf("\n");
		}
	}
}

