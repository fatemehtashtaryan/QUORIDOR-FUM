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
int beat2, beat1 ;
int turn;
int row1, column1, verticalsticks1, horizontalsticks1 ;
int row2=2, column2, verticalsticks2, horizontalsticks2 ;
int board[120][120] ;
int size_board ;
int beat1_1=35, beat1_2=42, beat2_1=36, beat2_2=126 ;
int colorscreen = 7 ;
int d=205 ;//horizontal line
int b=215 ;//vertical line
int a=201 ;//upper right corner
int f=187 ;//upper left corner
int e=188 ;//lower left corner
int c=200 ;//lower right corner
int sticks = 178 ;
int DFplayer;
int lastrow=0; //for DFS

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

#endif // subcodes
