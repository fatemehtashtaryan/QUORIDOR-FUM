#include "question_player.h"

void Scoreboard_player(int player)
{
     //By using the input of this function, there is no need to use two separate functions for two players
     int counterrow, countercolumn, x, y, color_sticks, horizontalsticks, verticalsticks;
     char beat, name_player[20];
     if(turn == 1 && player ==1) setTextColor(13, colorscreen);
     else if(turn == 2 && player ==2) setTextColor(9, colorscreen);
     else setTextColor(0, colorscreen);
     if( player ==1 ){
        x = 0 ;
        y = 0 ;
        beat = beat1 ;
        strcpy(name_player, name_player_1 ) ;
        color_sticks = 13 ;
        verticalsticks = verticalsticks1 ;
        horizontalsticks = horizontalsticks1 ;

     }
     else{
        x = 0 ;
        y = 89 ;
        beat = beat2 ;
        strcpy(name_player, name_player_2 ) ;
        color_sticks = 9 ;
        verticalsticks = verticalsticks2;
        horizontalsticks = horizontalsticks2 ;
     }
     //start of drawing the table
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < 20; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < 7; counterrow++)
    {
         gotoxy(counterrow+1, y) ;
          printf("%c", b) ;
     }
     gotoxy(counterrow+1, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn < 20; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     for(counterrow = 7; counterrow > 0; counterrow--)
    {
         gotoxy(counterrow, y+21) ;
          printf("%c", b) ;
     }
     //end of drawing the table
     //Start of writing information
     setTextColor(0, colorscreen);
     gotoxy(1, y+5) ;
     printf("player %c : %s\n", beat, name_player) ;
     gotoxy(3, y+7) ;
     setTextColor(color_sticks, colorscreen) ;
     printf("%c%c ", sticks, sticks) ;
     setTextColor(0,colorscreen) ;
     printf("%d", verticalsticks) ;
     gotoxy(4, y+7) ;
     setTextColor(color_sticks, colorscreen) ;
     printf("%c%c", sticks, sticks) ;
     gotoxy(6, y+7) ;
     printf("%c%c%c%c ", sticks, sticks, sticks, sticks) ;
     setTextColor(0, colorscreen) ;
     printf("%d",  horizontalsticks) ;
     //End of writing information
}

void Scoreboard()
{
    //This function performs score tables and printing the turns of two players
         Scoreboard_player(1) ;
         gotoxy(1, 44);
         setTextColor(10, colorscreen);
         printf("Q U O R I D O R   F U M!");
         setTextColor(0, colorscreen);
         gotoxy(4, 48);
         if(turn==1){
            printf("%s is your turn!", name_player_1);
         }
         else printf("%s is your turn!", name_player_2);
         Scoreboard_player(2);
         gotoxy(6, 102);
}
