#include "piece.h"
#include <iostream>
vector<int> getPositionInVector(string position)
{
	vector<int> positionInNumber;
	int file = position[0] - 'a' + 1;
	int row = position[1] - '0';
	positionInNumber.push_back(file);
	positionInNumber.push_back(row);
	return positionInNumber;

}
/*void Piece::setCurrentPosition(string position)
{
	//this->currentPosition = position;
}*/
string Piece::myName()
{
	return name;
}
King::King(string color)
{
	name = "King";
	alive = true;
	if (color == "white")
	{
		image = IMG_Load("ChessPieces/WhiteKing.png");
		this->isWhite = 1;
	}
	else
	{
		image = IMG_Load("ChessPieces/BlackKing.png");
		this->isWhite = 0;
	}
}
int King::movesInEmptyBoard(string initialPosition, string finalPosition)
{
	vector<int> initialPositionInNumber = getPositionInVector(initialPosition);
	vector<int> finalPositionInNumber = getPositionInVector(finalPosition);
	int x, y;

	vector<int> temp(2);

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			x = initialPositionInNumber[0];
			y = initialPositionInNumber[1];
			temp[0] = x + i;
			temp[1] = y + j;
			//std::cout << temp[0] << "," << temp[1] << "\n";
			if (finalPositionInNumber == temp)
			{
				return 1;
			}
		}
	}
	return 0;
}

Bishop::Bishop(string color)
{
	this->name = "Bishop";
	alive = true;
	//this->currentPosition = currentPosition;
	if (color == "white")
	{ 
		image=IMG_Load("ChessPieces/WhiteBishop.png");
		isWhite = true; 
	}
	else 
	{ 
		image=IMG_Load("ChessPieces/BlackBishop.png");
		isWhite = false;
	}
}

int Bishop::movesInEmptyBoard(string initialPosition, string finalPosition)
{
	vector<int> initialPositionInNumber = getPositionInVector(initialPosition);
	vector<int> finalPositionInNumber = getPositionInVector(finalPosition);
	int verticalPosDiff, horizontalPosDiff;
	verticalPosDiff = finalPositionInNumber[0] - initialPositionInNumber[0];
	horizontalPosDiff = finalPositionInNumber[1] - initialPositionInNumber[1];
	if (verticalPosDiff == 0) { return 0; }
	else if (abs(verticalPosDiff) == abs(horizontalPosDiff)) { return 1; }
	else { return 0; }
}
bool Piece::kill()
{
	if (alive)
	{
		alive = 0;
		std::cout << "piece killed successfully";
		return 1;
	}
	else
	{
		std::cout << "Piece already dead";
		return 0;
	}
}
Queen::Queen(string color)
{
	this->name = "Queen";
	alive = true;
	if (color == "white")
	{
		image=IMG_Load("ChessPieces/WhiteQueen.png");
		isWhite = true;
	}
	else
	{
		image=IMG_Load("ChessPieces/BlackQueen.png");
		isWhite = false;
	}
}
 
int Queen::movesInEmptyBoard(string initialPosition, string finalPosition)
{
	vector<int> initialPositionInNumber = getPositionInVector(initialPosition);
	vector<int> finalPositionInNumber = getPositionInVector(finalPosition);
	//Straight move 
	bool inStraightLine = (initialPositionInNumber[0] == finalPositionInNumber[0]) || (initialPositionInNumber[1] == finalPositionInNumber[1]);
	int verticalDifference = abs(finalPositionInNumber[0] - initialPositionInNumber[0]);
	int horizontalDifference = abs(finalPositionInNumber[1] - initialPositionInNumber[1]);
	bool inDiagonalLine = (verticalDifference == horizontalDifference);
	if (inStraightLine || inDiagonalLine)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Rook::Rook(string currentPosition, string color)
{
	this->name = "Rook";
	//this->currentPosition = currentPosition;
	if (color == "white") { isWhite = true; }
	else { isWhite = false; }
}

int Rook::movesInEmptyBoard(string initialPosition, string finalPosition)
{
	vector<int> initialPositionInNumber = getPositionInVector(initialPosition);
	vector<int> finalPositionInNumber = getPositionInVector(finalPosition);
	int checkColumn = finalPositionInNumber[0] - initialPositionInNumber[0];
	int checkRow = finalPositionInNumber[1] - initialPositionInNumber[1];
	if (checkColumn == 0 && checkRow != 0) { return 1; }
	else if (checkRow == 0 && checkColumn != 0) { return 1; }
	else { return 0; }
}