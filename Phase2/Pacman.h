/*parisa pourmand 810196601*/
#include <windows.h>
#include <conio.h>

#define PACMAN_RADIUS 5
#define ROWS_PER_TABLE 5
#define COLUMN_PER_TABLE 6
#define CELL_WIDTH 24

//Sets console screen to full screen
void initScreen();
//The following function manipulates cursor position
void gotoxy(int x, int y);
//This function will wait for "waitTime" milliseconds and get the new direction from the keybord
//100<waitTime<250 
//Use this function between printing the pacman shapes in a single cell
//If the direction is changed the return value is 1 else the return value is 0
int waitAndGetDirection(int waitTime, char *direction);

//This function draws pacman
void drawPacman(int dx, int dy, int mouthDegree, char direction);
//This function clears the cell pacman leaves
void clearCell(int x, int y);
//This function opens pacmans mouth
void drawOpeningMouthPacman(int dx, int dy, char *direction);
//This function sets pacmans next location
void setNextLocation(int *dx, int *dy, char direction, int table[][COLUMN_PER_TABLE + 1][2]);
//This function shows pacmans score
void addscore(int dx, int dy, int *score, int scoretable[COLUMN_PER_TABLE][ROWS_PER_TABLE]);

