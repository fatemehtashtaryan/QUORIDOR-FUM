#include "main_board.h"
#include "subcodes.h"
//this file is about print main board and colores around houses

void printboardgame(TotalRows, TotalColumn){

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
     //+
     if(board[row1-2][column1] != 1000 && board[row1-2][column1] != 2000 && board[row1-2][column1] != 8 && board[row1-4][column1] != 300 && turn == 1) board[row1-4][column1] =400;
     if(board[row1+2][column1] != 1000 && board[row1+2][column1] != 2000 && board[row1+2][column1] != 8 && board[row1+4][column1] != 300 && turn == 1) board[row1+4][column1] =400;
     if(board[row1][column1+4] != 1000 && board[row1][column1+4] != 2000 && board[row1][column1+3] != 7 && board[row1][column1+8] != 300 && turn == 1) board[row1][column1+8] =400;
     if(board[row1][column1-4] != 1000 && board[row1][column1-4] != 2000 && board[row1][column1-3] != 7 && board[row1][column1-8] != 300 && turn == 1) board[row1][column1-8] =400;
     if(board[row2][column2-4] != 1000 && board[row2][column2-4] != 2000 && board[row2][column2-3] != 7 && board[row2][column2-8] != 200 && turn == 2) board[row2][column2-8] =400;
     if(board[row2][column2+4] != 1000 && board[row2][column2+4] != 2000 && board[row2][column2+3] != 7 && board[row2][column2+8] != 200 && turn == 2) board[row2][column2+8] =400;
     if(board[row2+2][column2] != 1000 && board[row2+2][column2] != 2000 && board[row2+2][column2] != 8 && board[row2+4][column2] != 200 && turn == 2) board[row2+4][column2] =400;
     if(board[row2-2][column2] != 1000 && board[row2-2][column2] != 2000 && board[row2-2][column2] != 8 && board[row2-4][column2] != 200 && turn == 2) board[row2-4][column2] =400;

	 int  Row, Column, sw=1 ,i;
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
			}
	        else if(board[Row][Column] == 1 && Row!=TotalRows && Column!=TotalColumn) {
                printf("%c",205);
			}
			else if(board[Row][Column] ==2 && Row!=TotalRows && Column!=TotalColumn) {
	        	printf("%c",215);
			}
			else if(board[Row][Column] ==3 && Row!=TotalRows && Column!=TotalColumn) {
	        	printf("%c",201);
			}
			else if(board[Row][Column] ==4 && Row!=TotalRows && Column!=TotalColumn) {
	        	printf("%c",187);
			}
			else if(board[Row][Column] ==5 && Row!=TotalRows && Column!=TotalColumn) {
	        	printf("%c",200);
			}
			else if(board[Row][Column] ==6 && Row!=TotalRows && Column!=TotalColumn) {
	        	printf("%c",188);
			}
			////////// print main frame
			else if(board[Row][Column]==7 && Column!=TotalColumn && Row!=TotalRows )	{
						if(Column==0){
							for( i=1 ;i<=4*(14-size_board);i++){
								printf(" ");
							}

						}
						printf("%c",179);
			}
		    else if(board[Row][Column]==8 && Column!=TotalColumn && Row!=TotalRows )	{
						if(Row == 0){
                            setTextColor(9, colorscreen);
                            printf("%c",196);
                            setTextColor(0, colorscreen);
						}
						else if(Row == TotalRows -1){
                            setTextColor(13, colorscreen);
                            printf("%c",196);
                            setTextColor(0, colorscreen);
						}
						else printf("%c",196);
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
						}
						else
						{
								printf("%d",board[Row][Column]);
								}
					}
					else{
						printf(" ");
					}
				}
	      /////////////print sticks
	        if(board[Row][Column] == 1000)
            {
                setTextColor(13, colorscreen);
                printf("%c",178);}
            if( board[Row][Column] == 2000)
            {
                setTextColor(9, colorscreen);
                printf("%c",178);
            }
            ////////////
	        setTextColor(0, colorscreen);
		 	if(board[Row][Column] == 200) printf("%c", beat1);
            if(board[Row][Column] == 300) printf("%c", beat2);
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
            //+
            if(board[Row][Column] == 400) printf("+");
            setTextColor(0,colorscreen);
            if(board[Row][Column] == 30 || board[Row][Column] == 33)  board[Row][Column] = 3;
            if(board[Row][Column] == 40 || board[Row][Column] == 44)  board[Row][Column] = 4;
            if(board[Row][Column] == 50 || board[Row][Column] == 55)  board[Row][Column] = 5;
            if(board[Row][Column] == 60 || board[Row][Column] == 59)  board[Row][Column] = 6;
            if(board[Row][Column] == 63 || board[Row][Column] == 64)  board[Row][Column] = 1;
            if(board[Row][Column] == 62 || board[Row][Column] == 61)  board[Row][Column] = 2;
            if(board[Row][Column] == 400)  board[Row][Column] = 0;
	    }
	    printf("\n");
	}
}

