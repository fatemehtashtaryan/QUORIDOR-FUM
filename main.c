#include "general_print_board.h"
#include "print_main_board.h"
#include "move_player.h"
#include "subcodes.h"
#include "checking_move.h"
#include "computer_move_rand.h"
#include "compter_move_minimax.h"
#include "random_lucky_boxes.h"

//player2 = 'C'; ////is computer


int check_true_move;

int main()
{
    int n, sw;
    general_print();
    colorscreen=color;
    if(colorscreen ==15 ){
        system ("COLOR F0") ;
        }
    if(colorscreen == 11){
        system ("COLOR B0") ;
        }
    if(colorscreen == 14){
        system ("COLOR E0") ;
        }
    if(load==0){
        setTextColor (0,colorscreen) ;
        turn = 1;
        primarycolumn1=column1;
        primarycolumn2=column2;
        primaryrow1=row1;
        primaryverticalsticks1=verticalsticks1;
        primaryhorizontalsticks1=horizontalsticks1;
        primaryverticalsticks2=verticalsticks2;
        primaryhorizontalsticks2=horizontalsticks2;
        board[2][column2] = 300;
        board[row1][column1] = 200;
        if(Sw_four_playergame==0){
            primarycolumn3=column3;
            primarycolumn4=column4;
            primaryverticalsticks3=verticalsticks3;
            primaryhorizontalsticks3=horizontalsticks3;
            primaryverticalsticks4=verticalsticks4;
            primaryhorizontalsticks4=horizontalsticks4;
            board[2][column3] = 500;
            board[row1][column4] = 600;

        }
        Scoreboard();
        boardgame(TotalRows, TotalColumn);
        printf("\n\n\n");
        printboardgame(TotalRows, TotalColumn);
    }else{
         setTextColor (0,colorscreen) ;
         system("cls");
         setTextColor (0,colorscreen) ;
         if(turn==1){
              Scoreboard();
              printf("\n\n\n");
              printboardgame(TotalRows, TotalColumn);
         }
    }
    while(row1 != 2 && row2 != size_board*4-2){
         /*if(Luckybox_counter==turncounter){
             system("cls");
             setTextColor (0,colorscreen) ;
             rand_boxes();
             tboxrand+=2;
             Luckybox_counter+=tboxrand ;
             setTextColor (0,colorscreen) ;
             system("cls");
             setTextColor (0,colorscreen) ;
             Scoreboard();
             printf("\n\n\n");
             printboardgame(TotalRows, TotalColumn);
         }*/
         n=1;
         turncounter++;
         if(turn==1 && sw_turnagain2==1){
             do{
                if(n!=1 ){
                Sleep(2500);
                system("cls");
                Scoreboard();//in (Scoreboard_player)file that print scoreboards.
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
               }
                check_true_move = move_play();//in move_player file
                n++;
             }while(check_true_move == 0) ;
         }
         sw_turnagain2=1;
         swmove2=0;
         swstick2=0;
         turn = 2;
         if(sw_turnagain1==0) turn=1;
         n = 1;
         system("cls");
         Scoreboard();//in Scoreboard_player file that print scoreboards.
         printf("\n\n\n");
         printboardgame(TotalRows, TotalColumn);
         turncounter++;
         if(row1 != 2 && sw_turnagain1==1){
            do{
                if(n != 1 && typeplayer2==0){
                Sleep(2500);
                system("cls");
                Scoreboard();//in (Scoreboard_player)file that print scoreboards.
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
                }
                if( typeplayer2==0 ){
                   check_true_move = move_play();//in move_player fil
                    n++;
                }
                else{
                  if(typeplayer2==1){//random
                    check_true_move = rand_move_computer();//in computer_move_rand.h
                  }else{//minimax
                    check_true_move = minimax_move_computer();
                  }
                }
            }while(check_true_move == 0);
                swmove1=0;
                swstick1=0;
                turn = 1;
                PLAYER ='t';
                system("cls");
                Scoreboard();//in (Scoreboard_player)file that print scoreboards.
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
             }
        if(sw_turnagain2==0) turn=2;
        sw_turnagain1=1;
    }
    if (row1 == 2) {
        turn = 1;
        printwon(name_player_1);
    }
    else if( row2 == size_board*4-2 && typeplayer2==0 ) printwon(name_player_2);
          else {
           // turn = 3;
            printwon("computer") ;
           }
    setTextColor(7,0);
    system("cls");
    for(Row = 0; Row <= TotalRows ; Row++){
         for(Column = 0; Column <= TotalColumn; Column++){
             board[Row][Column]=0;
         }
    }
    verticalsticks1=primaryverticalsticks1;
    horizontalsticks1=primaryhorizontalsticks1;
    column1=primarycolumn1;
    row1=primaryrow1;
    verticalsticks2=primaryverticalsticks2;
    horizontalsticks2=primaryhorizontalsticks2;
    column2=primarycolumn2;
    row2=primaryrow2;
    main();
    return 0;
}
