#include "program.h"
Program::Program()
{
	isRunning = true;
	ptrToGraphic = new Graphic;
	ptrToBoard = new Board[1][8][8];
	ptrToNoPiece = new OnePiece("white");
	ptrToChess = new Chess("name1", "name2", ptrToBoard, ptrToNoPiece);
	//myGraphic.loadingScreen();

}
void Program::init()
{
	Game::initializeBoard(ptrToBoard, ptrToNoPiece, ptrToChess);
	Graphic myGraphic = *ptrToGraphic;
	Chess myChess = *ptrToChess;
	//Board (*myBoard)[8][8] = ptrToBoard;
	OnePiece noPiece = *ptrToNoPiece;
	string myMove;
	myGraphic.loadingScreen();
	while (isRunning)
	{
		myGraphic.mainmenu(*ptrToChess);
		std::cout << "\n" << myGraphic.currentWindowView << "\n";
		if (myGraphic.currentWindowView == "gameplay")
		{
			while (!myChess.isChessOver())
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
					Game::initializeBoard(ptrToBoard, &noPiece, &myChess);
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
					return;
				}
			}
			//SDL_Delay(10000);
		}
		else if (myGraphic.currentWindowView == "setting") { myGraphic.Setting(); }
		else
		{
			isRunning = false;
		}
	}
}
void Program::quit()
{
	isRunning = false;

}