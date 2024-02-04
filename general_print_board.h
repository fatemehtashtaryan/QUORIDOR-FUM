#ifndef general_print_board
#define general_print_board

#include "setting.h"
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
    int t=0,type,x,y,typeplayer,typelevel,typemembers,typefourplayer,swplay=1;
    Sw_four_playergame=1;
    char nameplayer2[20],nameplayer3[20],nameplayer4[20];
    gotoxy(2,50);
    printf("Q U O R I D O R   F U M!");
    menu_frame(4,36);
    x=7;y=44;
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
        if(t==1){
            setTextColor (7,0) ;
             home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
             home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
             setTextColor (2,0) ;
             home_menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");

            type=1;
        }
        if( t==2){
            setTextColor (7,0) ;
            home_menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
            home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
            setTextColor (9,0) ;
            home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
            type=2;
          }
         if(t==3){
            setTextColor (7,0) ;
            home_menu(x,y);gotoxy(x+2,y+12);printf("CONTINUE GAME");
            home_menu(x+5,y); gotoxy(x+7,y+14);  printf("LOAD GAME");
            setTextColor (6,0) ;
            home_menu(x+10,y); gotoxy(x+12,y+14);  printf("CUSTOMIZE");
            type=3;
            t=0;
        }
    }
     if(type==1){//countinue game
        t=0;
        system("cls");
        setTextColor (7,0) ;
        gotoxy(2,51);
        printf("Q U O R I D O R   F U M!");
        menu_frame(4,36);
        gotoxy(6,59);
        printf("OPPONENT");
        x=8;y=44;
        menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Computer");
        menu_opponent(x,y+21);   gotoxy(x+2,y+26); printf("Players");
        menu(22,y+14);   gotoxy(23,y+17); printf("Back");

        while(1){
            option_direction = getch() ;
            if(option_direction==13){ break;}
            while( option_direction != 224){ //check true button

                 option_direction = getch();
            }
            option_direction = getch() ;
            t++;
            if(option_direction==72){
                if(typeplayer==1){t=3;}
                if(typeplayer==2){t=1;}
                if(typeplayer==3){t=2;}
            }
            colorscreen=0;
            if(t==1){
                setTextColor (7,colorscreen) ;
                menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Computer");
                menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                setTextColor (3,colorscreen) ;
                menu_opponent(x,y+21);   gotoxy(x+2,y+26); printf("Players");

                typeplayer=1;
            }
            if( t==2){
                setTextColor (7,colorscreen) ;
                menu_opponent(x,y+21);   gotoxy(x+2,y+26); printf("Players");
                menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                setTextColor (5,colorscreen) ;
                menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Computer");

                typeplayer=2;
              }
           if(t==3){
                setTextColor (4,colorscreen) ;
                menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                setTextColor (7,colorscreen) ;
                menu_opponent(x,y+21);   gotoxy(x+2,y+26); printf("Players");
                menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Computer");
                typeplayer=3;
           }
           if(t==3){
                t=0;
            }
       }

        if(typeplayer==2){ //play with computer
            t=0;
            setTextColor (7,colorscreen) ;
            gotoxy(14,59);
            printf("Difficulty");
            x=16;y=44;
            menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Level 1");
            menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("Level 2");
            menu(22,y+14);   gotoxy(23,y+17); printf("Back");
            while(1){
                option_direction = getch() ;
                if(option_direction==13){ break;}
                while( option_direction != 224){ //check true button

                     option_direction = getch();
                }
                option_direction = getch() ;
                t++;
                if(option_direction==72){
                    if(typelevel==1){t=3;}
                    if(typelevel==2){t=1;}
                    if(typelevel==3){t=2;}
                }
                colorscreen=0;
                if(t==1){
                     setTextColor (7,colorscreen) ;
                     menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Level 1");
                     menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                     setTextColor (2,colorscreen) ;
                     menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("Level 2");
                     typelevel=1;
                }
                if( t==2){
                    setTextColor (7,colorscreen) ;
                    menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("Level 2");
                    menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                    setTextColor (6,colorscreen) ;
                    menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Level 1");
                    typelevel=2;
                  }
                if(t==3){
                    setTextColor (7,colorscreen) ;
                    menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("Level 2");
                    menu_opponent(x,y);  gotoxy(x+2,y+4); printf("Level 1");
                    setTextColor (4,colorscreen) ;
                    menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                    typelevel=3;
                }
                 if(t==3){
                    t=0;
                }
          }

          if(typelevel==2){
            strcpy(name_player_2,"computer");
            typeplayer2=1; //level 1
            Sw_four_playergame=1;
          }else if(typelevel==1){
            strcpy(name_player_2,"computer");
            typeplayer2=2; //level 2
            Sw_four_playergame=1;
          }else{
            setTextColor (7,0) ;
            system ("cls") ;
            load=0;
            main();
          }
    }else if(typeplayer==1){ //play with sveral members
        t=0;
        setTextColor (7,colorscreen) ;
        gotoxy(14,54);
        printf("number of members");
        x=16;y=44;
        menu_opponent(x,y);  gotoxy(x+2,y+4); printf("2 players");
        menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("4 players");
        menu(22,y+14);   gotoxy(23,y+17); printf("Back");
        while(1){
            option_direction = getch() ;
            if(option_direction==13){ break;}
            while( option_direction != 224){ //check true button
                     option_direction = getch();
            }
            option_direction = getch() ;
            t++;
            if(option_direction==72){
                if(typemembers==1){t=3;}
                if(typemembers==2){t=1;}
                if(typemembers==3){t=2;}
            }
            colorscreen=0;
            if(t==1){
                setTextColor (7,colorscreen) ;
                menu_opponent(x,y);  gotoxy(x+2,y+4); printf("2 players");
                menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                setTextColor (2,colorscreen) ;
                menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("4 players");
                typemembers=1;

            }if( t==2){
                setTextColor (7,colorscreen) ;
                menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("4 players");
                menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                setTextColor (6,colorscreen) ;
                menu_opponent(x,y);  gotoxy(x+2,y+4); printf("2 players");
                typemembers=2;

            }if(t==3){
                setTextColor (7,colorscreen) ;
                menu_opponent(x,y);  gotoxy(x+2,y+4); printf("2 players");
                menu_opponent(x,y+21);   gotoxy(x+2,y+25); printf("4 players");
                setTextColor (4,colorscreen) ;
                menu(22,y+14);   gotoxy(23,y+17); printf("Back");
                typemembers=3;

            }if(t==3){
                t=0;
            }
        }
        if(typemembers==2){
            strcpy(name_player_2,"TWO");
            typeplayer2=0;
            Sw_four_playergame=1;
        }
        else if(typemembers==1){
            x=10;y=44;t=0;
            int y2=y+25 ,y3=y+25 ,y4=y+4;
            strcpy(nameplayer2,"H U M A N");
            strcpy(nameplayer3,"H U M A N");
            strcpy(nameplayer4,"H U M A N");

            system("cls");
            setTextColor (7,0) ;
            gotoxy(2,51);
            printf("Q U O R I D O R   F U M!");
            menu_frame(4,36);
            gotoxy(6,43);
            printf(" * you can change the type of player ");
            gotoxy(7,52);
            printf(" by pressing Enter !");


            menu_opponent(x,y);  gotoxy(x+2,y+4);printf("H U M A N");
            menu_opponent(x,y+21);   gotoxy(x+2,y2); printf("%s",nameplayer2);
            menu_opponent(x+6,y+21);   gotoxy(x+8,y3); printf("%s",nameplayer3);
            menu_opponent(x+6,y);  gotoxy(x+8,y4); printf("%s",nameplayer4);
            menu(22,y+8);   gotoxy(23,y+11); printf("Back");
            menu(22,y+20);   gotoxy(23,y+23); printf("Play");

            while(swplay==1){
                while(1){
                    option_direction = getch() ;
                    if(option_direction==13){ break;}
                    while( option_direction != 224){ //check true button
                             option_direction = getch();
                    }
                    option_direction = getch() ;
                    t++;
                    if(option_direction==72){
                        if(typefourplayer==1){t=6;}
                        if(typefourplayer==2){t=1;}
                        if(typefourplayer==3){t=2;}
                        if(typefourplayer==4){t=3;}
                        if(typefourplayer==5){t=4;}
                        if(typefourplayer==6){t=5;}
                    }
                    colorscreen=0;
                    if(t==1){
                        setTextColor (7,colorscreen) ;
                        menu_opponent(x,y+21);   gotoxy(x+2,y2);printf("%s",nameplayer2);
                        menu(22,y+20);   gotoxy(23,y+23); printf("Play");
                        setTextColor (4,colorscreen) ;
                        menu_opponent(x,y);  gotoxy(x+2,y+4);printf("H U M A N");
                        typefourplayer=1;
                    }
                    if(t==2){
                        setTextColor (7,colorscreen) ;
                         menu_opponent(x,y);  gotoxy(x+2,y+4);printf("H U M A N");
                        menu_opponent(x+6,y+21);   gotoxy(x+8,y3);printf("%s",nameplayer3);
                        setTextColor (6,colorscreen) ;
                        menu_opponent(x,y+21);   gotoxy(x+2,y2);printf("%s",nameplayer2);
                        typefourplayer=2;
                    }
                    if(t==3){
                        setTextColor (7,colorscreen) ;
                        menu_opponent(x,y+21);   gotoxy(x+2,y2);printf("%s",nameplayer2);
                        menu_opponent(x+6,y);  gotoxy(x+8,y4);printf("%s",nameplayer4);
                        setTextColor (3,colorscreen) ;
                        menu_opponent(x+6,y+21);   gotoxy(x+8,y3);printf("%s",nameplayer3);
                        typefourplayer=3;
                    }
                    if(t==4){
                        setTextColor (7,colorscreen) ;
                        menu_opponent(x+6,y+21);   gotoxy(x+8,y3);printf("%s",nameplayer3);
                        menu(22,y+8);   gotoxy(23,y+11); printf("Back");
                        setTextColor (5,colorscreen) ;
                        menu_opponent(x+6,y);  gotoxy(x+8,y4);printf("%s",nameplayer4);
                        typefourplayer=4;
                    }
                    if(t==5){
                        setTextColor (7,colorscreen) ;
                        menu_opponent(x+6,y);  gotoxy(x+8,y4);printf("%s",nameplayer4);
                        menu(22,y+20);   gotoxy(23,y+23); printf("Play");
                        setTextColor (1,colorscreen) ;
                        menu(22,y+8);   gotoxy(23,y+11); printf("Back");
                        typefourplayer=5;
                    }
                    if(t==6){
                        setTextColor (7,colorscreen) ;
                        menu_opponent(x,y);  gotoxy(x+2,y+4);printf("H U M A N");
                        menu(22,y+8);   gotoxy(23,y+11); printf("Back");
                        setTextColor (2,colorscreen) ;
                        menu(22,y+20);   gotoxy(23,y+23); printf("Play");
                        typefourplayer=6;
                    }
                    if(t==6){
                        t=0;
                    }
                }
               if(typefourplayer==2){
                     if(option_direction==13){
                        if(strcmp(nameplayer2,"C O M P U T E R")==0){
                            strcpy(nameplayer2,"   H U M A N   ");
                            typeplayer2=0;
                        }else{
                            strcpy(nameplayer2,"C O M P U T E R");
                            typeplayer2=1;
                        }
                         y2=y+22;
                        menu_opponent(x,y+21);gotoxy(x+2,y2);printf("%s",nameplayer2);

                     }
                }if(typefourplayer==3){
                     if(option_direction==13){
                        if(strcmp(nameplayer3,"C O M P U T E R")==0){
                           strcpy(nameplayer3,"   H U M A N   ");
                            typeplayer3=0;
                        }else{
                            strcpy(nameplayer3,"C O M P U T E R");
                            typeplayer3=1;
                        }
                        y3=y+22;
                        menu_opponent(x+6,y+21);gotoxy(x+8,y3);printf("%s",nameplayer3);
                     }
                }if(typefourplayer==4){
                     if(option_direction==13){
                        if(strcmp(nameplayer4,"C O M P U T E R")==0){
                            strcpy(nameplayer4,"   H U M A N   ");
                            typeplayer4=0;
                        }else{
                            strcpy(nameplayer4,"C O M P U T E R");
                            typeplayer4=1;
                        }
                        y4=y+1;
                        menu_opponent(x+6,y);gotoxy(x+8,y4);printf("%s",nameplayer4);
                     }
                }if(typefourplayer==5){
                    setTextColor (7,0) ;
                    system ("cls") ;
                    load=0;
                    main();
                }if(typefourplayer==6){
<<<<<<< HEAD
=======

                    if(strcmp(nameplayer2,"C O M P U T E R")==0) {strcpy(name_player_2,"computer");}
                    else {strcpy(name_player_2,"TWO");}
                    if(strcmp(nameplayer3,"C O M P U T E R")==0) {strcpy(name_player_3,"computer");}
                    else {strcpy(name_player_3,"THREE");}
                    if(strcmp(nameplayer4,"C O M P U T E R")==0) {strcpy(name_player_4,"computer");}
                    else {strcpy(name_player_4,"FOUR");}

>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
                    Sw_four_playergame=0;
                    swplay=0;
                }
            }
    }else{
       setTextColor (7,0) ;
       system ("cls") ;
       load=0;
       main();
    }
    }else{
       setTextColor (7,0) ;
       system ("cls") ;
       load=0;
       main();
    }
    colorscreen=7;
    setTextColor (0,colorscreen) ;
    system ("cls") ;
    setTextColor (0,colorscreen) ;
<<<<<<< HEAD
    load=0;
    /*verticalsticks1=primaryverticalsticks1;
    horizontalsticks1=primaryhorizontalsticks1;
    column1=primarycolumn1;
    row1=primaryrow1;
    verticalsticks2=primaryverticalsticks2;
    horizontalsticks2=primaryhorizontalsticks2;
    column2=primarycolumn2;
    row2=primaryrow2;*/
=======
    load=1;
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
    }
    if(type==2){
      load=0;
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
      Sw_four_playergame=infoplayer1.Sw_four_playergame;
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

    if(Sw_four_playergame==0){
          fread(&infoplayer3,sizeof(struct players_information),1,gamefile);
          strcpy(name_player_3,infoplayer3.name);
          beat3=infoplayer3.beat;
          verticalsticks3=infoplayer3.verticalstick;
          horizontalsticks3=infoplayer3.horizontalstick;
          row3=infoplayer3.row;
          column3=infoplayer3.column;
          typeplayer3=infoplayer3.typeplayer;
          primaryrow3=infoplayer3.primaryrow;
          primaryhorizontalsticks3=infoplayer3.primaryhorizontalstick;
          primaryverticalsticks3=infoplayer3.primaryverticalstick;

          fread(&infoplayer4,sizeof(struct players_information),1,gamefile);
          strcpy(name_player_4,infoplayer4.name);
          beat4=infoplayer4.beat;
          verticalsticks4=infoplayer4.verticalstick;
          horizontalsticks4=infoplayer4.horizontalstick;
          row4=infoplayer4.row;
          column4=infoplayer4.column;
          typeplayer4=infoplayer4.typeplayer;
          primaryrow4=infoplayer4.primaryrow;
          primarycolumn4=infoplayer4.primarycolumn;
          primaryhorizontalsticks4=infoplayer4.primaryhorizontalstick;
          primaryverticalsticks4=infoplayer4.primaryverticalstick;
    }
      fread(&infoboard,sizeof(struct board_information),1,gamefile);
      colorscreen=infoboard.colorscreen;
      size_board=infoboard.size_board;
      Sw_four_playergame=infoboard.Sw_four_playergame;

      TotalRows = 4*size_board+1 ;
      TotalColumn = 8*size_board-1 ;

     for(int i=0 ; i<=TotalRows ; i++ ){
        for(int j=0 ; j<=TotalColumn ; j++){
            fread(&board[i][j],sizeof(int),1,gamefile);
        }
     }
      if(Sw_four_playergame==0){
          fread(&infoplayer3,sizeof(struct players_information),1,gamefile);
          strcpy(name_player_3,infoplayer3.name);
          beat3=infoplayer3.beat;
          verticalsticks3=infoplayer3.verticalstick;
          horizontalsticks3=infoplayer3.horizontalstick;
          row3=infoplayer3.row;
          column3=infoplayer3.column;
          typeplayer3=infoplayer3.typeplayer;
          primarycolumn3=infoplayer3.primarycolumn;
          primaryhorizontalsticks3=infoplayer3.primaryhorizontalstick;
          primaryverticalsticks3=infoplayer3.primaryverticalstick;

          fread(&infoplayer4,sizeof(struct players_information),1,gamefile);
          strcpy(name_player_4,infoplayer4.name);
          beat4=infoplayer4.beat;
          verticalsticks4=infoplayer4.verticalstick;
          horizontalsticks4=infoplayer4.horizontalstick;
          row4=infoplayer4.row;
          column4=infoplayer4.column;
          typeplayer4=infoplayer4.typeplayer;
          primarycolumn4=infoplayer4.primarycolumn;
          primaryhorizontalsticks4=infoplayer4.primaryhorizontalstick;
          primaryverticalsticks4=infoplayer4.primaryverticalstick;
     }
     fclose(gamefile);
    }
    if(type==3){
        system("cls");
        setting_player();
    }

}
#endif // general_print_board

