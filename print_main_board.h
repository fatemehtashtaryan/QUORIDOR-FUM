#include "main_board.h"
#include "subcodes.h"
//this file is about print main board and colores around houses

void printboardgame( TotalRows , TotalColumn){
    int  Rowcopy, Columncopy;
    int  Row, Column, sw=1 ,i ,swtogether=1,Ttogether=1,sw12=1,sw13=1,sw14=1,sw23=1,sw24=1,sw34=1;
    int  swtogether12=1,swtogether13=1,swtogether14=1,swtogether23=1,swtogether24=1,swtogether34=1;
    int  swtogether123=1,swtogether124=1,swtogether134=1,swtogether234=1,swtogether1234=1;
    ////////////////////////////////////////for minimax (copyboard)
    if(typeplayer2==2){
        for( Rowcopy = 0;  Rowcopy < TotalRows ;  Rowcopy++){
            for(Columncopy = 0; Columncopy < TotalColumn ; Columncopy++){

                    copy_board.copyboard[ Rowcopy][Columncopy] = board[ Rowcopy][Columncopy];
            }
        }
         copy_board.copyverticalsticks1 = verticalsticks1;
         copy_board.copyverticalsticks2 = verticalsticks2;
         copy_board.copyhorizontalsticks1 = horizontalsticks1;
         copy_board.copyhorizontalsticks2 = horizontalsticks2;
    }
    /////////////////////////////////////////// color around houses

     board[row1-1][column1-2]=30;
     board[row1-1][column1+2]=40;
     board[row1+1][column1-2]=50;
     board[row1+1][column1+2]=60;
     board[row1][column1-2]=62;
     board[row1][column1+2]=62;
     board[row1+1][column1]=63;
     board[row1-1][column1]=63;
     board[row1-1][column1-1]=63;
     board[row1-1][column1+1]=63;
     board[row1+1][column1-1]=63;
     board[row1+1][column1+1]=63;
     board[row2-1][column2-2]=33;
     board[row2-1][column2+2]=44;
     board[row2+1][column2-2]=55;
     board[row2+1][column2+2]=59;
     board[row2][column2-2]=61;
     board[row2][column2+2]=61;
     board[row2+1][column2]=64;
     board[row2-1][column2]=64;
     board[row2-1][column2+1]=64;
     board[row2-1][column2-1]=64;
     board[row2+1][column2-1]=64;
     board[row2+1][column2+1]=64;

     if(Sw_four_playergame==0){ //player3&&4
         board[row3-1][column3-2]=401;
         board[row3-1][column3+2]=402;
         board[row3+1][column3-2]=403;
         board[row3+1][column3+2]=404;
         board[row3][column3-2]=405;
         board[row3][column3+2]=405;
         board[row3+1][column3]=406;
         board[row3-1][column3]=406;
         board[row3-1][column3-1]=406;
         board[row3-1][column3+1]=406;
         board[row3+1][column3-1]=406;
         board[row3+1][column3+1]=406;
         board[row4-1][column4-2]=407;
         board[row4-1][column4+2]=408;
         board[row4+1][column4-2]=409;
         board[row4+1][column4+2]=410;
         board[row4][column4-2]=411;
         board[row4][column4+2]=411;
         board[row4+1][column4]=412;
         board[row4-1][column4]=412;
         board[row4-1][column4+1]=412;
         board[row4-1][column4-1]=412;
         board[row4+1][column4-1]=412;
         board[row4+1][column4+1]=412;
     }

     ////////////////////////////////////// for together beats
     if (board[row1][column1]!=500)board[row1][column1]=200;
     if (board[row2][column2]!=500)board[row2][column2]=300;
     if(Sw_four_playergame==0){
        if (board[row3][column3]!=500)board[row3][column3]=600;
        if (board[row4][column4]!=500)board[row4][column4]=700;
     }

     if((row1==row2 && column1==column2 &&Sw_four_playergame==1)){
         board[row1-1][column1-2]=301;
         board[row1-1][column1+2]=302;
         board[row1+1][column1-2]=303;
         board[row1+1][column1+2]=304;
         board[row1][column1-2]=305;
         board[row1][column1+2]=305;
         board[row1+1][column1]=306;
         board[row1-1][column1]=306;
         board[row1-1][column1-1]=306;
         board[row1-1][column1+1]=306;
         board[row1+1][column1-1]=306;
         board[row1+1][column1+1]=306;
         board[row1][column1]=500;
     }
     sw=1;
     if(Sw_four_playergame==0){ //for together beats
        if(row1==row2&&column1==column2) sw12=0;
        if(row1==row3&&column1==column3) sw13=0;
        if(row1==row4&&column1==column4) sw14=0;
        if(row2==row3&&column2==column3) sw23=0;
        if(row2==row4&&column2==column4) sw24=0;
        if(row3==row4&&column3==column4) sw34=0;
        if(sw12==0&&sw13==1&&sw14==1){swtogether12=0;Ttogether=2;}
        if(sw13==0&&sw14==1&&sw12==1){swtogether13=0;Ttogether=2;}
        if(sw14==0&&sw12==1&&sw13==1){swtogether14=0;Ttogether=2;}
        if(sw23==0&&sw24==1&&sw12==1){swtogether23=0;Ttogether=2;}
        if(sw24==0&&sw12==1&&sw23==1){swtogether24=0;Ttogether=2;}
        if(sw34==0&&sw13==1&&sw23==1){swtogether34=0;Ttogether=2;}
        if(sw12==0&&sw13==0&&sw14==1) {swtogether123=0;Ttogether=3;}
        if(sw12==0&&sw14==0&&sw12==1) {swtogether124=0;Ttogether=3;}
        if(sw13==0&&sw14==0&&sw12==1) {swtogether134=0;Ttogether=3;}
        if(sw23==0&&sw24==0&&sw12==1) {swtogether234=0;Ttogether=3;}
        if(sw23==0&&sw24==0&&sw12==0) {swtogether1234=0;Ttogether=4;}
        }


     ////////////////////////////////////////+
     for(t=1 ; t<=4 ;t++){
             if(t==1){Row=row1;Column=column1;}
             if(t==2){Row=row2;Column=column2;}
             if(t==3){Row=row3;Column=column3;}
             if(t==4){Row=row4;Column=column4;}
             if(board[Row-2][Column] == 0 && board[Row-4][Column] == 0 && turn == t) board[Row-4][Column] =400;
             if(board[Row+2][Column] == 0 && board[Row+4][Column] == 0 && turn == t) board[Row+4][Column] =400;
             if(board[Row][Column+4] == 0 && board[Row][Column+8] == 0 && turn == t) board[Row][Column+8] =400;
             if(board[Row][Column-4] == 0 && board[Row][Column-8] == 0 && turn == t) board[Row][Column-8] =400;
             if(Sw_four_playergame==1 && t==2) break;
      }

     ///////////////////////////////////
    for(Row = 0; Row <= TotalRows ; Row++){
       for(Column = 0; Column <= TotalColumn; Column++){

        //////////print 4 corners of the frame

        if(Row==0 && Column==0){
            for(i=1 ;i <=4*(14-size_board) ;i++){
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
            for( i=1 ;i<=4*(14-size_board);i++){
                printf(" ");
            }
            printf("%c",192);
        }

        ////////////// print houses

        if(board[Row][Column] == 0 && Row!=TotalRows){
            printf(" ");

        }else if(board[Row][Column] == 1 && Row!=TotalRows && Column!=TotalColumn) {
            printf("%c",205);

        }else if(board[Row][Column] ==2 && Row!=TotalRows && Column!=TotalColumn) {
            printf("%c",215);

        }else if(board[Row][Column] ==3 && Row!=TotalRows && Column!=TotalColumn) {
            printf("%c",201);

        }else if(board[Row][Column] ==4 && Row!=TotalRows && Column!=TotalColumn) {
            printf("%c",187);

        }else if(board[Row][Column] ==5 && Row!=TotalRows && Column!=TotalColumn) {
            printf("%c",200);

        }else if(board[Row][Column] ==6 && Row!=TotalRows && Column!=TotalColumn) {
            printf("%c",188);
        }

        ////////// print main frame

        else if(board[Row][Column]==7 && Column!=TotalColumn && Row!=TotalRows ) {
            if(Column==0){
                for( i=1 ;i<=4*(14-size_board);i++){
                    printf(" ");
                }
            }
            printf("%c",179);

        }else if(board[Row][Column]==8 && Column!=TotalColumn && Row!=TotalRows ) {
            if(Row == 0){
                setTextColor(9, colorscreen);
                printf("%c",196);
                setTextColor(0, colorscreen);
            }else if(Row == TotalRows -1){
                setTextColor(13, colorscreen);
                printf("%c",196);
                setTextColor(0, colorscreen);
            }else printf("%c",196);
        }

        ///////////print line nums.

        if(Column==TotalColumn && board[Row][Column]!=0 ){
            if(board[Row][Column]>64){
                printf("%c",board[Row][Column]);
            }else{
                printf("%d",board[Row][Column]);
            }
        }
        /////////print Column nums.

        if(Row==TotalRows){
            if(sw==1){
                for( i=1 ;i<=4*(14-size_board);i++){
                    printf(" ");
                }
                sw=0;
            }
            if(board[Row][Column]!=0 && Column<TotalColumn){
                if(board[Row][Column]>64){
                    printf("%c",board[Row][Column]);
                }else{
                    printf("%d",board[Row][Column]);
                }
            }else{
                printf(" ");
            }
        }

        /////////////print sticks

        if(board[Row][Column] == 1000){
            setTextColor(13, colorscreen);
            printf("%c",178);}
        if( board[Row][Column] == 2000){
            setTextColor(9, colorscreen);
            printf("%c",178);}
        if(Sw_four_playergame==0){
            if( board[Row][Column] == 3000){
                setTextColor(4, colorscreen);
                printf("%c",178);}
            if( board[Row][Column] == 4000){
                setTextColor(5, colorscreen);
                printf("%c",178);}
        }


        ////////////print  beats

        setTextColor(0, colorscreen);

        if(board[Row][Column] == 200 && (swtogether12==0 || swtogether13==0||swtogether14==0 || swtogether123==0 || swtogether124==0 || swtogether1234==0 || swtogether134==0) ) printf("%d",Ttogether);
        else  if(board[Row][Column] == 200 ) printf("%c", beat1);

        if(board[Row][Column] == 300 && (swtogether12==0 || swtogether23==0 || swtogether24==0 || swtogether123==0 || swtogether124==0 || swtogether1234==0)) printf("%d",Ttogether);
        else if(board[Row][Column] == 300 ) printf("%c", beat2);

        if(board[Row][Column] == 500) printf("%c", beat_together);
        if(Sw_four_playergame==0){

            if(board[Row][Column] == 600 && (swtogether13==0 || swtogether34==0 || swtogether23==0 || swtogether123==0 || swtogether134==0 || swtogether1234==0 )) printf("%d",Ttogether);
            else if(board[Row][Column] == 600 ) printf("%c", beat3);
            if(board[Row][Column] == 700 && (swtogether14==0 || swtogether24==0||swtogether34==0 || swtogether124==0 || swtogether1234==0 || swtogether134==0 )) printf("%d",Ttogether);
            else if(board[Row][Column] == 700  ) printf("%c", beat4);

        }

        //player 1 color around house

        setTextColor(13,colorscreen);
        if(board[Row][Column] == 30) printf("%c", 201);
        if(board[Row][Column] == 40) printf("%c", 187);
        if(board[Row][Column] == 50) printf("%c", 200);
        if(board[Row][Column] == 60) printf("%c", 188);
        if(board[Row][Column] == 63) printf("%c", 205);
        if(board[Row][Column] == 62) printf("%c", 215);

        //player 2 color around house

        setTextColor(9,colorscreen);
        if(board[Row][Column] == 33) printf("%c", 201);
        if(board[Row][Column] == 44) printf("%c", 187);
        if(board[Row][Column] == 55) printf("%c", 200);
        if(board[Row][Column] == 59) printf("%c", 188);
        if(board[Row][Column] == 64) printf("%c", 205);
        if(board[Row][Column] == 61) printf("%c", 215);
        setTextColor(10,colorscreen);

        if(Sw_four_playergame==0){
            //player 3 color around house
            setTextColor(4,colorscreen);
            if(board[Row][Column] == 401) printf("%c", 201);
            if(board[Row][Column] == 402) printf("%c", 187);
            if(board[Row][Column] == 403) printf("%c", 200);
            if(board[Row][Column] == 404) printf("%c", 188);
            if(board[Row][Column] == 405) printf("%c", 215);
            if(board[Row][Column] == 406) printf("%c", 205);
            setTextColor(10,colorscreen);

            //player 4 color around house
            setTextColor(5,colorscreen);
            if(board[Row][Column] == 407) printf("%c", 201);
            if(board[Row][Column] == 408) printf("%c", 187);
            if(board[Row][Column] == 409) printf("%c", 200);
            if(board[Row][Column] == 410) printf("%c", 188);
            if(board[Row][Column] == 411) printf("%c", 215);
            if(board[Row][Column] == 412) printf("%c", 205);
            setTextColor(10,colorscreen);


        }
        //player 1&&2 color around house

        if(row1==row2 && column1==column2){
            setTextColor(6,colorscreen);
            if(board[Row][Column] == 301) printf("%c", 201);
            if(board[Row][Column] == 302) printf("%c", 187);
            if(board[Row][Column] == 303) printf("%c", 200);
            if(board[Row][Column] == 304) printf("%c", 188);
            if(board[Row][Column] == 305) printf("%c", 215);
            if(board[Row][Column] == 306) printf("%c", 205);
            setTextColor(10,colorscreen);
        }
        ////+
        if(board[Row][Column] == 400) printf("+");
            setTextColor(0,colorscreen);
            if(board[Row][Column] == 30 || board[Row][Column] == 33 || board[Row][Column] == 401 || board[Row][Column] == 407)  board[Row][Column] = 3;
            if(board[Row][Column] == 40 || board[Row][Column] == 44 || board[Row][Column] == 402 || board[Row][Column] == 408)  board[Row][Column] = 4;
            if(board[Row][Column] == 50 || board[Row][Column] == 55 || board[Row][Column] == 403 || board[Row][Column] == 409)  board[Row][Column] = 5;
            if(board[Row][Column] == 60 || board[Row][Column] == 59 || board[Row][Column] == 404 || board[Row][Column] == 410)  board[Row][Column] = 6;
            if(board[Row][Column] == 63 || board[Row][Column] == 64 || board[Row][Column] == 406 || board[Row][Column] == 412)  board[Row][Column] = 1;
            if(board[Row][Column] == 62 || board[Row][Column] == 61 || board[Row][Column] == 405 || board[Row][Column] == 411)  board[Row][Column] = 2;
            if(board[Row][Column] == 400)  board[Row][Column] = 0;
        }
        printf("\n");
    }
}
