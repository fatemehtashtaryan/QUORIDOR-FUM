#define max 196
#include "subcodes.h"
#include "child_minimax.h"
int lastline_bfs ;
int answer;
int  pointer=0, counter_neighbor = 0 ;
t = 0;
//////////////////////////////bfs

struct coordinates_BFS{
    int row;
    int column;
    int core;

};
struct visited_BFS{
    struct coordinates_BFS location[196] ;
    int coordNo;
};

struct visited_BFS home;

void find_neighbor(int Targetrow, int Targetcolumn){
        if(board[Targetrow-2][Targetcolumn] != 100 && board[Targetrow-2][Targetcolumn] != 8 && board[Targetrow-2][Targetcolumn] !=200){ //up
            answer = SearchVisitHouse_BFS(Targetrow-4, Targetcolumn);
          if(answer == 0){
            home.location[ home.coordNo].row=Targetrow-4;
            home.location[ home.coordNo].column=Targetcolumn;
            home.coordNo++;
            counter_neighbor++;
          }
        }
        if(board[Targetrow][Targetcolumn+4]!=100 && board[Targetrow][Targetcolumn+3]!=7 && board[Targetrow][Targetcolumn+4]!=200){ //right
            answer = SearchVisitHouse_BFS(Targetrow, Targetcolumn+8);
          if(answer == 0){
            home.location[ home.coordNo].row=Targetrow;
            home.location[ home.coordNo].column=Targetcolumn+8;
            home.coordNo++;
            counter_neighbor++;
          }
        }
        if(board[Targetrow][Targetcolumn-4]!=100 && board[Targetrow][Targetcolumn-3]!=7 && board[Targetrow][Targetcolumn-4]!=200){ //left
          answer = SearchVisitHouse_BFS(Targetrow, Targetcolumn-8);
          if(answer == 0){
            home.location[ home.coordNo].row=Targetrow;
            home.location[ home.coordNo].column=Targetcolumn-8;
            home.coordNo++;
            counter_neighbor++;
          }
        }
        if(board[Targetrow+2][Targetcolumn]!=100 && board[Targetrow+2][Targetcolumn]!=8 && board[Targetrow+2][Targetcolumn]!=200){ //down
            answer = SearchVisitHouse_BFS(Targetrow+4, Targetcolumn);
          if(answer == 0){
            home.location[ home.coordNo].row=Targetrow+4;
            home.location[ home.coordNo].column=Targetcolumn;
            home.coordNo++;
            counter_neighbor++;
          }
        }
}

int SearchVisitHouse_BFS( int Targetrow , int Targetcolumn ){
    int i;
    for(i = 0; i < home.coordNo ; i++){
        if(home.location[i].row == Targetrow && home.location[i].column == Targetcolumn){
            return 1; //find the house thats visited it before
        }
    }
        return 0; //cant find house in list
}
int BFS_score(){
    int counter,sum=0,main_sum=home.location[0].core,i, main_sumbe,score=0;
    for(counter=0; counter<home.coordNo-1; counter+= main_sumbe){
        for(i=0; i<main_sum; i++){
            sum+=home.location[counter+i+1].core;
        }
        score++;
        main_sumbe=main_sum;
        main_sum=sum;
        sum=0;
}
    return score;
}

int BFS(int row,int column,int sw_minimax){
    if(sw_minimax==0){
        lastline_bfs=2;
    }else{
        lastline_bfs=TotalRows-2;
    }
     home.coordNo = 0 ;
     home.location[home.coordNo].row=row;
     home.location[home.coordNo].column=column;
     home.coordNo ++;
     while(home.location[pointer].row != lastline_bfs){
          find_neighbor(home.location[pointer].row, home.location[pointer].column);
          home.location[pointer].core= counter_neighbor;
          counter_neighbor=0;
          pointer++;
     }
     return BFS_score();
}

