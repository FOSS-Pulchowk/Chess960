#include <iostream>
#include "chess.h"
using std::cout;
using std::cin;
int main()
{
	King whiteKing("white");
	King blackKing("black");

	OnePiece noPiece("white");

	Board myBoard[8][8];
	setBoard(myBoard,&noPiece);
	Board(*pointer)[8][8] = &myBoard;
	myBoard[1][4].currentPiece = &whiteKing;
	myBoard[7][4].currentPiece = &blackKing;
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
		if (myChess.moveToEmptySquare(move))
		{
			myChess.changeTurn();
			count++;
			if (count == 3) myChess.endChess();
		}

	}

}