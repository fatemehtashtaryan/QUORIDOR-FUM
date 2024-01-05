#include "general_print_board.h"
#include "print_main_board.h"
#include "move_player.h"
#include "subcodes.h"
#include "checking_move.h"

int check_true_move;

int main()
{
    turn = 1 ;
    int n;
    general_print();
    boardgame(TotalRows, TotalColumn);
    printf("\n\n\n");
    column1=column1*8-5;//Changing the user's input number to the desired value
    column2=column2*8-5;//Changing the user's input number to the desired value
    row1=size_board*4-2;
    board[2][column2] = 300;
    board[size_board*4-2][column1] = 200;
    printboardgame(TotalRows, TotalColumn);
    while(row1 != 2 && row2 != size_board*4-2){
          n=1;
         do{
            if(n!=1){
            Sleep(2500);
            system("cls");
            Scoreboard();//in (Scoreboard_player)file that print scoreboards.
            printf("\n\n\n");
            printboardgame(TotalRows, TotalColumn);
            }
            check_true_move = move_play();//in move_player file
            n++;
         }while(check_true_move == 0) ;
         turn = 2 ;
         n = 1;
         system("cls");
         Scoreboard();//in Scoreboard_player file that print scoreboards.
         printf("\n\n\n");
         printboardgame(TotalRows, TotalColumn);
         if(row1 != 2){
            do{
                if(n!=1){
                Sleep(2500);
                system("cls");
                Scoreboard();//in (Scoreboard_player)file that print scoreboards.
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
                }
                check_true_move = move_play();//in move_player file
                n++;
            }while(check_true_move == 0);
                turn = 1;
                system("cls");
                Scoreboard();//in (Scoreboard_player)file that print scoreboards.
                printf("\n\n\n");
                printboardgame(TotalRows, TotalColumn);
             }
    }
    if (row1 == 2) printwon(name_player_1);
    else printwon(name_player_2);
    return 0;
}
