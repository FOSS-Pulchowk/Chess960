#include "piece.h"
#include "ChessFunctions.h"
King::King(string currentPosition)
{
	name = "King";
	this->currentPosition = currentPosition;
}
bool King::MovesInEmptyBoard(string initialPosition,string finalPosition)
{
	vector<int> initialPositionInNumber = Chess::getPositionInVector(initialPosition);
	vector<int> finalPositionInNumber = Chess::getPositionInVector(finalPosition);
	int i = -1;
	int j = -1;
	int x, y;
	vector<int> temp(2);
	for (; i <= 1; i++)
	{
		for (; j <= 1; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			x = initialPositionInNumber[0];
			y = initialPositionInNumber[1];
			temp[0] = x + i;
			temp[1] = y + j;
			if (finalPositionInNumber == temp)
			{
				return 1;
			}
		}
	}
}