#pragma once
#include <string>
#include "board.h"
#include "piece.h"
using std::string;
/*Contains basic game related information and pointer to the board */
class Board;
class Piece;

class Game
{
	string whitePlayerName;
	string blackPlayerName;
	bool whiteToPlay;
	bool isOver;
	
public:
	Board(*currentBoard)[8][8];
	Game(string name1, string name2, Board (*currentBoard)[8][8]);
	int moveToEmptySquare(string choosenMove);
	void changeTurn();
};