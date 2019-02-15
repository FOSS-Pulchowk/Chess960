#pragma once
#include <iostream>
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
	bool isWhite;
	//string currentPosition;
public:
	//void setCurrentPosition(string position);
	string myName();
	virtual int movesInEmptyBoard(string initialPosition, string finalPosition) = 0;
	bool getColor() { return isWhite; }
};

class King :public Piece
{
	
public:
	King(string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);

};

class Bishop :public Piece
{
	//bool isWhite;
public:
	Bishop(string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
};

class OnePiece : public Piece
{
public:
	OnePiece(string color)
	{
		name = "OnePiece";
		isWhite = 1;
	}
	int movesInEmptyBoard(string initialPosition, string finalPosition)
	{
		std::cout << "No Piece exists here";
		return 0;
	}
};
/*
class Queen :public Piece
{
public:
	Queen(string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
};*/
