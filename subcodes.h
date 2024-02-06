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
int colorscreen=7,color=7 ;
int turn=1;
char PLAYER='P';
int typeplayer1=0,typeplayer2=0,typeplayer3=0,typeplayer4=0;


char name_player_1[20]="ONE", name_player_2[20]="TWO" ,name_player_3[20]="THREE", name_player_4[20]="FOUR";
int primaryrow1=18, primarycolumn1=19, primaryverticalsticks1=5, primaryhorizontalsticks1=5 ; //for reset
int primaryrow2=2, primarycolumn2=19, primaryverticalsticks2=5, primaryhorizontalsticks2=5 ;
int primaryrow3=10, primarycolumn3=3, primaryverticalsticks3=5, primaryhorizontalsticks3=5 ;
int primaryrow4=10, primarycolumn4=35, primaryverticalsticks4=5, primaryhorizontalsticks4=5 ;

int row1=18, column1=19, verticalsticks1=5, horizontalsticks1=5 ;
int row2=2, column2=19, verticalsticks2=5, horizontalsticks2=5 ;
int row3=10, column3=3, verticalsticks3=5, horizontalsticks3=5 ;
int row4=10, column4=35, verticalsticks4=5, horizontalsticks4=5 ;

int beat2=35 , beat1=42 , beat3=36 , beat4=63 ;
int beat1_1=35, beat1_2=42, beat2_1=36, beat2_2=63, beat3_1=58, beat3_2=21, beat4_1=25, beat4_2=40 ;
int beat_together=79;

int horizontalstick_copy2, horizontalstick_copy1, verticalstick_copy1, verticalstick_copy2; //for load
int horizontalstick_copy3, horizontalstick_copy4, verticalstick_copy3, verticalstick_copy4; //for load
int verticalstick_copy, horizontalstick_copy;
int load=1;

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

int swundo1=-1,swundo2=-1,swundo3=-1,swundo4=-1; //undo
int swmove1,swmove2,swmove3,swmove4,swstick1,swstick2,swstick3,swstick4;
int turncounter=0,turncounter1;
int row01,column01,row02,column02,row03,column03,row04,column04;

int i,t;

int sw_minimax=1; //minimax
int depth;
int row_minimax, column_minimax;
int counter=0;
int maxeval, mineval;
int ev,i,j,p;
int Row,Column,Row1,Column1;

int menu_direction; //for menu
int option_direction;

int Sw_four_playergame=1;
int Sw_rand_putstick=1;
int sw_computer_won=1;
int Sw_changecolumn=1;
int Sw_change1=1,Sw_change2=1,Sw_change3=1,Sw_change4=1;
int Swloding=1;
//for pells and rewards
int spell=1;
int Luckybox_counter=8;
int tboxrand=0;
int tloop;
int x1=50,x2=50, x3=50, x4=50;
int sw_turnagain1=1, sw_turnagain2=1, sw_turnagain3=1, sw_turnagain4=1;

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
    int Sw_four_playergame;
};
struct players_information infoplayer1;
struct players_information infoplayer2;
struct players_information infoplayer3;
struct players_information infoplayer4;

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

struct children true_child[350];
struct children true_child1[350];
struct children true_child2[350];

///////////////////////////////////structs for copy board(minimax)
struct copy_game{
     int copyverticalsticks1, copyhorizontalsticks1;
     int copyverticalsticks2, copyhorizontalsticks2;
     int copyboard[120][120];
};
struct copy_game copy_board;

#endif // subcodes

