#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Graphic.h"
#include "chess.h"
//#include "rook.h"
int i = 0;
using std::cout;
using std::cin;
int main(int argc,char*args[])
{
	Graphic myGraphic;
	string move;
	string tempSelection = "0"; // extra haleko
	Board myBoard[8][8];
	OnePiece noPiece("white");
	Game::initializeBoard(&myBoard,&noPiece);
	//setBoard(myBoard, &noPiece);
	Board(*pointer)[8][8] = &myBoard;
	/*King whiteKing("white");
	King blackKing("black");
	Bishop whiteBishop1("white");
	Bishop blackBishop1("black");
	Bishop whiteBishop2("white");
	Bishop blackBishop2("black");
	Queen whiteQueen("white");
	Queen blackQueen("black");
	Rook blackRook("black");
	Rook whiteRook1("white");
	Rook whiteRook2("white");
	Rook blackRook1("black");
	Rook blackRook2("black");
	Knight whiteKnight1("white");
	Knight whiteKnight2("white");
	Knight blackKnight1("black");
	Knight blackKnight2("black");
	Pawn whitePawn1("white");
	Pawn blackPawn1("black");

	OnePiece noPiece("white");

	Board myBoard[8][8];
	setBoard(myBoard,&noPiece);
	Board(*pointer)[8][8] = &myBoard;

	myBoard[0][4].currentPiece = &whiteKing;
	myBoard[7][4].currentPiece = &blackKing;
	myBoard[0][2].currentPiece = &whiteBishop1;
	myBoard[7][2].currentPiece = &blackBishop1;
	myBoard[0][3].currentPiece = &whiteQueen;
	myBoard[7][3].currentPiece = &blackQueen;
	myBoard[0][0].currentPiece = &whiteRook1;
	myBoard[0][7].currentPiece = &whiteRook2;
	myBoard[7][0].currentPiece = &blackRook1;
	myBoard[7][7].currentPiece = &blackRook2;
	myBoard[0][1].currentPiece = &whiteKnight1;
	myBoard[0][6].currentPiece = &whiteKnight2;
	myBoard[7][1].currentPiece = &blackKnight1;
	myBoard[7][6].currentPiece = &blackKnight2;
	myBoard[1][0].currentPiece = &whitePawn1;
	myBoard[6][0].currentPiece = &blackPawn1;
	
	

	//myBoard[1][0].currentPiece = &whitePawn1;

//	myBoard[1][3].currentPiece = &whiteRook;
	//myBoard[3][2].currentPiece = &blackRook;	
	
	myBoard[7][5].currentPiece = &blackBishop2;
	myBoard[0][5].currentPiece = &whiteBishop2;
	*/
	Chess myChess("Player1", "Player2", &myBoard,&noPiece);
	
	
	int count = 1;
	//SDL_Event events;
	string myMove;
	while (!myChess.isChessOver())
	{
		myGraphic.run(myChess);
		//std::cout << (myChess.isAttacked(0, "e1")?"in check\n":"not in check\n");
		//std::cout << (myChess.isKingInCheck(1) ? "It is in check\n" : "it is not in check\n");
		myGraphic.getInput(myChess,&(myGraphic.graphicEvents),myMove);
		/*if (!myMove.empty())
		{
			if (myChess.execute(myMove))
			{
				myChess.changeTurn();
			}
			else
			{
				std::cout << "I cant execute given move\n";
			}
		}*/
		
	}
	return 0;
}
