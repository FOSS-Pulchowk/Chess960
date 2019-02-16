#include <iostream>
#include "chess.h"
using std::cout;
int main()
{
	King whiteKing("e2", "white");
	King blackKing("e8", "black");
	Pawn whitePawn("b2", "white");
	Pawn blackPawn("g4", "black");
	Bishop whiteBishop("d3", "white");
	Bishop blackBishop("f5", "black");
	Board myBoard[8][8];
	setBoard(myBoard);
	Board(*pointer)[8][8] = &myBoard;
	myBoard[1][4].currentPiece = &whiteKing;
	myBoard[3][6].currentPiece = &blackPawn;
	myBoard[4][5].currentPiece = &blackBishop;
	chess mygame("Player1", "Player2", &myBoard);
	cout << (*mygame.currentBoard)[1][4].currentPiece->myName();
	mygame.moveToEmptySquare("e2e3");
	cout << "\n" << (*mygame.currentBoard)[1][4].currentPiece->movesInEmptyBoard("e2", "e3");
	cout << "\n" << (*mygame.currentBoard)[3][6].currentPiece->myName() << (*mygame.currentBoard)[3][6].currentPiece->movesInEmptyBoard("g4", "g3") << std::endl;
	cout << (*mygame.currentBoard)[4][5].currentPiece->myName() << (*mygame.currentBoard)[4][5].currentPiece->movesInEmptyBoard("c8", "h3") << std::endl;
}