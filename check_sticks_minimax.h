#ifndef check_sticks_minimax.h
#define check_sticks_minimax.h

#include "subcodes.h"
//this file about check sticks and DFS
int i;
//////////////////////////////////////////// search to find visited houses for DFS to avoid going to duplicate houses
int SearchVisitHouse_minimax( int RowDestination , int ColumnDestination ){
    int i;
    for(i = 0; i < house.coordinatesNo ; i++){
        if(house.location[i].row == RowDestination && house.location[i].column == ColumnDestination){
            return 1; //find the house thats visited it before
        }
    }
        return 0; //cant find house in list
}
//////7>>end vertical walls of the board/8>>end horizontal walls of the board/1000>>name stick first player/2000>>name stick second player
int DFS_Players_minimax(int  Row, int Column, int RowDestination, int ColumnDestination){
    int lastline;
    if(DFplayer == 1){
        lastline = 2;
    }else{
        lastline = TotalRows-3;
    }
    if(RowDestination == lastline || lastrow == 1 ){ //lastrow is a variable to undrestand reaching the last row
            lastrow = 1;
			return 1; //if it has way to move
	}else  {
       if( SearchVisitHouse_minimax( RowDestination , ColumnDestination )== 0){   //search in visited list
           house.location[house.coordinatesNo].row=RowDestination;        //join coords of new house to visited houses
           house.location[house.coordinatesNo].column=ColumnDestination;
           house.coordinatesNo++;
            //checking the right neighborhood
            if(copy_board.copyboard[RowDestination][ColumnDestination+3] == 7 || copy_board.copyboard[RowDestination][ColumnDestination+4] == 1000 || copy_board.copyboard[RowDestination][ColumnDestination+4] == 2000 ){
                 if((copy_board.copyboard[RowDestination-2][ColumnDestination] == 1000 || copy_board.copyboard[RowDestination-2][ColumnDestination] == 2000) && (copy_board.copyboard[RowDestination+2][ColumnDestination] == 1000 || copy_board.copyboard[RowDestination+2][ColumnDestination] == 2000) && (copy_board.copyboard[RowDestination][ColumnDestination-4] == 1000 || copy_board.copyboard[RowDestination][ColumnDestination-4] == 2000) ){
                    if(lastrow!=1)return 0; //if it has no way to move
                 }
            }
            else {
                 DFS_Players_minimax(RowDestination,ColumnDestination,RowDestination,ColumnDestination+8); //move right
            }
            //checking the left neighborhood
            if(copy_board.copyboard[RowDestination][ColumnDestination-3] == 7 || copy_board.copyboard[RowDestination][ColumnDestination-4] == 1000 || copy_board.copyboard[RowDestination][ColumnDestination-4] == 2000){
                 if((copy_board.copyboard[RowDestination-2][ColumnDestination] == 1000 || copy_board.copyboard[RowDestination-2][ColumnDestination] == 2000)&&(copy_board.copyboard[RowDestination+2][ColumnDestination] == 1000||copy_board.copyboard[RowDestination+2][ColumnDestination] == 2000)&& (copy_board.copyboard[RowDestination][ColumnDestination+4] == 1000 || copy_board.copyboard[RowDestination][ColumnDestination+4] == 2000)){
                     if(lastrow!=1) return 0;//if it has no way to move
                }
            }
            else {

                DFS_Players_minimax(RowDestination,ColumnDestination,RowDestination,ColumnDestination-8); //move left
             }
              //checking the above neighborhood
            if(copy_board.copyboard[RowDestination-2][ColumnDestination] == 1000 || copy_board.copyboard[RowDestination-2][ColumnDestination] == 8 || copy_board.copyboard[RowDestination-2][ColumnDestination] == 2000  ){
                    if(copy_board.copyboard[RowDestination+2][ColumnDestination] == 1000 || copy_board.copyboard[RowDestination+2][ColumnDestination] == 2000){
                        if(lastrow!=1)return 0;//if it has no way to move
                    }
                }
            else {

                DFS_Players_minimax(RowDestination,ColumnDestination,RowDestination-4,ColumnDestination); //move up
            }
              //checking the below neighborhood
            if(copy_board.copyboard[RowDestination+2][ColumnDestination] == 1000 || copy_board.copyboard[RowDestination+2][ColumnDestination] == 8 || copy_board.copyboard[RowDestination+2][ColumnDestination] == 2000){
                 if(copy_board.copyboard[RowDestination-2][ColumnDestination] == 1000 || copy_board.copyboard[RowDestination-2][ColumnDestination] == 2000){
                   if(lastrow!=1)return 0;//if it has no way to move
                }
            }
            else{
                DFS_Players_minimax(RowDestination,ColumnDestination,RowDestination+4,ColumnDestination); //move down
            }
		}else { // when find the house in visited houses , back to previous coords
		     RowDestination = Row;
		    ColumnDestination = Column;
            return 0;
		}
    }
}

