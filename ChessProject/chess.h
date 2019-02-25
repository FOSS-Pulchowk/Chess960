#pragma once
#include <string>
#include "board.h"
#include "piece.h"
using std::string;
/*Contains basic Chess related information and pointer to the board */
class Board;
class Piece;
enum Color { WHITE, BLACK };
/*namespace Game
{
	int initializeBoard(Board (*myBoard)[8][8],OnePiece *noPiece);
	//void putPiece(Board (*myBoard)[8][8], Piece *myPiece,Position location);
}*/
class Chess
{
	string whitePlayerName;
	string blackPlayerName;
	bool whiteToPlay;
	bool isOver;
	OnePiece *ptrToNoPiece;
	bool whiteKingIsChecked;
	bool blackKingIsChecked;
	/*King ptrToWhiteKing("white");			//yah object nai create vakok xaina purai
	King ptrToBlackKing("black");
	Queen ptrToWhiteQueen("white");
	Queen ptrToBlackQueen("black");
	Bishop ptrToWhiteBishop1("white");
	Bishop ptrToWhiteBishop2("white");
	Bishop ptrToBlackBishop1("black");
	Bishop ptrToBlackBishop2("black");
	Knight ptrToWhiteKnight1("white");
	Knight ptrToWhiteKnight2("white");
	Knight ptrToBlackKnight1("black");
	Knight ptrToBlackKnight2("black");
	Rook ptrToWhiteRook1("white");
	Rook ptrToWhiteRook2("white");
	Rook ptrToBlackRook1("black");
	Rook ptrToBlackRook2("black");
	Pawn ptrToWhitePawn1("white");
	Pawn ptrToWhitePawn2("white");
	Pawn ptrToWhitePawn3("white");
	Pawn ptrToWhitePawn4("white");
	Pawn ptrToWhitePawn5("white");
	Pawn ptrToWhitePawn6("white");
	Pawn ptrToWhitePawn7("white");
	Pawn ptrToWhitePawn8("white");
	Pawn ptrToBlackPawn1("black");
	Pawn ptrToBlackPawn2("black");
	Pawn ptrToBlackPawn3("black");
	Pawn ptrToBlackPawn4("black");
	Pawn ptrToBlackPawn5("black");
	Pawn ptrToBlackPawn6("black");
	Pawn ptrToBlackPawn7("black");
	Pawn ptrToBlackPawn8("black");*/

public:
	vector <string> validMoves(string source);
	int canMoveHere(string choosenMove);
	int castle(string choosenMove);
	int undo();
	int piecesIntValue[8];
	Piece *limboPiece;
	string lastMove;
	bool pawnDoubleStep, pawnEnPassant;
	string enPassantPawnPosforRessurect;
	int isAttacked(bool color, string position);
	int canCapture(bool color,string choosenMove);
	int isKingInCheck(bool color);
	Board(*currentBoard)[8][8];
	Chess(string name1, string name2, Board (*currentBoard)[8][8],OnePiece *ptr);
	int moveToEmptySquare(string choosenMove);
	int isNotBlocked(string choosenMove);
	void changeTurn();
	void reset();
	void save();
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
	//bool enPassantValidity(string piece);
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