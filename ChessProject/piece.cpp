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
		this->isWhite = 1;
	}
	else
	{
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
		isWhite = true; 
	}
	else 
	{ 
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