int CheckSticksPlayers_minimax(char TypeStick,int Row1 ,int Column1, int Row , int Column ){
	int ansDFSplayer1, ansDFSplayer2, i ,sw=1;
	int stick, horizontalsticks, verticalsticks;
	int RowDestination, ColumnDestination; //for DFS
	if (sw_minimax ==0){
        stick=1000;
        horizontalsticks=copy_board.copyverticalsticks1;
        verticalsticks=copy_board.copyverticalsticks1;
	}else{//turn == 2 OR turn == 3
         stick=2000;
         horizontalsticks=copy_board.copyverticalsticks2;
         verticalsticks=copy_board.copyverticalsticks2;
	}
    ///////////////////////////////convert the position of stick to org coord
    coordRow=((int)rowlocation-64)*4;
	coordcolumn=((int)columnlocation-64)*8-1;
	//printf("coordRow=%d   coordcolumn=%d \n",coordRow,coordcolumn);
	//sleep(1000);
    ////////////////////////////////////check full
    if(TypeStick == 'h'){
        if(copy_board.copyboard[coordRow][coordcolumn] == 1000 || copy_board.copyboard[coordRow][coordcolumn+3] == 1000 || copy_board.copyboard[coordRow][coordcolumn-3] == 1000 || copy_board.copyboard[coordRow][coordcolumn] == 2000 || copy_board.copyboard[coordRow][coordcolumn+3] == 2000 || copy_board.copyboard[coordRow][coordcolumn-3] == 2000){
            return 0;
        }
    }
    else if(copy_board.copyboard[coordRow][coordcolumn] == 1000 || copy_board.copyboard[coordRow-2][coordcolumn] == 1000 || copy_board.copyboard[coordRow+2][coordcolumn] == 1000 || copy_board.copyboard[coordRow][coordcolumn] == 2000 || copy_board.copyboard[coordRow-2][coordcolumn]==2000 || copy_board.copyboard[coordRow+2][coordcolumn] == 2000){
            return 0;
    }
    /////////////////////////////////////////////////////////////// START DFS
	    house.coordinatesNo = 0;
		if(TypeStick == 'h' ){ /////////ASSUMED WOOD
            for(i = coordcolumn-6 ; i <= coordcolumn+6 ;i++){
                    copy_board.copyboard[coordRow][i]=stick;
            }
        }else{
            for(i = coordRow-3 ; i <= coordRow+3; i++){
				copy_board.copyboard[i][coordcolumn] = stick;
		}
    }
    ///////////////////////////////////////////// find a neighborhood player 1
        if(copy_board.copyboard[Row1-2][Column1] != 1000 && copy_board.copyboard[Row1-2][Column1] != 8 && copy_board.copyboard[Row1-2][Column1] !=2000 ){ //up
            RowDestination=Row1-4;
            ColumnDestination=Column1;
            sw=0;
        }
      /*   for(int Rowcopy = 0;  Rowcopy < TotalRows ;  Rowcopy++){
                for(int Columncopy = 0; Columncopy < TotalColumn ; Columncopy++){
                        if(copy_board.copyboard[ Rowcopy][Columncopy]==1000){
                            printf("*");
                        }else if(copy_board.copyboard[ Rowcopy][Columncopy]==2000){
                             printf("#");
                        }else if(copy_board.copyboard[ Rowcopy][Columncopy]==200){
                            printf("a");
                        }
                        else if(copy_board.copyboard[ Rowcopy][Columncopy]==300){
                            printf("b");
                        }else{
                             printf("%d", copy_board.copyboard[ Rowcopy][Columncopy]);

                        }
                }
                printf("\n");
            }*/
        //printf("=%d  %d",copy_board.copyboard[Row1][Column1+4],copy_board.copyboard[Row1][Column1+3]);
        if(copy_board.copyboard[Row1][Column1+4]!=1000 && copy_board.copyboard[Row1][Column1+3]!=7 && copy_board.copyboard[Row1][Column1+4]!=2000){ //right
            RowDestination=Row1;
            ColumnDestination=Column1+8;
            sw=0;
        }else if(copy_board.copyboard[Row1][Column1-4]!=1000 && copy_board.copyboard[Row1][Column1-3]!=7 && copy_board.copyboard[Row1][Column1-4]!=2000){ //left
            RowDestination=Row1;
            ColumnDestination=Column1-8;
            sw=0;
        }else if(copy_board.copyboard[Row1+2][Column1]!=1000 && copy_board.copyboard[Row1+2][Column1]!=8 && copy_board.copyboard[Row1+2][Column1]!=2000){ //down
             RowDestination=Row1+4;
            ColumnDestination=Column1;
            sw=0;
        }
        if(sw==1){
            if(TypeStick == 'h' ){
                for(i = coordcolumn-6; i <= coordcolumn+6; i++){
                    copy_board.copyboard[coordRow][i]=0;
                }
            }else{

                for(i=coordRow-3 ; i<=coordRow+3 ; i++){
                    copy_board.copyboard[i][coordcolumn]=0;
                }
            }
            return 0;
        }
        /////////////////////////////////////////check DFS player 1
        DFplayer=1;
        lastrow=0;
      /*  if(copy_board.copyboard[4][15]==1000 && copy_board.copyboard[4][7]==1000){
            printf("ggg");
        }*/
		ansDFSplayer1=DFS_Players_minimax(Row1, Column1, RowDestination,ColumnDestination);

        if(lastrow==1){
            ansDFSplayer1=1;
        }else{
            ansDFSplayer1=0;
        }
     //   printf("ans1=%d  ",ansDFSplayer1);


       ///////////////////////////////////////////// find a neighborhood player 2
        if(copy_board.copyboard[Row-2][Column]!=1000 && copy_board.copyboard[Row-2][Column]!=8 && copy_board.copyboard[Row-2][Column]!=2000){ //up
            RowDestination=Row-4;
            ColumnDestination=Column;
            sw=0;
        }else if(copy_board.copyboard[Row][Column+4]!=1000 && copy_board.copyboard[Row][Column+3]!=7 && copy_board.copyboard[Row][Column+4]!=2000){ //right
            RowDestination=Row;
            ColumnDestination=Column+8;
            sw=0;
        }else if(copy_board.copyboard[Row][Column-4]!=1000 && copy_board.copyboard[Row][Column-3]!=7 && copy_board.copyboard[Row][Column-4]!=2000 ){ //left
            RowDestination=Row;
            ColumnDestination=Column-8;
            sw=0;
        }else if(copy_board.copyboard[Row+2][Column]!=1000 && copy_board.copyboard[Row+2][Column]!=8 && copy_board.copyboard[Row+2][Column]!=2000 ){ //down
             RowDestination=Row+4;
            ColumnDestination=Column;
            sw=0;
        }
        if(sw==1){
            if(TypeStick == 'h' ){
                for(i = coordcolumn-6; i <= coordcolumn+6; i++){
                    copy_board.copyboard[coordRow][i]=0;
                }
            }else{

                for(i=coordRow-3 ; i<=coordRow+3 ; i++){
                    copy_board.copyboard[i][coordcolumn]=0;
                }
            }
            return 0;
        }
          ////////////////////////////////////////check DFS player 2
        house.coordinatesNo=0;
        DFplayer=2;
        lastrow=0;
        ansDFSplayer2=DFS_Players_minimax(Row,Column,RowDestination,ColumnDestination);

        if(lastrow==1){
            ansDFSplayer2=1;
        }else{
            ansDFSplayer2=0;
        }
       //printf("ans2=%d\n",ansDFSplayer2);

        lastrow = 0 ;
        /////////////////////////////////////////// remove assumed wood
        if(TypeStick == 'h' ){
                for(i = coordcolumn-6; i <= coordcolumn+6; i++){
                    copy_board.copyboard[coordRow][i]=0;
                }
        }else{

                for(i=coordRow-3 ; i<=coordRow+3 ; i++){
                    copy_board.copyboard[i][coordcolumn]=0;
            }
        }

        ///////////////////////////////////////////////////// close roads
		if(ansDFSplayer1 == 0 || ansDFSplayer2 == 0){
                return 0;
		}
        ///////////////////////////////////////////////////
             return 1;
}
#endif // check_sticks

