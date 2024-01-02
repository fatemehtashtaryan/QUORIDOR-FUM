void puttingsticks(char rowlocation,char columnlocation,char TypeStick){
	int i,coordRow,coordcolumn;
	coordRow = ((int)rowlocation-64)*4,
	coordcolumn = ((int)columnlocation-64)*8-1;
	if(TypeStick == 'H'|| TypeStick == 'h'){
		i=coordcolumn-6;
		for(i;i<=coordcolumn+6;i++){
				board[coordRow][i]=100;
		}
	}
	else
	{
       i=coordRow-3;
       for(i;i<=coordRow+3;i++) board[i][coordcolumn]=100;
	}

}
