#include <iostream>
#include "chess.h"
#include "rook.h"

using std::cout;
using std::cin;
int main()
{
	King whiteKing("white");
	King blackKing("black");
	Bishop whiteBishop1("white");
	Bishop blackBishop1("black");
	Bishop whiteBishop2("white");
	Bishop blackBishop2("black");
	Queen whiteQueen("white");
	Queen blackQueen("black");
	//Rook blackRook("e5", "black");
//	Rook whiteRook("a8", "black");


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
//	myBoard[1][3].currentPiece = &whiteRook;
	//myBoard[3][2].currentPiece = &blackRook;	

	myBoard[7][5].currentPiece = &blackBishop2;
	myBoard[0][5].currentPiece = &whiteBishop2;
	Chess myChess("Player1", "Player2", &myBoard,&noPiece);
	/*myChess.moveToEmptySquare("e2e3");
	//cout << "\n" << (*myChess.currentBoard)[1][4].currentPiece->movesInEmptyBoard("e2", "e3");
	cout <<"New Name" << (*myChess.currentBoard)[2][4].currentPiece->myName();
	myChess.moveToEmptySquare("e3e1");*/
	int count = 1;
	while (!myChess.isChessOver())
	{
		string move;
		cout << (myChess.getCurrentPlayer() ? "\nWhite:" : "\nBlack:");
		cout << "\nEnter move:";
		cin >> move;
		if (move=="")
			myChess.endChess();
		if (myChess.execute(move))
		{
			myChess.changeTurn();
		}

	}
}
