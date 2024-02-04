#include "subcodes.h"
#include "checking_move.h"
#include "check_sticks.h"
<<<<<<< HEAD
#include "menu.h"
=======
#include "gameboard_menu.h"
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d


int move_player;
int result_check;
int savegame(){
    FILE*gamefile;
     gamefile=fopen("Quoridor.qu","wb");
     if(!gamefile){
        printf("cant save !!");
        return 0;
     }
     strcpy(infoplayer1.name,name_player_1);
     infoplayer1.beat=beat1;
     infoplayer1.verticalstick=verticalsticks1;
     infoplayer1.horizontalstick=horizontalsticks1;
     infoplayer1.primaryverticalstick=primaryverticalsticks1;
     infoplayer1.primaryhorizontalstick=primaryhorizontalsticks1;
     infoplayer1.row=row1;
     infoplayer1.column=column1;
     infoplayer1.turn=turn;
<<<<<<< HEAD
=======
     infoplayer1.Sw_four_playergame=Sw_four_playergame;
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
     infoplayer1.primarycolumn=primarycolumn1;
     infoplayer1.primaryrow=primaryrow1;
     fwrite(&infoplayer1,sizeof(struct players_information),1,gamefile);

     strcpy(infoplayer2.name,name_player_2);
     infoplayer2.beat=beat2;
     infoplayer2.verticalstick=verticalsticks2;
     infoplayer2.horizontalstick=horizontalsticks2;
     infoplayer2.primaryverticalstick=primaryverticalsticks2;
     infoplayer2.primaryhorizontalstick=primaryhorizontalsticks2;
     infoplayer2.row=row2;
     infoplayer2.column=column2;
     infoplayer2.typeplayer=typeplayer2;
     infoplayer2.primarycolumn=primarycolumn2;
     fwrite(&infoplayer2,sizeof(struct players_information),1,gamefile);

     if(Sw_four_playergame==0){
         strcpy(infoplayer3.name,name_player_3);
         infoplayer3.beat=beat3;
         infoplayer3.verticalstick=verticalsticks3;
         infoplayer3.horizontalstick=horizontalsticks3;
<<<<<<< HEAD
         infoplayer3.primaryverticalstick=primaryverticalsticks3;
         infoplayer3.primaryhorizontalstick=primaryhorizontalsticks3;
         infoplayer3.row=row3;
         infoplayer3.column=column3;
         infoplayer3.typeplayer=typeplayer3;
         infoplayer3.primarycolumn=primarycolumn3;
         infoplayer3.primaryrow=primaryrow3;
         fwrite(&infoplayer3,sizeof(struct players_information),1,gamefile);

=======
         infoplayer3.row=row3;
         infoplayer3.column=column3;
         infoplayer3.typeplayer=typeplayer3;
         infoplayer3.primaryrow=primaryrow3;
         infoplayer3.primaryverticalstick=primaryverticalsticks3;
         infoplayer3.primaryhorizontalstick=primaryhorizontalsticks3;

         fwrite(&infoplayer3,sizeof(struct players_information),1,gamefile);
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
         strcpy(infoplayer4.name,name_player_4);
         infoplayer4.beat=beat4;
         infoplayer4.verticalstick=verticalsticks4;
         infoplayer4.horizontalstick=horizontalsticks4;
<<<<<<< HEAD
         infoplayer4.primaryverticalstick=primaryverticalsticks4;
         infoplayer4.primaryhorizontalstick=primaryhorizontalsticks4;
         infoplayer4.row=row4;
         infoplayer4.column=column4;
         infoplayer4.typeplayer=typeplayer4;
         infoplayer4.primarycolumn=primarycolumn4;
=======
         infoplayer4.row=row4;
         infoplayer4.column=column4;
         infoplayer4.typeplayer=typeplayer4;
         infoplayer4.primaryrow=primaryrow4;
         infoplayer4.primarycolumn=primarycolumn4;
         infoplayer4.primaryverticalstick=primaryverticalsticks4;
         infoplayer4.primaryhorizontalstick=primaryhorizontalsticks4;
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
         fwrite(&infoplayer4,sizeof(struct players_information),1,gamefile);
     }
     infoboard.colorscreen=colorscreen;
     infoboard.size_board=size_board;
<<<<<<< HEAD
     infoboard.Sw_four_playergame=Sw_four_playergame;
=======
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
     fwrite(&infoboard,sizeof(struct board_information),1,gamefile);

     for(int i=0 ; i<=TotalRows ; i++ ){
        for(int j=0 ; j<=TotalColumn ; j++){
            fwrite(&board[i][j],sizeof(int),1,gamefile);
        }
     }
     fclose(gamefile);
      return 0;
}

