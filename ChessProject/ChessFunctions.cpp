#include "ChessFunctions.h"
vector<int> Chess::getPositionInVector(string positionInString)
{
	vector<int> positionInNumber;
	int file =positionInString[0]-'a'+1;
	int row = positionInString[1] - '0';
	positionInNumber.push_back(file);
	positionInNumber.push_back(row);
	return positionInNumber;

}