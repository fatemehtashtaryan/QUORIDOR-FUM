#include "subcodes.h"

void reduction_wood(){
     int n =0;
       if(tloop ==2){
         for(Row = 0; Row <= TotalRows ; Row++){
            for(Column = 0; Column <= TotalColumn; Column++){
                if(board[Row][Column]==1000){
                    board[Row][Column]=0;
                    n++;
                }
            }
         }
         horizontalsticks1==primaryhorizontalsticks1;
         verticalsticks1=primaryverticalsticks1;
       }
       else if(tloop==1){
         for(Row = 0; Row <= TotalRows ; Row++){
            for(Column = 0; Column <= TotalColumn; Column++){
                if(board[Row][Column]==2000){
                    board[Row][Column]=0;
                    n++;
                }
            }
         }
         horizontalsticks2==primaryhorizontalsticks2;
         verticalsticks2=primaryverticalsticks2;
       }
       if(tloop==2&&n!=0) {gotoxy(19,x1-3+strlen(name_player_1)); printf("Sorry! Your sticks will be removed from the board.");}
       else if(tloop==1&&n!=0) {gotoxy(23,x2-3+strlen(name_player_2)); printf("Sorry! Your sticks will be removed from the board.");}
       else if(n==0&&tloop==2) {gotoxy(19,x1-3+strlen(name_player_1)); printf("You're LUCKY! you don't have any sticks on board to remove");}
       else if(n==0&&tloop==1) {gotoxy(23,x2-3+strlen(name_player_2)); printf("You're LUCKY! you don't have any sticks on board to remove");}
}

void roadblock(){
    spell=0;
    Sw_rand_putstick=0;
    int num_turn;
    num_turn=turn;
    if(tloop==2) turn=1;
    else turn = 1;
    int road_row, road_column, road_wood, road_vertical, road_horizontal, road_answer=0;
    if(turn == 1){
        road_row=row1; road_column=column1;
        road_wood=1000;
        road_horizontal=horizontalsticks1;
        road_vertical=verticalsticks1;
    }
    else{
        road_row=row2, road_column=column2;
        road_wood=2000;
        road_horizontal=horizontalsticks2;
        road_vertical=verticalsticks2;
    }
    if(board[road_row-2][road_column+4]!=road_wood && road_horizontal!=0 && road_row-2 !=0){//up_wood
        coordRow=road_row-2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('h');
    }
    if(road_answer==0 && board[road_row+2][road_column+4]!=road_wood && road_horizontal!=0 &&road_row+2!=TotalRows-1){//down_wood
        coordRow=road_row+2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('h');
    }
    if(road_answer==0 && board[road_row+2][road_column+4]!=road_wood && road_vertical!=0 && road_column+4!=0){//right_wood
        coordRow=road_row+2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('v');
    }
    if(road_answer==0 && board[road_row+2][road_column-4]!=road_wood && road_vertical!=0 && road_column-4 != TotalColumn-2){//left_wood
        coordRow=road_row+2;
        coordcolumn=road_column-4;
        road_answer=CheckSticksPlayers('v');
    }
    if(road_answer==0 && board[road_row-2][road_column-4]!=road_wood && road_horizontal!=0 && road_row-2 !=0){//up_wood
        coordRow=road_row-2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('h');
    }
    if(road_answer==0 && board[road_row+2][road_column-4]!=road_wood && road_horizontal!=0 && road_row+2!=TotalRows-1){//down_wood
        coordRow=road_row+2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('h');
    }
    if(road_answer==0 && board[road_row-2][road_column+4]!=road_wood && road_vertical!=0 && road_column+4!=0){//right_wood
        coordRow=road_row-2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('v');
    }
    if(road_answer==0 && board[road_row-2][road_column-4]!=road_wood && road_vertical!=0 && road_column-4 != TotalColumn-2){//left_wood
        coordRow=road_row-2;
        coordcolumn=road_column-4;
        road_answer=CheckSticksPlayers('v');
    }
    if(tloop==2 && road_answer==1) {setTextColor (4,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("your way block!");}
    else if(tloop==1&& road_answer==1) {setTextColor (4,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("your way block!");}
    else if(tloop==2 && road_answer==0){setTextColor (2,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("Your path cannot be blocked!!");}
    else if(tloop==1 && road_answer==0) {setTextColor (2,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("Your path cannot be blocked!!");}
    spell=1;
    turn = num_turn;
}

int reset(){
      for(int i=2 ; i<=TotalRows-2 ; i++ ){
         for(int j=1; j<=TotalColumn-2 ; j++){
                if(board[i][j]==1000 || board[i][j]==2000 || board[i][j]==200 || board[i][j]==300){
                    board[i][j]=0;
                }
         }
      }
      board[2][primarycolumn2]=300;
      column2=primarycolumn2;
      board[primaryrow1][primarycolumn1]=200;
      column1=primarycolumn1;
      row1=primaryrow1;
      row2=2;
      verticalsticks1 = primaryverticalsticks1;
      verticalsticks2 = primaryverticalsticks2;
      horizontalsticks1 = primaryhorizontalsticks1;
      horizontalsticks2 = primaryhorizontalsticks2;
      if(tloop==2) {gotoxy(19,x1-3+strlen(name_player_1)); printf("Board game is resetting!");}
      else {gotoxy(23,x2-3+strlen(name_player_2)); printf("Board game is resetting!");}
      return 0;
   }

int decrease_sticks_player(){
     int typesticks,number;
     int horizontalsticks, verticalsticks;
     if(tloop==2){
        if(horizontalsticks1==0 && verticalsticks1==0){
            gotoxy(19,x1-3+strlen(name_player_1)); printf("You have no wood to reduce!");
            return 0;
        }
        horizontalsticks=horizontalsticks1;
        verticalsticks=verticalsticks1;
     }else{
         if(horizontalsticks2==0 && verticalsticks2==0){
            gotoxy(23,x2-3+strlen(name_player_2)); printf("You have no wood to reduce!");
            return 0;
        }
        horizontalsticks=horizontalsticks2;
        verticalsticks=verticalsticks2;
     }
      srand(time(0));
      typesticks = rand()%100+1;//H or V
      number = rand()%2+1;
      if(typesticks%2==0 && horizontalsticks>=number || verticalsticks==0){
        if(tloop==2){
             horizontalsticks1 -= number;
        }else{
              horizontalsticks2 -= number;
            }
      }else if(typesticks%2==0 && horizontalsticks==1 ){
             if(tloop==2){
             horizontalsticks1 -= 1;
             }else{
                horizontalsticks2 -= 1;
            }
            number=1;
      }
      if(typesticks%2==1 && verticalsticks>=number || horizontalsticks==0 ){
         if(tloop==2){
               verticalsticks1 -= number;
        }else{
               verticalsticks2 -= number;
            }
      }else if(typesticks%2==1 && verticalsticks==1 ){
          if(tloop==2){
                verticalsticks1 -= 1;
          }else{
                verticalsticks2 -= 1;
               }
               number=1;
      }
      if(tloop==2) {gotoxy(19,x1-3+strlen(name_player_1)); printf("you lose %d stick!", number);}
      else if(tloop==1) {gotoxy(23,x2-3+strlen(name_player_2)); printf("you lose %d stick!", number);}
      return 1;
}

