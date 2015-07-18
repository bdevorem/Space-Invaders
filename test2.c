//Breanna DeVore-McDonald and Katie Quinn
//Ramzi Bualuan
//CSE 20211.01
//14 December 2014
//final.c

#include "gfx3.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define SIZEY 500
#define SIZEX 800
#define YPOS 475

void uShooter(int xposS);
void drawAliens(int xdist, int ydist);
int drawBullet(int xposS);//returns x value
void moveBullet(int posB[2][10], int j);
void initializeBullets(int posB[2][10]);
void dispScore(void); // to be edited later to actually show the score
// need a live counter function
void checkBullet(int posB[2][10],int i); //check if bullet is past y direction

int main(){
	int xposS = 370;
	char c; //user input
	int xdist = 0, ydist =0;
	int dx = 1;
	int Bnum = 0;
	int posB[2][10] = {0};
	unsigned int i, j;

	gfx_open(SIZEX, SIZEY, "Space Invaders"); //open window
	initializeBullets(posB);
	
	while(true){
		gfx_clear(); //clear screen

		dispScore();

		uShooter(xposS);
		drawAliens(xdist, ydist);

		if(gfx_event_waiting()){ //if true
			c = gfx_wait(); //find choice
			if (c == 'b'){
				xposS-=10;
				if (xposS <= 0) xposS = 0;
			}else if (c == 'n'){
				xposS +=10;
				if (xposS >= SIZEX-30) xposS = SIZEX-30;
			}else if (c == ' '){
				for(i=0; i<10; i++){
					if(posB[0][i] == -1){
						posB[0][i] = drawBullet(xposS);
						posB[1][i] = YPOS;
					}
				}
			}else if (c == 'q') return 0;		
			else continue;
			
		}
		
		xdist+=dx;

		if(xdist>=370 || xdist <=-100){
			dx*=-1;
		}
		if(xdist == 370 || xdist ==-100){
			ydist +=5;
		}
		if(ydist == 225) return 0; //change lives num	

		
		for(j=0; j<10; j++){
			if(posB[0][j] != -1){
				moveBullet(posB, j);	
			}
			checkBullet(posB,j);
		}



		usleep(25000);
		gfx_flush();
	}
}

void initializeBullets(int posB[2][10]){
	unsigned int i,j;

	for(i=0; i<2; i++){
		for(j=0;j<10;j++){
			posB[i][j] = -1;
		}
	}
}

int drawBullet(int xposS){ //return x pos of B
	gfx_line(xposS, YPOS, xposS, YPOS-3); //might have to change
	return xposS +15;
}

void moveBullet(int posB[2][10], int j){
	int temp = posB[1][j]-3;
	gfx_line(posB[0][j], posB[1][j], posB[0][j], temp);
	posB[1][j] = temp;
	gfx_flush();
}

void checkBullet(int posB[2][10],int i){ //check if bullet is past y direction
	if(posB[1][i] <= 0){
		posB[0][i] = -1;
		posB[1][i] = -1;
	}
}

void drawAliens(int xdist, int ydist){
	int aliens[2][55] = {};
	unsigned int i, j;

	//hard code y values
	for(i=0; i<=10; i++){
		aliens[0][i] = 100 + ydist;

	}
	for(i=11; i<=21; i++){
		aliens[0][i] = 100 + ydist+30;

	}
	for(i=22; i<=32; i++){
		aliens[0][i] = 100 + ydist+ 2 * 30;

	}
	for(i=33; i<=43; i++){
		aliens[0][i] = 100 + ydist+ 3 *30;

	}
	for(i=44; i<=54; i++){
		aliens[0][i] = 100 + ydist + 4*30;

	}

	// hard code x values
	//now prints row by row in case we want to switch up the colors
	for(i=0; i<=10; i++){
		aliens[1][i] = 100 + xdist + 30*i;
		gfx_color(255,255,255);//White (classic game)
		gfx_fill_rectangle(aliens[1][i], aliens[0][i], 20, 20);// print the first row
	}
	for(i=11; i<=21; i++){
		aliens[1][i] = 100 + xdist + 30 * (i-11);
		gfx_fill_rectangle(aliens[1][i], aliens[0][i], 20, 20);//print the second row
	}
	for(i=22; i<=32; i++){
		aliens[1][i] = 100 + xdist + 30 * (i-22);
		gfx_fill_rectangle(aliens[1][i], aliens[0][i], 20, 20);

	}
	for(i=33; i<=43; i++){
		aliens[1][i] = 100 + xdist + 30 * (i-33);
		gfx_fill_rectangle(aliens[1][i], aliens[0][i], 20, 20);

	}
	for(i=44; i<=54; i++){
		aliens[1][i] = 100 + xdist + 30 * (i-44);
		gfx_fill_rectangle(aliens[1][i], aliens[0][i], 20, 20);

	}
	

}

void uShooter(int xposS){
	gfx_color(24, 238, 0);
	gfx_fill_rectangle(xposS, YPOS, 30, 12);
	gfx_fill_rectangle(xposS+4,YPOS-2,23,2);// CHANGED BY KATIE TO MAKE SHIP
	gfx_fill_rectangle(xposS+12,YPOS-7,6,5);// FEEL FREE TO CHANGE ANYTHING
	gfx_fill_rectangle(xposS+14,YPOS-9,2,2);
}

void dispScore(void){
	gfx_color(24, 238, 0);
	gfx_text(3,10,"SCORE");//to be used to display score
	gfx_fill_rectangle(0,498,800,2);
}

