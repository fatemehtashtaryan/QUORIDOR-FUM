#include "subcodes.h"
#include "checking_move.h"
#include "check_sticks.h"
#include "gameboard_menu.h"
int move_player;
int result_check;
int menu_direction;

int move_play(){
    int x=TotalRows+12,y=30,t=0,type=1;
    int type_move;
    gotoxy(x+1,y-3); printf("<-");
    menu(x,y);    gotoxy(x+1,y+3);   printf("move");
    menu(x,y+11); gotoxy(x+1,y+13);  printf("stick");
    menu(x,y+22); gotoxy(x+1,y+25);  printf("undo");
    menu(x,y+33); gotoxy(x+1,y+35);  printf("reset");
    menu(x,y+44); gotoxy(x+1,y+47);  printf("save");
    gotoxy(x+1,y+55);  printf("->");
     /////////////
   while(getch()!=13){
        menu_direction = getch() ;
        while( menu_direction != 224){ //check true button

             menu_direction = getch();
        }
         menu_direction = getch() ;
        t++;
        if(menu_direction==75){
            if(type==1){t=5;}
            if(type==2){t=1;}
            if(type==3){t=2;}
            if(type==4){t=3;}
            if(type==5){t=4;}

        }
        if( t==1){
            setTextColor (0,colorscreen) ;
            menu(x,y+44); gotoxy(x+1,y+47);  printf("save");
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
             menu(x,y);    gotoxy(x+1,y+3);   printf("move");
             setTextColor (4,colorscreen) ;
             menu(x,y+44); gotoxy(x+1,y+47);  printf("save");

             type=5;
        }
           if(t==5) {
            t=0;
           }
   }
/////////////////////////
   setTextColor (0,colorscreen) ;
   if(type==1){
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
   else if(type==3){
     gotoxy(x+4,y+15);
     printf("undo");
   }
   else if(type==4){
     gotoxy(x+4,y+15);
     printf("reset");
   }
   else if(type==5){
     gotoxy(x+4,y+15);
     printf("saved!");
   }

}

