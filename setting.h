#ifndef setting
#define setting

#include "design_screen.h"
#include "subcodes.h"
#include "question_player.h"
#include "general_print_board.h"

int setting_shape(int x,int y, int n){
     int h=1, counterrow, countercolumn;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < n; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow <= 2; counterrow++)
    {
         gotoxy(x+h, y) ;
          printf("%c", b) ;
          h++;
     }
     gotoxy(x+4, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn <n; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     h=1;
     for(counterrow = 2; counterrow >= 0; counterrow--)
    {
         gotoxy(x+h, y+n+1) ;
          printf("%c", b) ;
          h++;
    }
}

int frame(int x,int y, int m, int n){
    int counterrow, countercolumn,h=1;
     h=1;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < m; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < n; counterrow++)
    {
         gotoxy(x+h, y) ;
          printf("%c", b) ;
          h++;
     }
     gotoxy(x+n+1, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn <m; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     h=1;
     for(counterrow = n; counterrow > 0; counterrow--)
    {
         gotoxy(x+h, y+m+1) ;
          printf("%c", b) ;
          h++;
    }
}

int setting_player(){
     char setting_direction;
     int number=0, type=1, sw_setting=0;
     setTextColor (7,0);
     system("cls");
     setTextColor (7,0);
     frame(6, 28, 69, 11);
     gotoxy(2,49); printf("Q U O R I D O R   SETTING!");
     setting_shape(7, 30, 30); gotoxy(9, 34); printf("First player information");
     setting_shape(7, 65, 30); gotoxy(8, 69); printf("Second player information"); gotoxy(10, 74); printf("(TWO players)");
     setting_shape(13, 30, 30); gotoxy(15, 37); printf("Game screen color");
     setting_shape(13, 65, 30); gotoxy(15, 74); printf("Game board size");
     setting_shape(21, 57, 10); gotoxy(23, 61); printf("EXIT");
     do{
           while(1){
             setting_direction = getch() ;
             if(setting_direction==13) break;
             setting_direction = getch() ;
             number++;
             if(setting_direction==75 || setting_direction==72){
                if(type==1){number=5;}
                if(type==2){number=1;}
                if(type==3){number=2;}
                if(type==4){number=3;}
                if(type==5){number=4;}
             }
            if(number==1){
                setTextColor (7,0); gotoxy(2,49); printf("Q U O R I D O R   SETTING!");
                setting_shape(7, 65, 30); gotoxy(8, 69); printf("Second player information"); gotoxy(10, 74); printf("(TWO players)");
                setting_shape(13, 30, 30); gotoxy(15, 37); printf("Game screen color");
                setting_shape(13, 65, 30); gotoxy(15, 74); printf("Game board size");
                setting_shape(21, 57, 10); gotoxy(23, 61); printf("EXIT");
                setTextColor (13,0);
                setting_shape(7, 30, 30); gotoxy(9, 34); printf("First player information");
                type = 1;
            }
            if(number==2){
                setTextColor (7,0); gotoxy(2,49); printf("Q U O R I D O R   SETTING!");
                setting_shape(7, 30, 30); gotoxy(9, 34); printf("First player information");
                setting_shape(13, 30, 30); gotoxy(15, 37); printf("Game screen color");
                setting_shape(13, 65, 30); gotoxy(15, 74); printf("Game board size");
                setting_shape(21, 57, 10); gotoxy(23, 61); printf("EXIT");
                setTextColor (9,0);
                setting_shape(7, 65, 30); gotoxy(8, 69); printf("Second player information"); gotoxy(10, 74); printf("(TWO players)");
                type = 2;
            }
           if(number==3){
                setTextColor (7,0); gotoxy(2,49); printf("Q U O R I D O R   SETTING!");
                setting_shape(7, 30, 30); gotoxy(9, 34); printf("First player information");
                setting_shape(7, 65, 30); gotoxy(8, 69); printf("Second player information"); gotoxy(10, 74); printf("(TWO players)");
                setting_shape(13, 65, 30); gotoxy(15, 74); printf("Game board size");
                setting_shape(21, 57, 10); gotoxy(23, 61); printf("EXIT");
                setTextColor (12,0);
                setting_shape(13, 30, 30); gotoxy(15, 37); printf("Game screen color");
                type = 3;
            }
           if(number==4){
                setTextColor (7,0); gotoxy(2,49); printf("Q U O R I D O R   SETTING!");
                setting_shape(7, 30, 30); gotoxy(9, 34); printf("First player information");
                setting_shape(7, 65, 30); gotoxy(8, 69); printf("Second player information"); gotoxy(10, 74); printf("(TWO players)");
                setting_shape(13, 30, 30); gotoxy(15, 37); printf("Game screen color");
                setting_shape(21, 57, 10); gotoxy(23, 61); printf("EXIT");
                setTextColor (10, 0);
                setting_shape(13, 65, 30); gotoxy(15, 74); printf("Game board size");
                type = 4;
           }
         if(number==5){
                setTextColor (7,0); gotoxy(2,49); printf("Q U O R I D O R   SETTING!");
                setting_shape(7, 30, 30); gotoxy(9, 34); printf("First player information");
                setting_shape(7, 65, 30); gotoxy(8, 69); printf("Second player information"); gotoxy(10, 74); printf("(TWO players)");
                setting_shape(13, 30, 30); gotoxy(15, 37); printf("Game screen color");
                setting_shape(13, 65, 30); gotoxy(15, 74); printf("Game board size");
                setTextColor (5, 0);
                setting_shape(21, 57, 10); gotoxy(23, 61); printf("EXIT");
                type = 5;
                number = 0;
           }
         }
         if(type==1){
            system("cls");
            question_boardplayer1();
         }
        if (type==2) {
             system("cls");
             question_boardplayer2();
         }
         else if(type ==3){
             system("cls");
             Design_color_screen();
              if(colorscreen ==15 ){
            system ("COLOR F0") ;

        }
        if(colorscreen == 11){
            system ("COLOR B0") ;

        }
        if(colorscreen == 14){
            system ("COLOR E0") ;
        }
         }
         else if(type == 4){
            system("cls");
            sizeboard();
            row1=size_board*4-2;
         }
         else {
            setTextColor (7,0);
            system("cls");
            sw_setting=1;
            main();
           }
    }while(sw_setting==0);
}
#endif // setting
