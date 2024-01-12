#include "subcodes.h"
#include "checking_move.h"
#include "check_sticks.h"
#include "main_board.h"

struct type_move{//for checking true movement
        int type_movement;
        int sw;
};

int stick_movement_h[14][14];
int stick_movement_v[14][14];
struct type_move movement[4] ;

int computer_stick(){
       int type_movement, result = 0, counter1, counter2, can_put_stick_h=1, can_put_stick_v=1, rowlocat, columnlocat;
       for(counter1 = 97; counter1 <= size_board+96; counter1++){//for checking places can put sticks
            for(counter2 = 97; counter2 <= size_board+96; counter2++){
                stick_movement_h[counter1-97][counter2-97] = 1;
                stick_movement_v[counter1-97][counter2-97] = 1;
         }
       }
       if(verticalsticks2 == 0) can_put_stick_v==0;
       if(horizontalsticks2 == 0) can_put_stick_h == 0;
          do{
            if(can_put_stick_h == 0 && can_put_stick_v==0) return 0;
            type_movement = rand()%2+1;//chosing horizontal or vertical stick
            if(type_movement == 1&& can_put_stick_h== 1 ){// if we can put horizontal stick
                    printf("%d",type_movement );
                do{
                    TypeStick = 'h';
                        can_put_stick_h = 0;
                        for(counter1 = 97; counter1 < size_board+96 && can_put_stick_h == 0; counter1++){//for checking places can put sticks
                             for(counter2 = 97; counter2 < size_board+96 && can_put_stick_h == 0; counter2++){
                                  if(stick_movement_h[counter1-97][counter2-97] == 1 && stick_movement_h_full[counter1-97][counter2-97] == 3) {
                                         printf("%d", stick_movement_h_full[counter1-97][counter2-97]);

                                      columnlocation=(char)counter1;
                                      rowlocation=(char)counter2;
                                      printf("%c %c",rowlocation, columnlocation);
                                      turn = 4;
                                      result = CheckSticksPlayers(TypeStick);
                                      if(result==1) can_put_stick_h=1;
                                      else can_put_stick_h=0;
                                  }
                             }
                         }
                    if(can_put_stick_h == 1){
                       do{
                            turn = 3;
                            rowlocat =rand()%(size_board-1)+97 ;//(size_board+95-97+1)
                            columnlocat =rand()%(size_board-1)+97 ;//(size_board+95-97+1)
                            columnlocation=(char)columnlocat;
                            rowlocation=(char)rowlocat;
                        }while ((stick_movement_h[rowlocat-97][columnlocat-97] == 0 || stick_movement_h_full[rowlocat-97][columnlocat-97] == 2) );//while we chose the true stick
                            result = CheckSticksPlayers(TypeStick);//checking for DFS
                            if (result ==0 ) stick_movement_h[rowlocat-97][columnlocat-97] = 0;//changing that position for putting stick to 0
                    }
            }while(result == 0&& can_put_stick_h == 1);
          }
          else type_movement = 2;
          if (type_movement == 2 && can_put_stick_v == 1){// if we can put vertical stick
                 printf("%d",type_movement );
                do{
                    TypeStick = 'v';
                        can_put_stick_v = 0;
                        for(counter1 = 97; counter1 < size_board+96 && can_put_stick_v == 0; counter1++){//for checking places can put sticks
                             for(counter2 = 97; counter2 < size_board+96 && can_put_stick_v == 0; counter2++){
                                  if(stick_movement_v[counter1-97][counter2-97] == 1 && stick_movement_v_full[counter1-97][counter2-97] == 3) {
                                    printf("%d", stick_movement_v_full[counter1-97][counter2-97]);
                                      columnlocation=(char)counter1;
                                      rowlocation=(char)counter2;
                                       printf("%c %c",rowlocation, columnlocation);
                                      turn = 4;
                                      result = CheckSticksPlayers(TypeStick);
                                      if(result ==1) can_put_stick_v=1;
                                      else can_put_stick_v=0;
                                  }
                             }
                         }
                     if(can_put_stick_v == 1){
                        do{
                            turn = 3;
                            printf("%dv", can_put_stick_v);
                            rowlocat = rand()%(size_board-1)+97;//(size_board+95-97+1)
                            rowlocation = (char)rowlocat;
                            columnlocat = rand()%(size_board-1)+97;//(size_board+95-97+1)
                            columnlocation = (char)columnlocat;
                        }while ((stick_movement_v[rowlocat-97][columnlocat-97] == 0 || stick_movement_v_full[rowlocat-97][columnlocat-97] == 2) );//while we chose the true stick
                          result = CheckSticksPlayers(TypeStick);//checking for DFS
                          if (result ==0 ) stick_movement_v[rowlocat-97][columnlocat-97] = 0;//changing that position for putting stick to 0
                     }
                }while(result == 0 && can_put_stick_v == 1);
          }
        else type_movement = 1;
    }while(result == 0 && (can_put_stick_h == 1 || can_put_stick_v == 1)) ;//while there is possible to putting stick
    if( can_put_stick_h == 0 && can_put_stick_v == 0) return 0;
    return 1;
}

int move_computer(){
    int counter, type_movement, result, can_move = 0, i, type_move;
    for(counter = 1; counter <= 4; counter++){//for checking places can move
     movement[counter-1].type_movement = counter;
     movement[counter-1].sw= 1 ;
    }
      do{
            can_move = 0;
            for(i = 0; i<4 && can_move == 0; i++){
                if( movement[i].sw == 1) can_move  = 1;
                }
            if(can_move == 0) return 0;//there is no movement
                type_movement = rand()%4+1;//type of move
                switch (type_movement){
                     case 1 : type_move = 72 ;//up
                                 break;
                     case 2 : type_move = 80 ;//down
                            break;
                     case 3 : type_move = 77; //right
                             break;
                     case 4 : type_move = 75 ;//left
                             break;
                }
                if(movement[type_movement-1].sw == 1 ){
                   result = check_move(type_move);//checking true move
                   if(result == 0) movement[type_movement-1].sw = 0;//changing switch of type of movement to 0
                }
        }while( result == 0 && can_move == 1);
        return 1;
}

int rand_move_computer(){
    int  movement, true_movement1 = 0, true_movement2 = 0;
    if(verticalsticks2 == 0 && horizontalsticks2 == 0) movement = 1;
    else {
        srand(time(0));
        movement = rand()%2+1;//move or stick
        printf("%d", movement);
        if(movement == 1){
           true_movement1 = computer_stick();
           turn = 3;
       }
        else true_movement1 = move_computer();
        if(true_movement1 == 1) return 1;
    }
    if(true_movement1 == 0){//changing last type of move to another type
    if( movement == 1 ) true_movement2 = move_computer();
    else if ( movement == 2 ) true_movement2 = computer_stick();
    }
    return 1;
}
