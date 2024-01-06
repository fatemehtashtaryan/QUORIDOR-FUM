#include "subcodes.h"
int menu(int x,int y){
     int counterrow, countercolumn,t=1;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < 8; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < 1; counterrow++)
    {
         gotoxy(x+t, y) ;
          printf("%c", b) ;
          t++;
     }
     gotoxy(x+2, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn < 8; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     t=1;
     for(counterrow = 1; counterrow > 0; counterrow--)
    {
         gotoxy(x+1, y+9) ;
          printf("%c", b) ;
     }

}
