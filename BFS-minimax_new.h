#define max 196
#include "subcodes.h"
#include "child_minimax.h"
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
    struct coordinates_BFS location[196] ;
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
        score++;
        main_sumbe=main_sum;
        main_sum=sum;
        sum=0;
    }

   // if(sw_minimax==1) return score-1;
     return score;
}

int BFS(int row,int column, int lastline_bfs){
    int i;
    pointer=0;
    for(i = 0; i < size_board*size_board ; i++){
            home.location[i].row=0;
            home.location[i].column=0;
            home.location[i].core;
        }
  /*  if(sw==0){
        lastline_bfs=TotalRows-3;
    }
    else{
        lastline_bfs=2;
    }*/
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
///////////////////////////////////////////////////////minimax
int maxeval=INT_MIN, mineval=INT_MAX,ev,i,j,p;
int minimax(int Row1 ,int Column1, int Row , int Column , int depth,int sw_minimax){
    if(Column1<3 || Row1<2 || Row1>TotalRows-3 || Column1>TotalColumn-4 || Column<3 || Row<2 || Row>TotalRows-3 || Column>TotalColumn-4 ){
        if(sw_minimax==1){
            return INT_MAX;
        }else{
            return INT_MIN;
        }
    }
    if(Row1==2 || Row== TotalRows-3 ){ //last line
         return (2*BFS(Row1,Column1,2)-1*BFS(Row,Column,TotalRows-3));

    }
    if (depth==0 ){
         return (2*BFS(Row1,Column1,2)-1*BFS(Row,Column,TotalRows-3));
    }

    if (sw_minimax==1){
        maxeval=INT_MIN;

        check_child(Row1,Column1,Row,Column,1);

     /*   printf("##################################################\n");
                for(int b=0; b<counter; b++){
                   printf("=row=%d= ",true_child[b].row);
                   printf("=colu=%d= ",true_child[b].column);
                   printf("=move=%c=\n",true_child[b].movement);
                  // printf ("=score==%d\n",true_child2[b].score);
                }
          printf("#######################################################\n");
                  sleep(4000);*/
        for(i=0; i<counter; i++){
            if(true_child[i].movement=='u'){
                  //  printf("u");
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row-4][Column]=300;
                Row-=4;
            }
            else if(true_child[i].movement=='d'){
                  //printf("d");
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row+4][Column]=300;
                Row+=4;
            }
            else if(true_child[i].movement=='l'){
                 // printf("l");
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column-8]=300;
                Column-=8;
            }
            else if(true_child[i].movement=='r'){
                //  printf("r");
                copy_board.copyboard[Row][Column]=0;
                copy_board.copyboard[Row][Column+8]=300;
                Column+=8;
            }
            else if(true_child[i].movement=='h'){
                for(p = true_child[i].column-6 ; p <= true_child[i].column+6 ;p++){
                    copy_board.copyboard[true_child[i].row][p]=2000;
                }
                 copy_board.copyhorizontalsticks2--;
            }
             else if(true_child[i].movement=='v'){
                for(p = true_child[i].row-3 ; p <= true_child[i].row+3 ;p++){
                    copy_board.copyboard[p][true_child[i].column]=2000;
                }
                copy_board.copyverticalsticks2--;
            }
            if (true_child[i].movement!='h' && true_child[i].movement!='v' ){
                Row=true_child[i].row;
                Column=true_child[i].column;
            }
            ev=minimax( Row1 , Column1 , Row, Column ,depth-1,0);
            if(maxeval<ev){
                 maxeval=ev;

            }
            if(true_child[i].movement=='d'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row-4][Column]=300;
                    Row-=4;
                }
            else if(true_child[i].movement=='u'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row+4][Column]=300;
                    Row+=4;
                }
            else if(true_child[i].movement=='r'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column-8]=300;
                    Column-=8;
                }
            else if(true_child[i].movement=='l'){
                    copy_board.copyboard[Row][Column]=0;
                    copy_board.copyboard[Row][Column+8]=300;
                    Column+=8;
                }
            else if(true_child[i].movement=='h'){
                    for(p = true_child[i].column-6 ; p <= true_child[i].column+6 ;p++){
                        copy_board.copyboard[true_child[i].row][p]=0;
                    }
                     copy_board.copyhorizontalsticks2++;
                }

            else if(true_child[i].movement=='v'){
                    for(p = true_child[i].row-3 ; p <= true_child[i].row+3 ;p++){
                         copy_board.copyboard[p][true_child[i].column]=0;

                    }
                     copy_board.copyverticalsticks2++;

                }
        }
        return maxeval;

    }else{
        mineval=INT_MAX;

         check_child(Row1,Column1,Row,Column,0);


            /*    printf("**********************************************************\n");
                for(int b=0; b<counter; b++){
                   printf("=row=%d= ",true_child1[b].row);
                   printf("=colu=%d= ",true_child1[b].column);
                   printf("=move=%c=\n",true_child1[b].movement);
                  // printf ("=score==%d\n",true_child2[b].score);
                }
          printf("*******************************************************\n");
                  sleep(4000);*/
        for(j=0 ; j<counter; j++){
            if(true_child1[j].movement=='u'){
                copy_board.copyboard[Row1][Column1]=0;
                copy_board.copyboard[Row1-4][Column1]=200;
                Row1-=4;
            }
            else if(true_child1[j].movement=='d'){
                copy_board.copyboard[Row1][Column1]=0;
                copy_board.copyboard[Row1+4][Column1]=200;
                Row1+=4;
            }
            else if(true_child1[j].movement=='l'){
                copy_board.copyboard[Row1][Column1]=0;
                copy_board.copyboard[Row1][Column1-8]=200;
                Column1-=8;
            }
            else if(true_child1[j].movement=='r'){
                copy_board.copyboard[Row1][Column1]=0;
                copy_board.copyboard[Row1][Column1+8]=200;
                Column1+=8;
            }
            else if(true_child1[j].movement=='h'){
                for(p = true_child1[j].column-6 ; p <= true_child1[j].column+6 ;p++){
                    copy_board.copyboard[true_child1[j].row][p]=1000;
                }
                 copy_board.copyhorizontalsticks1--;
            }
             else if(true_child1[j].movement=='v'){
                for(p = true_child1[j].row-3 ; p <= true_child1[j].row+3 ;p++){
                    copy_board.copyboard[p][true_child1[j].column]=1000;
                }
                copy_board.copyverticalsticks1--;
            }
            if (true_child1[j].movement!='h' && true_child1[j].movement!='v' ){
                Row1=true_child1[j].row;
                Column1=true_child1[j].column;
            }
            ev=minimax(Row1,Column1, Row ,Column ,depth-1,1);
            if(mineval>ev){
                 mineval=ev;
            }

            if(true_child1[j].movement=='d'){
                    copy_board.copyboard[Row1][Column1]=0;
                    copy_board.copyboard[Row1-4][Column1]=200;
                    Row1-=4;
                }
            else if(true_child1[j].movement=='u'){
                    copy_board.copyboard[Row1][Column1]=0;
                    copy_board.copyboard[Row1+4][Column1]=200;
                    Row1+=4;
                }
            else if(true_child1[j].movement=='r'){
                    copy_board.copyboard[Row1][Column1]=0;
                    copy_board.copyboard[Row1][Column1-8]=200;
                    Column1-=8;
                }
            else if(true_child1[j].movement=='l'){
                    copy_board.copyboard[Row1][Column1]=0;
                    copy_board.copyboard[Row1][Column1+8]=200;
                    Column1+=8;
                }
            else if(true_child1[j].movement=='h'){
                    for(p = true_child1[j].column-6 ; p <= true_child1[j].column+6 ;p++){
                        copy_board.copyboard[true_child1[j].row][p]=0;
                    }
                    copy_board.copyhorizontalsticks1++;
                }
            else if(true_child1[j].movement=='v'){
                    for(p = true_child1[j].row-3 ; p <= true_child1[j].row+3 ;p++){
                        copy_board.copyboard[p][true_child1[j].column]=0;
                    }
                     copy_board.copyverticalsticks1++;
                }
            }

        return mineval;


    }
}


