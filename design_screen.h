#ifndef design_screen
#define design_screen

#include "subcodes.h"
#include "setting.h"
//This file consists of a number of functions that can be seen at the beginning of the game and the last function is for printing the winner

void sizeboard(){
      char setting_direction;
      int number=0, type=1, sw_setting=0;
      size_board=5;
      setTextColor (7,0);
      frame(8,39 ,35,10);
      gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
      gotoxy(10,41); printf ("'CHOOSE THE BOARD SIZE YOU WANT'") ;
      setTextColor(7,0); setting_shape(13, 41, 9); gotoxy(15,45); printf("<<<");
      setTextColor(7,0); setting_shape(13, 52, 9); gotoxy(15,57); printf("%d", size_board);
      setTextColor (7,0); setting_shape(13, 63, 9); gotoxy(15,67); printf(">>>");
      setTextColor (7,0); setting_shape(20, 51, 11); gotoxy(22,56); printf("EXIT");
      do{
        while(1){
            setting_direction=getch();
            if(setting_direction==13) break;
            setting_direction=getch();
            number++;
             if(setting_direction==75 || setting_direction==72){
                if(type==1){number=3;}
                if(type==2){number=1;}
                if(type==3){number=2;}
             }
             if(number==1){
                setTextColor (7,0);
                gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
                gotoxy(10,41); printf ("'CHOOSE THE BOARD SIZE YOU WANT'") ;
                setTextColor (7,0); setting_shape(13, 52, 9); gotoxy(15,57); printf("%d", size_board);
                setTextColor (7,0); setting_shape(13, 63, 9); gotoxy(15,67); printf(">>>");
                setTextColor (7,0); setting_shape(20, 51, 11); gotoxy(22,56); printf("EXIT");
                setTextColor (10,0);
                setting_shape(13, 41, 9); setTextColor (15,0); gotoxy(15,45); printf("<<<");
                type=1;
        }
           if(number==2){
                setTextColor (7,0);
                gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
                gotoxy(10,41); printf ("'CHOOSE THE BOARD SIZE YOU WANT'") ;
                setting_shape(13, 41, 9); gotoxy(15,45); printf("<<<");
                setTextColor (7,0); setting_shape(13, 52, 9); gotoxy(15,57); printf("%d", size_board);
                setTextColor (7,0); setting_shape(20, 51, 11); gotoxy(22,56); printf("EXIT");
                setTextColor (10,0);
                setting_shape(13, 63, 9); setTextColor (15,0); gotoxy(15,67); printf(">>>");
                type=2;
        }
           if(number==3){
                setTextColor (7,0);
                gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
                gotoxy(10,41); printf ("'CHOOSE THE BOARD SIZE YOU WANT'") ;
                setting_shape(13, 41, 9); setTextColor (7,0); gotoxy(15,45); printf("<<<");
                setTextColor (7,0); setting_shape(13, 52, 9); setTextColor (7,0); gotoxy(15,57); printf("%d", size_board);
                setting_shape(13, 63, 9); setTextColor (7,0); gotoxy(15,67); printf(">>>");
                setTextColor (5,0);
                setting_shape(20, 51, 11); gotoxy(22,56); printf("EXIT");
                type=3;
                number=0;
           }
        }
        if(type==1){
            if(size_board>2) size_board--;
            if(size_board<10) gotoxy(15,58); printf(" ");
            setTextColor (7,0); setting_shape(13, 52, 9); setTextColor (4,0); gotoxy(15,57); printf("%d", size_board);
        }
       if(type==2){
            if(size_board<14) size_board++;
            setTextColor (7,0); setting_shape(13, 52, 9); setTextColor (4,0); gotoxy(15,57); printf("%d", size_board);
        }
       if(type==3){
            TotalColumn=8*size_board-1;
            TotalRows=4*size_board+1;
            row1=size_board*4-2;
            sw_setting=1;
            system("cls");
            setting_player();
        }
      }while(sw_setting==0);
}


