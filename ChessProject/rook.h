#include "piece.h"

class Rook :public Piece
{
public:
	Rook(string currentPosition, string color);
	int MovesInEmptyBoard(string initialPosition, string finalPosition);
};
