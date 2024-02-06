#include "question_player.h"

void Scoreboard_player(int player)
{

     //By using the input of this function, there is no need to use two separate functions for two players
     int counterrow, countercolumn, x, y, color_sticks, horizontalsticks, verticalsticks;
     char beat, name_player[20];
     //start of drawing the table
     if( player ==1 && turn==1) setTextColor(13, colorscreen);
     else if( player ==2 && turn==2) setTextColor(9, colorscreen);
     else if( player ==3 && turn==3) setTextColor(4, colorscreen);
     else if( player ==4 && turn==4) setTextColor(5, colorscreen);
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
     else if( player ==2 ){
        x = 0 ;
        y = 89 ;
        beat = beat2 ;
        strcpy(name_player, name_player_2 ) ;
        color_sticks = 9 ;
        verticalsticks = verticalsticks2;
        horizontalsticks = horizontalsticks2 ;
     }
     else if( player ==3 ){
        x = TotalRows+21 ;
        y = 0 ;
        beat = beat3 ;
        strcpy(name_player, name_player_3 ) ;
        color_sticks = 4 ;
        verticalsticks = verticalsticks3;
        horizontalsticks = horizontalsticks3 ;
     }
     else if( player ==4 ){
        x = TotalRows+21 ;
        y = 89 ;
        beat = beat4 ;
        strcpy(name_player, name_player_4 ) ;
        color_sticks = 5 ;
        verticalsticks = verticalsticks4;
        horizontalsticks = horizontalsticks4 ;
     }
     int h=1;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countercolumn = 0; countercolumn < 25; countercolumn++)
    {
          printf ("%c", d) ;
     }
     printf ("%c", f) ;
     for(counterrow = 0; counterrow < 7; counterrow++)
    {
          gotoxy(x+h, y) ;
          printf("%c", b) ;
          h++;
     }
     gotoxy(x+8, y) ;
     printf("%c", c) ;
     for(countercolumn = 0; countercolumn < 25; countercolumn++)
    {
          printf("%c", d) ;
     }
     printf("%c", e) ;
     h=1;
     for(counterrow = 7; counterrow > 0; counterrow--)
    {
         gotoxy(x+h, y+26) ;
          printf("%c", b) ;
          h++;
     }
     //end of drawing the table
     //Start of writing information
     setTextColor(0, colorscreen);
     gotoxy(x+1, y+5) ;
     printf("player %c : %s\n", beat, name_player) ;
     setTextColor(color_sticks, colorscreen) ;
     gotoxy(x+3, y+7) ;
     printf("%c%c ", sticks, sticks) ;
     gotoxy(x+4, y+7) ;
     printf("%c%c ", sticks, sticks) ;
     setTextColor(0,colorscreen) ;
     printf("%d", verticalsticks) ;
     setTextColor(color_sticks, colorscreen) ;
     gotoxy(x+6, y+7) ;
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
         if(turn==1) printf("%s is your turn!", name_player_1);
         else if(turn==2) printf("%s is your turn!", name_player_2);
         else if(turn==3) printf("%s is your turn!", name_player_3);
         else if(turn==4) printf("%s is your turn!", name_player_4);
         Scoreboard_player(2);
         if(Sw_four_playergame==0){
            Scoreboard_player(3);
            Scoreboard_player(4);
         }
         gotoxy(6, 102);
}
