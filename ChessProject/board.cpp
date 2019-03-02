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

//void setBoard(Board currentBoard[8][8],OnePiece* onePiece)
//{
//	std::cout << "Address of ONe Piece inside setBoard:" << onePiece << "|\n";
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			string tempLocation;
//			tempLocation.push_back('a' + j);
//			tempLocation.push_back('1' + i);
//			currentBoard[i][j].currentPiece = onePiece;
//			currentBoard[i][j].setMyLocation(tempLocation);
//		}
//	}
//}

//void copyBoard(Board sourceBoard[8][8], Board destinationBoard[8][8])
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			//destinationBoard[i][j].setMyLocation(sourceBoard[8][8].getMyLocation());
//			if (sourceBoard[i][j].currentPiece->myName()=="OnePiece")
//				destinationBoard[i][j].currentPiece=ptrToNoPiece
//			destinationBoard[i][j].myLocation = sourceBoard[i][j].myLocation;
//			destinationBoard[i][j].currentPiece = sourceBoard[i][j].currentPiece;
//			
//
//		}
//	}
//}

