#include"subcodes.h"
#include "BFS-minimax.h"

// this file is about calling Minimax and choosing the best path and transferring it to the main board

int minimax_move_computer(){
     int alpha=INT_MIN,beta=INT_MAX;
     int counterTotalchilds=2*(size_board)*(size_board)-2*(size_board)+4;
     int k,numberPrimaryChildren,j,i;

     for(j=0;j<counterTotalchilds;j++){ //empty the array
         true_child2[j].movement=0;
         true_child2[j].row=0;
         true_child2[j].column=0;
         true_child2[j].score=0;
     }

        sw_minimax=-1;
        Row=row2;Column=column2;
        Row1=row1;Column1=column1;

        check_child(row1,column1,row2,column2,sw_minimax);
        numberPrimaryChildren=counter;

        for(k=0; k<numberPrimaryChildren; k++){

            for(j=0;j<counterTotalchilds;j++){ //empty the array
                true_child[j].movement=0;
                true_child[j].row=0;
                true_child[j].column=0;
                true_child1[j].movement=0;
                true_child1[j].row=0;
                true_child1[j].column=0;
            }
            ///////////////////////////////////////////////////putting children on the copy board
            if(true_child2[k].movement=='u'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row-4][Column]=300;
                Row-=4;

            }else if(true_child2[k].movement=='d'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row+4][Column]=300;
                Row+=4;

            }else if(true_child2[k].movement=='l'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column-8]=300;
                Column-=8;

            }else if(true_child2[k].movement=='r'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column+8]=300;
                Column+=8;

            }else if(true_child2[k].movement=='h'){
                for(i = true_child2[k].column-6 ; i <= true_child2[k].column+6 ;i++){
                    copy_board.copyboard[true_child2[k].row][i]=2000;
                }
                   copy_board.copyhorizontalsticks2--;

            }else if(true_child2[k].movement=='v'){
                for(i = true_child2[k].row-3 ; i <= true_child2[k].row+3 ;i++){
                    copy_board.copyboard[i][true_child2[k].column]=2000;
                }
                copy_board.copyverticalsticks2--;
            }
            ///////////////////////////////////////////////////////////// call minimax

            true_child2[k].score= minimax(Row1, Column1, Row, Column,2,alpha,beta,0);

            //////////////////////////////////////////////////////////////

            if(true_child2[k].movement=='d'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row-4][Column]=300;
                    Row-=4;

            }else if(true_child2[k].movement=='u'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row+4][Column]=300;
                    Row+=4;

            }else if(true_child2[k].movement=='r'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column-8]=300;
                    Column-=8;

            }else if(true_child2[k].movement=='l'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column+8]=300;
                    Column+=8;

            }else if(true_child2[k].movement=='h'){
                    for(i = true_child2[k].column-6 ; i <= true_child2[k].column+6 ;i++){
                        copy_board.copyboard[true_child2[k].row][i]=0;
                    }
                    copy_board.copyhorizontalsticks2++;

            }else if(true_child2[k].movement=='v'){
                    for(i = true_child2[k].row-3 ; i <= true_child2[k].row+3 ;i++){
                        copy_board.copyboard[i][true_child2[k].column]=0;
                    }
                     copy_board.copyverticalsticks2++;
                }
        }
        ////////////////////////////////////////////////////////////////// find best score

        int max_minimax = INT_MIN, number=0;

        for(i=0; i<numberPrimaryChildren; i++){
            if(max_minimax< true_child2[i].score){
                max_minimax=true_child2[i].score;
                number=i;
            }
        }
        i=number;
        Row=true_child2[i].row;
        Column=true_child2[i].column;

        //////////////////////////////////////////////////////////////////// transfer the desired momevent on the main board

        if(true_child2[i].movement=='u'){
                board[row2][column2]=0;
                if(Row==Row1 && Column==Column1 ){
                    board[Row][Column]=500;
                }else{
                     board[Row][Column]=300;
                }
        }else if(true_child2[i].movement=='d'){
                board[row2][column2]=0;
                if(Row==Row1 && Column==Column1 ){
                    board[Row][Column]=500;
                }else{
                     board[Row][Column]=300;
                }
        }else if(true_child2[i].movement=='l'){
               board[row2][column2]=0;
               if(Row==Row1 && Column==Column1 ){
                    board[Row][Column]=500;
               }else{
                     board[Row][Column]=300;
                }
        }else if(true_child2[i].movement=='r'){
                board[row2][column2]=0;
                if(Row==Row1 && Column==Column1 ){
                    board[Row][Column]=500;
                }else{
                     board[Row][Column]=300;
                }

        }else if(true_child2[i].movement=='h'){
                for(j = Column-6 ; j <= Column+6 ;j++){
                    board[Row][j]=2000;

                }
                 horizontalsticks2--;

        }else if(true_child2[i].movement=='v'){
                for(j =Row-3 ; j <=Row+3 ;j++){
                    board[j][Column]=2000;
                }
                verticalsticks2--;

        }if(true_child2[i].movement!='h' && true_child2[i].movement!='v'){
                row2=Row;
                column2=Column;
        }

        return 1;
}
