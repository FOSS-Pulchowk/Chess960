#pragma once
#include <string>
using std::string;
class Board;
class Game
{
	string whitePlayerName;
	string blackPlayerName;
	bool whiteToPlay;
	bool isOver;
	Board (*currentBoard)[8][8];
public:
	Game(string name1, string name2, Board (*currentBoard)[8][8]);
	int moveToEmptySquare(string choosenMove);
	void changeTurn();
};