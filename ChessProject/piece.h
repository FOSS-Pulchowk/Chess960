#pragma once
#include <vector>
#include <string>
#include <fstream>
using std::string;
using std::vector;

vector<int> getPositionInVector(string position);
int getPositionInInteger(string position);
class Piece
{
protected:
	string name;
	string currentPosition;
	bool isWhite; //yeslai child class bata piece class ma haldeko
public:
	//bool lai int gareko hai yah maile
	virtual int MovesInEmptyBoard(string initialPosition, string finalPosition) = 0;
};

class King :public Piece
{
public:
	King(string currentPosition, string color);
	int MovesInEmptyBoard(string initialPosition, string finalPosition);
};

class Pawn :public Piece
{
	std::ifstream moveRefFile;
	std::ifstream eatRefFile;
public:
	Pawn(string currentPosition, string color);
	//Does eat and move validation
	int MovesInEmptyBoard(string initialPosition, string finalPosition);
	//0 = Move not Valid, 1 = Move Valid, 2 = Move Possible if it has opposite piece
	void anything();
};

class Bishop :public Piece
{
public:
	Bishop(string currentPosition, string color);
	int MovesInEmptyBoard(string initialPosition, string finalPosition);
};