#include "subcodes.h"
#include "check_sticks.h"
#include "checking_move.h"



int Row, Column, counter=0, verticalstick, horizontalstick, counter1, counter2;

void check_child_stick(){//checking places that possible to putting stick
       int result = 0;
       turn = 4 ;
       TypeStick = 'h' ;
       for(counter1 = 65; counter1<size_board+64 && horizontalstick != 0; counter1++){//finding the places where the horiontal stick will be plased
            for(counter2 = 65; counter2<size_board+64 &&  horizontalstick != 0 ; counter2++){
                if(stick_movement_h_full[counter1-65][counter2-65] == 3){//checking whether it is possible to put stick or not
                     rowlocation = (char)counter1;
                     columnlocation = (char)counter2;
                     result = CheckSticksPlayers(TypeStick) ;//checking in DFS
                     if(result == 1){//everything is OK
                         true_child[counter].row = coordRow;
                         true_child[counter].column = coordcolumn;
                         true_child[counter].movement = 'h';
                         counter++;
                     }
                  }
            }
       }
       TypeStick = 'v' ;
       for(counter1 = 65; counter1<size_board+64 && verticalstick != 0; counter1++){//finding the places where the vertical stick will be plased
            for(counter2 = 65; counter2<size_board+64 && verticalstick != 0; counter2++){
                if(stick_movement_v_full[counter1-65][counter2-65] == 3){//checking whether it is possible to put stick or not
                     rowlocation = (char)counter1;
                     columnlocation = (char)counter2;
                     result = CheckSticksPlayers(TypeStick) ;//checking in DFS
                     if(result == 1){//everything is OK
                         true_child[counter].row = coordRow;
                         true_child[counter].column = coordcolumn;
                         true_child[counter].movement = 'v';
                         counter++;
                     }
                  }
            }
       }
}

void check_child_move(){
    PLAYER = 'C' ;
    int type_move;
        int result = 0;
        type_move = 72 ;//up
        result = check_move(type_move);
        if(result == 1){//everything is OK
            true_child[counter].row = Row-4;
            true_child[counter].column = Column;
            true_child[counter].movement = 'm';
            Row += 4 ;//Return to previous state
            counter ++;
        }
        type_move = 80 ;//down
        result = check_move(type_move);
        if(result == 1){//everything is OK
            true_child[counter].row = Row+4;
            true_child[counter].column = Column;
            true_child[counter].movement = 'm';
            Row -= 4;//Return to previous state
            counter ++;
        }
        type_move = 77; //right
        result = check_move(type_move);
        if(result == 1){//everything is OK
            true_child[counter].row = Row;
            true_child[counter].column = Column+8;
            true_child[counter].movement = 'm';
            Column -= 8;//Return to previous state
            counter ++;
        }
        type_move = 75 ;//left
        result = check_move(type_move);
        if(result == 1){//everything is OK
            true_child[counter].row = Row;
            true_child[counter].column = Column-8;
            true_child[counter].movement = 'm';
            Column += 8;//Return to previous state
            counter ++;
        }
}

void check_child(){//sorting functions
        if(turn == 1){
            Row = row1;
            Column = column1;
            horizontalstick = horizontalsticks1;
            verticalstick = verticalsticks1;
        }
        else{
            Row = row2;
            Column = column2;
            horizontalstick = horizontalsticks2;
            verticalstick = verticalsticks2;

        }
        check_child_stick();
        check_child_move();
}
