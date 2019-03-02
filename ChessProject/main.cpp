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
OnePiece* Chess::ptrToNoPiece = new OnePiece("white");
int main(int argc,char*args[])
{

	//Program myProgram;
	//myProgram.init();
	Graphic myGraphic;
	Chess *ptrToChess=new Chess("Player1", "Player2");
	
	//delete ptrToChess;
	string myMove;
	Chess *lastState = new Chess(*ptrToChess);
	std::cout << ((*ptrToChess).getCurrentPlayer() ? "White " : "Black ") << "to play.\n";
	while (!(*ptrToChess).isChessOver())
	{
		//std::cout << "IS Over outside: " << (*ptrToChess).isChessOver();
		myGraphic.run(*ptrToChess);
		//std::cout << "Outside of run\n";
		int inputTrue = myGraphic.getInput(*ptrToChess, &(myGraphic.graphicEvents), myMove);
		
		if (inputTrue == 1)
		{
			//*lastState = myChess;
			
			std::cout << " Is Copy constructer called?\n";
			lastState = new Chess(*ptrToChess);
			int result = (*ptrToChess).execute(myGraphic.inputMove);
			if (result==1)
			{
				std::cerr << "I am executing inside rresult==1 \n";
				//myChess.canUndo = true;
				//std::cout << myChess.lastMove << std::endl; //yo bujhina hai... tala assign hunu vanda pailai lastmove ma input gaisakyo
				//myChess.lastMove2 = myChess.lastMove;
				//myChess.lastMove = myGraphic.inputMove;
				//std::cout << myChess.lastMove << myChess.lastMove2;
				//if (!myChess.pawnEnPassant) { myChess.lastMove2 = myChess.lastMove; }
				//string move = myChess.lastMove; //yo var tala lekhda lamo nahos vanera matrai ho
				//myChess.pawnDoubleStep2 = myChess.pawnDoubleStep;
				//if (abs(move[1] - move[3]) == 2 && (*myChess.currentBoard)[move[3] - '1'][move[2] - 'a'].currentPiece->myName() == "Pawn") { myChess.pawnDoubleStep = true; }
				//else { myChess.pawnDoubleStep = false; }
				std::cout << "Piece on e4: " << (*(*ptrToChess).currentBoard)[3][4].currentPiece->myName() << "\n";
				(*ptrToChess).changeTurn();
				std::cout << ((*ptrToChess).getCurrentPlayer() ? "White " : "Black ") << "to play.\n";
				//delete lastState;
				//lastState = new Chess(*ptrToChess);
				//std::cout << "I copied \n";
				//ptrToChess = lastState;
				//std::cout << (myChess.isKingInCheck(1) ? "It is in check\n" : "it is not in check\n");
				std::cout << " Created a new lastState after executieon\n";
				myGraphic.inputMove = "";
			}
			else if (result==2)
			{
				goto label;
				//std::cout << "You cant execute this move\n";
				//if (lastState != NULL)
				//{
				//	std::cout << "Last state is not null\n";
				//	delete ptrToChess;
				//	ptrToChess = lastState;
				//	std::cout << " check bata Is Chess Over? " << ptrToChess->isChessOver() << ".\n";
				//	//delete lastState;
				//	lastState = NULL;
				//	std::cout << "Last state is NULLED\n";
				//	
				//}
				//std::cout << "After check, setting Input move \n";
				//myGraphic.inputMove = "";
				
			}
			else
			{
				myGraphic.inputMove = "";
				std::cout << "Invalid move";
				//delete lastState;
				//lastState = NULL;
			}
		}
		else if (inputTrue==2)
		{
			label:
			std::cout << "Piece on e4: before changing" << (*(*ptrToChess).currentBoard)[3][4].currentPiece->myName() << "\n";
			if (lastState != NULL)
			{
				std::cout << "I am in side 2 and changing to last state\n";
				delete ptrToChess;
				ptrToChess = lastState;
				/*std::cout << "after clicking undo Is Chess Over? " << ptrToChess->isChessOver() << ".\n";
				std::cout << ((*ptrToChess).getCurrentPlayer() ? "White " : "Black ") << "to play.\n";*/
				lastState = NULL;
			}
			else
			{
				std::cout << "Last state is null\n";
			}
			myGraphic.inputMove = "";
			std::cout << "Piece on e4: after changing " << (*(*ptrToChess).currentBoard)[3][4].currentPiece->myName() << "\n";
		}
		//std::cout << " After undo after check: ";
	}
	return 0;
}
