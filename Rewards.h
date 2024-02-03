#include "subcodes.h"

int increase_sticks(){
      int typesticks,number;
      srand(time(0));
      typesticks = rand()%100+1;//H or V
      number = rand()%2+1;
      if(typesticks%2==0){
        if(tloop==2){
             horizontalsticks1 += number;
        }else{
             horizontalsticks2 += number;
        }
      }else{
        if(tloop==2){
             verticalsticks1 += number;
        }else{
             verticalsticks2 += number;
        }
      }
    if(tloop==2) {gotoxy(19,x1-3+strlen(name_player_1)); printf("increase your sticks!");}
    else if(tloop==1) {gotoxy(23,x2-3+strlen(name_player_2)); printf("increase your sticks!");}
    return 1;
}
int Open_path(){
    int t,row,Column;
    if(tloop==2){
        row=row1;
        Column=column1;
        t=-2;
    }else{
        row=row2;
        Column=column2;
        t=2;
    }
        if(board[row+t][Column]==1000 || board[row+t][Column]==2000 || board[row][Column+4]==1000 || board[row][Column+4]==2000 || board[row][Column-4]==1000 || board[row][Column-4]==2000 ){
            if(board[row][Column+4]==1000 || board[row][Column+4]==2000 || board[row][Column-4]==1000 || board[row][Column-4]==2000){ //v
                if(board[row+t][Column+4]==1000 || board[row+t][Column+4]==2000){
                    coordcolumn = Column+4;
                    coordRow = row+t;
                }else if(board[row-t][Column+4]==1000 || board[row-t][Column+4]==2000){
                    coordcolumn = Column+4;
                    coordRow = row-t;
                }else if(board[row+t][Column-4]==1000 || board[row+t][Column-4]==2000){
                    coordcolumn = Column-4;
                    coordRow = row+t;
                }else if(board[row-t][Column-4]==1000 || board[row-t][Column-4]==2000){
                    coordcolumn = Column-4;
                    coordRow = row-t;
                }

                for(i=coordRow-3 ; i<=coordRow+3 ; i++){
                        board[i][coordcolumn]=0;
                }
                 return 1;
            }else if(board[row+t][Column+4]==1000 || board[row+t][Column+4]==2000){ //H
                    coordcolumn = Column+4;
                    coordRow = row+t;
                }else{
                    coordcolumn = Column-4;
                    coordRow = row+t;
                }
                for(i = coordcolumn-6; i <= coordcolumn+6; i++){
                        board[coordRow][i]=0;
                }
                 return 1;
        }
        return 0;
}

int undo_competitor(){
    if(turncounter<2 || tloop==2 && swundo1==1 || tloop==1 && swundo2==2  ){
            return 0;
    }
    if(tloop==2 ){
        swundo1=1;
        swundo2=0;
        if(swmove2==1){
            board[row2][column2]=0;
            row2=row02; column2=column02;
            board[row2][column2]=300;
        }else if(swstick2==1){
            coordRow=((int)rowlocation-64)*4;
            coordcolumn=((int)columnlocation-64)*8-1;
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
        return 1;
     }

     if( tloop==1 ){
        swundo2=1;
        swundo1=0;
        if(swmove1==1){
            board[row1][column1]=0;
            row1=row01; column1=column01;
            board[row1][column1]=200;
        }else if(swstick1==1){
            coordRow=((int)rowlocation-64)*4;
            coordcolumn=((int)columnlocation-64)*8-1;
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
        return 1;
     }
      return 0;
}

int decrease_sticks_competitor(){
     int typesticks,number;
     int horizontalsticks, verticalsticks;
     if(tloop==2){
        if(horizontalsticks2==0 && verticalsticks2==0){
            gotoxy(19,x1-3+strlen(name_player_1)); printf("Sorry! Your opponent has no sticks to reduce.");
            return 0;
        }
        horizontalsticks=horizontalsticks2;
        verticalsticks=verticalsticks2;
     }else{
         if(horizontalsticks1==0 && verticalsticks1==0){
            gotoxy(23,x2-3+strlen(name_player_2)); printf("Sorry! Your opponent has no sticks to reduce.");
            return 0;
        }
        horizontalsticks=horizontalsticks1;
        verticalsticks=verticalsticks1;
     }
      srand(time(0));
      typesticks = rand()%100+1;//H or V
      number = rand()%2+1;
      if(typesticks%2==0 && horizontalsticks>=number || verticalsticks==0){
        if(tloop==2){
             horizontalsticks2 -= number;
        }else{
              horizontalsticks1 -= number;
            }
      }else if(typesticks%2==0 && horizontalsticks==1 ){
             if(tloop==2){
             horizontalsticks2 -= 1;
             }else{
                horizontalsticks1 -= 1;
            }
            number = 1;
      }
      if(typesticks%2==1 && verticalsticks>=number || horizontalsticks==0 ){
         if(tloop==2){
               verticalsticks2 -= number;
        }else{
               verticalsticks1 -= number;
            }
      }else if(typesticks%2==1 && verticalsticks==1 ){
          if(tloop==2){
                verticalsticks2 -= 1;
          }else{
                verticalsticks1 -= 1;
               }
            number = 1;
      }
      if(tloop==2) {gotoxy(19,x1-3+strlen(name_player_1)); printf("%d of your opponent's sticks are reduced", number);}
      else {gotoxy(23,x2-3+strlen(name_player_2)); printf("%d of your opponent's sticks are reduced", number);}
      return 1;
}

int rand_again(){
    int swrand_again;
    swrand_again=1;
    if(tloop==2) {gotoxy(19,x1-3+strlen(name_player_1)); printf("You have new Chance!");}
    else {gotoxy(23,x2-3+strlen(name_player_2)); printf("You have new Chance!");}
}

