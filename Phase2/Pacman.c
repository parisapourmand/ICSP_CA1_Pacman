/*parisa pourmand 810196601*/
#include "Pacman.h"
#include <stdio.h>
#include <math.h>
void initScreen()
{
	COORD coord;
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(stdHandle, CONSOLE_FULLSCREEN_MODE, &coord);

}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int waitAndGetDirection(int waitTime, char *direction)
{
	DWORD start_time, check_time;

	start_time = GetTickCount();
	check_time = start_time + waitTime; //GetTickTime returns time in miliseconds
	char ch = 0;
	char hit = 0;

	while (check_time>GetTickCount())
	{
		if (_kbhit())
		{
			hit = 1;
			ch = _getch();
			if (ch == 0)
				ch = _getch();
			break;
		}
	}

	switch (ch)
	{
	case 'w':
		ch = 'U';
		break;
	case 'z':
		ch = 'D';
		break;
	case 'a':
		ch = 'L';
		break;
	case 's':
		ch = 'R';
		break;
	default:
		break;
	}

	if (ch != *direction && (ch == 'U' || ch == 'D' || ch == 'L' || ch == 'R'))
	{
		*direction = ch;
		return 1;
	}
	else
		return 0;

}

/*function for drawing pacman*/
void drawPacman(int dx, int dy, int mouthDegree, char direction) {
	int x = dx*CELL_WIDTH;
	int y = dy*CELL_WIDTH / 2;
	x++;
	y++;
	int x1 = x;
	gotoxy(x,y);
		float deg = mouthDegree* 3.14 / 180;/*Convert degree to radian*/
		int  i, j;
		switch (direction) {/*drawing pacman according to its direction*/
		case'D': 
			for (i = -PACMAN_RADIUS; i <= PACMAN_RADIUS; i++) {
		 	  for (j = -PACMAN_RADIUS; j <= PACMAN_RADIUS; j++) {
				if (i*i + j*j < PACMAN_RADIUS*PACMAN_RADIUS && (i*tan(deg / 2) <= j || j <= -i*tan(deg / 2)))
					printf("##");
				else
					printf("  ");/*end of if*/
			}
			y++;
			gotoxy(2 * x - x1, y);
		}
				 break; 
		case'U':
			for (i = -PACMAN_RADIUS; i <= PACMAN_RADIUS; i++) {
				for (j = -PACMAN_RADIUS; j <= PACMAN_RADIUS; j++) {
					if (i*i + j*j < PACMAN_RADIUS*PACMAN_RADIUS && (i*tan(deg / 2) >= j || j >= -i*tan(deg / 2)))
						printf("##");
					else
						printf("  ");
				}/*end of if*/
				y++;
				gotoxy(2 * x - x1, y);
			}	
				break;
		case'R':
			for (i = -PACMAN_RADIUS; i <= PACMAN_RADIUS; i++) {
		 	  for (j = -PACMAN_RADIUS; j <= PACMAN_RADIUS; j++) {
				if (i*i + j*j < PACMAN_RADIUS*PACMAN_RADIUS && (j*tan(deg / 2) <= i || i <= -j*tan(deg / 2)))
					printf("##");
				else
					printf("  ");
			}/*end of if*/
			y++;
			gotoxy(2 * x - x1, y);
		}
				 break;
		case'L':
			for (i = -PACMAN_RADIUS; i <= PACMAN_RADIUS; i++) {
			  for (j = -PACMAN_RADIUS; j <= PACMAN_RADIUS; j++) {
				if (i*i + j*j < PACMAN_RADIUS*PACMAN_RADIUS && (j*tan(deg / 2) >= i || i >= -j*tan(deg / 2)))
					printf("##");
				else
					printf("  ");
			}/*end of if*/
			y++;
			gotoxy(2 * x - x1, y);
		}
				 break;
		}/*end of switch(drc)*/
	}
/*function for opening pacmans mouth*/
void drawOpeningMouthPacman(int dx, int dy, char *direction) {
	int m,mdeg;
	for (m = 0; m < 4; m++) {/*opens pacmans mouth*/
		switch (m) {
		case 0: 
			mdeg = 0;
			 break;
		case 1:
			mdeg = 60;
			 break;
		case 2:
			mdeg = 90;
			 break;
		case 3:
			mdeg = 120;
			 break;
		}/*end of switch*/
		drawPacman(dx, dy, mdeg, *direction);
		waitAndGetDirection(150, direction);
	}/*end of for*/
	for (m = 3; m > -1; m--) {/*closes pacmans mouth*/
		switch (m) {
		case 0:
			mdeg = 0;
			 break;
		case 1: 
			mdeg = 60;
			 break;
		case 2:
			mdeg = 90;
			 break;
		case 3:
			mdeg = 120;
		 	 break;
		}/*end of switch*/
		drawPacman(dx, dy, mdeg, *direction);
		waitAndGetDirection(150, direction);
	}/*end of for*/
}
/*function for clearing pacmans previous cell*/
void clearCell(int x, int y) {
	x = x*CELL_WIDTH;
	y = y*CELL_WIDTH / 2;
	gotoxy(x+ 1, y+1);/*go to pacmans location and print space instead of pacman*/
	for (int i = 0; i <= 2*PACMAN_RADIUS; i++) {
		for (int j = 0; j <= 4*PACMAN_RADIUS;j++) {
			printf(" ");
	}/*end of for*/
		y++;
		gotoxy(x + 1, y + 1);
}/*end of for*/
}
/*function for changing location*/
void setNextLocation(int *dx, int *dy, char direction, int table[][COLUMN_PER_TABLE + 1][2]) {
		switch (direction) {
		case 'R':
			if (table[*dy][(*dx)+1][1] == 0)/*change loacaton if there isn't a wall*/
				(*dx)++;
			break;
		case 'L':
			if (table[*dy][*dx][1] == 0)/*change loacaton if there isn't a wall*/
				(*dx)--;
			break;
		case 'U':
			if (table[*dy][*dx][0] == 0)/*change loacaton if there isn't a wall*/
				(*dy)--;
			break;
		case 'D':
			if (table[(*dy)+1][*dx ][0] == 0)/*change loacaton if there isn't a wall*/
				(*dy)++;
			break;
		}/*end of switch*/
}
/*function for adding score*/
void addscore(int dx, int dy, int *score, int scoretable[COLUMN_PER_TABLE][ROWS_PER_TABLE]) {
	if (scoretable[dx][dy] == 0) {/*add score if pacman enters a cell it hasn't entered before*/
		 (*score)++;
		 scoretable[dx][dy] = 1;
		 gotoxy(COLUMN_PER_TABLE*CELL_WIDTH + 8, 0);/*print the score next to the table*/
		 printf("%d", *score);
	}
}