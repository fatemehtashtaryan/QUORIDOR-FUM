#ifndef checking_move
#define checking_move

#include "subcodes.h"

//up_move=72;
// down_move=80
// left_move=75;
// right_move=77;

int check_move (int type_of_movement)
{
    int full_house, row, column, beat, x;
   if(size_board>12) x = 10 ;
   else x = 15 ;
   if (turn == 1){
      beat = 200;
      column = column1;
      row = row1;
      full_house = 300;
   }
   else {//turn == 2 OR turn == 3;
      beat = 300;
      column = column2;
      row = row2;
      full_house = 200;
   }
   switch (type_of_movement){
     case 72 :
        if (board[row-2][column] == 1000 || board[row-2][column] == 8 || board[row-2][column] == 2000)//check sticks & walls
        {
            if(turn != 3){
              beep(500, 100);
              gotoxy(x, 44);
              setTextColor(12, colorscreen);
              printf("your way is C L O S E D!");
              setTextColor(0, colorscreen);
            }
            return 0;
        }
        else if (board[row-4][column] == full_house )//check empty house
        {
            if(turn != 3){
              beep(500, 100);
              gotoxy(x, 44);
              setTextColor(12, colorscreen);
              printf("house is F U L L!");
              setTextColor(0, colorscreen);
            }
            return 0;
        }
        else
        {
            board[row][column] = 0 ;
            board[row-4][column] = beat ;//placing beat
            row -= 4 ;
             if (turn == 1){
               column1 = column;
               row1 = row;
            }
           else {//turn == 2;
             column2 = column;
             row2 = row;
           }
            return 1;
        }
        break;

    case 80 :
        if ( board[row+2][column] == 1000 || board[row+2][column] == 8 || board[row+2][column] == 2000)//check sticks & walls
        {
            if(turn != 3){
              beep (500, 100);
              gotoxy (x, 44);
              setTextColor (12, colorscreen);
              printf ("your way is C L O S E D!");
              setTextColor(0, colorscreen);
            }
            return 0;
        }
        else if (board[row+4][column] == full_house )//check empty house
        {
            if(turn != 3){
              beep (500, 100);
              gotoxy (x, 44);
              setTextColor (12, colorscreen);
              printf ("house is F U L L!");
              setTextColor(0, colorscreen);
            }
            return 0;
        }
        else
        {
            board[row][column] = 0 ;
            board[row+4][column] = beat ;//placing beat
            row += 4;
             if (turn == 1){
               column1 = column;
               row1 = row;
            }
           else {//turn == 2; OR turn ==3
             column2 = column;
             row2 = row;
           }
            return 1;
        }
        break;

    case 77:
        if (board[row][column+4] ==1000 || board[row][column+3]==7 || board[row][column+4] ==2000)//check sticks & walls
            {
            if(turn != 3){
              beep(500, 100);
              gotoxy(x, 44);
              setTextColor(12, colorscreen);
              printf("your way is C L O S E D!");
              setTextColor(0, colorscreen);
           }
            return 0;
        }
        else if (board[row][column+8] == full_house)//check empty house
           {
            if(turn != 3){
                beep(500, 100);
                gotoxy(x, 44);
                setTextColor(12, colorscreen);
                printf("house is F U L L!");
                setTextColor(0, colorscreen);
            }
            return 0;
        }
        else{
            board[row][column]=0;
            board[row][column+8] = beat;//placing beat
            column += 8;
             if (turn == 1){
               column1 = column;
               row1 = row;
            }
           else {//turn == 2; OR turn ==3
             column2 = column;
             row2 = row;
           }
            return 1;
        }
        break;

    case 75:
        if (board[row][column-4] == 1000 || board[row][column-3] == 7 || board[row][column-4] == 2000)//check sticks & walls
            {
            if(turn != 3){
              beep(500, 100);
              gotoxy(x, 44);
              setTextColor(12, colorscreen);
              printf("your way is C L O S E D!");
              setTextColor(0, colorscreen);
            }
            return 0;
        }
        else if(board[row][column-8] == full_house)//check empty house
            {
            if(turn != 3){
              beep(500, 100);
              gotoxy(x, 44);
              setTextColor(12, colorscreen);
              printf("house is F U L L!");
              setTextColor(0, colorscreen);
            }
            return 0;
        }
        else{
            board[row][column] = 0;
            board[row][column-8] = beat;//placing beat
            column -= 8;
            if (turn == 1){
               column1 = column;
               row1 = row;
            }
         else {//turn == 2 OR turn ==3
             column2 = column;
             row2 = row;
          }
            return 1;
        }
        break;
   }
}
#endif // checking_move
