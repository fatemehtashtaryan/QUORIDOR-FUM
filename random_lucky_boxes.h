#ifndef random_lucky_boxes
#include "subcodes.h"
#include "Rewards.h"
#include "spell.h"

//This file contains main function for "spell" and "rewards" (for 2 players OR 4 players).

int  Lucky_box(int x,int y){//for drawing box
     int T=1,countcolumn,countrow, sw_rewards ;
     gotoxy(x, y) ;
     printf ("%c", a) ;
     for(countcolumn = 0; countcolumn < 3; countcolumn++)
    {
        printf ("%c", d) ;
     }
     printf ("%c", f) ;

     gotoxy(x+T, y) ;
     printf("%c", b) ;
     T++;

     gotoxy(x+2, y) ;
     printf("%c", c) ;
     for(countcolumn = 0; countcolumn <3; countcolumn++)
    {
        printf("%c", d) ;
     }
     printf("%c", e) ;
     T=1;

    gotoxy(x+T, y+4) ;
    printf("%c", b) ;
    T++;
}

int rand_boxes()
{
    int x=10,y=1,t=0,swcolor,tbox,s=80,a=1,sw_rewards, n=1, sw_turnagainblock1=1, sw_turnagainblock2=1;
    tloop=4;
    srand(time(0));
    tbox = rand()%27+1;
    //drawing lucky boxes
    Lucky_box(y+3,x+20); gotoxy(y+4,x+22); printf("?");
    Lucky_box(y+3,x+26); gotoxy(y+4,x+28); printf("?");
    Lucky_box(y+6,x+20); gotoxy(y+7,x+22); printf("?");
    Lucky_box(y+9,x+20); gotoxy(y+10,x+22); printf("?");
    Lucky_box(y+9,x+26); gotoxy(y+10,x+28); printf("?");
    Lucky_box(y+12,x+20); gotoxy(y+13,x+22); printf("?");
    Lucky_box(y+3,x+34); gotoxy(y+4,x+36); printf("?");
    Lucky_box(y+6,x+34); gotoxy(y+7,x+36); printf("?");
    Lucky_box(y+9,x+34); gotoxy(y+10,x+36); printf("?");
    Lucky_box(y+12,x+34); gotoxy(y+13,x+36); printf("?");
    Lucky_box(y+12,x+40); gotoxy(y+13,x+42); printf("?");
    Lucky_box(y+12,x+46); gotoxy(y+13,x+48); printf("?");
    Lucky_box(y+9,x+46); gotoxy(y+10,x+48); printf("?");
    Lucky_box(y+6,x+46); gotoxy(y+7,x+48); printf("?");
    Lucky_box(y+3,x+46); gotoxy(y+4,x+48); printf("?");
    Lucky_box(y+3,x+54); gotoxy(y+4,x+56); printf("?");
    Lucky_box(y+6,x+54); gotoxy(y+7,x+56); printf("?");
    Lucky_box(y+9,x+54); gotoxy(y+10,x+56); printf("?");
    Lucky_box(y+12,x+54); gotoxy(y+13,x+56); printf("?");
    Lucky_box(y+12,x+54); gotoxy(y+13,x+56); printf("?");
    Lucky_box(y+3,x+60); gotoxy(y+4,x+62); printf("?");
    Lucky_box(y+6,x+66); gotoxy(y+7,x+68); printf("?");
    Lucky_box(y+3,x+72); gotoxy(y+4,x+74); printf("?");
    Lucky_box(y+3,x+78); gotoxy(y+4,x+80); printf("?");
    Lucky_box(y+6,x+78); gotoxy(y+7,x+80); printf("?");
    Lucky_box(y+9,x+78); gotoxy(y+10,x+80); printf("?");
    Lucky_box(y+12,x+78); gotoxy(y+13,x+80); printf("?");
    /////
   while(tloop>0){//if it is for 4 players
       if(Sw_four_playergame==1){if(tloop<=2) break;}//if it is not for 4 players
       while(1){//changing the color of locky boxes
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+3,x+20); gotoxy(y+4,x+22); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+3,x+20); gotoxy(y+4,x+22); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+3,x+26); gotoxy(y+4,x+28); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+3,x+26); gotoxy(y+4,x+28); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+6,x+20); gotoxy(y+7,x+22); printf("?");swcolor=0;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+6,x+20); gotoxy(y+7,x+22); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+9,x+20); gotoxy(y+10,x+22); printf("?");swcolor=1;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+9,x+20); gotoxy(y+10,x+22); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+9,x+26); gotoxy(y+10,x+28); printf("?");swcolor=0;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+9,x+26); gotoxy(y+10,x+28); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+12,x+20); gotoxy(y+13,x+22); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+12,x+20); gotoxy(y+13,x+22); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+3,x+34); gotoxy(y+4,x+36); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+3,x+34); gotoxy(y+4,x+36); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+6,x+34); gotoxy(y+7,x+36); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+6,x+34); gotoxy(y+7,x+36); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+9,x+34); gotoxy(y+10,x+36); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+9,x+34); gotoxy(y+10,x+36); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+12,x+34); gotoxy(y+13,x+36); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+12,x+34); gotoxy(y+13,x+36); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+12,x+40); gotoxy(y+13,x+42); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+12,x+40); gotoxy(y+13,x+42); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+12,x+46); gotoxy(y+13,x+48); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+12,x+46); gotoxy(y+13,x+48); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+9,x+46); gotoxy(y+10,x+48); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+9,x+46); gotoxy(y+10,x+48); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+6,x+46); gotoxy(y+7,x+48); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+6,x+46); gotoxy(y+7,x+48); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+3,x+46); gotoxy(y+4,x+48); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+3,x+46); gotoxy(y+4,x+48); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+3,x+54); gotoxy(y+4,x+56); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+3,x+54); gotoxy(y+4,x+56); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+6,x+54); gotoxy(y+7,x+56); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+6,x+54); gotoxy(y+7,x+56); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+9,x+54); gotoxy(y+10,x+56); printf("?"); swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+9,x+54); gotoxy(y+10,x+56); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+12,x+54); gotoxy(y+13,x+56); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+12,x+54); gotoxy(y+13,x+56); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+12,x+54); gotoxy(y+13,x+56); printf("?");swcolor=1;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+12,x+54); gotoxy(y+13,x+56); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+3,x+60); gotoxy(y+4,x+62); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+3,x+60); gotoxy(y+4,x+62); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+6,x+66); gotoxy(y+7,x+68); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+6,x+66); gotoxy(y+7,x+68); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+3,x+72); gotoxy(y+4,x+74); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+3,x+72); gotoxy(y+4,x+74); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+3,x+78); gotoxy(y+4,x+80); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+3,x+78); gotoxy(y+4,x+80); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+6,x+78); gotoxy(y+7,x+80); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+6,x+78); gotoxy(y+7,x+80); printf("?");
            sleep(s);setTextColor (4,colorscreen); Lucky_box(y+9,x+78); gotoxy(y+10,x+80); printf("?");swcolor=0;t++;if(t==tbox)break;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+9,x+78); gotoxy(y+10,x+80); printf("?");
            sleep(s);setTextColor (2,colorscreen); Lucky_box(y+12,x+78); gotoxy(y+13,x+80); printf("?");swcolor=1;t++;if(t==tbox)break;s+=a*30;
            sleep(s);setTextColor (0,colorscreen); Lucky_box(y+12,x+78); gotoxy(y+13,x+80); printf("?");
       }
