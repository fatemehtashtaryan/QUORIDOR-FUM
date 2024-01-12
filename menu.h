#include "subcodes.h"
int counterrow, countercolumn,t=1;
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
     t=1;

     gotoxy(x+1, y+9) ;
     printf("%c", b) ;


}
int home_menu(int x,int y){
     t=1;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < 35; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < 3; counterrow++)
    {
         gotoxy(x+t, y) ;
          printf("%c", b) ;
          t++;
     }
     gotoxy(x+4, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn < 35; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     t=1;
     for(counterrow = 3; counterrow > 0; counterrow--)
    {
         gotoxy(x+t, y+36) ;
          printf("%c", b) ;
          t++;

    }
}
