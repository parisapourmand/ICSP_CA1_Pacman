/*parisa pourmand*/
#include <stdio.h>
#include "Pacman.h"
/*function for drawing table*/
void Table(int table[ROWS_PER_TABLE + 1][COLUMN_PER_TABLE + 1][2]) 
{
	int i, j,m,n;
	for (m = 0; m <= COLUMN_PER_TABLE; m++) {/*Initializing table walls */
		for (n = 0; n <= ROWS_PER_TABLE; n++) {
			table[m][n][0] = table[m][n][1] = 0;
		}
	}
	for (i = 0; i < COLUMN_PER_TABLE; i++) {/*Initializing table walls*/
		table[0][i][0] = table[ROWS_PER_TABLE][i][0] = 1;
	}
			for (j = 0; j < ROWS_PER_TABLE; j++) {/*Initializing table walls*/
			table[j][0][1] =table[j][COLUMN_PER_TABLE][1] = 1;
		}
			/*Initializing table walls*/
			table[0][4][1] = table[1][4][0] = table[1][2][1] = table[1][5][1] = table[2][2][0] = table[2][3][1] = table[3][0][0] = table[3][1][1] = table[3][3][0] = table[3][4][1] = table[4][1][0] = table[4][4][0] = table[4][5][1] = 1;

			/*print - for table walls*/
			for (i = 0; i < ROWS_PER_TABLE + 1; i++) {
				for ( j = 0; j < COLUMN_PER_TABLE + 1; j++)
				{
					if (table[i][j][0] == 1) {
						gotoxy(j * CELL_WIDTH, i * CELL_WIDTH /2);
						for (int k = 0; k < CELL_WIDTH; k++)
						{
							printf("-");
						}
					}
				}
			}
			/*print | for table walls*/
			for (i = 0; i < ROWS_PER_TABLE + 1; i++) {
				for (j = 0; j < COLUMN_PER_TABLE + 1; j++)
				{
					if (table[i][j][1] == 1) {
						for (int k = 0; k < CELL_WIDTH/2; k++)
						{
							gotoxy(j * CELL_WIDTH, i * CELL_WIDTH / 2 + k);
							printf("|");
						}
					}
				}
			}
			/*print * in each cell*/
			for (i = 0; i < ROWS_PER_TABLE; i++) {
				for (j = 0; j < COLUMN_PER_TABLE; j++) {
					gotoxy(10+j*CELL_WIDTH ,(10+i*CELL_WIDTH)/2);
					printf("@");
				}
			}
		
}

