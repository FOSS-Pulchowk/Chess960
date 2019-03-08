#include "program.h"


Program::Program()
{
	isRunning = true;
	ptrToGraphic = new Graphic;
	//ptrToNoPiece = new OnePiece("white");
	ptrToChess = new Chess("name1", "name2");
	//myGraphic.loadingScreen();

}
void Program::init()
{
	//Game::initializeBoard(ptrToBoard, ptrToNoPiece, ptrToChess);
	Graphic myGraphic = *ptrToGraphic;
	Chess myChess = *ptrToChess;
	vector<string> moveSet;
	moveSet.push_back("e2b6");
	moveSet.push_back("b5d3");
	moveSet.push_back("a3f6");
	moveSet.push_back("c3f5");
	moveSet.push_back("a2c8");
	moveSet.push_back("f2e4");
	moveSet.push_back("a1b3");
	moveSet.push_back("c3f5");
	moveSet.push_back("d2f8");
	moveSet.push_back("e5a6");
	moveSet.push_back("c3d7");
	//Board (*myBoard)[8][8] = ptrToBoard;
	//OnePiece noPiece = *ptrToNoPiece;
	string myMove;
	myGraphic.loadingScreen();
	while (isRunning)
	{
		myGraphic.mainmenu(*ptrToChess);
		std::cout << "\n" << myGraphic.currentWindowView << "\n";
		if (myGraphic.currentWindowView == "gameplay")
		{
			while (!(*ptrToChess).isChessOver())
			{
				//std::cout << "IS Over outside: " << (*ptrToChess).isChessOver();
				//myGraphic.run(*ptrToChess, (*ptrToChess).moveSet);
				myGraphic.run(*ptrToChess, moveSet);
				int inputTrue;// = myGraphic.getInput(*ptrToChess, &(myGraphic.graphicEvents), myMove);
				inputTrue = myGraphic.getInput(*ptrToChess, &(myGraphic.graphicEvents), myMove);
				/*if ((*ptrToChess).getCurrentPlayer())
				{
					inputTrue = myGraphic.getInput(*ptrToChess, &(myGraphic.graphicEvents), myMove);
				}
				else
				{
					string move = (*ptrToChess).getSingleMove(0);
					myGraphic.inputMove = move;
					inputTrue = 1;
				}*/
				//std::cout << "Move from engine: " << (*ptrToChess).getSingleMove() << "\n";
				if (inputTrue == 1)
				{
					backUpState = new Chess(*ptrToChess);
					std::cout << " I created backup chess\n";
					//*lastState = myChess;
					//lastState = new Chess(*ptrToChess);
					int result = (*ptrToChess).execute(myGraphic.inputMove);
					if (result == 1)
					{
						(*ptrToChess).moveSet.push_back(myGraphic.inputMove);
						std::cout << "Moveset: " << (*ptrToChess).moveSet[0];
						//std::cerr << "I am executing inside rresult==1 \n";
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
						//std::cout << "Piece on e4: " << (*(*ptrToChess).currentBoard)[3][4].currentPiece->myName() << "\n";

						//std::cout << ((*ptrToChess).getCurrentPlayer() ? "White " : "Black ") << "to play.\n";
						(*ptrToChess).changeTurn();
						if ((*ptrToChess).checkState() == 0)
						{
							std::cout << "\n-------------------------------------------------------------------------\n";
							std::cout << "Black Wins\n";
							//SDL_Surface *whiteWins = IMG_Load("WhiteWins.png");
							myGraphic.run(*ptrToChess, (*ptrToChess).moveSet);
							//SDL_Blit(whiteWins, NULL, myGraphic.screenSurface);
							//SDL_Rect whiteWins;
							
							//SDL_Blit(whiteWins,NULL,screenSurfacee)
							//SDL_Delay(2000);
							(*ptrToChess).endChess();
						}
						else if ((*ptrToChess).checkState() == 1)
						{
							std::cout << "\n-------------------------------------------------------------------------\n";
							std::cout << "White Wins\n";
							myGraphic.run(*ptrToChess, (*ptrToChess).moveSet);
							(*ptrToChess).endChess();
						}
						if (lastState != NULL)
						{
							delete lastState;
							lastState = NULL;
						}
						lastState = backUpState;
						canRevert = 1;
						//std::cout << " Created a new lastState after executieon\n";
						myGraphic.inputMove = "";
					}
					else if (result == 2)
					{
						if (lastState != NULL)
						{
							delete lastState;
							lastState = NULL;
						}
						lastState = backUpState;
						canRevert = 1;
						goto label;
					}
					else
					{
						myGraphic.inputMove = "";
						std::cout << "Invalid move";
						//delete lastState;
						//lastState = NULL;
					}
				}
				else if (inputTrue == 2||inputTrue==7)
				{
				label:
					std::cout << "Piece on e4: before changing" << (*(*ptrToChess).currentBoard)[3][4].currentPiece->myName() << "\n";
					if (canRevert && lastState != NULL)
					{
						std::cout << "I am in side 2 and changing to last state\n";
						delete ptrToChess;
						ptrToChess = lastState;
						//moveCount--;
						/*std::cout << "after clicking undo Is Chess Over? " << ptrToChess->isChessOver() << ".\n";
						std::cout << ((*ptrToChess).getCurrentPlayer() ? "White " : "Black ") << "to play.\n";*/
						lastState = NULL;
						canRevert = false;
					}
					else
					{
						std::cout << "Last state is null\n";
					}
					myGraphic.inputMove = "";
					//std::cout << "Piece on e4: after changing " << (*(*ptrToChess).currentBoard)[3][4].currentPiece->myName() << "\n";
				}
				else if (inputTrue==3)
				{
					delete ptrToChess;
					Chess *newChess= new Chess("Player1", "Player2");
					ptrToChess = newChess;
				}
				else if (inputTrue == 8 || inputTrue==6)
				{
					ptrToChess->endChess();
					exit(0);
				}


				//std::cout << " After undo after check: ";
			}
			//SDL_Delay(10000);
		}
		else if (myGraphic.currentWindowView == "setting") { myGraphic.Setting(); }
		else if (myGraphic.currentWindowView=="")
		{
			isRunning = false;
			exit(0);
			return;
		}
	}
}
void Program::quit()
{
	isRunning = false;

}