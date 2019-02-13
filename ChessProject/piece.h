#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;
/*The abstract Piece class contains name and position of piece. Other objects inherit and override the virtual function in the base class. */
vector<int> getPositionInVector(string position);
class Piece
{
protected:
	string name;
	//string currentPosition;
public:
	void setCurrentPosition(string position);
	string myName();
	virtual int movesInEmptyBoard(string initialPosition, string finalPosition) = 0;
};

class King :public Piece
{
	bool isWhite;
public:
	King(string currentPosition, string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);

};
