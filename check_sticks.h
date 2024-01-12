#ifndef check_sticks.h
#define check_sticks.h

#include "subcodes.h"
//this file about check sticks and DFS

//////////////////////////////////////////// search to find visited houses for DFS to avoid going to duplicate houses
int SearchVisitHouse( int RowDestination , int ColumnDestination ){
    int i;
    for(i = 0; i < house.coordinatesNo ; i++){
        if(house.location[i].row == RowDestination && house.location[i].column == ColumnDestination){
            return 1; //find the house thats visited it before
        }
    }
        return 0; //cant find house in list
}
//////7>>end vertical walls of the board/8>>end horizontal walls of the board/1000>>name stick first player/2000>>name stick second player
int DFS_Players(int  Row, int Column, int RowDestination, int ColumnDestination){
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
       if( SearchVisitHouse( RowDestination , ColumnDestination )== 0){   //search in visited list
           house.location[house.coordinatesNo].row=RowDestination;        //join coords of new house to visited houses
           house.location[house.coordinatesNo].column=ColumnDestination;
           house.coordinatesNo++;
            //checking the right neighborhood
            if(board[RowDestination][ColumnDestination+3] == 7 || board[RowDestination][ColumnDestination+4] == 1000 || board[RowDestination][ColumnDestination+4] == 2000 ){
                 if((board[RowDestination-2][ColumnDestination] == 1000 || board[RowDestination-2][ColumnDestination] == 2000) && (board[RowDestination+2][ColumnDestination] == 1000 || board[RowDestination+2][ColumnDestination] == 2000)){
                    if(lastrow!=1)return 0; //if it has no way to move
                 }
            }
            else {
                 DFS_Players(RowDestination,ColumnDestination,RowDestination,ColumnDestination+8); //move right
            }
            //checking the left neighborhood
            if(board[RowDestination][ColumnDestination-3] == 7 || board[RowDestination][ColumnDestination-4] == 1000 || board[RowDestination][ColumnDestination-4] == 2000){
                 if((board[RowDestination-2][ColumnDestination] == 1000 || board[RowDestination-2][ColumnDestination] == 2000)&&(board[RowDestination+2][ColumnDestination] == 1000||board[RowDestination+2][ColumnDestination] == 2000)){
                     if(lastrow!=1) return 0;//if it has no way to move
                }
            }
            else {

                 DFS_Players(RowDestination,ColumnDestination,RowDestination,ColumnDestination-8); //move left
             }
              //checking the above neighborhood
            if(board[RowDestination-2][ColumnDestination] == 1000 || board[RowDestination-2][ColumnDestination] == 8 || board[RowDestination-2][ColumnDestination] == 2000  ){
                    if(board[RowDestination+2][ColumnDestination] == 1000 || board[RowDestination+2][ColumnDestination] == 2000){
                        if(lastrow!=1)return 0;//if it has no way to move
                    }
                }
            else {

                   DFS_Players(RowDestination,ColumnDestination,RowDestination-4,ColumnDestination); //move up
            }
              //checking the below neighborhood
            if(board[RowDestination+2][ColumnDestination] == 1000 || board[RowDestination+2][ColumnDestination] == 8 || board[RowDestination+2][ColumnDestination] == 2000){
                 if(board[RowDestination-2][ColumnDestination] == 1000 || board[RowDestination-2][ColumnDestination] == 2000){
                   if(lastrow!=1)return 0;//if it has no way to move
                }
            }
            else{
                 DFS_Players(RowDestination,ColumnDestination,RowDestination+4,ColumnDestination); //move down
            }
		}else { // when find the house in visited houses , back to previous coords
		     RowDestination = Row;
		    ColumnDestination = Column;
          return 0;
		}
    }
}

