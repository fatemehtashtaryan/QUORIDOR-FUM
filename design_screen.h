#include "subcodes.h"
void Design_color_screen()
{
printf ("'SELECT YOUR SCREEN COLOR BY PRESS ENTER THEN PRESS 0'\n") ;
    char charnumber=(char)(0+'0');
    while ( getch() == 13 )
        {
         beep (500,100) ;
         if ( getch() == 13 )
         {
            system ("COLOR F0") ;
            colorscreen =15 ;
         }
         else if ( getch() != '\n' ) break ;
         beep (500,100) ;
         if ( getch() == 13 )
         {
            system ("COLOR B0") ;
            colorscreen = 11 ;
         }
         else if ( getch() != '\n' ) break ;
         beep (500,100) ;
         if ( getch() == 13 )
         {
            system ("COLOR E0") ;
            colorscreen = 14 ;
         }
         else if ( getch() != '\n' ) break ;
         beep (500,100) ;
    }
}

void loading(){
    int number=1, t=20, i ;
    printslowly(" LOADING . . .",16,60)  ;
    sleep(800);
    system("cls") ;
     int x=18, y=47;
     gotoxy(x, y);
     for(number = 1 ; number<=5 ; number++){
     	for(i=1;i<=8;i++){
     		y+=1;
     	    gotoxy(x, y);
     	    setTextColor(2,0);
     	    printf("%c",223);
		 }
		 gotoxy(x, y+1);
         printf(" %d %c",t,37);
         if(t==60){
         	sleep(1200);
		 }
         else sleep(600);
         t+=20;
     }

    	printslowly("COMPLETE !!! ",16,64);
    	sleep(50);
}

void printwon(char name[])
{
    int n ;
    system("cls");
    setTextColor (10, 15) ;
    for (n=0; n<=179; n++)
    {
        printf (" Congratulations, %s won ! ", name);
        sleep (30) ;
    }
}



