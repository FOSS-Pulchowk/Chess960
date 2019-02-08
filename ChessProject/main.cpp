#include <iostream>
#include "game.h"
using std::cout;
int main()
{
	King whiteKing("e2", "white");
	King blackKing("e8", "black");
	Board myBoard[8][8];
	setBoard(myBoard);
	Board(*pointer)[8][8] = &myBoard;
	myBoard[1][4].currentPiece = &whiteKing;
	Game mygame("Player1", "Player2", &myBoard);
	cout <<(*mygame.currentBoard)[1][4].currentPiece->myName();
	mygame.moveToEmptySquare("e2e3");
	cout << "\n" << (*mygame.currentBoard)[1][4].currentPiece->movesInEmptyBoard("e2","e3");
	
}