void Design_color_screen()//Choice of screen color by players
{

    int n=1;
    char setting_direction;
    int number=0, type=1, sw_setting=0;
    setTextColor (7,0);
    frame(8,23 ,70,10);
    gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
    gotoxy(10,32); printf ("'SELECT YOUR SCREEN COLOR BY PRESS ENTER THEN EXIT'") ;
    setting_shape(13, 25, 17); setTextColor (15,colorscreen); gotoxy(15,30); printf("W H I T E");
    setTextColor (0,colorscreen); setting_shape(13, 49, 17); setTextColor (11,colorscreen); gotoxy(15,55); printf("B L U E");
    setTextColor (0,colorscreen);setting_shape(13, 74, 17); setTextColor (14,colorscreen); gotoxy(15,78); printf("Y E L L O W");
    setTextColor (0,colorscreen); setting_shape(20, 51, 12); gotoxy(22,56); printf("EXIT");
    do{
        while(1){
            setting_direction=getch();
            if(setting_direction==13) break;
            setting_direction=getch();
            number++;
             if(setting_direction==75 || setting_direction==72){
                if(type==1){number=4;}
                if(type==2){number=1;}
                if(type==3){number=2;}
                if(type==4){number=3;}
             }
            if(number==1){
                setTextColor (0,colorscreen);
                gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
                gotoxy(10,32); printf ("'SELECT YOUR SCREEN COLOR BY PRESS ENTER THEN EXIT'") ;
                setTextColor (10,colorscreen); setting_shape(13, 25, 17); setTextColor (10,colorscreen); gotoxy(15,30); printf("W H I T E");
                setTextColor (11,colorscreen); setting_shape(13, 49, 17); setTextColor (0,colorscreen); gotoxy(15,55); printf("B L U E");
                setTextColor (14,colorscreen);setting_shape(13, 74, 17); setTextColor (0,colorscreen); gotoxy(15,78); printf("Y E L L O W");
                setTextColor (0,colorscreen); setting_shape(20, 51, 12); gotoxy(22,56); printf("EXIT");
                type=1;
            }
            if(number==2){
                setTextColor (0,colorscreen);
                gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
                gotoxy(10,32); printf ("'SELECT YOUR SCREEN COLOR BY PRESS ENTER THEN EXIT'") ;
                setTextColor (15,colorscreen); setting_shape(13, 25, 17); setTextColor (0,colorscreen); gotoxy(15,30); printf("W H I T E");
                setTextColor (10,colorscreen); setting_shape(13, 49, 17); setTextColor (10,colorscreen); gotoxy(15,55); printf("B L U E");
                setTextColor (14,colorscreen);setting_shape(13, 74, 17); setTextColor (0,colorscreen); gotoxy(15,78); printf("Y E L L O W");
                setTextColor (0,colorscreen); setting_shape(20, 51, 12); gotoxy(22,56); printf("EXIT");
                type=2;
            }
            if(number==3){
                setTextColor (0,colorscreen);
                gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
                gotoxy(10,32); printf ("'SELECT YOUR SCREEN COLOR BY PRESS ENTER THEN EXIT'") ;
                setTextColor (15,colorscreen); setting_shape(13, 25, 17); setTextColor (0,colorscreen); gotoxy(15,30); printf("W H I T E");
                setTextColor (11,colorscreen); setting_shape(13, 49, 17); setTextColor (0,colorscreen); gotoxy(15,55); printf("B L U E");
                setTextColor (10,colorscreen);setting_shape(13, 74, 17); setTextColor (10,colorscreen); gotoxy(15,78); printf("Y E L L O W");
                setTextColor (0,colorscreen); setting_shape(20, 51, 12); gotoxy(22,56); printf("EXIT");
                type=3;
            }
            if(number==4){
                setTextColor (0,colorscreen);
                gotoxy(4,45); printf("Q U O R I D O R   SETTING!");
                gotoxy(10,32); printf ("'SELECT YOUR SCREEN COLOR BY PRESS ENTER THEN EXIT'") ;
                setTextColor (15,colorscreen); setting_shape(13, 25, 17); setTextColor (0,colorscreen); gotoxy(15,30); printf("W H I T E");
                setTextColor (11,colorscreen); setting_shape(13, 49, 17); setTextColor (0,colorscreen); gotoxy(15,55); printf("B L U E");
                setTextColor (14,colorscreen);setting_shape(13, 74, 17); setTextColor (0,colorscreen); gotoxy(15,78); printf("Y E L L O W");
                setTextColor (10,colorscreen); setting_shape(20, 51, 12); gotoxy(22,56); printf("EXIT");
                type=4;
                number =0 ;
            }
        }
        if(type==1){
            system ("COLOR F0") ;
            colorscreen =15 ;
        }
        if(type==2){
            system ("COLOR B0") ;
            colorscreen = 11 ;
        }
        if(type==3){
            system ("COLOR E0") ;
            colorscreen = 14 ;
        }
        if(type==4){
            system("cls");
            setting_player();
            sw_setting = 1;
        }
    }while(sw_setting==0);
  /*  while ( getch() == 13 )
        {
         beep (500,100) ;
         if (n!=1){
            if(getch() == 13)
         {
            system ("COLOR F0") ;
            colorscreen =15 ;
         }
         else if ( getch() != '\n' ) break ;
         }
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
         n++;
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
    	sleep(50);*/
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
        if(turn != 3){
           printf (" Congratulations, %s won ! ", name);
           sleep (30) ;
        }
        else{
            setTextColor (12, 15) ;
            printf (" Sorry, you LOST !");
           sleep (30) ;
        }
    }
}
#endif // design_screen