//start for player 1
       if(tloop==4){//for player 1
            if(swcolor==1){//for rewards
                setTextColor (2,colorscreen);
                 sw_rewards=rand()%100+1;
                 if(sw_rewards%5==0) increase_sticks();
                 else if(sw_rewards%5==1){
                    if(Open_path()==1) {gotoxy(19,x1-3+strlen(name_player_1)); printf("your path is opeining!");}
                    else{setTextColor(4, colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("Oops!! your path was open!");setTextColor(2, colorscreen); }
                }
                else if(sw_rewards%5==2) decrease_sticks_competitor();
                else if(sw_rewards%5==3) {gotoxy(19,x1-3+strlen(name_player_1)); printf("1 more Move!"); sw_turnagain1=0;}//if sw_turnagain==0 means move twice
                else if(sw_rewards%5==4){setTextColor (4,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("Sorry! this box is empty, you have no rewards"); setTextColor (2,colorscreen);}//if the box is empty
            }else{//for spells
                setTextColor (4,colorscreen);
                sw_rewards=rand()%100+1;
                if(sw_rewards%6==0) reset();
                else if(sw_rewards%6==1) roadblock();
                else if(sw_rewards%6==2) decrease_sticks_player();
                else if(sw_rewards%6==3) reduction_wood();
                else if(sw_rewards%6==4){setTextColor (2,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("You are lucky, this box is empty"); setTextColor (4,colorscreen);}//if the box is empty
                else if(sw_rewards%6==5){gotoxy(19,x1-3+strlen(name_player_1)); printf("You cannot move for ONCE!"); sw_turnagain2=0; sw_turnagainblock1=0;}//if sw_turnagain==0 means move twice
            }
             if(swcolor==1) setTextColor (2,colorscreen);
             else setTextColor (4,colorscreen);
             Lucky_box(18,x1-10); gotoxy(19,x1-8); printf("?");
            gotoxy(19,x1-4); printf("%s:", name_player_1);
////end of player 1
//start of player 2
       }else if(tloop==3){//for player 2
            if(swcolor==1){//for rewards
                setTextColor (2,colorscreen);
                 sw_rewards=rand()%100+1;
                 if(sw_rewards%5==0) increase_sticks();
                 else if(sw_rewards%5==1){
                    if(Open_path()==1) { gotoxy(23,x2-3+strlen(name_player_2)); printf("your path is opeining!");}
                    else{setTextColor(4, colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("Oops!! your path was open!"); setTextColor(2, colorscreen);}
                 }
                 else if(sw_rewards%5==2)decrease_sticks_competitor();
                 else if(sw_rewards%5==3&&sw_turnagain1==1&&sw_turnagainblock1==1) {gotoxy(23,x2-3+strlen(name_player_2)); printf("1 more Move!"); sw_turnagain2=0;}//sw_turnagain==0 means move twice && sw_turnagainblock==0 means player can not move
                 else if(sw_rewards%5==3&&(sw_turnagain1==0 || sw_turnagainblock1==0)) {setTextColor (4,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("Sorry! this box is empty, you have no rewards"); setTextColor (2,colorscreen);}//if another player can move twice OR can not move
                 else if(sw_rewards%5==4) {setTextColor (4,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("Sorry! this box is empty, you have no rewards"); setTextColor (2,colorscreen);}//if the box is empty
            }else{//for spells
                setTextColor (4,colorscreen);
                sw_rewards=rand()%100+1;
                if(sw_rewards%6==0) reset();
                else if(sw_rewards%6==1) roadblock();
                else if(sw_rewards%6==2) decrease_sticks_player();
                else if(sw_rewards%6==3) reduction_wood();
                else if(sw_rewards%6==4){setTextColor (2,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("You are lucky, this box is empty"); setTextColor (4,colorscreen);}//if the box is empty
                else if(sw_rewards%6==5&&sw_turnagainblock1==1&&sw_turnagain1==1){gotoxy(23,x2-3+strlen(name_player_2)); printf("You cannot move for ONCE!"); sw_turnagain1=0;}//sw_turnagain==0 means move twice && sw_turnagainblock==0 means player can not move
                else if(sw_rewards%6==5&&(sw_turnagainblock1==0 || sw_turnagain1==0)){setTextColor (2,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("You are lucky, this box is empty"); setTextColor (4,colorscreen);}//if another player can not move OR move twice, player two should move
            }
             if(swcolor==1) setTextColor (2,colorscreen);
             else setTextColor (4,colorscreen);
             Lucky_box(22,x2-10); gotoxy(23,x2-8); printf("?");
             gotoxy(23,x2-4); printf("%s:", name_player_2);
       }
////end of player 2
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
////for 4 players game :
//start of player 3
       if(Sw_four_playergame==0){
          if(tloop==2){//for player 3
             if(swcolor==1){//for rewards
                setTextColor (2,colorscreen);
                 sw_rewards=rand()%100+1;
                 if(sw_rewards%4==0) increase_sticks();
                 else if(sw_rewards%4==1){
                    if(Open_path()==1) { gotoxy(27,x3-3+strlen(name_player_3)); printf("your path is opeining!");}
                    else{setTextColor(4, colorscreen); gotoxy(27,x3-3+strlen(name_player_3)); printf("Oops!! your path was open!"); setTextColor(2, colorscreen);}
                 }
                 else if(sw_rewards%4==2)decrease_sticks_competitor();
                 else if(sw_rewards%4==3) {setTextColor (4,colorscreen); gotoxy(27,x3-3+strlen(name_player_3)); printf("Sorry! this box is empty, you have no rewards"); setTextColor (2,colorscreen);}//if the box is empty
            }else{//for spells
                setTextColor (4,colorscreen);
                sw_rewards=rand()%100+1;
                sw_rewards=1;
                if(sw_rewards%5==0) reset();
                else if(sw_rewards%5==1) roadblock();
                else if(sw_rewards%5==2) decrease_sticks_player();
                else if(sw_rewards%5==3) reduction_wood();
                else if(sw_rewards%5==4){setTextColor (2,colorscreen); gotoxy(27,x3-3+strlen(name_player_3)); printf("You are lucky, this box is empty"); setTextColor (4,colorscreen);}//if the box is empty
            }
             if(swcolor==1) setTextColor (2,colorscreen);
             else setTextColor (4,colorscreen);
             Lucky_box(26,x3-10); gotoxy(27,x3-8); printf("?");
             gotoxy(27,x3-4); printf("%s:", name_player_3);
       }
////end of player 3
//start for player4:
          else if(tloop==1){//for player 4
            if(swcolor==1){//for rewards
                setTextColor (2,colorscreen);
                 sw_rewards=rand()%100+1;
                 if(sw_rewards%4==0) increase_sticks();
                 else if(sw_rewards%4==1){
                    if(Open_path()==1) { gotoxy(31,x4-3+strlen(name_player_4)); printf("your path is opeining!");}
                    else{setTextColor(4, colorscreen); gotoxy(31,x4-3+strlen(name_player_4)); printf("Oops!! your path was open!"); setTextColor(2, colorscreen);}
                 }
                 else if(sw_rewards%4==2)decrease_sticks_competitor();
                 else if(sw_rewards%4==3) {setTextColor (4,colorscreen); gotoxy(31,x4-3+strlen(name_player_4)); printf("Sorry! this box is empty, you have no rewards"); setTextColor (2,colorscreen);}//if the box is empty
            }else{//for spells
                setTextColor (4,colorscreen);
                sw_rewards=rand()%100+1;
                sw_rewards=1;
                if(sw_rewards%5==0) reset();
                else if(sw_rewards%5==1) roadblock();
                else if(sw_rewards%5==2) decrease_sticks_player();
                else if(sw_rewards%5==3) reduction_wood();
                else if(sw_rewards%5==4){setTextColor (2,colorscreen); gotoxy(31,x4-3+strlen(name_player_4)); printf("You are lucky, this box is empty"); setTextColor (4,colorscreen);}//if the box is empty
            }
             if(swcolor==1) setTextColor (2,colorscreen);
             else setTextColor (4,colorscreen);
             Lucky_box(30,x4-10); gotoxy(31,x4-8); printf("?");
             gotoxy(31,x4-4); printf("%s:", name_player_4);
          }
////end of player 4
       }
/////////////////////////////////////////////////////////////////////////////////end of 4 players game
        t=0;
        tbox=7;
        tloop--;
        s=80;
   }
   sleep(7000);
}
#endif // random_lucky_boxes
