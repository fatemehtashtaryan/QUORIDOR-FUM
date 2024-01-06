#include "subcodes.h"

//This file consists of a number of functions that can be seen at the beginning of the game and the last function is for printing the winner

void Design_color_screen()//Choice of screen color by players
{
printf ("'SELECT YOUR SCREEN COLOR BY PRESS ENTER THEN PRESS 0'\n") ;
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
     	    printf("%c",223);//rectangle ascii
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

int logo(int TotalRows,int TotalColumn){
     int  Row, Column ,i;
     for(i=1;i<=5;i++){
				board[4][i]=100;
		}
     for(i=9;i<=13;i++){
				board[4][i]=200;
		}
     for(i=1;i<=3;i++){
				board[i][7]=300;
		}
     for(i=5;i<=7;i++){
				board[i][7]=400;
		}
	 for(Row = 0; Row <= TotalRows-1 ; Row++){
	    for(Column = 0; Column <= TotalColumn-1 ; Column++){
	    	//////////print 4 corners of the frame
			if(Row==0 && Column==0){
					for(i=1 ;i <=55 ;i++){
								printf(" ");
							}
					printf("%c",218);
			}
			if(Row==0 && Column==TotalColumn-2){
					printf("%c",191);
			}
			if(Row==TotalRows-1 && Column==TotalColumn-2){
					printf("%c",217);
			}
			if(Row==TotalRows-1 && Column==0){
					for( i=1 ;i<=55;i++){
								printf(" ");
							}
					printf("%c",192);
			}
			////////////// print houses
	        if(board[Row][Column] == 0 ){
	        	printf(" ");
			}
	        else if(board[Row][Column] == 1   ) {
                printf("%c",205);
			}
			else if(board[Row][Column] ==2  ) {
	        	printf("%c",215);
			}
			else if(board[Row][Column] ==3  ) {
	        	printf("%c",201);
			}
			else if(board[Row][Column] ==4) {
	        	printf("%c",187);
			}
			else if(board[Row][Column] ==5 ) {
	        	printf("%c",200);
			}
			else if(board[Row][Column] ==6  ) {
	        	printf("%c",188);
			}
			////////// print main frame
			else if(board[Row][Column]==7  )	{
						if(Column==0){
							for( i=1 ;i<=55;i++){
								printf(" ");
							}
						}
						printf("%c",179);
			}
		    else if(board[Row][Column]==8 )	{
                            printf("%c",196);
		    }
		    if(board[Row][Column]==100){
                 setTextColor(2,0);
                printf("%c",178);
                  setTextColor(3,0);
                }
            if(board[Row][Column]==200){
                 setTextColor(6,0);
                printf("%c",178);
                  setTextColor(3,0);
                }
            if(board[Row][Column]==300){
                 setTextColor(4,0);
                printf("%c",178);
                  setTextColor(3,0);
                }
            if(board[Row][Column]==400){
                 setTextColor(5,0);
                printf("%c",178);
                  setTextColor(3,0);
                }
	    }
	     printf("\n");
	 }
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
