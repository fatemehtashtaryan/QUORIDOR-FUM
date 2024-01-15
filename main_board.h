#ifndef main_board
#define main_board
#include "subcodes.h"
//this file about building and numbering boardgame
int lineColumnsnumbering(int TotalRows, int TotalColumn){
	///////////////////////////////////////////////line numbering.
	int counter_row, counter_column;
	for(counter_row=0; counter_row<14; counter_row++){
        for(counter_column=0; counter_column<14; counter_column++){
            stick_movement_h_full[counter_row][counter_column]=3;
            stick_movement_v_full[counter_row][counter_column]=3;
        }
	}
   	int  Row, Column ,name_lines = 65;
    for(Row = 0; Row <= TotalRows; Row++){
		if((Row+2)%4  == 0){
				board[Row][TotalColumn] = (Row+2)/4;
		}
		//Naming between lines.
		else if(Row != 0 && Row%4 == 0 && Row<TotalRows-1){
			board[Row][TotalColumn]= name_lines;
			 name_lines ++;
		}else{
				board[Row][TotalColumn] = 0; //put space.
		}
	}
	/////////////////////////////////////////////Columns numbering.
	name_lines = 65;
	for(Column = 0; Column <= TotalColumn-4; Column++){
			// numbering of Columns (1-9).
			if((Column+5)%8 == 0 && Column <= 69){
				board[TotalRows][Column] = (Column+5)/8;
			// numbering of Columns more than 9.
			}else if(Column > 69 && (Column-5)%7 == 0 && Column < TotalColumn-3 ){
						board[TotalRows][Column]=(Column-5)/7;
				}
			//Naming between Columns (1-14).
			else if ((Column+1 )%8 ==0 && Column<=83){
					board[TotalRows][Column]=name_lines;
					name_lines++;
			}
			else if(Column > 83 && ( Column+3 )%8==0 && Column < 97){
                board[TotalRows][Column] = name_lines;
					name_lines ++;
			}
			else if(Column >= 97 && (Column+3 )%8 == 0){
                board[TotalRows][Column] = name_lines;
					name_lines ++;
			}
			else {
					//put space.
					board[TotalRows][Column]=0;
			}
	}
}
int boardgame(int TotalRows,int TotalColumn){
	int  Row, Column;
	int  existence = 0; //existence checks if we have reached the end of the row.
	int Player_House = 3, SpaceBetween_Row=4, SpaceBetween_Column_oddRow=6, SpaceBetween_Column_evenRow=6, sw=1;
	///////////////////////////////////////////////////////////////////////////////////// //Building board
	for(Row = 1; Row < TotalRows-1 ; Row++){
        for(Column = 1; Column < TotalColumn -1 ; Column++){
            if(Row % 2 == 1){
               //Checking the space between houses in Column for odd row .
               if(Column == SpaceBetween_Column_oddRow){
                  SpaceBetween_Column_oddRow += 8; //THe space between the Column is 5.
                  existence++;
                  if(existence < size_board  ){ // if existence < size_board we need space after house
                     board[Row][Column] = 0; //if the coordinate is related to the space between the Column, put 2 space.
                     board[Row][Column+1] = 0;
                     board[Row][Column+2] = 0;
               	    Column+=2;
                     sw = 0;
                  }
               }
               if((Row+1)%4==0){
	               if(Column == SpaceBetween_Column_oddRow-5 ){
	               		board[Row][Column] = 5;  // Building the down left corner of the houses
	               		sw=0;
				   }
				   if(Column == SpaceBetween_Column_oddRow-1 ){
	               		board[Row][Column] = 6;  // Building the down right corner of the houses
	               		sw=0;
				   }
			     }else{
			     	 if(Column == SpaceBetween_Column_oddRow-5 ){
	               		board[Row][Column] = 3;  // Building the upper left corner of the houses
	               		sw=0;
				   }
				   if(Column == SpaceBetween_Column_oddRow-1 ){
	               		board[Row][Column] = 4;  // Building the upper right corner of the houses
	               		sw=0;
				   }
				 }
               if(sw == 1 ) board[Row][Column] = 1; //Building walls of houses
               sw = 1;
            }
            else{
            	//Checking the space between houses in rows .
                if(Row == SpaceBetween_Row ){
                   board[Row][Column] = 0;  //if the coordinate is related to the space between the rows, put space.
                   if(Column == TotalColumn-2) SpaceBetween_Row += 4; //THe space between the rows is 4.
                 }
                else{
                	//checking player's house.
                	if(Column == Player_House-1){
                		  board[Row][Column] = 0;
                		  sw=0;
					}
                    if(Column == Player_House ){
                       Player_House += 8; //The distance between player houses is 5 .

                       board[Row][Column] = 0; //if the coordinate is related to the player's house , put space.
                       sw = 0;
                    }
                    if(Column == Player_House-7){
                		  board[Row][Column] = 0;
                		  sw=0;
					}
                    //Checking the space between houses in Column for even row .
                    if(Column == SpaceBetween_Column_evenRow ){
	                       board[Row][Column] = 0; //if the coordinate is related to the space between the Column for even row, put 2 space.
	                       board[Row][Column+1] = 0;
	                       board[Row][Column+2] = 0;
                       Column+=2;
                       SpaceBetween_Column_evenRow += 8; //THe space between the Column is 5.
                    }
                    else{
                    	//Building walls of houses.
                        if(sw == 1 ){
                        	board[Row][Column] = 2;
						}
                        sw = 1;
                    }
                }
           }
        }
        Player_House = 3;
        SpaceBetween_Column_oddRow = 6;
        existence = 0;
        SpaceBetween_Column_evenRow = 6;
    }
   	/////////////////////////////////////////////////////////////// making a frame around the board
	for(Column = 0; Column <= TotalColumn -3 ; Column++){
		board[0][Column] = 8;  // for row=0 && row=last
		board[TotalRows-1][Column] = 8;
	}
	for(Row = 1; Row <= TotalRows-2 ; Row++){
		board[Row][0] = 7; //for Column=1 && Column=last
		board[Row][TotalColumn-1] = 7;
	}
	///////////////////////////////////////////////////////////////////
     lineColumnsnumbering(TotalRows, TotalColumn);
}
#endif // main_board
