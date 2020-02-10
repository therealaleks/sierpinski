#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


int powerOfTwo(unsigned int x){
	return ((x != 0) && !(x & (x - 1)));
}

int exponential(int num, int pow){
	int answer = num;
	if (pow == 0){
		return 1;
	}else if (pow == 1){
		return num;
	}else{
		for(int i=1; i < pow; i++){
			answer = answer*num;
		}
	}
	return answer;
}


void main(int argc, char *argv[]){
        if (argc!=3){
		printf("ERROR: Wrong number of arguments. Two required. \n");
		return;
        }
		int hi=atoi(argv[1]);
		int l=atoi(argv[2]);
		int lcondition;
                lcondition=exponential(2, (l-1));
		if (hi < 0 | hi%2==0){
		printf("ERROR: Bad argument. Height must be positive odd integer. \n");
		}
                else if (!powerOfTwo((hi/2)+1) | lcondition > ((hi/2)+1)) {
                        printf("ERROR: Height does not allow evenly dividing requested number of levels. \n");

                }              
		else if (l <= 0){
			printf("ERROR: Bad argument. Level must be positive integer greater than 0. \n");
		}
		
		else{	
			int h = (hi + 1) / 2;
			int width = hi;

			int rrey[h][width];

			for (int i = 0; i < h; i++) {
			for (int a = 0; a < width; a++) {
			rrey[i][a] = 0;
			}
			}

			int g = (width - 1) / 2;
			int f = 0;
			
			int printrow(int g, int f, int h, int l) {
				if (l == 1) {
				int count = 0;
				for (int i = f; i < f + h; i++) {
				if (i == f) {
				int count = 1;
				rrey[i][g] = 1;
				}
				if (i > f) {
				count += 1;
				for (int b = g - count; b < g + count + 1; b++) {
				rrey[i][b] = 1;
					}
					}
				}
				}
				else {
				printrow(g, f, h / 2, l - 1);

				printrow(g + h / 2, f + h / 2, h / 2, l - 1);

				printrow(g - h / 2, f + h / 2, h / 2, l - 1);
				}
				return 0;
			}

			printrow(g, f, h, l);

			for (int i = 0; i < h; i++) {
			for (int c = 0; c < width; c++) {
				if (rrey[i][c] == 1) {
				printf("*");
				}
				else {
				printf(" ");
				}
				}
				printf("\n");
			}
			for (int i = h - 2; i >= 0; i--) {
				for (int d = 0; d < width; d++) {
				if (rrey[i][d] == 1) {
				printf("*");
				}
				else {
				printf(" ");
				}
				}
				printf("\n");

			}

		}

}
