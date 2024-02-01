#ifndef question_player
#define question_player

#include "subcodes.h"
#include "setting.h"
//This file contains the tables that contain the questions needed at the beginning of the game
//up_move=72;
// down_move=80
// left_move=75;
// right_move=77;
int question_frame(int x,int y, int n){
     int h=1, counterrow, countercolumn;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < n; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < 2; counterrow++)
    {
         gotoxy(x+h, y) ;
          printf("%c", b) ;
          h++;
     }
     gotoxy(x+3, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn <n; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     h=1;
     for(counterrow = 2; counterrow > 0; counterrow--)
    {
         gotoxy(x+h, y+n+1) ;
          printf("%c", b) ;
          h++;
    }
}


void question_boardplayer1()
{
    char  beatnumber1, verticalstick, horizontalstick, setting_direction=12;
     int counterrow, countercolumn, sw = 0, number=0, type=1, sw_setting=0, n=1;
     char tens_digit_column1, units_digit_column1, tens_digit_size_board, units_digit_size_board;
     gotoxy(2,49); setTextColor (7,0); printf("Q U O R I D O R   SETTING!");
     setTextColor (13,0);frame(3, 32, 56, 24);
     question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 1");
     setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
     question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat1_1, beat1_2);
     question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
     question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
     question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
     question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
     do{
     while(1){
        setting_direction = getch() ;
        if(setting_direction==13) break;
        setting_direction = getch() ;
        number++;
        if(setting_direction==75 || setting_direction==72){
            if(type==1){number=6;}
            if(type==2){number=1;}
            if(type==3){number=2;}
            if(type==4){number=3;}
            if(type==5){number=4;}
            if(type==6){number=5;}
         }
         if(number==1){
            setTextColor (7,0);
            gotoxy(2,49);
            printf("Q U O R I D O R   SETTING!");
            setTextColor (13,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 1");
            setTextColor (7,0); question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat1_1, beat1_2);
            question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
           question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
           question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
           question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
           setTextColor (11,0);
           question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
           type =1;
         }
         if(number==2){
            setTextColor (7,0);
            gotoxy(2,49);
            printf("Q U O R I D O R   SETTING!");
            setTextColor (13,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 1");
            setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
            question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
            question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
            question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
            question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
            setTextColor (4,0);
            question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat1_1, beat1_2);
            type = 2;
         }
         if(number==3){
            setTextColor (7,0);
            gotoxy(2,49);
            printf("Q U O R I D O R   SETTING!");
            setTextColor (13,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 1");
            setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
            question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat1_1, beat1_2);
            question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
            question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
            question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
            setTextColor (6,0);
            question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
            type =3;
         }
          if(number==4){
            setTextColor (7,0);
            gotoxy(2,49);
            printf("Q U O R I D O R   SETTING!");
            setTextColor (13,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 1");
            setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
            question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat1_1, beat1_2);
            question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
            question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
            question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
            setTextColor (2,0);
            question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
            type=4;
          }
           if(number==5){
            setTextColor (7,0);
            gotoxy(2,49);
            printf("Q U O R I D O R   SETTING!");
            setTextColor (13,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 1");
            setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
            question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat1_1, beat1_2);
            question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
            question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
            question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
            setTextColor (1,0);
            question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
            type= 5;
           }
           if(number==6){
            setTextColor (7,0);
            gotoxy(2,49);
            printf("Q U O R I D O R   SETTING!");
            setTextColor (13,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 1");
            setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
            question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat1_1, beat1_2);
            question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
            question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
            question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
            setTextColor (5,0);
            question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
            type=6;
            number =0;
           }
     }
      setting_direction=12;
      if(type==1){
        gotoxy(9, 65);
        printf(" ");
        setTextColor (11,0);
        gets(name_player_1);
      }
     if(type==2){
        gotoxy(13, 83);
        printf(" ");
        setTextColor (4,0);
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
             }
        if(type == 3){
            setTextColor (6,0);
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
                    gotoxy(17, 83);
                    printf(" ");
                    printf("%c%c", tens_digit_column1, units_digit_column1);
                  }
             }
             tens_digit_column1 -= '0';
             units_digit_column1 -= '0';
             column1 = tens_digit_column1*10+units_digit_column1 ;
             column1=column1*8-5;//Changing the user's input number to the desired value
             getch();
            }
       if(type == 4){
            setTextColor (2,0);
            verticalstick=getch();
            while(verticalstick>'9' || verticalstick<'1'){//check the number of verticalstick, It should not be more than 9
                beep(500, 100);
                verticalstick=getch();
             }
            verticalsticks1=verticalstick-'0';
            gotoxy(21, 79);
            printf(" ");
            printf("%d", verticalsticks1);
            getch();
            }
      if(type == 5){
          setTextColor (1,0);
          horizontalstick=getch();
         while(horizontalstick>'9' || horizontalstick<'1'){//check the number of horizontalstick, It should not be more than 9
            beep(500, 100);
            horizontalstick=getch();
         }
         horizontalsticks1 = horizontalstick - '0' ;
         gotoxy(25, 80);
         printf(" ");
         printf("%d", horizontalsticks1);
         getch();
        }
     if(type == 6){
        system("cls");
        setting_player();
        sw_setting = 1;
     }
    }while(sw_setting==0);
}