int undo(){
     int x=TotalRows+12,y=30;
    if(turncounter<=2 || turn==1 && swundo1==1 || turn==2 && swundo2==2 || turncounter-turncounter1==1 ){
            gotoxy(x+4,y+10);
            printf("Ando is currently disabled !",turncounter);
            return 0;
    }
    if(turn==1 ){
        turncounter1=turncounter;
        swundo1=1;
        swundo2=0;
        if(swmove2==1){
            board[row2][column2]=0;
            row2=row02; column2=column02;
            board[row2][column2]=300;
        }else if(swstick2==1){
            coordRow=((int)rowlocation-64)*4;
            coordcolumn=((int)columnlocation-64)*8-1;
            if(TypeStick == 'H' || TypeStick == 'h' ){
                for(i = coordcolumn-6; i <= coordcolumn+6; i++){
                    board[coordRow][i]=0;
                }
            }else{
                for(i=coordRow-3 ; i<=coordRow+3 ; i++){
                    board[i][coordcolumn]=0;
                }
            }
        }
        return 1;
     }
     else if( turn==2 ){
        turncounter1=turncounter;
        swundo2=1;
        swundo1=0;
        if(swmove1==1){
            board[row1][column1]=0;
            row1=row01; column1=column01;
            board[row1][column1]=200;
        }else if(swstick1==1){
            coordRow=((int)rowlocation-64)*4;
            coordcolumn=((int)columnlocation-64)*8-1;
            if(TypeStick == 'H' || TypeStick == 'h' ){
                for(i = coordcolumn-6; i <= coordcolumn+6; i++){
                    board[coordRow][i]=0;
                }
            }else{
                for(i=coordRow-3 ; i<=coordRow+3 ; i++){
                    board[i][coordcolumn]=0;
                }
            }
        }
        return 1;
     }
}

