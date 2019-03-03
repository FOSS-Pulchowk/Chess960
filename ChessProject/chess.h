#pragma once
#include <string>
#include "board.h"
#include "piece.h"
using std::string;

/*Contains basic Chess related information and pointer to the board */
class Board;
class Piece;
enum Color { BLACK,WHITE,NONE };
/*namespace Game
{
	int initializeBoard(Board (*myBoard)[8][8],OnePiece *noPiece);
	//void putPiece(Board (*myBoard)[8][8], Piece *myPiece,Position location);
}*/
class Chess
{
	bool whiteToPlay;
	bool isOver;

	static OnePiece *ptrToNoPiece;
	
	King *ptrToWhiteKing;// = new King("white");
	King *ptrToBlackKing;// = new King("black");
	Queen *ptrToWhiteQueen;// = new Queen("white");
	Queen *ptrToBlackQueen;// = new Queen("black");
	Bishop *ptrToWhiteBishop1;// = new Bishop("white");
	Bishop *ptrToWhiteBishop2;// = new Bishop("white");
	Bishop *ptrToBlackBishop1;// = new Bishop("black");
	Bishop *ptrToBlackBishop2;// = new Bishop("black");
	Knight *ptrToWhiteKnight1;// = new Knight("white");
	Knight *ptrToWhiteKnight2;// = new Knight("white");
	Knight *ptrToBlackKnight1;// = new Knight("black");
	Knight *ptrToBlackKnight2;// = new Knight("black");

	Rook *ptrToWhiteRook1;//=new Rook("white");
	Rook *ptrToWhiteRook2;//=new Rook("white");
	Rook *ptrToBlackRook1;//=new Rook("black");
	Rook *ptrToBlackRook2;//=new Rook("black");
	/* 
	Pawn *ptrToWhitePawn1;//=new Pawn("white");
	Pawn *ptrToWhitePawn2;//=new Pawn("white");
	Pawn *ptrToWhitePawn3;//=new Pawn("white");
	Pawn *ptrToWhitePawn4;//=new Pawn("white");
	Pawn *ptrToWhitePawn5;//=new Pawn("white");
	Pawn *ptrToWhitePawn6;//=new Pawn("white");
	Pawn *ptrToWhitePawn7;//=new Pawn("white");
	Pawn *ptrToWhitePawn8;//=new Pawn("white");
	Pawn *ptrToBlackPawn1;//=new Pawn("black");
	Pawn *ptrToBlackPawn2;//=new Pawn("black");
	Pawn *ptrToBlackPawn3;//=new Pawn("black");
	Pawn *ptrToBlackPawn4;//=new Pawn("black");
	Pawn *ptrToBlackPawn5;//=new Pawn("black");
	Pawn *ptrToBlackPawn6;//=new Pawn("black");
	Pawn *ptrToBlackPawn7;//=new Pawn("black");
	Pawn *ptrToBlackPawn8;//=new Pawn("black");
	*/
	Pawn *whitePawns[8];
	Pawn *blackPawns[8];
	
public:
	Board(*ptrToBoard)[8][8];// = new Board[1][8][8];
	Piece *whitePieces[16];
	Piece *blackPieces[16];
	string whitePlayerName;
	string blackPlayerName;
	vector<string>  getAllMoves();
	string getSingleMove(bool color);
	Chess(string name1, string name2);
	Chess(Chess&obj);
	~Chess();
	int initializeBoard();
	//Board(*ptrToBoard)**getBoard();
	auto getBoard();
	//Chess::ptrToBoard getBoard();
	vector <string> validMoves(string source);
	int canMoveHere(string choosenMove);
	int castle(string choosenMove);
	int undo();
	int piecesIntValue[8];
	Piece *limboPiece;
	string lastMove, lastMove2;
	bool pawnDoubleStep, pawnEnPassant, pawnDoubleStep2, pawnEnPassant2, canUndo;
	string enPassantPawnPosforRessurect;
	int isAttacked(bool color, string position);
	int canCapture(bool color,string choosenMove);
	int isKingInCheck(bool color);
	Board(*currentBoard)[8][8];
	int moveToEmptySquare(string choosenMove);
	int isNotBlocked(string choosenMove);
	void changeTurn();
	void reset();
	int score();
	void save();
	bool isChessOver() const;
	bool getCurrentPlayer() const;
	int checkState();
	void endChess();
	int capture(string choosenMove);
	int execute(string move);
	string getKing(Color color);

	
	string getPiecesConfig();
	//void setBoard(Board currentBoard[8][8]);
	//void copyBoard(Board (*sourceBoard)[8][8]);
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

