
#include "chess.h"
#include <iostream>
#include <cmath>
#include <ctime>

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
	bool canMove = 0;
	if (sourcePiece->movesInEmptyBoard(source, destination) == 1) { canMove = 1; }
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
		//std::cout << "Move done Successfully\n";
		//std::cout << sourcePieceName << " moved from " << source << " to " << destination << "\n";
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
	bool canMove;
	if (sourcePiece->myName() == "Pawn")
	{
		std::cout << "I am here pawn capture";
		std::cout << "The function returns " << (sourcePiece->movesInEmptyBoard(source, destination) == 2);
		canMove = (sourcePiece->movesInEmptyBoard(source, destination) == 2);
	}
	else
	{
		canMove = (sourcePiece->movesInEmptyBoard(source, destination));
	}
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
		return 0;
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
				//SDL_Delay(1000);
			}
		}
	}
	else
	{
	blocked = false;
	}
	return !blocked;
}

bool rookRepeatDecider(string temp, int tempNum)
{
	bool repeat;
	if (tempNum == 0)
	{
		if (temp[1] == 'R')
		{
			repeat = true;
		}
		else { repeat = false; }
	}
	else if (tempNum == 7)
	{
		if (temp[6] == 'R')
		{
			repeat = true;
		}
		else { repeat = false; }
	}
	else
	{
		if (temp[tempNum - 1] == 'R' || temp[tempNum + 1] == 'R')
		{
			repeat = true;
		}
		else { repeat = false; }
	}
	return repeat;
}
string Chess::getPiecesConfig()
{
	string temp = "00000000";
	int tempNum, posTemp[2];
	bool rookPosGenRepeat = false;
	srand(time(NULL));
	tempNum = rand() % 8;
	temp[tempNum] = 'R';
	posTemp[0] = tempNum;
	tempNum = rand() % 8;
	rookPosGenRepeat = rookRepeatDecider(temp, tempNum);
	while (temp[tempNum] != '0' || rookPosGenRepeat)
	{
		tempNum = rand() % 8;
		rookPosGenRepeat = rookRepeatDecider(temp, tempNum);
	}
	temp[tempNum] = 'R';
	posTemp[1] = tempNum;
	tempNum = rand() % (abs(posTemp[1] - posTemp[0]) - 1);
	if (posTemp[1] > posTemp[0]) { temp[posTemp[0] + tempNum + 1] = 'K'; }
	else { temp[posTemp[1] + tempNum + 1] = 'K'; }
	tempNum = rand() % 4;
	while (temp[2 * tempNum] != '0')
	{
		tempNum = rand() % 4;
	}
	temp[2 * tempNum] = 'B';
	tempNum = rand() % 4;
	while (temp[2 * tempNum + 1] != '0')
	{
		tempNum = rand() % 4;
	}
	temp[2 * tempNum + 1] = 'B';
	tempNum = rand() % 8;
	for (int i = 0; i < 2; i++)
	{
		while (temp[tempNum] != '0')
		{
			tempNum = rand() % 8;
		}
		temp[tempNum] = 'N';
		tempNum = rand() % 8;
	}
	for (int i = 0; i < 8; i++)
	{
		if (temp[i] == '0')
		{
			temp[i] = 'Q';
			break;
		}
	}
	return temp;
}