void question_boardplayer2(){
      int counterrow, countercolumn, sw = 0, number=0, type=1, sw_setting=0, n=1;
     char   beatnumber2, verticalstick, horizontalstick, setting_direction=12;
     char units_digit_column2, tens_digit_column2, units_digit_size_board, tens_digit_size_board;
     setTextColor (7,0); gotoxy(2,49); printf("Q U O R I D O R   SETTING!");
     setTextColor (9,0); frame(3, 32, 56, 24);
     question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 2");
     setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
     question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat2_1, beat2_2);
     question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
     question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
     question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
     question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
     do{
        while(1){
           setting_direction = getch() ;
           if(setting_direction==13) break;
            setting_direction = getch() ;
            number++;
            if(setting_direction==75 || setting_direction==72){
                if(type==1){number=6;}
                if(type==2){number=1;}
                if(type==3){number=2;}
                if(type==4){number=3;}
                if(type==5){number=4;}
                if(type==6){number=5;}
             }
             if(number==1){
                setTextColor (7,0);
                gotoxy(2,49);
                printf("Q U O R I D O R   SETTING!");
                setTextColor (9,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 2");
                setTextColor (7,0); question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat2_1, beat2_2);
                question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
               question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
               question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
               question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
               setTextColor (11,0);
               question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
               type =1;
             }
             if(number==2){
                setTextColor (7,0);
                gotoxy(2,49);
                printf("Q U O R I D O R   SETTING!");
                setTextColor (9,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 2");
                setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
                question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
                question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
                question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
                question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
                setTextColor (4,0);
                question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat2_1, beat2_2);
                type = 2;
             }
             if(number==3){
                setTextColor (7,0);
                gotoxy(2,49);
                printf("Q U O R I D O R   SETTING!");
                setTextColor (9,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 2");
                setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
                question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat2_1, beat2_2);
                question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
                question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
                question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
                setTextColor (6,0);
                question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
                type =3;
             }
              if(number==4){
                setTextColor (7,0);
                gotoxy(2,49);
                printf("Q U O R I D O R   SETTING!");
                setTextColor (9,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 2");
                setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
                question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat2_1, beat2_2);
                question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
                question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
                question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
                setTextColor (2,0);
                question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
                type=4;
              }
               if(number==5){
                setTextColor (7,0);
                gotoxy(2,49);
                printf("Q U O R I D O R   SETTING!");
                setTextColor (9,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 2");
                setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
                question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat2_1, beat2_2);
                question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
                question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
                question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
                setTextColor (1,0);
                question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
                type= 5;
               }
               if(number==6){
                setTextColor (7,0);
                gotoxy(2,49);
                printf("Q U O R I D O R   SETTING!");
                setTextColor (9,0); question_frame(4, 54, 12); gotoxy(5, 57); printf("PLAYER 2");
                setTextColor (7,0); question_frame(8, 45, 30); gotoxy(9, 47); printf("What is your name? ");
                question_frame(12, 35, 50); gotoxy(13, 37); printf("Enter your beat number(beat1= %c ; beat2= %c ): ", beat2_1, beat2_2);
                question_frame(16, 35, 50); gotoxy(17, 37); printf("Enter the column of your PLAYER(like 01 / 12): ");
                question_frame(20, 39, 43); gotoxy(21, 41); printf("Enter your number of vertical sticks: ");
                question_frame(24, 39, 43); gotoxy(25, 41); printf("Enter your number of horizontal sticks: ");
                setTextColor (5,0);
                question_frame(29, 56, 8); gotoxy(30, 59); printf("EXIT");
                type=6;
                number =0;
               }
     }
      if(type==1){
        gotoxy(9, 65);
        printf(" ");
        setTextColor (11,0);
        gets(name_player_2);
      }
     if(type==2){
        gotoxy(13, 83);
        printf(" ");
        setTextColor (4,0);
         while(1){
               beatnumber2 = getch();
               if(beatnumber2 > '2' || beatnumber2 < '1') beep(500,100);
               else{
                printf("%c", beatnumber2);
                break;
               }
        }
           if(beatnumber2 == '1') beat2 = beat2_1;
          else beat2 = beat2_2;
          getch();
        }
    if(type == 3){
                setTextColor (6,0);
                 units_digit_size_board=size_board%10+'0';
             if(size_board >= 10)
                {
                 tens_digit_size_board = '1';
             }
             else tens_digit_size_board = '0';
             while(sw != 1){
                   tens_digit_column2 = getch();
                   units_digit_column2 = getch();
                   while((tens_digit_column2 != '0' && tens_digit_column2 != '1') || (units_digit_column2 < '0' || units_digit_column2 > '9')){
                     beep(500,100);
                     tens_digit_column2 = getch();
                     units_digit_column2 = getch();
                   }
                    if(tens_digit_column2 == '0' && tens_digit_size_board == '0'){
                      if(units_digit_column2 > units_digit_size_board) beep(500,100);
                      else sw=1;
                   }
                   else  if(tens_digit_column2 == '0' && tens_digit_size_board == '1')  sw = 1;
                   else if(tens_digit_column2 == tens_digit_size_board){
                      if(units_digit_column2 > units_digit_size_board) beep(500,100);
                      else sw = 1;
                  }
                  else beep(500,100);
                  if(sw == 1){
                    gotoxy(17, 83);
                    printf(" ");
                    printf("%c%c", tens_digit_column2, units_digit_column2);
                  }
             }
             tens_digit_column2 -= '0';
             units_digit_column2 -= '0';
             column2 = tens_digit_column2*10+units_digit_column2 ;
             column2=column2*8-5;//Changing the user's input number to the desired value
             getch();
        }
       if(type == 4){
            setTextColor (2,0);
            verticalstick=getch();
            while(verticalstick>'9' || verticalstick<'1'){//check the number of verticalstick, It should not be more than 9
                beep(500, 100);
                verticalstick=getch();
             }
            verticalsticks2=verticalstick-'0';
            gotoxy(21, 79);
            printf(" ");
            printf("%d", verticalsticks2);
            getch();
       }
      if(type == 5){
          setTextColor (1,0);
          horizontalstick=getch();
         while(horizontalstick>'9' || horizontalstick<'1'){//check the number of horizontalstick, It should not be more than 9
            beep(500, 100);
            horizontalstick=getch();
         }
         horizontalsticks2 = horizontalstick - '0' ;
         gotoxy(25, 80);
         printf(" ");
         printf("%d", horizontalsticks2);
         getch();
      }
     if(type == 6){
        system("cls");
        setting_player();
        sw_setting = 1;
     }
    }while(sw_setting==0);
}

#endif // question_player
