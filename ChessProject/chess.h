#pragma once
#include <string>
#include "board.h"
#include "piece.h"
using std::string;
/*Contains basic Chess related information and pointer to the board */
class Board;
class Piece;

class Chess
{
	string whitePlayerName;
	string blackPlayerName;
	bool whiteToPlay;
	bool isOver;
	OnePiece *ptrToNoPiece;
	
public:
	Board(*currentBoard)[8][8];
	Chess(string name1, string name2, Board (*currentBoard)[8][8],OnePiece *ptr);
	int moveToEmptySquare(string choosenMove);
	int isNotBlocked(string choosenMove);
	void changeTurn();
	bool isChessOver();
	bool getCurrentPlayer();
	void checkState();
	void endChess();
	int capture(string choosenMove);
	int execute(string move);
};

struct Position
{
	int x;
	int y;
	Position(string location)
	{
		y= location[0] - 'a' + 1;
		x = location[1] - '0';
	}
};