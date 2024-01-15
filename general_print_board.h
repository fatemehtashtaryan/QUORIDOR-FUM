#include "question_player.h"
#include "Scoreboard_player.h"
#include "design_screen.h"
#include "main_board.h"
#include "subcodes.h"

//This file arranges the functions that we need at the beginning of the game and also includes questions such as the size of the board

void general_print()
{
   /* loading();
    system("cls");
    setTextColor (3, 0) ;
    TotalRows=9, TotalColumn=15;
    printf("\n\n\n\n");
    size_board=2;
    boardgame(TotalRows,TotalColumn);
    logo(TotalRows,TotalColumn);
    setTextColor (0, 10) ;
    const char *welcome = "Welcome to the FUM QUORIDOR!";
    printslowly( welcome,18,48) ;
    sleep (150) ;
    setTextColor(0, 7);
    system ("cls") ;
    gotoxy (15, 43) ;
    sleep (100) ;
    setTextColor (0, 3) ;
    Design_color_screen() ;
    system ("cls") ;
    gotoxy (15, 47) ;
    setTextColor (34, colorscreen) ;*/
    printf ("Enter the size of the GAME BOARD: ") ;
    while(1)
    {
        scanf ("%d", &size_board) ;
        if ( size_board > 15 || size_board <= 0 )
        {
            beep (500,100) ;
            system ("cls") ;
            gotoxy (15, 70) ;
            printf ("WRONG!") ;
            sleep (800) ;
            system ("cls") ;
            gotoxy (15, 47) ;
            printf ("Enter the size of the GAME BOARD: ") ;
        }
        else break ;
    }
    //Converting to desired number of columns and rows
    TotalRows = 4*size_board+1 ;
    TotalColumn = 8*size_board-1 ;
    system ("cls") ;
    setTextColor (0, colorscreen) ;
    question_boardplayer1() ;
    if(turn != 3) question_boardplayer2() ;
    system ("cls") ;
    sleep (50) ;
    Scoreboard() ;
}
