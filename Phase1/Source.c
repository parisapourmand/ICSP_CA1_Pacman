/*parisa pourmand*/
#include<stdio.h>
#include"pacman.h"
#include"table.h"
void main() {
	while (true) {
		int n;
		/*choose what to draw or exit program*/
		printf("What do you want to draw?\n0 Exit program\n1 Draw Pacman\n2 Draw table\n");
		scanf_s("%d", &n);
		switch (n) {
			/*draw pacman*/
		case 1:{printf("You want to draw Pacman.\n");
			int r;
			float deg;
			char drc;
			/*get input for drawing pacman*/
			printf("Enter Pacmans radius(4-20):");
			scanf_s("%d", &r);
			if (r < 4 || r>20) {/*error for invalid radius input*/
				printf("The radius is invalid.\n");
				break;
			}
			printf("Enter Pacmans mouth degree(0,60,90,120):");
			scanf_s("%f", &deg);
			if (deg != 0 && deg != 60 && deg != 90 && deg != 120) {/*error for invalid degree input*/
				printf("The mouth degree is invalid.\n");
				break;
			}
			printf("Enter Pacmans direction(U,D,R,L):");
			scanf_s(" %c", &drc);
			pacman(r, deg, drc);
			break;
		}/*end of drawing pacman*/
			/*draw the table*/
		case 2: {printf("You want to to draw the table.\n");
			int s, row, column;
			/*get input for drawing table*/
			printf("Enter the length:\n");
			scanf_s("%d", &s);
			printf("Enter the number of rows : \n");
			scanf_s("%d", &row);
			printf("Enter the number of columns : \n");
			scanf_s("%d", &column);
			table(s,row,column);
			break;
		}/*end of drawing table*/
		case 0:printf("Exiting program.\n");/*exit program message*/
			break;
		default:printf("Enter a valid number.\n");/*error for invalid n*/
		}/*end of switch(n)*/
		if (n == 0) {/*exit program*/
			break;
		}/*end of switch(n)*/
	}
}