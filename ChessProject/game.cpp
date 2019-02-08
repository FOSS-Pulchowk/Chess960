
#include "game.h"
Game::Game(string name1, string name2, Board (*currentBoard)[8][8])
{
	whiteToPlay = true;
	isOver = false;
	whitePlayerName = name1;
	blackPlayerName = name2;
	this->currentBoard = currentBoard;
}
void Game::changeTurn()
{
	whiteToPlay = !whiteToPlay;
}
int Game::moveToEmptySquare(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow= source[1] - '1' + 1;
	return 0;
	//(*currentBoard)[sourceRow-1][sourceFile-1].
}