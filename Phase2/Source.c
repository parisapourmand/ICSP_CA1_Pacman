/*parisa pourmand*/
#include <stdio.h>
#include "Pacman.h"
#include "table.h"

void main() {
	initScreen();
	int table[ROWS_PER_TABLE + 1][COLUMN_PER_TABLE + 1][2], scoretable[ROWS_PER_TABLE][COLUMN_PER_TABLE];
	/*Initializing scoretable*/
	for (int i = 0; i < ROWS_PER_TABLE; i++) {
		for (int j = 0; j < COLUMN_PER_TABLE; j++) {
			scoretable[i][j] = 0;
		}/*end of for*/
	}/*end of for*/
	int dx = 0, dy = 0,score=0;	/*Initializing dx,dy and score*/
	char direction='R';	/*Initializing direction*/
	Table(table);/*function for drawing table*/
	gotoxy(COLUMN_PER_TABLE*CELL_WIDTH+1, 0);/*print score next to table*/
	printf("score:");
	while (1) {
		drawOpeningMouthPacman(dx, dy, &direction);	
		addscore(dx, dy, &score, scoretable);/*function for adding score*/
		waitAndGetDirection(120, &direction);/*function waiting and geting the new direction from the keybord*/
		clearCell(dx, dy);/*function for clearing pacmans previous cell*/
		setNextLocation(&dx, &dy, direction, table);/*function for changing location*/
	}
}