int Game::initializeBoard(Board(*myBoard)[8][8], OnePiece *noPiece)
{
	King *ptrToWhiteKing = new King("white");
	King *ptrToBlackKing = new King("black");
	Queen *ptrToWhiteQueen = new Queen("white");
	Queen *ptrToBlackQueen = new Queen("black");
	Bishop *ptrToWhiteBishop1 = new Bishop("white");
	Bishop *ptrToWhiteBishop2 = new Bishop("white");
	Bishop *ptrToBlackBishop1 = new Bishop("black");
	Bishop *ptrToBlackBishop2 = new Bishop("black");
	Knight *ptrToWhiteKnight1 = new Knight("white");
	Knight *ptrToWhiteKnight2 = new Knight("white");
	Knight *ptrToBlackKnight1 = new Knight("black");
	Knight *ptrToBlackKnight2 = new Knight("black");
	Rook *ptrToWhiteRook1 = new Rook("white");
	Rook *ptrToWhiteRook2 = new Rook("white");
	Rook *ptrToBlackRook1 = new Rook("black");
	Rook *ptrToBlackRook2 = new Rook("black");

	//OnePiece *ptrToOnePiece = new OnePiece("white");

	Pawn *ptrToWhitePawn1 = new Pawn("white");
	Pawn *ptrToWhitePawn2 = new Pawn("white");
	Pawn *ptrToWhitePawn3 = new Pawn("white");
	Pawn *ptrToWhitePawn4 = new Pawn("white");
	Pawn *ptrToWhitePawn5 = new Pawn("white");
	Pawn *ptrToWhitePawn6 = new Pawn("white");
	Pawn *ptrToWhitePawn7 = new Pawn("white");
	Pawn *ptrToWhitePawn8 = new Pawn("white");


	Pawn *ptrToBlackPawn1 = new Pawn("black");
	Pawn *ptrToBlackPawn2 = new Pawn("black");
	Pawn *ptrToBlackPawn3 = new Pawn("black");
	Pawn *ptrToBlackPawn4 = new Pawn("black");
	Pawn *ptrToBlackPawn5 = new Pawn("black");
	Pawn *ptrToBlackPawn6 = new Pawn("black");
	Pawn *ptrToBlackPawn7 = new Pawn("black");
	Pawn *ptrToBlackPawn8 = new Pawn("black");

	setBoard(*myBoard, noPiece);

	(*myBoard)[0][4].currentPiece = ptrToWhiteKing;
	(*myBoard)[7][4].currentPiece = ptrToBlackKing;
	(*myBoard)[0][3].currentPiece = ptrToWhiteQueen;
	(*myBoard)[3][7].currentPiece = ptrToBlackQueen;
	(*myBoard)[0][2].currentPiece = ptrToWhiteBishop1;
	(*myBoard)[0][5].currentPiece = ptrToWhiteBishop2;
	(*myBoard)[7][2].currentPiece = ptrToBlackBishop1;
	(*myBoard)[7][5].currentPiece = ptrToBlackBishop2;
	(*myBoard)[0][1].currentPiece = ptrToWhiteKnight1;
	(*myBoard)[0][6].currentPiece = ptrToWhiteKnight2;
	(*myBoard)[7][1].currentPiece = ptrToBlackKnight1;
	(*myBoard)[7][6].currentPiece = ptrToBlackKnight2;
	(*myBoard)[0][0].currentPiece = ptrToWhiteRook1;
	(*myBoard)[0][7].currentPiece = ptrToWhiteRook2;
	(*myBoard)[7][0].currentPiece = ptrToBlackRook1;
	(*myBoard)[7][7].currentPiece = ptrToBlackRook2;

	(*myBoard)[1][0].currentPiece = ptrToWhitePawn1;
	(*myBoard)[1][1].currentPiece = ptrToWhitePawn2;
	(*myBoard)[1][2].currentPiece = ptrToWhitePawn3;
	(*myBoard)[1][3].currentPiece = ptrToWhitePawn4;
	(*myBoard)[1][4].currentPiece = ptrToWhitePawn5;
	(*myBoard)[1][5].currentPiece = ptrToWhitePawn6;
	(*myBoard)[1][6].currentPiece = ptrToWhitePawn7;
	(*myBoard)[1][7].currentPiece = ptrToWhitePawn8;

	(*myBoard)[6][0].currentPiece = ptrToBlackPawn1;
	(*myBoard)[6][1].currentPiece = ptrToBlackPawn2;
	(*myBoard)[6][2].currentPiece = ptrToBlackPawn3;
	(*myBoard)[6][3].currentPiece = ptrToBlackPawn4;
	(*myBoard)[6][4].currentPiece = ptrToBlackPawn5;
	(*myBoard)[6][5].currentPiece = ptrToBlackPawn6;
	(*myBoard)[6][6].currentPiece = ptrToBlackPawn7;
	(*myBoard)[6][7].currentPiece = ptrToBlackPawn8;
	
	return 1;
	
}

int Chess::isAttacked(bool colorOfAttacker,string position)
{
	Position pos(position);
	bool result;
	for (char row = 0; row < 8; row++)
	{
		for (char col = 0; col < 8; col++)
		{
			string source;
			source.push_back(row + 'a');
			source.push_back(col + '1');
			if (result = canCapture(colorOfAttacker, source + position)) //This is assignment and not comparision
			{
				break;
			}
			else
			{
				std::cout << (*currentBoard)[row][col].currentPiece->myName() << " cant captrue on e1\n";

			}
			
		}
	}
	return result;
}
int Chess::canCapture(bool color,string choosenMove)
{
	Position source(choosenMove.substr(0, 2));
	Position destination(choosenMove.substr(2, 2));
	//std::cout << "current string in loop" << choosenMove;

	Piece *sourcePiece = (*currentBoard)[source.x - 1][source.y - 1].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destination.x - 1][destination.y - 1].currentPiece;
	bool canMove;
	if (sourcePiece->myName() == "Pawn")
	{
		//std::cout << "I am here pawn capture";
		//std::cout << "The function returns " << (sourcePiece->movesInEmptyBoard(choosenMove.substr(0,2),choosenMove.substr(1,2)) == 2);
		canMove = (sourcePiece->movesInEmptyBoard(choosenMove.substr(0, 2), choosenMove.substr(2, 2)) == 2);
	}
	else
	{
		canMove = (sourcePiece->movesInEmptyBoard(choosenMove.substr(0, 2), choosenMove.substr(2, 2)));
	}
	bool playerMatchesPiece = (color == sourcePiece->getColor());
	bool isOpponentPiece = (sourcePiece->getColor() != destinationPiece->getColor());
	if (canMove  && playerMatchesPiece && isOpponentPiece && isNotBlocked(choosenMove))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Chess::isKingInCheck(bool color)
{
	Position kingPosition;
	for (char row = 0; row< 8; row++)
	{
		for (char col = 0; col < 8; col++)
		{
			Piece *currentPiece = (*currentBoard)[row][col].currentPiece;
			if (currentPiece->myName() == "King" && currentPiece->getColor() == color)
			{
				kingPosition.x = row + 1;
				kingPosition.y = col + 1;
			}
		}
	}
	return isAttacked(color, kingPosition.getString());

}


