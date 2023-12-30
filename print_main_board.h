#include "main_board.h"
#include "subcodes.h"


void printboardgame(TotalRows, TotalColumn){
     board[row1-1][column1-2]=30;
     board[row1-1][column1+2]=40;
     board[row1+1][column1-2]=50;
     board[row1+1][column1+2]=60;
     board[row1][column1-2]=80;
     board[row1][column1+2]=80;
     board[row1+1][column1]=70;
     board[row1-1][column1]=70;
     board[row1-1][column1-1]=70;
     board[row1-1][column1+1]=70;
     board[row1+1][column1-1]=70;
     board[row1+1][column1+1]=70;
     board[row2-1][column2-2]=33;
     board[row2-1][column2+2]=44;
     board[row2+1][column2-2]=55;
     board[row2+1][column2+2]=66;
     board[row2][column2-2]=88;
     board[row2][column2+2]=88;
     board[row2+1][column2]=77;
     board[row2-1][column2]=77;
     board[row2-1][column2+1]=77;
     board[row2-1][column2-1]=77;
     board[row2+1][column2-1]=77;
     board[row2+1][column2+1]=77;
     if(board[row1-2][column1] != 100 && board[row1-2][column1] != 8 && board[row1-4][column1] != 300 && turn == 1) board[row1-4][column1] =400;
     if(board[row1+2][column1] != 100 && board[row1+2][column1] != 8 && board[row1+4][column1] != 300 && turn == 1) board[row1+4][column1] =400;
     if(board[row1][column1+4] != 100 && board[row1][column1+3] != 7 && board[row1][column1+8] != 300 && turn == 1) board[row1][column1+8] =400;
     if(board[row1][column1-4] != 100 && board[row1][column1-3] != 7 && board[row1][column1-8] != 300 && turn == 1) board[row1][column1-8] =400;
     if(board[row2][column2-4] != 100 && board[row2][column2-3] != 7 && board[row2][column2-8] != 200 && turn == 2) board[row2][column2-8] =400;
     if(board[row2][column2+4] != 100 && board[row2][column2+3] != 7 && board[row2][column2+8] != 200 && turn == 2) board[row2][column2+8] =400;
     if(board[row2+2][column2] != 100 && board[row2+2][column2] != 8 && board[row2+4][column2] != 200 && turn == 2) board[row2+4][column2] =400;
     if(board[row2-2][column2] != 100 && board[row2-2][column2] != 8 && board[row2-4][column2] != 200 && turn == 2) board[row2-4][column2] =400;
	 int  Row, Column ,name_lines=65,situation ,sw=1 ,i;
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
						}else{

								printf("%d",board[Row][Column]);
								}
					}else{
						printf(" ");
					}
				}
	      /////////////
	        if(turn==1) setTextColor(9
                                  , colorscreen);
	        else setTextColor(13, colorscreen);
	        if( board[Row][Column] == 100) printf("%c",178);
	        setTextColor(0, colorscreen);
		 	if(board[Row][Column] == 200) printf("%c", beat1);
            if(board[Row][Column] == 300) printf("%c", beat2);
            setTextColor(13,colorscreen);
            if(board[Row][Column] == 30) printf("%c", 201);
            if(board[Row][Column] == 40) printf("%c", 187);
            if(board[Row][Column] == 50) printf("%c", 200);
            if(board[Row][Column] == 60) printf("%c", 188);
            if(board[Row][Column] == 70) printf("%c", 205);
            if(board[Row][Column] == 80) printf("%c", 215);
            setTextColor(9,colorscreen);
            if(board[Row][Column] == 33) printf("%c", 201);
            if(board[Row][Column] == 44) printf("%c", 187);
            if(board[Row][Column] == 55) printf("%c", 200);
            if(board[Row][Column] == 66) printf("%c", 188);
            if(board[Row][Column] == 77) printf("%c", 205);
            if(board[Row][Column] == 88) printf("%c", 215);
            setTextColor(10,colorscreen);
            if(board[Row][Column] == 400) printf("+");
            setTextColor(0,colorscreen);
            if(board[Row][Column] == 30 || board[Row][Column] == 33)  board[Row][Column] = 3;
            if(board[Row][Column] == 40 || board[Row][Column] == 44)  board[Row][Column] = 4;
            if(board[Row][Column] == 50 || board[Row][Column] == 55)  board[Row][Column] = 5;
            if(board[Row][Column] == 60 || board[Row][Column] == 66)  board[Row][Column] = 6;
            if(board[Row][Column] == 70 || board[Row][Column] == 77)  board[Row][Column] = 1;
            if(board[Row][Column] == 80 || board[Row][Column] == 88)  board[Row][Column] = 2;
            if(board[Row][Column] == 400)  board[Row][Column] = 0;
	    }
	    printf("\n");
	}
	////////////////////print the letters j and later to name the Columns.
	name_lines = 73;
	situation = 72+4*(14-size_board);
	for(Row = size_board ; size_board >= 10 ; size_board--){
		gotoxy(TotalRows+1+5,situation);
		printf("%c",name_lines);
		situation += 8;
		name_lines++;
	}
	////////////////////////////
}

