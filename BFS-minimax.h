#define max 196
#include "subcodes.h"
#include "child_minimax.h"

// this file is about minimax && score calculation by BFS

int lastline_bfs ;
int answer;
int  pointer=0, counter_neighbor = 0 ;
t = 0;
int Rowcopy, Columncopy;

//////////////////////////////bfs

struct coordinates_BFS{
    int row;
    int column;
    int core;

};
struct visited_BFS{
    struct coordinates_BFS location[1000] ;
    int coordNo;
};

struct visited_BFS home;

void find_neighbor(int Targetrow, int Targetcolumn){
        if(copy_board.copyboard[Targetrow-2][Targetcolumn] != 1000 && copy_board.copyboard[Targetrow-2][Targetcolumn] != 8 && copy_board.copyboard[Targetrow-2][Targetcolumn] !=2000){ //up
            answer = SearchVisitHouse_BFS(Targetrow-4, Targetcolumn);
          if(answer == 0){
            home.location[ home.coordNo].row=Targetrow-4;
            home.location[ home.coordNo].column=Targetcolumn;
            home.coordNo++;
            counter_neighbor++;
          }
        }
        if(copy_board.copyboard[Targetrow][Targetcolumn+4]!=1000 && copy_board.copyboard[Targetrow][Targetcolumn+3]!=7 && copy_board.copyboard[Targetrow][Targetcolumn+4]!=2000){ //right
            answer = SearchVisitHouse_BFS(Targetrow, Targetcolumn+8);
          if(answer == 0){
            home.location[ home.coordNo].row=Targetrow;
            home.location[ home.coordNo].column=Targetcolumn+8;
            home.coordNo++;
            counter_neighbor++;
          }
        }
        if(copy_board.copyboard[Targetrow][Targetcolumn-4]!=1000 && copy_board.copyboard[Targetrow][Targetcolumn-3]!=7 && copy_board.copyboard[Targetrow][Targetcolumn-4]!=2000){ //left
          answer = SearchVisitHouse_BFS(Targetrow, Targetcolumn-8);
          if(answer == 0){
            home.location[ home.coordNo].row=Targetrow;
            home.location[ home.coordNo].column=Targetcolumn-8;
            home.coordNo++;
            counter_neighbor++;
          }
        }
        if(copy_board.copyboard[Targetrow+2][Targetcolumn]!=1000 && copy_board.copyboard[Targetrow+2][Targetcolumn]!=8 && copy_board.copyboard[Targetrow+2][Targetcolumn]!=2000){ //down
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
    int  Rowcopy, Columncopy;
    int counter,sum=0,main_sum=home.location[0].core,i, main_sumbe,score=0;
    for(counter=0; counter<home.coordNo-1; counter+= main_sumbe){
        for(i=0; i<main_sum; i++){
            sum+=home.location[counter+i+1].core;
        }
        score++; // the shortest path to the destination
        main_sumbe=main_sum;
        main_sum=sum;
        sum=0;
    }
     return score;
}

int BFS(int row,int column, int lastline_bfs){
    int i;
    pointer=0;
    for(i = 0 ; i < size_board * size_board ; i++){
            home.location[i].row=0;
            home.location[i].column=0;
    }
    // add the initial coordinates to the list
    home.coordNo = 0 ;
    home.location[home.coordNo].row=row;
    home.location[home.coordNo].column=column;
    home.coordNo ++;
    while(home.location[pointer].row != lastline_bfs &&  home.location[pointer].row>1){
          find_neighbor(home.location[pointer].row, home.location[pointer].column);  //find the neighbor of each list member
          home.location[pointer].core= counter_neighbor;  //calculate the score of each list member besed on thr number of neighbors
          counter_neighbor=0;
          pointer++;
    }
     return BFS_score();
}
///////////////////////////////////////////////////////minimax
// alpha is maxi and beta is min >>>if alpha>Beta no need to check

int minimax(int Row1 ,int Column1, int Row , int Column , int depth ,int alpha ,int beta ,int sw_minimax){
    int counter_child;
    if(Column1<3 || Row1<2 || Row1>TotalRows-3 || Column1>TotalColumn-3 || Column<3 || Row<2 || Row>TotalRows-3 || Column>TotalColumn-3 ){ //coords out of range
        if(sw_minimax==1){
            return INT_MAX;
        }else{
            return INT_MIN;
        }
    }
    if(Row1==2 || Row== TotalRows-3 ){ //last line

         return -1*BFS(Row,Column,TotalRows-3)+BFS(Row1,Column1,2);
    }
    if (depth==0 ){
         return -1*BFS(Row,Column,TotalRows-3)+BFS(Row1,Column1,2);
    }

    if (sw_minimax==1){
        maxeval=INT_MIN;
        counter_child=check_child(Row1,Column1,Row,Column,1);

        for(i=0; i<counter_child; i++){
            ///////////////////////////////////////////putting children on the copy board
            if(true_child[i].movement=='u'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row-4][Column]=300;
                Row-=4;

            }else if(true_child[i].movement=='d'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row+4][Column]=300;
                Row+=4;

            }else if(true_child[i].movement=='l'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column-8]=300;
                Column-=8;

            }else if(true_child[i].movement=='r'){
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column+8]=300;
                Column+=8;

            }else if(true_child[i].movement=='h'){
                for(p = true_child[i].column-6 ; p <= true_child[i].column+6 ;p++){
                    copy_board.copyboard[true_child[i].row][p]=2000;
                }
                 copy_board.copyhorizontalsticks2--;

            }else if(true_child[i].movement=='v'){
                for(p = true_child[i].row-3 ; p <= true_child[i].row+3 ;p++){
                    copy_board.copyboard[p][true_child[i].column]=2000;
                }
                copy_board.copyverticalsticks2--;

            }if (true_child[i].movement!='h' && true_child[i].movement!='v' ){
                Row=true_child[i].row;
                Column=true_child[i].column;
            }

           //////////////////////////////////////////////////////// eval

            ev=minimax( Row1 , Column1 , Row, Column ,depth-1, alpha , beta ,0);

            if(maxeval<ev){
                 maxeval=ev;
            }if(alpha<ev){
                 alpha = ev;
            }
            //////////////////////////////////////////////// undo

            if(true_child[i].movement=='d'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row-4][Column]=300;
                    Row-=4;

            }else if(true_child[i].movement=='u'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row+4][Column]=300;
                    Row+=4;

            }else if(true_child[i].movement=='r'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column-8]=300;
                    Column-=8;

            }else if(true_child[i].movement=='l'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column+8]=300;
                    Column+=8;

            }else if(true_child[i].movement=='h'){
                    for(p = true_child[i].column-6 ; p <= true_child[i].column+6 ;p++){
                        copy_board.copyboard[true_child[i].row][p]=0;
                    }
                     copy_board.copyhorizontalsticks2++;

            }else if(true_child[i].movement=='v'){
                    for(p = true_child[i].row-3 ; p <= true_child[i].row+3 ;p++){
                         copy_board.copyboard[p][true_child[i].column]=0;

                    }
                     copy_board.copyverticalsticks2++;

            }
           ////////////////////////////////////// check alpha
            if(beta <= alpha)  break;

        }

        return maxeval;

    }else{
        mineval=INT_MAX;

        counter_child=check_child(Row1,Column1,Row,Column,0);

        for(j=0 ; j<counter_child; j++){
        ///////////////////////////////////////////////////putting children on the copy board
            if(true_child1[j].movement=='u'){
                copy_board.copyboard[Row1][Column1]=0;
                copy_board.copyboard[Row1-4][Column1]=200;
                Row1-=4;

            }else if(true_child1[j].movement=='d'){
                copy_board.copyboard[Row1][Column1]=0;
                copy_board.copyboard[Row1+4][Column1]=200;
                Row1+=4;

            }else if(true_child1[j].movement=='l'){
                copy_board.copyboard[Row1][Column1]=0;
                copy_board.copyboard[Row1][Column1-8]=200;
                Column1-=8;

            }else if(true_child1[j].movement=='r'){
                copy_board.copyboard[Row1][Column1]=0;
                copy_board.copyboard[Row1][Column1+8]=200;
                Column1+=8;

            }else if(true_child1[j].movement=='h'){
                for(p = true_child1[j].column-6 ; p <= true_child1[j].column+6 ;p++){
                    copy_board.copyboard[true_child1[j].row][p]=1000;
                }
                 copy_board.copyhorizontalsticks1--;

            }else if(true_child1[j].movement=='v'){
                for(p = true_child1[j].row-3 ; p <= true_child1[j].row+3 ;p++){
                    copy_board.copyboard[p][true_child1[j].column]=1000;
                }
                copy_board.copyverticalsticks1--;

            }if (true_child1[j].movement!='h' && true_child1[j].movement!='v' ){
                Row1=true_child1[j].row;
                Column1=true_child1[j].column;
            }

            /////////////////////////////////////// eval

            ev=minimax( Row1 , Column1 , Row, Column ,depth-1, alpha , beta ,1);
            if(mineval>ev){
                 mineval=ev;
            }
            if(beta>ev){
                 beta = ev;
            }
            ////////////////////////////////////// undo

            if(true_child1[j].movement=='d'){
                    copy_board.copyboard[Row1][Column1]=0;
                    copy_board.copyboard[Row1-4][Column1]=200;
                    Row1-=4;

            }else if(true_child1[j].movement=='u'){
                    copy_board.copyboard[Row1][Column1]=0;
                    copy_board.copyboard[Row1+4][Column1]=200;
                    Row1+=4;

            }else if(true_child1[j].movement=='r'){
                    copy_board.copyboard[Row1][Column1]=0;
                    copy_board.copyboard[Row1][Column1-8]=200;
                    Column1-=8;

            }else if(true_child1[j].movement=='l'){
                    copy_board.copyboard[Row1][Column1]=0;
                    copy_board.copyboard[Row1][Column1+8]=200;
                    Column1+=8;

            }else if(true_child1[j].movement=='h'){
                    for(p = true_child1[j].column-6 ; p <= true_child1[j].column+6 ;p++){
                        copy_board.copyboard[true_child1[j].row][p]=0;
                    }
                    copy_board.copyhorizontalsticks1++;

            }else if(true_child1[j].movement=='v'){
                    for(p = true_child1[j].row-3 ; p <= true_child1[j].row+3 ;p++){
                        copy_board.copyboard[p][true_child1[j].column]=0;
                    }
                     copy_board.copyverticalsticks1++;
            }
             //////////////////////////////////////////////// check alpha
            if(beta <= alpha) break;

        }

        return mineval;

    }
}


