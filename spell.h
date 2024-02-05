#include "subcodes.h"

//This file spells : reduction_wood, roadblock, reset, decrease_sticks_player

void reduction_wood(){//for delete all the stick's player
     int n =0;
       if(tloop ==4){//for player 1
         for(Row = 0; Row <= TotalRows ; Row++){//deleting all wood
            for(Column = 0; Column <= TotalColumn; Column++){
                if(board[Row][Column]==1000){
                    board[Row][Column]=0;
                    n++;
                }
            }
         }
         horizontalsticks1=primaryhorizontalsticks1;
         verticalsticks1=primaryverticalsticks1;
       }
       else if(tloop==3){//for player 2
         for(Row = 0; Row <= TotalRows ; Row++){//deleting all wood
            for(Column = 0; Column <= TotalColumn; Column++){
                if(board[Row][Column]==2000){
                    board[Row][Column]=0;
                    n++;
                }
            }
         }
         horizontalsticks2=primaryhorizontalsticks2;
         verticalsticks2=primaryverticalsticks2;
       }else if(tloop==2){//for player 3
         for(Row = 0; Row <= TotalRows ; Row++){//deleting all wood
            for(Column = 0; Column <= TotalColumn; Column++){
                if(board[Row][Column]==3000){
                    board[Row][Column]=0;
                    n++;
                }
            }
         }
         horizontalsticks3=primaryhorizontalsticks3;
         verticalsticks3=primaryverticalsticks3;
       }else{//for player 4
         for(Row = 0; Row <= TotalRows ; Row++){//deleting all wood
            for(Column = 0; Column <= TotalColumn; Column++){
                if(board[Row][Column]==4000){
                    board[Row][Column]=0;
                    n++;
                }
            }
         }
         horizontalsticks4=primaryhorizontalsticks4;
         verticalsticks4=primaryverticalsticks4;
       }
       if(tloop==4&&n!=0) {gotoxy(19,x1-3+strlen(name_player_1)); printf("Sorry! Your sticks will be removed from the board.");}
       else if(tloop==3&&n!=0) {gotoxy(23,x2-3+strlen(name_player_2)); printf("Sorry! Your sticks will be removed from the board.");}
       else if(n==0&&tloop==4) {gotoxy(19,x1-3+strlen(name_player_1)); printf("You're LUCKY! you don't have any sticks on board to remove");}//if there wasn't any wood
       else if(n==0&&tloop==3) {gotoxy(23,x2-3+strlen(name_player_2)); printf("You're LUCKY! you don't have any sticks on board to remove");}//if there wasn't any wood
       else if(tloop==2&&n!=0) {gotoxy(27,x3-3+strlen(name_player_3)); printf("Sorry! Your sticks will be removed from the board.");}
       else if(tloop==1&&n!=0) {gotoxy(31,x4-3+strlen(name_player_4)); printf("Sorry! Your sticks will be removed from the board.");}
       else if(n==0&&tloop==2) {gotoxy(27,x3-3+strlen(name_player_3)); printf("You're LUCKY! you don't have any sticks on board to remove");}//if there wasn't any wood
       else if(n==0&&tloop==1) {gotoxy(31,x4-3+strlen(name_player_4)); printf("You're LUCKY! you don't have any sticks on board to remove");}//if there wasn't any wood
}

