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
	
	/*myChess.moveToEmptySquare("e2e3");
	//cout << "\n" << (*myChess.currentBoard)[1][4].currentPiece->movesInEmptyBoard("e2", "e3");
	cout <<"New Name" << (*myChess.currentBoard)[2][4].currentPiece->myName();
	myChess.moveToEmptySquare("e3e1");*/
	int count = 1;
	//SDL_Event events;
	string myMove;
	while (!myChess.isChessOver())
	{
		myGraphic.run(myChess);
		//cout << (myChess.getCurrentPlayer() ? "\nWhite:" : "\nBlack:");
<<<<<<< HEAD
		
		//cout << "\nEnter move:";
		//cin >> move;
		move=myGraphic.input(myChess,myGraphic.e);
		if (move.length() == 2)
=======
		//string myMove;
		//myMove=myGraphic.input(&myEvent);
		//myMove = "e1e2";
		//if (myChess.execute(myMove))
		//{
			//myChess.changeTurn();
			//i = i + 4;
		//}
		//else
		//{
		//	std::cout << "false move";
		//}

		/*if (SDL_PollEvent(&events))
		{
			//If a key was pressed
			if (events.type == SDL_KEYDOWN)
			{
				//Set the proper message surface
				switch (events.key.keysym.sym)
				{
				case SDLK_UP: myMove = "e1e2"; break;
				case SDLK_DOWN: myMove = "e8e7"; break;
				case SDLK_LEFT: myMove = "e2e3"; break;
				case SDLK_RIGHT: myMove = "e7e6"; break;
				}
				if (myChess.execute(myMove))
				{
					myChess.changeTurn();

				}
			}

			//If the user has Xed out the window
			else if (events.type == SDL_QUIT)
			{
				//Quit the program
				myChess.endChess();
			}
		}*/
		myGraphic.getInput(myChess,&(myGraphic.graphicEvents),myMove);
		/*if (move.length() == 2)
>>>>>>> dc081163dbfea43407f350dd37210f8be484819e
		{
			if (tempSelection == move)
			{
				tempSelection = "0";
			}
			else if (tempSelection == "0")
			{
				tempSelection = move;
			}
			else
			{
				myChess.execute(tempSelection+move);
				tempSelection = "0";
			}
		}
		/*
		if (move=="")
			myChess.endChess();
		if (myChess.execute(move))
		{
			myChess.changeTurn();
		}*/

	}
	return 0;
}
