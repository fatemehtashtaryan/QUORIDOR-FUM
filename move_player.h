#include "subcodes.h"
#include "checking_move.h"
#include "check_sticks.h"

int move_player;
int result_check;
int move_player1()
{
    char type_move ;
    printf( "Select ACTION: 1 = MOVE / 2 = STICKS") ;
    printf("\n");
    type_move=getch();
    while(type_move != '1' && type_move != '2'){
        beep(500,100);
        type_move=getch();
    }
    type_move -='0';
    int movement = type_move;
    if(movement == 1)
        {
        printf("BY : v ^ > < ") ;
        move_player = getch() ;
        while(move_player != 224)//check true button
        {
            beep(500,100) ;
            move_player = getch();
        }
        move_player = getch() ; //up or down or right or left
        result_check = check_move1(move_player) ; //in checking move header
        }
    else if(movement == 2)
    {
        printf("Type Stick? Horizontal = H / Vertical = V");
        TypeStick = getch();
        while (TypeStick != 'H' && TypeStick != 'h' && TypeStick != 'V' && TypeStick != 'v'){
            beep(500, 100);
            TypeStick=getch();
        }
        result_check = CheckSticksPlayers(TypeStick);
    }
    return result_check;
}

int move_player2()
{
    char type_move ;
    printf( "Select ACTION: 1 = MOVE / 2 = STICKS") ;
    printf("\n");
    type_move=getch();
    while(type_move != '1' && type_move != '2'){
        beep(500,100);
        type_move=getch();
    }
    type_move -='0';
    int movement = type_move;
    if( movement == 1 )
        {
        printf( "BY : v ^ > < " ) ;
        move_player = getch() ;
        while( move_player != 224 )//check true button
        {
            beep (500,100) ;
            move_player = getch() ;
        }
        move_player = getch() ;//up or down or right or left
            result_check=check_move2(move_player) ;//in checking move header
        }
    else if(movement == 2)
    {
        printf("Type Stick? Horizontal = H / Vertical = V");
        TypeStick=getch();
        while (TypeStick != 'H' && TypeStick != 'h' && TypeStick != 'V' && TypeStick != 'v'){
            beep(500, 100);
            TypeStick=getch();
        }
        result_check = CheckSticksPlayers(TypeStick);
    }
    return result_check;
}
