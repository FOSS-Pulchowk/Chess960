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

bool Piece::resurrect()
{
	if (alive)
	{
		std::cout << "Piece is alreay alive\n";
		return 0;
	}
	else
	{
		alive = 1;
		std::cout << "Piece resurrected successfully\n";
		return 1;
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

Rook::Rook(string color)
{
	this->name = "Rook";
	alive = true;
	//this->currentPosition = currentPosition;
	if (color == "white")
	{ 
		image = IMG_Load("ChessPieces/WhiteRook.png");
		isWhite = true;
	}
	else 
	{ 
		image = IMG_Load("ChessPieces/BlackRook.png");
		isWhite = false; 
	}
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

Knight::Knight(string color)
{
	this->name = "Knight";
	alive = true;
	// this->currentPosition = currentPosition;
	if (color == "white") {
		isWhite = true;
		image = IMG_Load("ChessPieces/WhiteKnight.png");
	}
	else {
		isWhite = false;
		image = IMG_Load("ChessPieces/BlackKnight.png");
	}
}

int Knight::movesInEmptyBoard(string initialPosition, string finalPosition)
{
	vector<int> initialPositionInNumber = getPositionInVector(initialPosition);
	vector<int> finalPositionInNumber = getPositionInVector(finalPosition);
	int checkColumn = abs(finalPositionInNumber[0] - initialPositionInNumber[0]);
	int checkRow = abs(finalPositionInNumber[1] - initialPositionInNumber[1]);
	if (checkColumn == 1 && checkRow == 2) { return 1; }
	else if (checkColumn == 2 && checkRow == 1) { return 1; }
	else { return 0; }
}

//gives integer value in serial from a1 to h8
int getPositionInInteger(string position)
{
	return position[0] - 'a' + (position[1] - '1') * 8;
}
/*void Piece::setCurrentPosition(string position)
{
	//this->currentPosition = position;
}*/

Pawn::Pawn(string color)
{
	name = "Pawn";
	alive = true;
	promoted = false;
	promotedPiece = NULL;
	//this->currentPosition = currentPosition;
	if (color == "white")
	{
		this->isWhite = true;
		image = IMG_Load("ChessPieces/whitePawn.png");
	}
	else
	{
		this->isWhite = false;
		image = IMG_Load("ChessPieces/blackPawn.png");
	}
}

int Pawn::movesInEmptyBoard(string initialPosition, string finalPosition)
{
	if (!promoted)
	{
		if (isWhite && (finalPosition[0] == initialPosition[0]))
		{
			if ((finalPosition[1] - initialPosition[1]) == 1) { return 1; }
			else if (((initialPosition[1] - '0') == 2) && ((finalPosition[1] - initialPosition[1]) == 2)) { return 1; }
		}
		else if (!isWhite && (finalPosition[0] == initialPosition[0]))
		{
			if ((initialPosition[1] - finalPosition[1]) == 1) { return 1; }
			else if (((initialPosition[1] - '0') == 7) && ((initialPosition[1] - finalPosition[1]) == 2)) { return 1; }
		}
		if ((abs(finalPosition[1] - initialPosition[1]) == 1) && (abs(finalPosition[0] - initialPosition[0]) == 1))
		{
			if (isWhite && (finalPosition[1] > initialPosition[1])) { return 2; }
			else if (!isWhite && (finalPosition[1] < initialPosition[1])) { return 2; }
		}
		return 0;
	}
	else
	{
		return promotedPiece->movesInEmptyBoard(initialPosition, finalPosition);
	}
}
int Pawn::promote(string piece)
{
	if (piece == "Queen")
	{
		if (getColor())
		{
			promotedPiece = new Queen("white");
		}
		else
		{
			promotedPiece = new Queen("black");
		}
		promoted = true;
		image = promotedPiece->image;
		std::cerr << "I am promoteing\n";
	}
	return promoted;
}