#define max 196
int lastline_bfs ;
int answer;
int t = 0, pointer=0, counter_neighbor = 0 ;
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

int BFS(int row,int column){
    if(turn==1){
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