int move_play(){
    int x=TotalRows+12,y=25,t=0,type=1;
    int type_move;
    gotoxy(x+1,y-3); printf("<-");
    menu(x,y);    gotoxy(x+1,y+3);   printf("move");
    menu(x,y+11); gotoxy(x+1,y+13);  printf("stick");
    menu(x,y+22); gotoxy(x+1,y+25);  printf("undo");
    menu(x,y+33); gotoxy(x+1,y+35);  printf("reset");
    menu(x,y+44); gotoxy(x+1,y+47);  printf("save");
    menu(x,y+55); gotoxy(x+1,y+58);  printf("Home");
    gotoxy(x+1,y+66);  printf("->");
     /////////////
   while(1){
        menu_direction = getch() ;
        if(menu_direction==13){break;}
        while( menu_direction != 224){ //check true button

             menu_direction = getch();
        }
         menu_direction = getch() ;
        t++;
        if(menu_direction==75){
            if(type==1){t=6;}
            if(type==2){t=1;}
            if(type==3){t=2;}
            if(type==4){t=3;}
            if(type==5){t=4;}
            if(type==6){t=5;}
        }
        if( t==1){
            setTextColor (0,colorscreen) ;
            menu(x,y+55); gotoxy(x+1,y+58);  printf("Home");
            menu(x,y+11); gotoxy(x+1,y+13);  printf("stick");
            setTextColor (4,colorscreen) ;
            menu(x,y);    gotoxy(x+1,y+3);   printf("move");

            type=1;
        }
        if( t==2){
            setTextColor (0,colorscreen) ;
            menu(x,y);    gotoxy(x+1,y+3);   printf("move");
            menu(x,y+22); gotoxy(x+1,y+25);  printf("undo");
            setTextColor (4,colorscreen) ;
            menu(x,y+11); gotoxy(x+1,y+13);  printf("stick");

            type=2;
          }
         if(t==3){
            setTextColor (0,colorscreen) ;
            menu(x,y+11); gotoxy(x+1,y+13);  printf("stick");
            menu(x,y+33); gotoxy(x+1,y+35);  printf("reset");
            setTextColor (4,colorscreen) ;
            menu(x,y+22); gotoxy(x+1,y+25);  printf("undo");

            type=3;
        }
         if(t==4){
             setTextColor (0,colorscreen) ;
             menu(x,y+22); gotoxy(x+1,y+25);  printf("undo");
             menu(x,y+44); gotoxy(x+1,y+47);  printf("save");
             setTextColor (4,colorscreen) ;
             menu(x,y+33); gotoxy(x+1,y+35);  printf("reset");

             type=4;
        }
         if(t==5){
             setTextColor (0,colorscreen) ;
             menu(x,y+33); gotoxy(x+1,y+35);  printf("reset");
             menu(x,y+55); gotoxy(x+1,y+58);  printf("Home");
             setTextColor (4,colorscreen) ;
             menu(x,y+44); gotoxy(x+1,y+47);  printf("save");

             type=5;
        }
        if(t==6){
             setTextColor (0,colorscreen) ;
              menu(x,y+44); gotoxy(x+1,y+47);  printf("save");
             menu(x,y);    gotoxy(x+1,y+3);   printf("move");
             setTextColor (4,colorscreen) ;
             menu(x,y+55); gotoxy(x+1,y+58);  printf("Home");

             type=6;
        }
        if(t==6) {
            t=0;
        }
   }
/////////////////////////
   setTextColor (0,colorscreen) ;
   if(type==1){
      if(turn==1){
        swmove1=1;
<<<<<<< HEAD
      }else{
          swmove2=1;
=======
      }else if(turn==2){
          swmove2=1;
      }else if(turn==3){
          swmove3=1;
      }else if(turn==4){
          swmove4=1;
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
      }
      setTextColor (4,colorscreen) ;
      menu(x,y);    gotoxy(x+1,y+3);   printf("move");
      setTextColor (0,colorscreen) ;
      gotoxy(x+4,y+15);
      printf("Select the direction by : v ^ > < ") ;
      move_player = getch() ;
        while(move_player != 224)//check true button
        {
            beep(500,100) ;
            move_player = getch();
        }
        move_player = getch() ; //up or down or right or left
        result_check = check_move(move_player) ; //in checking move header
        return result_check;
    }
   else if(type==2){
     if(turn==1){
        swstick1=1;
<<<<<<< HEAD
      }else{
        swstick2=1;
=======
      }else if(turn==2){
        swstick2=1;
      }else if(turn==3){
        swstick3=1;
      }else if(turn==4){
        swstick4=1;
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
      }
     gotoxy(x+4,y+10);
     printf("Type Stick? Horizontal = H / Vertical = V");
     TypeStick = getch();
     while (TypeStick != 'H' && TypeStick != 'h' && TypeStick != 'V' && TypeStick != 'v'){
            beep(500, 100);
            TypeStick=getch();
     }
     result_check = CheckSticksPlayers(TypeStick);
     return result_check;
    }
    ///////////////////////////////
   else if(type==3){
      int ans;
      ans=undo();
      if(ans==0){
        return 0;
      }else{
        return 1;
      }
   }
   else if(type==4){

      for(int i=1 ; i<=TotalRows-2 ; i++ ){
         for(int j=0; j<=TotalColumn-2 ; j++){
                if(board[i][j]==1000 || board[i][j]==2000 || board[i][j]==200 || board[i][j]==300 ){
                    board[i][j]=0;
                }
         }
      }
      board[2][primarycolumn2]=300;
      column2=primarycolumn2;
      board[primaryrow1][primarycolumn1]=200;
      column1=primarycolumn1;
      row1=primaryrow1;
      row2=2;
      verticalsticks1 = primaryverticalsticks1;
      verticalsticks2 = primaryverticalsticks2;
      horizontalsticks1 = primaryhorizontalsticks1;
      horizontalsticks2 = primaryhorizontalsticks2;
      return 0;
   }
   else if(type==5){
     gotoxy(x+3,55);
     printf("saved!");
     if(savegame()==0){
        return 0;
     }
   }
   else if(type==6){
     int t=0;
     gotoxy(x+4,43);
     printf("Do you want to save your game? ");
    menu(x+5,y+22); gotoxy(x+6,y+25);  printf("YES");
    menu(x+5,y+33); gotoxy(x+6,y+37);  printf("NO");
     while(1){
        menu_direction = getch() ;
        if(menu_direction==13){break;}
        while( menu_direction != 224){ //check true button
             menu_direction = getch();
        }
        menu_direction = getch() ;
        t++;
        if(menu_direction==75){
            if(type==1){t=2;}
            if(type==2){t=1;}
        }
        if(t==1){
            setTextColor (0,colorscreen) ;
            menu(x+5,y+33); gotoxy(x+6,y+37);  printf("NO");
            setTextColor (2,colorscreen) ;
            menu(x+5,y+22); gotoxy(x+6,y+25);  printf("YES");
            type=1;
        }
        if(t==2){
            setTextColor (0,colorscreen) ;
           menu(x+5,y+22); gotoxy(x+6,y+25);  printf("YES");
            setTextColor (4,colorscreen) ;
            menu(x+5,y+33); gotoxy(x+6,y+37);  printf("NO");
            type=2;
        }
        if(t==2) {
            t=0;
        }

    }


    if(type==1){
      savegame();
      setTextColor(7,0);
      system("cls");
      setTextColor(7,0);
<<<<<<< HEAD
      for(Row = 0; Row <= TotalRows ; Row++){
=======
    /*  for(Row = 0; Row <= TotalRows ; Row++){
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
         for(Column = 0; Column <= TotalColumn; Column++){
             board[Row][Column]=0;
            }
        }
        verticalsticks1=primaryverticalsticks1;
        horizontalsticks1=primaryhorizontalsticks1;
        column1=primarycolumn1;
        row1=primaryrow1;
        verticalsticks2=primaryverticalsticks2;
        horizontalsticks2=primaryhorizontalsticks2;
        column2=primarycolumn2;
<<<<<<< HEAD
        row2=primaryrow2;
=======
        row2=primaryrow2;*/
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
      main();
    }else{
     setTextColor(7,0);
     system("cls");
     setTextColor(7,0);
<<<<<<< HEAD
      for(Row = 0; Row <= TotalRows ; Row++){
=======
      /*for(Row = 0; Row <= TotalRows ; Row++){
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
         for(Column = 0; Column <= TotalColumn; Column++){
             board[Row][Column]=0;
            }
        }
        verticalsticks1=primaryverticalsticks1;
        horizontalsticks1=primaryhorizontalsticks1;
        column1=primarycolumn1;
        row1=primaryrow1;
        verticalsticks2=primaryverticalsticks2;
        horizontalsticks2=primaryhorizontalsticks2;
        column2=primarycolumn2;
<<<<<<< HEAD
        row2=primaryrow2;
=======
        row2=primaryrow2;*/
>>>>>>> a1e9cdaf4d0f8b298729b8ed35ad0696338b265d
        main();
    }
   }
}
