
#include "game.h"
#include <iostream>
class Board;
class Piece;
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
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	std::cout << "source: " << source << ": " << destination;
	//(*currentBoard)[1][4].currentPiece->movesInEmptyBoard("e2", "e4");
	//(*pointer)[][4].currentPiece->movesInEmptyBoard("e2", "e4");
	/*bool canMove = (*currentBoard)[sourceRow][sourceFile].currentPiece->movesInEmptyBoard(source, destination);
	if (canMove)
	{
		(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece = (*currentBoard)[sourceRow-1][sourceFile-1].currentPiece;
		(*currentBoard)[sourceRow-1][sourceFile-1].currentPiece = NULL;
		string destinationPosition = (*currentBoard)[destinationRow-1][destinationFile-1].getMyLocation();
		(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece->setCurrentPosition(destinationPosition);
		return 1;
	}	
	else
	{
		return 0;
	}*/
	return 1;
}
