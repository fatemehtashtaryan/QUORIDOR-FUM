#ifndef subcodes
#define subcodes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#define maxi 196
char name_player_1[20], name_player_2[20], TypeStick;
char message_board[6][100] ;
int TotalRows, TotalColumn ;
int beat2 , beat1 ;
int turn=1;
int turncounter=4;
int row1, column1, verticalsticks1, horizontalsticks1 ;
int row2=2, column2=1, verticalsticks2, horizontalsticks2 ;
int row01,column01,row02,column02;  //befor motion
int board[120][120];
int size_board ;
int beat2=36 , beat1 ;
int turn=1;
int turncounter=4;
int row1, column1, verticalsticks1, horizontalsticks1 ;
int primaryrow1, primarycolumn1, primaryverticalsticks1, primaryhorizontalsticks1 ; //for reset
int row2=2, column2=1, verticalsticks2=2, horizontalsticks2=2 ;
int primaryrow2=2, primarycolumn2=1, primaryverticalsticks2=2, primaryhorizontalsticks2=2 ;
int row01,column01,row02,column02;  //befor motion
int board[120][120];
int size_board=3 ;
int beat1_1=35, beat1_2=42, beat2_1=36, beat2_2=63 ;
int colorscreen=7 ;
int d=205 ;//horizontal line
int b=215 ;//vertical line
int a=201 ;//upper right corner
int f=187 ;//upper left corner
int e=188 ;//lower left corner
int c=200 ;//lower right corner
int sticks = 178 ;
int DFplayer;
int lastrow=0; //for DFS
int stick_movement_h_full[14][14];
int stick_movement_v_full[14][14];
<<<<<<< HEAD
int stick_movement_h_full_copy[14][14];
int stick_movement_v_full_copy[14][14];
=======
>>>>>>> d6b70ab19f65a62790f12e634d12e51e33c5f568
int coordRow, coordcolumn;
int Targetrow,Targetcolumn;
int swundo1=-1,swundo2=-1; //undo
int swmove1,swmove2,swstick1,swstick2;
char PLAYER;
char rowlocation,columnlocation; // the place of receipt of sticks
int load=0;
int i,sw=1,t;
int player2 = 8;
int sw_minimax;
int counter=0;
<<<<<<< HEAD
int typeplayer2=2;
int depth;
int Row,Column;
int horizontalstick_copy2, horizontalstick_copy1, verticalstick_copy1, verticalstick_copy2;
int verticalstick_copy, horizontalstick_copy;
=======
int typeplayer2=0;
int depth;
int Row,Column;
int  menu_direction;
int option_direction;
>>>>>>> d6b70ab19f65a62790f12e634d12e51e33c5f568
void setTextColor (int textColor, int backColor)
{
     HANDLE consoleHandle = GetStdHandle (STD_OUTPUT_HANDLE) ;
     int colorAttribute = backColor << 4 | textColor ;
     SetConsoleTextAttribute (consoleHandle, colorAttribute) ;
 }


void gotoxy (int x, int y)
{
    HANDLE consoleHandle = GetStdHandle (STD_OUTPUT_HANDLE) ;
    COORD cursorCoord ;
    cursorCoord.X = y ;
    cursorCoord.Y = x ;
    SetConsoleCursorPosition (consoleHandle, cursorCoord) ;
}

void beep (int frequency, int duration)
 {
    Beep (frequency, duration) ;
}

void sleep(unsigned int mseconds)
{
     clock_t goal = mseconds+ clock() ;
     while (goal > clock()) ;
}

void printslowly(const char *text, int x, int y)
{
     int number ;
     gotoxy (x, y) ;
     for(number = 0 ; text[number] != '\0'; number++)
        {
         printf ( "%c", text[number] ) ;
         sleep (100) ;
     }
}

////////////////////////////////// struct for visited houses
struct coordinates{
    int row;
    int column;
};
struct visited{
    struct coordinates location[maxi] ;
    int coordinatesNo;
};
struct visited house;


struct players_information{
    char name[20];
    int beat;
    int verticalsticks;
    int verticalstick;
    int horizontalstick;
    int row;
    int column;
    int turn;
    char player[10];
    int typeplayer;
    int primarycolumn;
    int primaryrow;
    int primaryverticalstick;
    int primaryhorizontalstick;
};
struct players_information infoplayer1;
struct players_information infoplayer2;

struct board_information{
    int colorscreen;
    int size_board ;
};
struct children{
         int row;
         int column;
         char movement;
         int numchildren;
         int score;
};

struct children true_child[120];

struct board_information infoboard;

struct copy_game{
     int copyverticalsticks1, copyhorizontalsticks1;
     int copyverticalsticks2, copyhorizontalsticks2;
     int copyboard[120][120];
};
struct copy_game copy_board;
#endif // subcodes
