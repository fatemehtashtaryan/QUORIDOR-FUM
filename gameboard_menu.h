#include "subcodes.h"

// this file is about formation of game menus

int counterrow, countercolumn,h=1;
int menu_frame(int x,int y){
     h=1;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < 52; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < 20; counterrow++)
    {
         gotoxy(x+h, y) ;
          printf("%c", b) ;
          h++;
     }
     gotoxy(x+21, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn <52; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     h=1;
     for(counterrow = 20; counterrow > 0; counterrow--)
    {
         gotoxy(x+h, y+53) ;
          printf("%c", b) ;
          h++;

    }
}
int menu(int x,int y){
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < 8; countercolumn++)
     {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;

     gotoxy(x+1, y) ;
     printf("%c", b) ;


     gotoxy(x+2, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn < 8; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     h=1;

     gotoxy(x+1, y+9) ;
     printf("%c", b) ;


}
int home_menu(int x,int y){
     h=1;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < 35; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < 3; counterrow++)
    {
         gotoxy(x+h, y) ;
          printf("%c", b) ;
          h++;
     }
     gotoxy(x+4, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn < 35; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     h=1;
     for(counterrow = 3; counterrow > 0; counterrow--)
    {
         gotoxy(x+h, y+36) ;
          printf("%c", b) ;
          h++;

    }
}
int menu_opponent(int x,int y){
     h=1;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < 15; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < 3; counterrow++)
    {
         gotoxy(x+h, y) ;
          printf("%c", b) ;
          h++;
     }
     gotoxy(x+4, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn <15; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     h=1;
     for(counterrow = 3; counterrow > 0; counterrow--)
    {
         gotoxy(x+h, y+16) ;
          printf("%c", b) ;
          h++;

    }
}
