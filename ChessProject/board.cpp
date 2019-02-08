#include "board.h"

void Board::setBoard(string location)
{
	this->location = location;
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
void Boards::setBoard(Board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			string tempLocation;
			tempLocation.push_back('a' + i);
			tempLocation.push_back('1' + j);

		}
	}
}

