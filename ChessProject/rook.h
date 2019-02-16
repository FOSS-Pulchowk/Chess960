#include "piece.h"

class Rook :public Piece
{
public:
	Rook(string currentPosition, string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
};
