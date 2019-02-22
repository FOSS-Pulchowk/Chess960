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
	//Game::initializeBoard(&myBoard,&noPiece);
	//setBoard(myBoard, &noPiece);
	Board(*pointer)[8][8] = &myBoard;
	Chess myChess("Player1", "Player2", &myBoard,&noPiece);
	Game::initializeBoard(&myBoard, &noPiece, &myChess);
	//dynamic_cast<Pawn*>((*(myChess.currentBoard))[1][0]).currentPiece)->promote("Queen");
	dynamic_cast<Pawn*>((*myChess.currentBoard)[1][0].currentPiece)->promote("Queen");

	int count = 1;
	//SDL_Event events;
	string myMove;
	while (!myChess.isChessOver())
	{
		myGraphic.run(myChess);
		int inputTrue = myGraphic.getInput(myChess, &(myGraphic.graphicEvents), myMove);
		if (inputTrue==1)
		{
			if (myChess.execute(myGraphic.inputMove))
			{
				std::cerr << "I am executing\n";
				myChess.lastMove = myGraphic.inputMove;
				string move = myChess.lastMove;
				if (abs(move[1] - move[3]) == 2 && (*myChess.currentBoard)[move[3] - '1'][move[2] - 'a'].currentPiece->myName() == "Pawn") { myChess.pawnDoubleStep = true; }
				else { myChess.pawnDoubleStep = false; }
				myChess.changeTurn();
				//std::cout << (myChess.isKingInCheck(1) ? "It is in check\n" : "it is not in check\n");
				myGraphic.inputMove = "";
			}
			else
			{
				myGraphic.inputMove = "";
				std::cout << "Invalid move";
			}
		}
		else if (inputTrue == 2)
		{
			myChess.undo();
		}
	
		
	}
	return 0;
}
