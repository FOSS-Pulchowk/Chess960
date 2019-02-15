#include <iostream>
#include "game.h"
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
	Game myGame("Player1", "Player2", &myBoard,&noPiece);
	cout << (*myGame.currentBoard)[1][4].currentPiece->myName();
	/*myGame.moveToEmptySquare("e2e3");
	//cout << "\n" << (*mygame.currentBoard)[1][4].currentPiece->movesInEmptyBoard("e2", "e3");
	cout <<"New Name" << (*myGame.currentBoard)[2][4].currentPiece->myName();
	myGame.moveToEmptySquare("e3e1");*/
	int count = 1;
	while (!myGame.isGameOver())
	{
		string move;
		cout << (myGame.getCurrentPlayer() ? "\nWhite:" : "\nBlack:");
		cout << "\nEnter move:";
		cin >> move;
		if (myGame.moveToEmptySquare(move))
		{
			myGame.changeTurn();
			count++;
			if (count == 3) myGame.endGame();
		}

	}

}