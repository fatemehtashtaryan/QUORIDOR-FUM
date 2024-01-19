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
    sleep (150) ;*/
<<<<<<< HEAD
    int x=2,y=44,t=0,type;
    int  menu_direction;
    menu(x,y);    gotoxy(x+2,y+12);   printf("CONTINUE GAME");
    menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
    menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
=======
    int t=0,type,x,y,typeop,typeopp;


    gotoxy(2,50);
    printf("Q U O R I D O R   F U M!");
    menu_frame(4,36);

    x=7;y=44;
    home_menu(x,y);    gotoxy(x+2,y+12);   printf("CONTINUE GAME");
    home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
    home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
>>>>>>> d6b70ab19f65a62790f12e634d12e51e33c5f568
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
<<<<<<< HEAD
             menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
             menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
            setTextColor (2,colorscreen) ;
             menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
=======
             home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
             home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
             setTextColor (2,colorscreen) ;
             home_menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
>>>>>>> d6b70ab19f65a62790f12e634d12e51e33c5f568

            type=1;
        }
        if( t==2){
            setTextColor (7,colorscreen) ;
<<<<<<< HEAD
            menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
            menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
            setTextColor (9,colorscreen) ;
            menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
=======
            home_menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
            home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
            setTextColor (9,colorscreen) ;
            home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
>>>>>>> d6b70ab19f65a62790f12e634d12e51e33c5f568

            type=2;
          }
         if(t==3){
            setTextColor (7,colorscreen) ;
            menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
            menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
            setTextColor (6,colorscreen) ;
<<<<<<< HEAD
             menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
=======
            home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
>>>>>>> d6b70ab19f65a62790f12e634d12e51e33c5f568
            type=3;
        }
        if(t==3){
            t=0;
        }
    }
    if(type==1){
        system("cls");
        setTextColor (7,colorscreen) ;
        gotoxy(2,51);
        printf("Q U O R I D O R   F U M!");
        menu_frame(4,36);
        gotoxy(7,59);
        printf("OPPONENT");
        x=9;y=44;
        menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Computer");
        menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("2 Players");
        t=0;
        while(1){
            option_direction = getch() ;
            if(option_direction==13){ break;}
            while( option_direction != 224){ //check true button

                 option_direction = getch();
            }
            option_direction = getch() ;
            t++;
            if(option_direction==72){
                if(typeop==1){t=2;}
                if(typeop==2){t=1;}
            }
            colorscreen=0;
            if(t==1){
                setTextColor (7,colorscreen) ;
                menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Computer");
                setTextColor (3,colorscreen) ;
                menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("2 Players");
                typeop=1;
            }
            if( t==2){
                setTextColor (7,colorscreen) ;
                menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("2 Players");
                setTextColor (5,colorscreen) ;
                menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Computer");
                typeop=2;
              }

             if(t==2){
                t=0;
            }
       }

        if(typeop==2){

            t=0;
            setTextColor (7,colorscreen) ;
            gotoxy(15,59);
            printf("Difficulty");
            x=17;y=44;
            menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Level 1");
            menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("Level 2");
            while(1){
                option_direction = getch() ;
                if(option_direction==13){ break;}
                while( option_direction != 224){ //check true button

                     option_direction = getch();
                }
                option_direction = getch() ;
                t++;
                if(option_direction==72){
                    if(typeop==1){t=2;}
                    if(typeop==2){t=1;}
                }
                colorscreen=0;
                if(t==1){
                     setTextColor (7,colorscreen) ;
                     menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Level 1");
                     setTextColor (4,colorscreen) ;
                     menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("Level 2");
                     typeopp=1;
                }
                if( t==2){
                    setTextColor (7,colorscreen) ;
                    menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("Level 2");
                    setTextColor (6,colorscreen) ;
                    menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Level 1");
                    typeopp=2;
                  }

                 if(t==2){
                    t=0;
                }
          }

        if(typeopp==2){
            typeplayer2=1;
        }else{
            typeplayer2=2;
        }
    }
          //Converting to desired number of columns and rows
        setTextColor(0, 7);
        system ("cls") ;
        gotoxy (15, 43) ;
        setTextColor (0, 7) ;
        TotalRows = 4*size_board+1 ;
        TotalColumn = 8*size_board-1 ;
        system ("cls") ;
        setTextColor (0, 7) ;
        colorscreen=7;
        question_boardplayer1() ;
        if(typeplayer2!=1 && typeplayer2!=2) question_boardplayer2() ;
        system ("cls") ;
        sleep (50) ;
        Scoreboard() ;

    }

    if(type==2){
      load=1;
      FILE*gamefile;
      gamefile=fopen("Quoridor.qu","rb");

      fread(&infoplayer1,sizeof(struct players_information),1,gamefile);
      strcpy(name_player_1,infoplayer1.name);
      beat1=infoplayer1.beat;
      verticalsticks1=infoplayer1.verticalstick;
      horizontalsticks1=infoplayer1.horizontalstick;
      row1=infoplayer1.row;
      column1=infoplayer1.column;
      turn=infoplayer1.turn;
      primarycolumn1=infoplayer1.primarycolumn;
      primaryrow1=infoplayer1.primaryrow;
      primaryhorizontalsticks1=infoplayer1.primaryhorizontalstick;
      primaryverticalsticks1=infoplayer1.primaryverticalstick;

      fread(&infoplayer2,sizeof(struct players_information),1,gamefile);
      strcpy(name_player_2,infoplayer2.name);
      beat2=infoplayer2.beat;
      verticalsticks2=infoplayer2.verticalstick;
      horizontalsticks2=infoplayer2.horizontalstick;
      row2=infoplayer2.row;
      column2=infoplayer2.column;
      typeplayer2=infoplayer2.typeplayer;
      primarycolumn2=infoplayer2.primarycolumn;
      primaryhorizontalsticks2=infoplayer2.primaryhorizontalstick;
      primaryverticalsticks2=infoplayer2.primaryverticalstick;

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
<<<<<<< HEAD
    setTextColor(0, 7);
    system ("cls") ;
    gotoxy (15, 43) ;
    sleep (100) ;
    setTextColor (0, 3) ;
    Design_color_screen() ;
    system ("cls") ;
    gotoxy (15, 47) ;
    setTextColor (34, colorscreen) ;
    setTextColor (0, 7) ;
    Design_color_screen() ;
    system ("cls") ;
    gotoxy (15, 47) ;
    printf ("Enter the size of the GAME BOARD: ") ;
    while(1)
    {
        scanf ("%d", &size_board) ;
        if ( size_board > 15 || size_board <= 0 )
=======
    if(type==3){
        setTextColor(0, 7);
        system ("cls") ;
        gotoxy (15, 43) ;
        sleep (100) ;
        setTextColor (0, 7) ;
        Design_color_screen() ;
        system ("cls") ;
        gotoxy (15, 47) ;

        printf ("Enter the size of the GAME BOARD: ") ;
        while(1)
>>>>>>> d6b70ab19f65a62790f12e634d12e51e33c5f568
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
    }

}
