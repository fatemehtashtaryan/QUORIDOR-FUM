#ifndef question_player
#define question_player

#include "subcodes.h"

void boardplayer1()
{
    char   beatnumber1;
     int counterrow, countercolumn, sw = 0;
     char tens_digit_column1, units_digit_column1, tens_digit_size_board, units_digit_size_board;
     //start of drawing board inforaition
     printf("%c", a);
     for(countercolumn = 0; countercolumn < 75; countercolumn++){
          printf("%c", d);
     }
     printf("%c", f);
     for(counterrow = 0; counterrow < 6; counterrow++){
         gotoxy(counterrow+1, 0);
          printf("%c", b);
     }
     gotoxy(counterrow+1, 0);
     printf("%c", c);
     for(countercolumn = 0; countercolumn < 75; countercolumn++){
          printf("%c", d);
     }
     printf("%c", e);
     for(counterrow = 6; counterrow > 0; counterrow--){
         gotoxy(counterrow, 76);
          printf("%c", b);
     }
     //end of drawing board inforaition
     gotoxy(1,1);
     //Start of asking for information
     printf("PLAYER 1:");
     gotoxy(2,2);
     printf("What is your name? ");
     scanf("%s", name_player_1);
     gotoxy(3,2);
     printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat1_1, beat1_2);
     while(1){
           beatnumber1 = getch();
           if(beatnumber1 > '2' || beatnumber1 < '1') beep(500,100);
           else{
            printf("%c", beatnumber1);
            break;
           }
     }
     if(beatnumber1 == '1') beat1 = beat1_1;
     else beat1 = beat1_2;
     getch();
     gotoxy(4,2);
     printf("Enter the column of your PLAYER(like 01 / 12): ");
     //Start of checking the player answer for column
          units_digit_size_board=size_board%10+'0';
     if(size_board >= 10)
        {
         tens_digit_size_board = '1';
     }
     else tens_digit_size_board = '0';
     while(sw != 1){
           tens_digit_column1 = getch();
           units_digit_column1 = getch();
           while((tens_digit_column1 != '0' && tens_digit_column1 != '1') || (units_digit_column1 < '0' || units_digit_column1 > '9')){
             beep(500,100);
             tens_digit_column1 = getch();
             units_digit_column1 = getch();
           }
            if(tens_digit_column1 == '0' && tens_digit_size_board == '0'){
              if(units_digit_column1 > units_digit_size_board) beep(500,100);
              else sw=1;
           }
           else  if(tens_digit_column1 == '0' && tens_digit_size_board == '1')  sw = 1;
           else if(tens_digit_column1 == tens_digit_size_board){
              if(units_digit_column1 > units_digit_size_board) beep(500,100);
              else sw = 1;
          }
          else beep(500,100);
          if(sw == 1){
            printf("%c%c", tens_digit_column1, units_digit_column1);
          }
     }
     tens_digit_column1 -= 48;
     units_digit_column1 -= 48;
     column1 = tens_digit_column1*10+units_digit_column1 ;
     //End of checking the player answer for column
     getch();
     gotoxy(5,2);
     printf("Enter your number of vertical sticks: ");
     scanf("%d", &verticalsticks1);
     gotoxy(6,2);
     printf("Enter your number of horizontal sticks: ");
     scanf("%d", &horizontalsticks1);
     //End of asking for information
}

void boardplayer2(){
     int counterrow, countercolumn, sw=0;
     char   beatnumber2;
     char units_digit_column2, tens_digit_column2, units_digit_size_board, tens_digit_size_board;
     //start of drawing board inforaition
     gotoxy(9,0);
     printf("%c", a);
     for(countercolumn = 0; countercolumn < 75; countercolumn++){
          printf("%c", d);
     }
     printf("%c", f);
     for(counterrow = 0; counterrow < 6; counterrow++){
         gotoxy(counterrow+10, 0);
          printf("%c", b);
     }
     gotoxy(counterrow+10, 0);
     printf("%c", c);
     for(countercolumn = 0; countercolumn < 75; countercolumn++){
          printf("%c", d);
     }
     printf("%c", e);
     for(counterrow = 6; counterrow > 0; counterrow--){
         gotoxy(counterrow+9, 76);
          printf("%c", b);
     }
     //end of drawing board inforaition
     gotoxy(10,1);
     //Start of asking for information
     printf("PLAYER 2:");
     gotoxy(11,2);
     printf("What is your name? ");
     scanf("%s", name_player_2);
     gotoxy(12,2);
     printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat2_1, beat2_2);
     while(1){
           beatnumber2 = getch();
           if (beatnumber2 > '2' || beatnumber2 < '1') beep(500,100);
           else{
            printf("%c", beatnumber2);
            break;
           }
     }
     if (beatnumber2 == '1') beat2 = beat2_1;
     else beat2 = beat2_2;
     getch();
     gotoxy(13,2);
     printf("Enter the column of your PLAYER(like 01 / 12): ");
     //Start of checking the player answer for column
     units_digit_size_board = size_board%10+'0';
     if (size_board >= 10){
         tens_digit_size_board = '1';
     }
     else tens_digit_size_board = '0';
     while (sw != 1){
           tens_digit_column2=getch();
           units_digit_column2=getch();
           while((tens_digit_column2 != '0' && tens_digit_column2 != '1') || (units_digit_column2 <'0' || units_digit_column2 > '9')|| (tens_digit_column2 == '0'&&units_digit_column2 == '0' ) ){
             beep(500,100);
             tens_digit_column2 = getch();
             units_digit_column2 = getch();
           }
           if (tens_digit_column2 == '0' && tens_digit_size_board == '0'){
              if (units_digit_column2 > units_digit_size_board) beep(500,100);
              else sw = 1;
           }
          else if (tens_digit_column2 == '0' && tens_digit_size_board == '1') sw = 1;
           else if (tens_digit_column2 == tens_digit_size_board){
              if (units_digit_column2 > units_digit_size_board) beep(500,100);
              else sw = 1;
          }
          else beep(500,100);
          if (sw == 1){
            printf("%c%c", tens_digit_column2, units_digit_column2);
          }
     }
     tens_digit_column2 -= 48;
     units_digit_column2 -= 48;
     column2 = tens_digit_column2*10 + units_digit_column2;
     //End of checking the player answer for column
     getch();
     gotoxy(14,2);
     printf("Enter your number of vertical sticks: ");
     scanf("%d", &verticalsticks2);
     gotoxy(15,2);
     printf("Enter your number of horizontal sticks: ");
     scanf("%d", &horizontalsticks2);
     //End of asking for information
}
#endif // question_player
