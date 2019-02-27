#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Graphic.h"
#include "chess.h"
#include "program.h"
//#include "rook.h"
int i = 0;
using std::cout;
using std::cin;
int main(int argc,char*args[])
{
	Program myProgram;
	myProgram.init();

	/*
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
	//dynamic_cast<Pawn*>((*myChess.currentBoard)[1][0].currentPiece)->promote("Queen");

	int count = 1;
	//SDL_Event events;
	string myMove;
	while (!myChess.isChessOver())
	{
		if (myGraphic.currentWindowView == "loading"){ myGraphic.loadingScreen(); }
		else if (myGraphic.currentWindowView == "mainmenu") 
		{
			myGraphic.mainmenu(myChess);
			if(myGraphic.currentWindowView == "gameplay")
			{
				Game::initializeBoard(&myBoard, &noPiece, &myChess);
				myChess.reset();
			}
		}
		else if (myGraphic.currentWindowView == "setting") { myGraphic.Setting(); }
		else if (myGraphic.currentWindowView == "gameplay")
		{
			myGraphic.run(myChess);
			int inputTrue = myGraphic.getInput(myChess, &(myGraphic.graphicEvents), myMove);
			if (inputTrue == 1)
			{
				if (myChess.execute(myGraphic.inputMove))
				{
					std::cerr << "I am executing\n";
					myChess.canUndo = true;
					std::cout << myChess.lastMove << std::endl; //yo bujhina hai... tala assign hunu vanda pailai lastmove ma input gaisakyo
					myChess.lastMove2 = myChess.lastMove;
					myChess.lastMove = myGraphic.inputMove;
					std::cout << myChess.lastMove << myChess.lastMove2;
					//if (!myChess.pawnEnPassant) { myChess.lastMove2 = myChess.lastMove; }
					string move = myChess.lastMove; //yo var tala lekhda lamo nahos vanera matrai ho
					myChess.pawnDoubleStep2 = myChess.pawnDoubleStep;
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
			else if (inputTrue == 3) // new game
			{
				Game::initializeBoard(&myBoard, &noPiece, &myChess);
				myChess.reset(); // k k chaine no new game ma yesh vitra hai
			}
			else if (inputTrue == 4) // save/load
			{
				myChess.save();
			}
			else if (inputTrue == 5) // draw
			{

			}
			else if (inputTrue == 6) { myGraphic.currentWindowView = "mainmenu"; } // resign
			else if (inputTrue == 7) // undo
			{
				myChess.undo();
			}
			else if (inputTrue == 8) // exit
			{
				//myGraphic.freeSurface(); // yah vitra k k free garne ho lekhne... pointer haru
				myChess.endChess();
			}
		}
		
	}
	*/
	return 0;
}
