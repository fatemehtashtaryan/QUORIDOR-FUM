#ifndef random_lucky_boxes
#include "subcodes.h"
#include "Rewards.h"
#include "pells.h"
int  Lucky_box(int x,int y){
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
    int x=10,y=1,t=0,swcolor,tbox,s=100,a=1,swagain1=1, swagain2=1,x1=50,x2=50, sw_rewards, n=1;
    tloop=2;
    srand(time(0));
    tbox = rand()%27+1;
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
   while(tloop>0){
       while(1){
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
       if(tloop==2){
            if(swagain2==0&&n!=1&&swagain1==1) break;
            swcolor=1;
            if(swcolor==1){
                setTextColor (2,colorscreen);
                 sw_rewards=rand()%100+1;
                 sw_rewards=13;
                 if(sw_rewards%8==0) increase_sticks();
                 if(sw_rewards%8==1){
                    if(Open_path()==1) {gotoxy(19,x1+strlen(name_player_1)); printf("your path is opeining!");}
                    else{setTextColor(4, colorscreen); gotoxy(19,x1+7+strlen(name_player_1)); printf("Oops!! can't open your path!");setTextColor(2, colorscreen); }
                }
                 if(sw_rewards%8==2){
                      if(undo_competitor()==1){gotoxy(19,x1-3+strlen(name_player_1)); printf("You can undo your opponent's move");}
                      else{gotoxy(19,x1-3+strlen(name_player_1)); printf("Oops!! you can't use the competitor's Ando move bonus");}
               }
                if(sw_rewards%8==3) decrease_sticks_competitor();
                if(sw_rewards%8==4) swagain1=0;
                if(sw_rewards%8==5&&sw_turnagain2==1) {printf("1 more Move!"); sw_turnagain1=0;}
               //if(sw_rewards%8==6)
               if(sw_rewards%8==7){setTextColor (4,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("Sorry! this box is empty, you have no rewards"); setTextColor (2,colorscreen);}
            }else{
                setTextColor (4,colorscreen);
                sw_rewards=rand()%100+1;
                if(sw_rewards%7==0) reset();
                if(sw_rewards%7==1) roadblock();
                if(sw_rewards%7==2) decrease_sticks_player();
                if(sw_rewards%7==3) reduction_wood();
                //if(sw_rewards%7==4)
                //if(sw_rewards%7==5)
                if(sw_rewards%7==6){setTextColor (2,colorscreen); gotoxy(19,x1-3+strlen(name_player_1)); printf("You are lucky, this box is empty"); setTextColor (4,colorscreen);}
            }
            Lucky_box(18,x1-10); gotoxy(19,x1-8); printf("?");
            gotoxy(19,x1-4); printf("%s:", name_player_1);
            // swagain=0;
             if(swagain1==0){
                    gotoxy(19,x1-3+strlen(name_player_1)); printf("You have new Chance!");
             }
      //   if(swagain1==0&&swagain2==1&&n!=1) tloop=3;
       }else if(tloop==1){
            if(swagain1==0&&n!=1&&swagain2==1) break;
            if(swcolor==1){
                setTextColor (2,colorscreen);
                 sw_rewards=rand()%100+1;
                 if(sw_rewards%8==0) increase_sticks();
                 if(sw_rewards%8==1){
                    if(Open_path()==1) { gotoxy(23,x2+7+strlen(name_player_2)); printf("your path is opeining!");}
                    else{setTextColor(4, colorscreen); gotoxy(23,x2+7+strlen(name_player_2)); printf("Oops!! can't open your path!"); setTextColor(2, colorscreen);}
                 }
                 if(sw_rewards%8==2){
                       if(undo_competitor()==1){gotoxy(23,x2-3+strlen(name_player_2)); printf("undo your opponent's move");}
                       else{gotoxy(23,x2-3+strlen(name_player_2)); printf("Oops!! you can't use the competitor's undo move bonus");}
                  }
                 if(sw_rewards%8==3)decrease_sticks_competitor();
                 if(sw_rewards%8==4) swagain2=0;
                 if(sw_rewards%8==5&&sw_turnagain1==1) {printf("1 more Move!"); sw_turnagain2=0;}
              // if(sw_rewards%8==6)
                 if(sw_rewards%8==7) {setTextColor (4,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("Sorry! this box is empty, you have no rewards"); setTextColor (2,colorscreen);}
            }else{
                setTextColor (4,colorscreen);
                sw_rewards=rand()%100+1;
                if(sw_rewards%7==0) reset();
                if(sw_rewards%7==1) roadblock();
                if(sw_rewards%7==2) decrease_sticks_player();
                if(sw_rewards%7==3) reduction_wood();
                //if(sw_rewards%7==4)
                //if(sw_rewards%7==5)
                if(sw_rewards%7==6){setTextColor (2,colorscreen); gotoxy(23,x2-3+strlen(name_player_2)); printf("You are lucky, this box is empty"); setTextColor (4,colorscreen);}
            }
             Lucky_box(22,x2-10); gotoxy(23,x2-8); printf("?");
             gotoxy(23,x2-4); printf("%s:", name_player_2);
             if(swagain2==0){
                    gotoxy(23,x2-3+strlen(name_player_2)); printf("You have new Chance!");

             }
       }
        t=0;
        tbox=7;
        tloop--;
   /*     if(swagain1==1&&swagain2==1) tloop=2;
        if(swagain1==0)tloop=2;
        swagain1=1;
        if(swagain2==0)tloop=1;
        swagain2=1;
        n++;*/
   }
   sleep(7000);
}
#endif // random_lucky_boxes