int CheckSticksPlayers(char TypeStick){
    int x ; //for gotoxy function
    if(size_board>12) x = 10 ;
    else x = 15 ;

	int ansDFSplayer1, ansDFSplayer2, i;
	int stick, horizontalsticks, verticalsticks;
	int RowDestination, ColumnDestination; //for DFS
	if ( turn ==1){
        stick=1000;
        horizontalsticks=horizontalsticks1;
        verticalsticks=verticalsticks1;
	}else{//turn == 2 OR turn == 3
         stick=2000;
         horizontalsticks=horizontalsticks2;
         verticalsticks=verticalsticks2;
	}
	///////////////////////////////////////////////////////////////////Check number of sticks
	if(turn != 3 && turn != 4){
            if(TypeStick=='H' || TypeStick=='h'  ){
                if(horizontalsticks==0){
                      setTextColor(12, colorscreen);
                      gotoxy(x,38);
                      printf("Your number of horizontal sticks is 0");
                      setTextColor(0, colorscreen);
                    return 0;
                }
            }else{
                if(verticalsticks==0){
                      setTextColor(12, colorscreen);
                      gotoxy(x,40);
                      printf("Your number of vertical sticks is 0");
                      setTextColor(0, colorscreen);
                     return 0;
                }
            }
	}
	if(TypeStick == 'H' || TypeStick == 'h'  ){
        horizontalsticks--;
	}else{
        verticalsticks--;
	}
	////////////////////////////////////////////////////////////
	if(turn != 3 && turn != 4){
	   printf("\nEnter the name of the line where you want the stick to be placed!");
       rowlocation=getch();
	   while(rowlocation<'A' || (rowlocation>'A'+size_board-2 && rowlocation<'a') || rowlocation>'a'+size_board-2){
           beep(500, 100);
           rowlocation=getch();
	   }
	   columnlocation=getch();
	   printf("\nEnter the name of the column where you want the stick to be placed!!");
	   while(columnlocation<'A' || (columnlocation>'A'+size_board-2 && columnlocation<'a') || columnlocation>'a'+size_board-2){
           beep(500, 100);
           columnlocation=getch();
	   }
	}
    if(rowlocation>='a') rowlocation-=32;
    if(columnlocation >= 'a') columnlocation -= 32;
    ///////////////////////////////convert the position of stick to org coord
    coordRow=((int)rowlocation-64)*4;
	coordcolumn=((int)columnlocation-64)*8-1;
    ////////////////////////////////////check full
    if(TypeStick == 'H' || TypeStick == 'h'){
        if(board[coordRow][coordcolumn] == 1000 || board[coordRow][coordcolumn+3] == 1000 || board[coordRow][coordcolumn-3] == 1000 || board[coordRow][coordcolumn] == 2000 || board[coordRow][coordcolumn+3] == 2000 || board[coordRow][coordcolumn-3] == 2000){
            if( turn != 3 && turn != 4){
                gotoxy(x,44);
               setTextColor(12, colorscreen);
               printf("(%c,%c) is full!",rowlocation,columnlocation);
               setTextColor(0, colorscreen);
            }
            return 0;
        }
    }
    else if(board[coordRow][coordcolumn] == 1000 || board[coordRow-2][coordcolumn] == 1000 || board[coordRow+2][coordcolumn] == 1000 || board[coordRow][coordcolumn] == 2000 || board[coordRow-2][coordcolumn]==2000 || board[coordRow+2][coordcolumn] == 2000){
            if( turn != 3 && turn != 4){
               setTextColor(12, colorscreen);
               gotoxy(x,44);
               printf("(%c,%c) is full!",rowlocation,columnlocation);
               setTextColor(0, colorscreen);
            }
            return 0;
    }
    /////////////////////////////////////////////////////////////// START DFS
	    house.coordinatesNo = 0;
		if(TypeStick == 'H' || TypeStick == 'h' ){ /////////ASSUMED WOOD
		for(i = coordcolumn-6 ; i <= coordcolumn+6 ;i++){
				board[coordRow][i]=stick;
		}
        }else{
		for(i = coordRow-3 ; i <= coordRow+3; i++){
				board[i][coordcolumn] = stick;
		}
    }
    ///////////////////////////////////////////// find a neighborhood player 1
        if(board[row1-2][column1] != 1000 && board[row1-2][column1] != 8 && board[row1-2][column1] !=2000 ){ //up
            RowDestination=row1-4;
            ColumnDestination=column1;
        }else if(board[row1][column1+4]!=1000 && board[row1][column1+3]!=7 && board[row1][column1+4]!=2000){ //right
            RowDestination=row1;
            ColumnDestination=column1+8;
        }else if(board[row1][column1-4]!=1000 && board[row1][column1-3]!=7 && board[row1][column1-4]!=2000){ //left
            RowDestination=row1;
            ColumnDestination=column1-8;
        }else if(board[row1+2][column1]!=1000 && board[row1+2][column1]!=8 && board[row1+2][column1]!=2000){ //down
             RowDestination=row1+4;
            ColumnDestination=column1;
        }
        /////////////////////////////////////////check DFS player 1
        DFplayer=1;
        lastrow=0;
		ansDFSplayer1=DFS_Players(row1, column1, RowDestination,ColumnDestination);
		printf("%d", ansDFSplayer1);
        sleep(600);
        if(lastrow==1){
            ansDFSplayer1=1;
        }else{
            ansDFSplayer1=0;
        }

       ///////////////////////////////////////////// find a neighborhood player 2
        if(board[row2-2][column2]!=1000 && board[row2-2][column2]!=8 && board[row2-2][column2]!=2000){ //up
            RowDestination=row2-4;
            ColumnDestination=column2;
        }else if(board[row2][column2+4]!=1000 && board[row2][column2+3]!=7 && board[row2][column2+4]!=2000){ //right
            RowDestination=row2;
            ColumnDestination=column2+8;
        }else if(board[row2][column2-4]!=1000 && board[row2][column2-3]!=7 && board[row2][column2-4]!=2000 ){ //left
            RowDestination=row2;
            ColumnDestination=column2-8;
        }else if(board[row2+2][column2]!=1000 && board[row2+2][column2]!=8 && board[row2+2][column2]!=2000 ){ //down
             RowDestination=row2+4;
            ColumnDestination=column2;
        }
          ////////////////////////////////////////check DFS player 2
        house.coordinatesNo=0;
        DFplayer=2;
        lastrow=0;
        ansDFSplayer2=DFS_Players(row2,column2,RowDestination,ColumnDestination);
        printf("%d", ansDFSplayer2);
        sleep(600);
        if(lastrow==1){
            ansDFSplayer2=1;
        }else{
            ansDFSplayer2=0;
        }
        lastrow = 0 ;
        ///////////////////////////////////////////////////// close roads
		if(ansDFSplayer1 == 0 || ansDFSplayer2 == 0){
            if( turn != 3  && turn != 4){
			   gotoxy(x,35);
			   setTextColor(12, colorscreen);
			   printf("By putting stick in (%c,%c) you will close all the roads!",rowlocation,columnlocation);
			   setTextColor(0, colorscreen);
            }
			/////////////////////////////////////////// remove assumed wood
            if(TypeStick == 'H' || TypeStick == 'h' ){
                for(i = coordcolumn-6; i <= coordcolumn+6; i++){
                    board[coordRow][i]=0;
                }
            }else{
                for(i=coordRow-3 ; i<=coordRow+3 ; i++){
                    board[i][coordcolumn]=0;
            }
        }
        return 0;
        ///////////////////////////////////////////////////
		}
		if(ansDFSplayer1 == 1 && ansDFSplayer2 == 1){ //ok all of things
        /////////
          if(turn == 4){
            if(TypeStick == 'H' || TypeStick == 'h' ){
                for(i = coordcolumn-6; i <= coordcolumn+6; i++){
                    board[coordRow][i]=0;
                }
            }else{
                for(i=coordRow-3 ; i<=coordRow+3 ; i++){
                    board[i][coordcolumn]=0;
                }
            }
          }
        /////////
          else if(turn == 1){
              if(TypeStick == 'H' || TypeStick == 'h'){ horizontalsticks1--; stick_movement_h_full[(int)rowlocation-65][(int)columnlocation-65] = 2; stick_movement_v_full[(int)rowlocation-65][(int)columnlocation-65] = 2; stick_movement_h_full[(int)rowlocation-65][(int)columnlocation-65-1] = 2;
              stick_movement_h_full[rowlocation-65][columnlocation-65+1] = 2;}
             else {verticalsticks1--; stick_movement_v_full[(int)rowlocation-65][(int)columnlocation-65] = 2; stick_movement_h_full[(int)rowlocation-65][(int)columnlocation-65] = 2; stick_movement_v_full[(int)rowlocation-65-1][(int)columnlocation-65] = 2; stick_movement_v_full[(int)rowlocation-65+1][(int)columnlocation-65] = 2;}
         }
        ////////
         else{
            if(TypeStick == 'H' || TypeStick == 'h') {horizontalsticks2--; stick_movement_h_full[(int)rowlocation-65][(int)columnlocation-65] = 2; stick_movement_v_full[(int)rowlocation-65][(int)columnlocation-65] = 2; stick_movement_h_full[(int)rowlocation-65][(int)columnlocation-65-1] = 2;
            stick_movement_h_full[rowlocation-65][columnlocation-65+1] = 2;}
            else {verticalsticks2--; stick_movement_v_full[(int)rowlocation-65][(int)columnlocation-65] = 2; stick_movement_h_full[(int)rowlocation-65][(int)columnlocation-65] = 2; stick_movement_v_full[(int)rowlocation-65-1][(int)columnlocation-65] = 2; stick_movement_v_full[(int)rowlocation-65+1][(int)columnlocation-65] = 2;}
         }
        ////////
		    return 1;
		}

}
#endif // check_sticks
