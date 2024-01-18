#include"subcodes.h"
#include "BFS-minimax.h"

int minimax_move_computer(){
        check_child(row2,column2);
        Row=row2;Column=column2;
        for(i=0; i<counter; i++){
            if(true_child[i].movement=='u'){
                printf("u");
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row-4][Column]=300;
                Row-=4;
            }
            else if(true_child[i].movement=='d'){
                  printf("d");
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row+4][Column]=300;
                Row+=4;
            }
            else if(true_child[i].movement=='l'){
                  printf("l");
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column-8]=300;
                Column-=8;
            }
            else if(true_child[i].movement=='r'){
                  printf("r");
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column+8]=300;
                Column+=8;
            }
            true_child[i].score= minimax(Row, Column, 3 ,1);
            printf("mmmmmmmmin");
        }
        int max_minimax = -1, number=0;
        for(i=0; i<counter; i++){
            if(max_minimax< true_child[i].score){
                max_minimax=true_child[i].score;
                number=i;
            }
        }
        i=number;
        Row=true_child[i].row;
        Column=true_child[i].column;
        if(true_child[i].movement=='u'){
                board[row2][column2]=0;
                board[Row][Column]=300;
            }
            else if(true_child[i].movement=='d'){
                board[row2][Column]=0;
                board[Row][Column]=300;

            }
            else if(true_child[i].movement=='l'){
                board[Row][Column]=0;
                board[Row][Column]=300;

            }
            else if(true_child[i].movement=='r'){
                board[Row][Column]=0;
                board[Row][Column]=300;
            }
            else if(true_child[i].movement=='h'){
                for(i = Column-6 ; i <= Column+6 ;i++){
                    board[Row][i]=2000;
                }
            }
             else if(true_child[i].movement=='v'){
                for(i =Row-3 ; i <=Row+3 ;i++){
                    board[i][Column]=2000;
                }
            }
            row2=Row;
            column2=Column;
            return 1;
}
