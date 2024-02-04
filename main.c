#include "general_print_board.h"
#include "print_main_board.h"
#include "move_player.h"
#include "subcodes.h"
#include "checking_move.h"
#include "computer_move_rand.h"
#include "computer_move_minimax.h"
#include "random_lucky_boxes.h"

//player2 = 'C'; ////is computer


int check_true_move;

int main()
{
    int n, sw;
    row1=size_board*4-2;
    row2=2;
    column3=3;
    column4=TotalColumn-4;
    primaryrow1=row1;
    primaryrow2=row2;
    primarycolumn3=column3;
    primarycolumn4=column4;
    for(Row = 0; Row <= TotalRows ; Row++){
         for(Column = 0; Column <= TotalColumn; Column++){
             board[Row][Column]=0;
            }
        }
     verticalsticks1=primaryverticalsticks1;
     horizontalsticks1=primaryhorizontalsticks1;
     verticalsticks2=primaryverticalsticks2;
     horizontalsticks2=primaryhorizontalsticks2;
     verticalsticks3=primaryverticalsticks3;
     horizontalsticks3=primaryhorizontalsticks3;
     verticalsticks4=primaryverticalsticks4;
     horizontalsticks4=primaryhorizontalsticks4;
     general_print();
    if(Sw_changecolumn==1){
        if(size_board%2==0 ){
            column1=8*(size_board/2)-5;
            primarycolumn1=column1;
            column2=column1;
            primarycolumn2=column2;
            row3=4*(size_board/2+1)+2;
            primaryrow3=row3;
            row4=row3;
            primaryrow4=row4;
        }else{
            column1=8*(size_board/2+1)-5;
            primarycolumn1=column1;
            column2=column1;
            primarycolumn2=column2;
            row3=4*(size_board/2)+2;
            primaryrow3=row3;
            row4=row3;
            primaryrow4=row4;
        }
    }
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
    if(load==1){
        setTextColor (0,colorscreen) ;
        Scoreboard();
        boardgame(TotalRows, TotalColumn);
        printf("\n\n\n");
        printboardgame(TotalRows, TotalColumn);
    }else{
         setTextColor (0,colorscreen) ;
         system("cls");
         setTextColor (0,colorscreen) ;
              Scoreboard();
              printf("\n\n\n");
              printboardgame(TotalRows, TotalColumn);

    }
    while(1){
       /*  if(Luckybox_counter==turncounter){
             system("cls");
             setTextColor (0,colorscreen) ;
             rand_boxes();
             Luckybox_counter+=tboxrand ;
             tboxrand+=6;
             setTextColor (0,colorscreen) ;
             system("cls");
             setTextColor (0,colorscreen) ;
             Scoreboard();
             printf("\n\n\n");
             printboardgame(TotalRows, TotalColumn);
         }*/
         n=1;
         turncounter++;
         if(load==1){
            turn=1;
         }
         if(turn==1){
         PLAYER='P';
         load=1;
         swmove1=0;
         swstick1=0;
            do{
                if(n!=1 ){
                Sleep(1500);
                gotoxy(15,76);
                printf("                   ");
                Scoreboard();//in (Scoreboard_player)file that print scoreboards.
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
               }

                gotoxy(TotalRows+16,0);
                printf("                                                                                              ") ;
                gotoxy(TotalRows+18,0);
                printf("                                                                           ");
                gotoxy(TotalRows+19,0);
                printf("                                                                           ");
                check_true_move = move_play();//in move_player file
                n++;
             }while(check_true_move == 0) ;}

         if(load==1){
            turn=2;
         }
         n = 1;
         Scoreboard();
         printf("\n\n\n");
         printboardgame(TotalRows, TotalColumn);
         turncounter++;
         if(row1 == 2) break;
         if( turn == 2 ){
            load=1;
            swmove2=0;
            swstick2=0;
            do{
                if(n != 1 && typeplayer2==0){
                Sleep(1500);
                gotoxy(15,76);
                printf("                   ");
                Scoreboard();
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
                }
                if( typeplayer2==0 ){
                gotoxy(TotalRows+16,0);
                printf("                                                                                              ") ;
                gotoxy(TotalRows+18,0);
                printf("                                                                           ");
                gotoxy(TotalRows+19,0);
                printf("                                                                           ");
                   check_true_move = move_play();//in move_player fil
                    n++;
                }
                else{
                  if(typeplayer2==1){
                    check_true_move = rand_move_computer();//in computer_move_rand.h
                  }else{
                    check_true_move = minimax_move_computer();
                  }
                }
            }while(check_true_move == 0);}
            if(Sw_four_playergame==1){
                turn = 1;
                Scoreboard();
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
                if(row2 == size_board*4-2) break;
            }else{ ////////////////////////////////////////////////////////////////////////////////////////////4 players
                 if(load==1){
                    turn = 3;
                 }
                 n = 1;
                 Scoreboard();
                 printf("\n\n\n");
                 printboardgame(TotalRows, TotalColumn);
                 turncounter++;
                 if(row2 == size_board*4-2) break;
                 if(turn==3){
                    load=1;
                    swmove3=0;
                    swstick3=0;
                    do{
                        if(n != 1 && typeplayer3==0){
                        Sleep(1500);
                        gotoxy(15,76);
                        printf("                   ");
                        Scoreboard();
                        printf("\n\n\n");
                        printboardgame(TotalRows, TotalColumn);
                        }
                        if( typeplayer3==0 ){
                            gotoxy(TotalRows+16,0);
                            printf("                                                                                              ") ;
                            gotoxy(TotalRows+18,0);
                            printf("                                                                           ");
                            gotoxy(TotalRows+19,0);
                            printf("                                                                           ");
                            check_true_move = move_play();//in move_player fil
                            n++;
                        }
                        else{
                           if(typeplayer3==1){
                             check_true_move = rand_move_computer();//in computer_move_rand.h
                          }
                        }
                    }while(check_true_move == 0);}
                 if(load==1){
                    turn = 4;
                  }
                 n = 1;
                 Scoreboard();
                 printf("\n\n\n");
                 printboardgame(TotalRows, TotalColumn);
                 turncounter++;
                 if(column3 == TotalColumn-4) break;
                 if(turn==4){
                    load=1;
                    swmove4=0;
                    swstick4=0;
                    do{
                        if(n != 1 && typeplayer4==0){
                            Sleep(1500);
                            gotoxy(15,76);
                            printf("                   ");
                            Scoreboard();
                            printf("\n\n\n");
                            printboardgame(TotalRows, TotalColumn);

                         }if( typeplayer4==0 ){
                            gotoxy(TotalRows+16,0);
                            printf("                                                                                              ") ;
                            gotoxy(TotalRows+18,0);
                            printf("                                                                           ");
                            gotoxy(TotalRows+19,0);
                            printf("                                                                           ");
                            check_true_move = move_play();//in move_player fil
                            n++;

                         }else{
                              if(typeplayer4==1){
                                check_true_move = rand_move_computer();//in computer_move_rand.h
                              }
                            }
                     }while(check_true_move == 0);}
                turn = 1;
                Scoreboard();
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
                if(column4 == 3) break;
          }
    }

    if (row1 == 2)printwon(name_player_1);
    else if( row2 == size_board*4-2  ) printwon(name_player_2);
    else if(column3 == TotalColumn-4 ) printwon(name_player_3);
    else if(column4 == 3 ) printwon(name_player_3);\

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
    verticalsticks3=primaryverticalsticks3;
    horizontalsticks3=primaryhorizontalsticks3;
    column3=primarycolumn3;
    row3=primaryrow3;
    verticalsticks4=primaryverticalsticks4;
    horizontalsticks4=primaryhorizontalsticks4;
    column4=primarycolumn4;
    row4=primaryrow4;
    main();
    return 0;
}
