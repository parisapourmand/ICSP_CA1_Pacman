/*parisa pourmand*/
#include <stdio.h>
#include <math.h>
void pacman(int r, float deg,char drc){
	 deg = deg* 3.14 / 180;
	int  i, j;
	switch (drc) {/*draw pacman according to the direction*/
	case'D': {for (i = -r; i <= r; i++) {
		for (j = -r; j <= r; j++) {
			if (i*i + j*j < r*r && (i*tan(deg / 2) <=j  || j <= -i*tan(deg / 2)))
				printf("#");
			else
				printf(" ");/*end of if*/
		}printf("\n");
	}
			 break; }
	case'U': {for (i = -r; i <= r; i++) {
		for (j = -r; j <= r; j++) {
			if (i*i + j*j < r*r && (i*tan(deg / 2)>=j  || j>= -i*tan(deg / 2)))
				printf("#");
			else
				printf(" ");
		}/*end of if*/
		printf("\n");
	}
			 break;
	}
	case'R': { for (i = -r; i <= r; i++) {
		for (j = -r; j <= r; j++) {
			if (i*i + j*j < r*r && (j*tan(deg / 2)<=i || i<= -j*tan(deg / 2)))
				printf("#");
			else
				printf(" ");
		}/*end of if*/
		printf("\n");
	}
			 break;
	}

	case'L': {for (i = -r; i <= r; i++) {
		for (j = -r; j <= r; j++) {
			if (i*i + j*j < r*r && (j*tan(deg / 2)>=i || i>= -j*tan(deg / 2)))
				printf("#");
			else
				printf(" ");
		}/*end of if*/
		printf("\n");
	}
			 break;
	}
	default: {/*error for wrong input direction*/
		printf("The direction is invalid.\n"); }
	}/*end of switch(drc)*/
}