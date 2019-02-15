#include "board.h"

void Board::setMyLocation(string location)
{
	this->myLocation = location;
}
bool Board::setPiece(Piece *pieceptr)
{
	if (!this->currentPiece)
	{
		this->currentPiece = pieceptr;
		return 1;
	}
	else
	{
		return 0;
	}
}
string Board::getMyLocation()
{
	return this->myLocation;
}
void setBoard(Board currentBoard[8][8],OnePiece* onePiece)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			string tempLocation;
			tempLocation.push_back('a' + j);
			tempLocation.push_back('1' + i);
			currentBoard[i][j].currentPiece = onePiece;
			currentBoard[i][j].setMyLocation(tempLocation);
		}
	}
}

