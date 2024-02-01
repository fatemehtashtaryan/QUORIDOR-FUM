#ifndef subcodes
#define subcodes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#define maxi 196

int board[120][120];
int TotalRows=4*5+1, TotalColumn=8*5-1 ;
int size_board=5;
int colorscreen=7 ;
int turn=1;
char PLAYER;
int typeplayer2=0;

char name_player_1[20]="ONE", name_player_2[20]="TWO";
int primaryrow1=30, primarycolumn1=3, primaryverticalsticks1=5, primaryhorizontalsticks1=5 ; //for reset
int primaryrow2=2, primarycolumn2=3, primaryverticalsticks2=5, primaryhorizontalsticks2=5 ;

int row1=18, column1=3, verticalsticks1=5, horizontalsticks1=5 ;
int row2=2, column2=3, verticalsticks2=5, horizontalsticks2=5 ;
int beat2=36 , beat1=42 ;
int beat1_1=35, beat1_2=42, beat2_1=36, beat2_2=63 ;

int horizontalstick_copy2, horizontalstick_copy1, verticalstick_copy1, verticalstick_copy2; //for load
int verticalstick_copy, horizontalstick_copy;
int load=0;

int d=205 ;//horizontal line
int b=215 ;//vertical line
int a=201 ;//upper right corner
int f=187 ;//upper left corner
int e=188 ;//lower left corner
int c=200 ;//lower right corner
int sticks = 178 ;

int DFplayer; //for DFS
int lastrow=0;
int coordRow, coordcolumn;
char rowlocation,columnlocation; // the place of receipt of sticks
char TypeStick;

int Targetrow,Targetcolumn; //for BFS

int stick_movement_h_full[14][14];
int stick_movement_v_full[14][14];
int stick_movement_h_full_copy[14][14];
int stick_movement_v_full_copy[14][14];

int swundo1=-1,swundo2=-1; //undo
int swmove1,swmove2,swstick1,swstick2;
int turncounter=0,turncounter1;
int row01,column01,row02,column02;

int i,t;

int sw_minimax=1; //minimax
int sw_movecomputer;
int depth;
int row_minimax, column_minimax;
int counter=0;

int Row,Column,Row1,Column1;

int menu_direction; //for menu
int option_direction;

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

//////////////////////////////struct for load
struct players_information{
    char name[20];
    int beat;
    int verticalstick;
    int horizontalstick;
    int row;
    int column;
    int turn;
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
struct board_information infoboard;

///////////////////////////struct for find childs
struct children{
         int row;
         int column;
         char movement;
         int numchildren;
         int score;

};

struct children true_child[120];
struct children true_child1[120];
struct children true_child2[120];

///////////////////////////////////structs for copy board(minimax)
struct copy_game{
     int copyverticalsticks1, copyhorizontalsticks1;
     int copyverticalsticks2, copyhorizontalsticks2;
     int copyboard[120][120];
};
struct copy_game copy_board;

#endif // subcodes