void roadblock(){//for blocking path for player
    spell=0;
    Sw_rand_putstick=0;
    int num_turn;
    num_turn=turn;//saving turn
    if(tloop==4) turn=1;
    else if(tloop==3) turn = 2;
    else if(tloop==2) turn = 3;
    else turn = 4;
    int road_row, road_column, road_wood, road_vertical, road_horizontal, road_answer=0;
    if(turn == 1){
        road_row=row1; road_column=column1;
        road_wood=1000;
        road_horizontal=horizontalsticks1;
        road_vertical=verticalsticks1;
    }
    else if(turn == 2){
        road_row=row2, road_column=column2;
        road_wood=2000;
        road_horizontal=horizontalsticks2;
        road_vertical=verticalsticks2;
    }
    else if(turn == 3){
        road_row=row3, road_column=column3;
        road_wood=3000;
        road_horizontal=horizontalsticks3;
        road_vertical=verticalsticks3;
    }
    else{
        road_row=row4, road_column=column4;
        road_wood=4000;
        road_horizontal=horizontalsticks4;
        road_vertical=verticalsticks4;
    }
    if(board[road_row-2][road_column+4]!=road_wood && road_horizontal!=0 && road_row-2 !=0 && road_column+4!=TotalColumn-2){//up_wood
        coordRow=road_row-2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('h');
    }
    if(road_answer==0 && board[road_row+2][road_column+4]!=road_wood && road_horizontal!=0 &&road_row+2!=TotalRows-1 && road_column+4!=TotalColumn-2){//down_wood
        coordRow=road_row+2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('h');
    }
    if(road_answer==0 && board[road_row+2][road_column+4]!=road_wood && road_vertical!=0 && road_column+4!=TotalColumn-2 && road_row+2!=TotalRows-1){//right_wood
        coordRow=road_row+2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('v');
    }
    if(road_answer==0 && board[road_row+2][road_column-4]!=road_wood && road_vertical!=0 && road_column-4 != 0 && road_row+2!=TotalRows-1){//left_wood
        coordRow=road_row+2;
        coordcolumn=road_column-4;
        road_answer=CheckSticksPlayers('v');
    }
    if(road_answer==0 && board[road_row-2][road_column-4]!=road_wood && road_horizontal!=0 && road_row-2 !=0 && road_column-4 != 0){//up_wood
        coordRow=road_row-2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('h');
    }
    if(road_answer==0 && board[road_row+2][road_column-4]!=road_wood && road_horizontal!=0 && road_row+2!=TotalRows-1 &&road_column-4 != 0){//down_wood
        coordRow=road_row+2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('h');
    }
    if(road_answer==0 && board[road_row-2][road_column+4]!=road_wood && road_vertical!=0 && road_column+4!=TotalColumn-3 && road_row-2 !=0){//right_wood
        coordRow=road_row-2;
        coordcolumn=road_column+4;
        road_answer=CheckSticksPlayers('v');
    }
    if(road_answer==0 && board[road_row-2][road_column-4]!=road_wood && road_vertical!=0 && road_column-4 != 0 && road_row-2 !=0){//left_wood
        coordRow=road_row-2;
        coordcolumn=road_column-4;
        road_answer=CheckSticksPlayers('v');
    }
    if(tloop==4 && road_answer==1) {setTextColor (4,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("your way block!");}
    else if(tloop==3&& road_answer==1) {setTextColor (4,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("your way block!");}
    else if(tloop==4 && road_answer==0){setTextColor (2,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("Your path cannot be blocked!!");}//if can't block path
    else if(tloop==3 && road_answer==0) {setTextColor (2,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("Your path cannot be blocked!!");}//if can't block path
    else if(tloop==2 && road_answer==1) {setTextColor (4,colorscreen); gotoxy(27,x3-3+strlen(name_player_3)); printf("your way block!");}
    else if(tloop==1&& road_answer==1) {setTextColor (4,colorscreen); gotoxy(31,x4-3+strlen(name_player_4)); printf("your way block!");}
    else if(tloop==2 && road_answer==0){setTextColor (2,colorscreen); gotoxy(27,x3-3+strlen(name_player_3)); printf("Your path cannot be blocked!!");}//if can't block path
    else if(tloop==1 && road_answer==0) {setTextColor (2,colorscreen); gotoxy(31,x4-3+strlen(name_player_4)); printf("Your path cannot be blocked!!");}//if can't block path
    spell=1;
    turn = num_turn;
}

int reset(){//for reseting board game
      if(tloop==4) {gotoxy(19,x1-3+strlen(name_player_1)); printf("Board game is resetting!");}
      else if(tloop==3){gotoxy(23,x2-3+strlen(name_player_2)); printf("Board game is resetting!");}
      else if(tloop==2){gotoxy(23,x3-3+strlen(name_player_3)); printf("Board game is resetting!");}
      else{gotoxy(23,x4-3+strlen(name_player_4)); printf("Board game is resetting!");}
      for(int i=2 ; i<=TotalRows-2 ; i++ ){
         for(int j=1; j<=TotalColumn-2 ; j++){
                if(board[i][j]==1000 || board[i][j]==2000 || board[i][j]==200 || board[i][j]==300 || board[i][j]==600 || board[i][j]==700 || board[i][j]==3000 || board[i][j]==4000){
                    board[i][j]=0;
                }
         }
      }
      //copy informations into values
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
      if(Sw_four_playergame==0){//if 4 player's game
          board[primaryrow3][primarycolumn3]=600;
          column3=primarycolumn3;
          board[primaryrow4][primarycolumn4]=700;
          column4=primarycolumn4;
          row4=primaryrow4;
          row3=primaryrow3;
          verticalsticks3 = primaryverticalsticks3;
          verticalsticks4 = primaryverticalsticks4;
          horizontalsticks3 = primaryhorizontalsticks3;
          horizontalsticks4 = primaryhorizontalsticks4;
      }
      ////end of copy information
      return 0;
   }

int decrease_sticks_player(){
     int typesticks,number;
     int horizontalsticks, verticalsticks;
     if(tloop==4){
        if(horizontalsticks1==0 && verticalsticks1==0){//if doesn't have stick
            setTextColor(2,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("You have no wood to reduce!");
            return 0;
        }
        horizontalsticks=horizontalsticks1;
        verticalsticks=verticalsticks1;
     }else if(tloop==3){
         if(horizontalsticks2==0 && verticalsticks2==0){//if doesn't have stick
            gotoxy(23,x2-3+strlen(name_player_2)); printf("You have no wood to reduce!");
            return 0;
        }
        horizontalsticks=horizontalsticks2;
        verticalsticks=verticalsticks2;
     }else if(tloop==2){
         if(horizontalsticks3==0 && verticalsticks3==0){//if doesn't have stick
            gotoxy(27,x3-3+strlen(name_player_3)); printf("You have no wood to reduce!");
            return 0;
        }
        horizontalsticks=horizontalsticks3;
        verticalsticks=verticalsticks3;
     }else{
         if(horizontalsticks4==0 && verticalsticks4==0){//if doesn't have stick
            gotoxy(31,x4-3+strlen(name_player_4)); printf("You have no wood to reduce!");
            return 0;
        }
        horizontalsticks=horizontalsticks4;
        verticalsticks=verticalsticks4;
     }
      srand(time(0));
      typesticks = rand()%100+1;//H or V
      number = rand()%2+1;//number of wood
      if(typesticks%2==0 && horizontalsticks>=number || verticalsticks==0){//if doesn't have verticalsticks
        if(tloop==4){
             horizontalsticks1 -= number;
        }else if(tloop==3){
              horizontalsticks2 -= number;
        }else if(tloop==2){
              horizontalsticks3 -= number;
        }else{
              horizontalsticks4 -= number;
        }
      }else if(typesticks%2==0 && horizontalsticks==1 ){//if just has one stick
             if(tloop==4){
                horizontalsticks1 -= 1;
             }else if(tloop==3){
                horizontalsticks2 -= 1;
            }else if(tloop==2){
                horizontalsticks3 -= 1;
            }else{
                horizontalsticks4 -= 1;
            }
            number=1;
      }
      if(typesticks%2==1 && verticalsticks>=number || horizontalsticks==0 ){//if doesn't have horizontalsticks
         if(tloop==4){
               verticalsticks1 -= number;
        }else if(tloop==3){
               verticalsticks2 -= number;
        }else if(tloop==2){
               verticalsticks3 -= number;
        }else{
               verticalsticks4 -= number;
        }
      }else if(typesticks%2==1 && verticalsticks==1 ){//if just has one verticalstick
          if(tloop==4){
                verticalsticks1 -= 1;
          }else if(tloop==3){
                verticalsticks2 -= 1;
          }else if(tloop==2){
                verticalsticks3 -= 1;
          }else{
                verticalsticks4 -= 1;
          }
        number=1;
      }
      if(tloop==4) {gotoxy(19,x1-3+strlen(name_player_1)); printf("you lose %d stick!", number);}
      else if(tloop==3) {gotoxy(23,x2-3+strlen(name_player_2)); printf("you lose %d stick!", number);}
      else if(tloop==2) {gotoxy(27,x3-3+strlen(name_player_3)); printf("you lose %d stick!", number);}
      else {gotoxy(31,x4-3+strlen(name_player_4)); printf("you lose %d stick!", number);}
      return 1;
}
