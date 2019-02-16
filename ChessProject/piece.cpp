#include "piece.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

vector<int> getPositionInVector(string position)
{
	vector<int> positionInNumber;
	int file = position[0] - 'a' + 1;
	int row = position[1] - '0';
	positionInNumber.push_back(file);
	positionInNumber.push_back(row);
	return positionInNumber;

}

//gives integer value in serial from a1 to h8
int getPositionInInteger(string position)
{
	return position[0] - 'a' + (position[1] - '1') * 8;
}

void Piece::setCurrentPosition(string position)
{
	//this->currentPosition = position;
}

string Piece::myName()
{
	return name;
}

King::King(string currentPosition, string color)
{
	name = "King";
	//this->currentPosition = currentPosition;
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

Pawn::Pawn(string currentPosition, string color)
{
	name = "Pawn";
	//this->currentPosition = currentPosition;
	if (color == "white")
	{
		this->isWhite = true;
		this->moveRefFile.open("PawnBottomMove.txt");
		//this->eatRefFile.open("PawnBottomEat.txt");
	}
	else
	{
		this->isWhite = false;
		this->moveRefFile.open("PawnTopMove.txt");
		//this->eatRefFile.open("PawnTopEat.txt");
	}
}

int Pawn::movesInEmptyBoard(string initialPosition, string finalPosition)
{
	int initialPosEquivInteger = getPositionInInteger(initialPosition);
	int finalPosEquivInteger = getPositionInInteger(finalPosition);
	string initialPosMoveValue; //initalPosEatValue;
	for (int i = 0; i <= initialPosEquivInteger; i++)
	{
		std::getline(this->moveRefFile, initialPosMoveValue);
		//std::getline(this->eatRefFile, initalPosEatValue);
	}
	if ((initialPosMoveValue[finalPosEquivInteger] - '0') == 1)
	{
		this->moveRefFile.seekg(0, std::ios::beg);
		return 1;
	}
	/*else if ((initalPosEatValue[finalPosEquivInteger] - '0') == 1)
	{
		this->eatRefFile.seekg(0, std::ios::beg);
		return 2;
	}*/
	this->moveRefFile.seekg(0, std::ios::beg);
	//this->eatRefFile.seekg(0, std::ios::beg);
	return 0;
}

//ettikai check garna halya ho
void Pawn::anything()
{
	std::cout << "sdvsvzdv";
}

Bishop::Bishop(string currentPosition, string color)
{
	this->name = "Bishop";
	//this->currentPosition = currentPosition;
	if (color == "white") { isWhite = true; }
	else { isWhite = false; }
}

int Bishop::movesInEmptyBoard(string initialPosition, string finalPosition)
{
	vector<int> initialPositionInNumber = getPositionInVector(initialPosition);
	vector<int> finalPositionInNumber = getPositionInVector(finalPosition);
	int verticalPosDiff, horizontalPosDiff;
	verticalPosDiff = finalPositionInNumber[0] - initialPositionInNumber[0];
	horizontalPosDiff = finalPositionInNumber[1] - initialPositionInNumber[1];
	if (verticalPosDiff == 0) { return 0; }
	else if (verticalPosDiff == abs(horizontalPosDiff)) { return 1; }
	else { return 0; }
}