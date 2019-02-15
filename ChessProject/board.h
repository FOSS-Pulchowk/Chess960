#pragma once
#include <string>
#include <vector>
#include "piece.h"
using std::string;
using std::vector;
/*Board is made up of 8*8 individual squares. All the squares contain information about their location. Each square contain a pointer to base class of Piece. */
class Board
{
	string myLocation;//It contains the algebraic notation address of the current square. For ex. "e1"
public:
	Piece *currentPiece;//This is a pointer to base class which points to a derived object like king, rook,etc
	void setMyLocation(string location);
	string getMyLocation();
	bool setPiece(Piece *pieceptr);//This sets the value of currentPiece Pointer to a pointer to derived object
	friend void setBoard(Board currentBoard[8][8],OnePiece *onePiece);
};
names
void setBoard(Board currentBoard[8][8],OnePiece *onePiece);
