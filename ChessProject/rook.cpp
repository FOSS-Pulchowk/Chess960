#include "rook.h"


Rook::Rook(string currentPosition, string color)
{
	this->name = "Rook";
	//this->currentPosition = currentPosition;
	if (color == "white") { isWhite = true; }
	else { isWhite = false; }
}

int Rook::MovesInEmptyBoard(string initialPosition, string finalPosition)
{
	vector<int> initialPositionInNumber = getPositionInVector(initialPosition);
	vector<int> finalPositionInNumber = getPositionInVector(finalPosition);
	int checkColumn = finalPositionInNumber[0] - initialPositionInNumber[0];
	int checkRow= finalPositionInNumber[1] - initialPositionInNumber[1];
	if (checkColumn == 0 && checkRow !=0) { return 1;}
	else if (checkRow == 0 && checkColumn !=0) { return 1;}
	else { return 0;}
}

