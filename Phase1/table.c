/*parisa pourmand*/
#include <stdio.h>
void table(int s, int row, int column) {
	int i, j;
	for (j = 1; j <= s*row + 1; j++) {
		if (j%s == 1) {
			for (i = 1; i <= s*column + 1; i++)
				printf("_");
			printf("\n");
		}
		else {

			for (i = 1; i <= s*column + 1; i++) {
				if (i%s == 1)
					printf("|");
				else
					printf(" ");
			}/*end of for*/
			printf("\n");
		}
	}
}