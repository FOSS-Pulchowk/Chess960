
#include "game.h"
#include <iostream>
class Board;
class Piece;
Game::Game(string name1, string name2, Board (*currentBoard)[8][8],OnePiece *ptr)
{
	whiteToPlay = true;
	isOver = false;
	whitePlayerName = name1;
	blackPlayerName = name2;
	this->currentBoard = currentBoard;
	this->ptrToNoPiece = ptr;
	
}
bool Game::getCurrentPlayer() { return whiteToPlay; }
bool Game::isGameOver()
{
	return isOver;
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
	Piece *thisPiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	bool canMove = thisPiece->movesInEmptyBoard(source, destination);
	bool playerMatchesPiece = (getCurrentPlayer() == thisPiece->getColor());
	//std::cout << canMove;
	
	if (canMove && playerMatchesPiece)
	{
		(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece = (*currentBoard)[sourceRow-1][sourceFile-1].currentPiece;
		(*currentBoard)[sourceRow-1][sourceFile-1].currentPiece = ptrToNoPiece;
		//string destinationPosition = (*currentBoard)[destinationRow-1][destinationFile-1].getMyLocation();
		//(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece->setCurrentPosition(destinationPosition);
		std::cout << "Move done Successfully";

		return 1;
	}	
	else
	{
		if (playerMatchesPiece == 0)
		{
			std::cout << "Wrong Piece";
		}
		else if (canMove == 0)
		{
			std::cout << "Cant Move";
		}
		return 0;
	}
}
void Game::checkState()
{
	//if (*currentBoard)[0][5].currentPiece != noPiece;
}
void Game::endGame()
{
	isOver = true;
}