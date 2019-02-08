#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;
class Piece
{
protected:
	string name;
	string currentPosition;
public:
	virtual bool MovesInEmptyBoard(string initialPosition, string finalPosition) {}
};
class King:public Piece
{
	bool isWhite;
public:
	King(string position);
	bool MovesInEmptyBoard(string initialPosition, string finalPosition);
};