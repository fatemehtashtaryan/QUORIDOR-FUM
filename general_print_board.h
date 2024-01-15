#include "question_player.h"
#include "Scoreboard_player.h"
#include "design_screen.h"
#include "main_board.h"
#include "subcodes.h"

//This file arranges the functions that we need at the beginning of the game and also includes questions such as the size of the board

void general_print()
{
   /* loading();
    system("cls");
    setTextColor (3, 0) ;
    TotalRows=9, TotalColumn=15;
    printf("\n\n\n\n");
    size_board=2;
    boardgame(TotalRows,TotalColumn);
    logo(TotalRows,TotalColumn);
    setTextColor (0, 10) ;
    const char *welcome = "Welcome to the FUM QUORIDOR!";
    printslowly( welcome,18,48) ;
<<<<<<< HEAD
    sleep (150) ;
=======
    sleep (150) ;*/
    int x=2,y=44,t=0,type;
    int  menu_direction;
    home_menu(x,y);    gotoxy(x+2,y+12);   printf("CONTINUE GAME");
    home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
    home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
    while(1){
        menu_direction = getch() ;
        if(menu_direction==13){ break;}
        while( menu_direction != 224){ //check true button

             menu_direction = getch();
        }
        menu_direction = getch() ;
        t++;
        if(menu_direction==72){
            if(type==1){t=3;}
            if(type==2){t=1;}
            if(type==3){t=2;}
        }
        colorscreen=0;
        if(t==1){
            setTextColor (7,colorscreen) ;
             home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
             home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
            setTextColor (2,colorscreen) ;
             home_menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");

            type=1;
        }
        if( t==2){
            setTextColor (7,colorscreen) ;
            home_menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
             home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
            setTextColor (9,colorscreen) ;
           home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");

            type=2;
          }
         if(t==3){
            setTextColor (7,colorscreen) ;
            home_menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
            home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
            setTextColor (6,colorscreen) ;
             home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
            type=3;
        }
        if(t==3){
            t=0;
        }
    }

    if(type==2){
      load=1;
      FILE*gamefile;
      gamefile=fopen("Quoridor.qu","rb");
      fread(&infoplayer1,sizeof(struct players_information),1,gamefile);
      strcpy(name_player_1,infoplayer1.name);
      beat1=infoplayer1.beat;
      verticalsticks1=infoplayer1.verticalsticks;
      horizontalsticks1=infoplayer1.horizontalstick;
      row1=infoplayer1.row;
      column1=infoplayer1.column;
      turn=infoplayer1.turn;

      fread(&infoplayer2,sizeof(struct players_information),1,gamefile);
      strcpy(name_player_2,infoplayer2.name);
      beat2=infoplayer2.beat;
      verticalsticks2=infoplayer2.verticalsticks;
      horizontalsticks2=infoplayer2.horizontalstick;
      row2=infoplayer2.row;
      column2=infoplayer2.column;
      strcpy(infoplayer2.player,player2);

     fread(&infoboard,sizeof(struct board_information),1,gamefile);
     colorscreen=infoboard.colorscreen;
     size_board=infoboard.size_board;

     TotalRows = 4*size_board+1 ;
     TotalColumn = 8*size_board-1 ;

     for(int i=0 ; i<=TotalRows ; i++ ){
        for(int j=0 ; j<=TotalColumn ; j++){
            fread(&board[i][j],sizeof(int),1,gamefile);
        }
     }
    fclose(gamefile);
     system("cls");
     return 1;

    }
>>>>>>> 219c9dcddfb31bbdcba4a623dd31c589a53af1a7
    setTextColor(0, 7);
    system ("cls") ;
    gotoxy (15, 43) ;
    sleep (100) ;
<<<<<<< HEAD
    setTextColor (0, 3) ;
    Design_color_screen() ;
    system ("cls") ;
    gotoxy (15, 47) ;
    setTextColor (34, colorscreen) ;*/
=======
    setTextColor (0, 7) ;
    Design_color_screen() ;
    system ("cls") ;
    gotoxy (15, 47) ;

>>>>>>> 219c9dcddfb31bbdcba4a623dd31c589a53af1a7
    printf ("Enter the size of the GAME BOARD: ") ;
    while(1)
    {
        scanf ("%d", &size_board) ;
        if ( size_board > 15 || size_board <= 0 )
        {
            beep (500,100) ;
            system ("cls") ;
            gotoxy (15, 70) ;
            printf ("WRONG!") ;
            sleep (800) ;
            system ("cls") ;
            gotoxy (15, 47) ;
            printf ("Enter the size of the GAME BOARD: ") ;
        }
        else break ;
    }
    //Converting to desired number of columns and rows
    TotalRows = 4*size_board+1 ;
    TotalColumn = 8*size_board-1 ;
    system ("cls") ;
    setTextColor (0, colorscreen) ;
    question_boardplayer1() ;
    if(turn != 3) question_boardplayer2() ;
    system ("cls") ;
    sleep (50) ;
    Scoreboard() ;
}
