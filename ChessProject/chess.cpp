#include "chess.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
class Board;
class Piece;
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
chess::chess(string name1, string name2, Board (*currentBoard)[8][8])
{
	whiteToPlay = true;
	isOver = false;
	whitePlayerName = name1;
	blackPlayerName = name2;
	this->currentBoard = currentBoard;
	
}
void chess::changeTurn()
{
	whiteToPlay = !whiteToPlay;
}
int chess::moveToEmptySquare(string choosenMove)
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
string chess::getPiecesConfig()
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
	{ tempNum = rand() % 4;	}
	temp[2 * tempNum] = 'B';
	tempNum = rand() % 4;
	while (temp[2 * tempNum + 1] != '0')
	{ tempNum = rand() % 4;	}
	temp[2 * tempNum + 1] = 'B';
	tempNum = rand() % 8;
	for (int i = 0; i < 2; i++)
	{
		while (temp[tempNum] != '0')
		{
			tempNum = rand() % 8;
		}
		temp[tempNum] = 'k';
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