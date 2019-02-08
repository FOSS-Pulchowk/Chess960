#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;

vector<int> getPositionInVector(string position);
class Piece
{
protected:
	string name;
	string currentPosition;
public:
	virtual bool MovesInEmptyBoard(string initialPosition, string finalPosition) = 0;
};

class King:public Piece
{
	bool isWhite;
public:
	King(string currentPosition,string color);
	bool MovesInEmptyBoard(string initialPosition, string finalPosition);
};