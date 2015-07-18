test.c


				if(Bnum>9) Bnum=-1;
				Bnum++;
				xposB[Bnum] = drawBullet(xposS);





		if(Bnum != -1){
			for(i=0;i<Bnum;i++){
				dy[i] += 2;
				
				if(xposB[i] != -1){
					moveBullet(xposB[i], dy[i]);
					if(dy[i] >=475){
						dy[i] = 0;
						Bnum--;
						xposB[i] = -1;
					}
				}
			}
		}



	/*if (count<10) return 2;
	else if (count>10){
		 if (*count>20){
		 count = 0;
		}
		 return 1;
	}*/

//	gfx_ellipse(posS[0], posS[1], 33, 15);
	/*for(i=0;i<33;i++){
		for(j=0;j<15;j++){
			gfx_ellipse(posS[0], posS[1], i, j);	
		}
	}*/


for(i=45;i>=1;i-=11){


	}
	for(i=46;i>=2;i-=11){


	}
	for(i=47;i>=3;i-=11){


	}
	for(i=48;i>=4;i-=11){


	}
	for(i=49;i>=5;i-=11){


	}
	for(i=50;i>=6;i-=11){


	}
	for(i=51;i>=7;i-=11){


	}
	for(i=52;i>=8;i-=11){


	}
	for(i=53;i>=9;i-=11){


	}
	for(i=54;i>=10;i-=11){


	}
