
#include "chess.h"
#include <iostream>
#include <cmath>
Chess::Chess(string name1, string name2, Board (*currentBoard)[8][8],OnePiece *ptr)
{
	whiteToPlay = true;
	isOver = false;
	whitePlayerName = name1;
	blackPlayerName = name2;
	this->currentBoard = currentBoard;
	this->ptrToNoPiece = ptr;
	
}
bool Chess::getCurrentPlayer() { return whiteToPlay; }
bool Chess::isChessOver()
{
	return isOver;
}
void Chess::changeTurn()
{
	whiteToPlay = !whiteToPlay;
}
int Chess::moveToEmptySquare(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow= source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	Piece *sourcePiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	bool canMove = sourcePiece->movesInEmptyBoard(source, destination);
	int pathIsNotBlocked = isNotBlocked(choosenMove);
	if (!canMove)
	{
		
		std::cout << "I cant move " << sourcePiece->myName() << "in here" << "from " << source << "to " << destination << "\n";
	}
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	string sourcePieceName = sourcePiece->myName();
	//std::cout << canMove;
	
	if (canMove && playerMatchesPiece && pathIsNotBlocked)
	{
		(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece = (*currentBoard)[sourceRow-1][sourceFile-1].currentPiece;
		(*currentBoard)[sourceRow-1][sourceFile-1].currentPiece = ptrToNoPiece;
		//string destinationPosition = (*currentBoard)[destinationRow-1][destinationFile-1].getMyLocation();
		//(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece->setCurrentPosition(destinationPosition);
		std::cout << "Move done Successfully\n";
		std::cout << sourcePieceName << " moved from " << source << " to " << destination << "\n";
		return 1;
	}	
	else
	{
		if (playerMatchesPiece == 0)
		{
			std::cout << "You cant move piece of opponent. \n";
		}
		else if (canMove == 0)
		{
			std::cout << "Not a Valid Move\n";
		}
		else if (!pathIsNotBlocked)
		{
			std::cout << "There is something in the path";
		}
		return 0;
	}
}
int Chess::capture(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow = source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	Piece *sourcePiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece;
	bool canMove = sourcePiece->movesInEmptyBoard(source, destination);
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	bool isOpponentPiece = (getCurrentPlayer() != destinationPiece->getColor());
	//std::cout << canMove;

	if (canMove && playerMatchesPiece && isOpponentPiece && isNotBlocked(choosenMove))
	{

		destinationPiece->kill();
		//(*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece = ptrToNoPiece;
		(*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
		(*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece = ptrToNoPiece;
		//string destinationPosition = (*currentBoard)[destinationRow-1][destinationFile-1].getMyLocation();
		//(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece->setCurrentPosition(destinationPosition);
		std::cout << "Move done Successfully\n";
		std::cout << "you captured " << destinationPiece->myName() << " in " << destination << "with " << sourcePiece->myName() << " in " << source << "\n";
		return 1;
	}
	else
	{
		if (playerMatchesPiece == 0)
		{
			std::cout << "You cant move piece of opponent. \n";
		}
		else if (canMove == 0)
		{
			std::cout << "Not a Valid Move\n";
		}
		return 0;
	}
}
int Chess::execute(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow = source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	Piece *sourcePiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece;
	if (destinationPiece->myName() == "OnePiece")
	{
		std::cout << "Sending move to empty square\n";
		if (moveToEmptySquare(choosenMove))
			return 1;
		else
			return 0;
	}
	else if (destinationPiece->myName()!="OnePiece" && destinationPiece->getColor()!=getCurrentPlayer())
	{
		std::cout << "Sending mvoe to capture\n";
		if (capture(choosenMove))
			return 1;
		else
			return 0;
	}
	else
	{
		std::cout << "It is neither capture nor move";
	}
	bool canMove = sourcePiece->movesInEmptyBoard(source, destination);
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	bool isOpponentPiece = (getCurrentPlayer() != destinationPiece->getColor());


}
void Chess::checkState()
{
	//if (*currentBoard)[0][5].currentPiece != noPiece;
}
void Chess::endChess()
{
	isOver = true;
}
int Chess::isNotBlocked(string choosenMove)
{
	string sourceString = choosenMove.substr(0, 2);
	string destinationString = choosenMove.substr(2, 2);
	Position source(sourceString);
	Position destination(destinationString);
	bool inStraightLine = (source.x == destination.x) || (source.y == destination.y);
	int verticalDifference = abs(source.x - destination.x);
	int horizontalDifference = abs(source.y - destination.y);
	bool inDiagonalLine = (verticalDifference == horizontalDifference);
	bool blocked = false;
	if (inStraightLine)
	{
		std::cout << "Source and destination " << source.x << "," << source.y << "\n";
		int currX;
		int currY;
		if (source.x == destination.x && source.y == destination.y)
		{
			blocked = false;
		}
		else if (source.x == destination.x)
		{
			std::cout << "Here the rows of source and destiantion are same.";
			if (abs(source.y - destination.y) == 1)
			{
				std::cout << "The move takes place in adjacent square so block is false.";
				blocked = false;
			}
			else
			{
				
				if (source.y < destination.y)
				{
					currX = source.x;
					currY = source.y+1;
		
					while (currY < destination.y)
					{
						if ((*currentBoard)[currX-1][currY-1].currentPiece != ptrToNoPiece)
						{
							std::cout << ((*currentBoard)[currX-1][currY-1].currentPiece->myName());
							std::cout << " blocks the path first \n";
							blocked = true;
							break;
						}
						currY++;
					}
				}
				else if (source.y > destination.y)
				{
					currX = source.x;
					currY = source.y - 1;
					std::cout << "Here currX and y" << currX << " " << currY;
					while (currY > destination.y)
					{
						if ((*currentBoard)[currX-1][currY-1].currentPiece != ptrToNoPiece)
						{
							std::cout << ((*currentBoard)[currX-1][currY-1].currentPiece->myName());
							std::cout << " blocks the 2nd  path\n";
							blocked = true;
							break;
						}
						currY--;
					}
				}
				else if (source.y==destination.y)
				{
					std::cout << "This place shouldnt be reached. ";
				}
			}

			
		}
		else if (source.y == destination.y)
		{
			std::cout << "Here the column are equal";
			if (abs(source.x - destination.x) == 1)
			{
				std::cout << "The move takes place in adjacent square so block is false.";
				blocked = false;
			}
			else
			{
				
				if (source.x < destination.x)
				{
					currX = source.x  +1;
					currY = source.y;
					currX += 1;
					while (currX < destination.x)
					{
						if ((*currentBoard)[currX-1][currY-1].currentPiece != ptrToNoPiece)
						{
							std::cout << ((*currentBoard)[currX-1][currY-1].currentPiece->myName());
							std::cout << " blocks the path column \n";
							blocked = true;
							break;
						}
						currX++;
					}
				}
				else if (source.x > destination.x)
				{
					currX = source.x-1;
					currY = source.y;
					while (currX > destination.x)
					{
						if ((*currentBoard)[currX-1][currY-1].currentPiece != ptrToNoPiece)
						{
							std::cout << ((*currentBoard)[currX-1][currY-1].currentPiece->myName());
							std::cout << currX << " " << currY << " ";
							std::cout << " blocks the path pathe\n";
							blocked = true;
							
						}
						currX--;
					}
				}
				else if (source.x == destination.x)
				{
					std::cout << "This place shouldnt be reached. ";
				}
			}

		}
	}
	else if (inDiagonalLine)
	{
		std::cout << "Source and destination " << source.x << "," << source.y << "\n";
		int currX;
		int currY;
		if (source.x == destination.x && source.y == destination.y)
		{
			blocked = false;
		}
		else if (abs(source.x-destination.x)==1)
		{
			blocked = false;
		}
		else
		{
			int movX;
			int movY;
			movX = (source.x < destination.x) ? 1 : -1;
			movY = (source.y < destination.y) ? 1 : -1;
			currX = source.x+ movX;
			currY = source.y + movY;
			std::cout << "movX:" << movX << " movY:" << movY << " currX:" << currX << " currY" << currY << "\n";
			while (abs(currX - destination.x) > 0)
			{
				if (((*currentBoard)[currX - 1][currY - 1].currentPiece != ptrToNoPiece))
				{
					std::cout << (*currentBoard)[currX - 1][currY - 1].currentPiece->myName() << " blocks the path\n";
					std::cout << "I am inside if";
					blocked = true;
					break;
				}
				currX = currX+ movX;
				currY = currY + movY;
				std::cout << "I am inside while after incrementing. " << "currX:" << currX << " currY:" << currY << " \n";
				SDL_Delay(1000);
			}
		}
	}
	else
	{
	blocked = false;
	}
	return !blocked;
}