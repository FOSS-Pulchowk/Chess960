#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using std::string;
using std::vector;
/*The abstract Piece class contains name and position of piece. Other objects inherit and override the virtual function in the base class. */
vector<int> getPositionInVector(string position);
class Piece
{
protected:
	string name;
	bool isWhite;
	bool alive;
	//string currentPosition;
public:
	//void setCurrentPosition(string position);
	string myName();
	SDL_Surface *image;
	virtual int movesInEmptyBoard(string initialPosition, string finalPosition) = 0;
	bool isAlive() { return alive; }
	bool kill();
	bool resurrect();
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
		//std::cout << "No Piece exists here";
		return 0;
	}
};

class Queen :public Piece
{
public:
	Queen(string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
};

class Rook :public Piece
{
public:
	Rook(string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
};

class Knight :public Piece
{
public:
	Knight(string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
};
class Pawn :public Piece
{
public:
	Pawn(string color);
	int promoted;
	int promote(string piece);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
	Piece *promotedPiece;
};