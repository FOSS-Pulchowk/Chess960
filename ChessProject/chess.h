#pragma once
#include <string>
#include "board.h"
#include "piece.h"
using std::string;
/*Contains basic Chess related information and pointer to the board */
class Board;
class Piece;
enum Color { WHITE, BLACK };
class Chess
{
	string whitePlayerName;
	string blackPlayerName;
	bool whiteToPlay;
	bool isOver;
	OnePiece *ptrToNoPiece;
	bool whiteKingIsChecked;
	bool blackKingIsChecked;
public:
	vector <string> validMoves(string source);
	int canMoveHere(string choosenMove);
	int castle(string choosenMove);
	int undo();
	int piecesIntValue[8];
	Piece *limboPiece;
	string lastMove;
	int isAttacked(bool color, string position);
	int canCapture(bool color,string choosenMove);
	int isKingInCheck(bool color);
	Board(*currentBoard)[8][8];
	Chess(string name1, string name2, Board (*currentBoard)[8][8],OnePiece *ptr);
	int moveToEmptySquare(string choosenMove);
	int isNotBlocked(string choosenMove);
	void changeTurn();
	bool isChessOver();
	bool getCurrentPlayer();
	void checkState();
	void endChess();
	int capture(string choosenMove);
	int execute(string move);
	bool isWhiteChecked()
	{
		return whiteKingIsChecked;
	}
	bool isBlackChecked()
	{
		return blackKingIsChecked;
	}

	string getPiecesConfig();
};

struct Position
{
	int x;
	int y;
	Position() {}
	Position(string location)
	{
		y= location[0] - 'a' + 1;
		x = location[1] - '0';
	}
	Position set(string location)
	{
		y = location[0] - 'a' + 1;
		x = location[1] - '0';
		return *this;
	}
	string getString()
	{
		string temp;
		temp.push_back(y + 'a' - 1);
		temp.push_back(x + '1' - 1);
		return temp;
	}
};

namespace Game
{
	int initializeBoard(Board(*myBoard)[8][8], OnePiece *noPiece, Chess *mychess);
	//void putPiece(Board (*myBoard)[8][8], Piece *myPiece,Position location);
}