int maxeval=-1, mineval=1000,ev;
int minimax(int Row , int Column , int depth,int sw_minimax){

    if (depth=0){
        return BFS(Row,Column,0);
    }
    if (sw_minimax==1){

        check_child(Row,Column);
        printf("*********\n");
        for(int b=0; b<counter; b++){
           printf("r=%d ",true_child[b].row);
            printf("c=%d ",true_child[b].column);
           printf("m=%c\n",true_child[b].movement);
        }
         printf("*********");
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
            else if(true_child[i].movement=='h'){
                for(i = true_child[i].column-6 ; i <= true_child[i].column+6 ;i++){
                    copy_board.copyboard[true_child[i].row][i]=2000;
                }
            }
             else if(true_child[i].movement=='v'){
                for(i = true_child[i].row-3 ; i <= true_child[i].row+3 ;i++){
                    copy_board.copyboard[i][true_child[i].column]=2000;
                }
            }
            ev=minimax(true_child[i].row, true_child[i].column ,depth-1,0);
            printf("maxx");
            if(maxeval<ev){
                 maxeval=ev;
            }
            if(true_child[i].movement=='d'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row-4][Column]=200;
                    Row-=4;
                }
            else if(true_child[i].movement=='u'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row+4][Column]=200;
                    Row+=4;
                }
            else if(true_child[i].movement=='r'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column-8]=200;
                    Column-=8;
                }
            else if(true_child[i].movement=='l'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column+8]=200;
                    Column+=8;
                }
            else if(true_child[i].movement=='h'){
                    for(i = true_child[i].column-6 ; i <= true_child[i].column+6 ;i++){
                        copy_board.copyboard[true_child[i].row][i]=0;
                    }
                }
            else if(true_child[i].movement=='v'){
                    for(i = true_child[i].row-3 ; i <= true_child[i].row+3 ;i++){
                        copy_board.copyboard[i][true_child[i].column]=0;
                    }
                }
        }
        maxeval=-1;
        return maxeval;
    }else{

        check_child(Row,Column);
        for(i=0; i<counter; i++){
                    for(i=0; i<counter; i++){
            if(true_child[i].movement=='u'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row-4][Column]=200;
                Row-=4;
            }
            else if(true_child[i].movement=='d'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row+4][Column]=200;
                Row+=4;
            }
            else if(true_child[i].movement=='l'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column-8]=200;
                Column-=8;
            }
            else if(true_child[i].movement=='r'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column+8]=200;
                Column+=8;
            }
            else if(true_child[i].movement=='h'){
                for(i = true_child[i].column-6 ; i <= true_child[i].column+6 ;i++){
                    copy_board.copyboard[true_child[i].row][i]=1000;
                }
            }
             else if(true_child[i].movement=='v'){
                for(i = true_child[i].row-3 ; i <= true_child[i].row+3 ;i++){
                    copy_board.copyboard[i][true_child[i].column]=1000;
                }
            }
            ev=minimax(true_child[i].row, true_child[i].column,depth-1,1);
            if(mineval>ev){
                 mineval=ev;
            }
            if(true_child[i].movement=='d'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row-4][Column]=200;
                    Row-=4;
                }
            else if(true_child[i].movement=='u'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row+4][Column]=200;
                    Row+=4;
                }
            else if(true_child[i].movement=='r'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column-8]=200;
                    Column-=8;
                }
            else if(true_child[i].movement=='l'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column+8]=200;
                    Column+=8;
                }
            else if(true_child[i].movement=='h'){
                    for(i = true_child[i].column-6 ; i <= true_child[i].column+6 ;i++){
                        copy_board.copyboard[true_child[i].row][i]=0;
                    }
                }
            else if(true_child[i].movement=='v'){
                    for(i = true_child[i].row-3 ; i <= true_child[i].row+3 ;i++){
                        copy_board.copyboard[i][true_child[i].column]=0;
                    }
                }
        }
        mineval=1000;
        return mineval;

        }
    }
}


