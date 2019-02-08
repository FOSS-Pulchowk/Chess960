#include <iostream>
#include "piece.h"
#include "board.h"
using std::cout;
int main()
{
	King whiteKing("e1", "white");
	King blackKing("e8", "black");
	Board myBoard[8][8];
	setBoard(myBoard);
	Board(*pointer)[8][8] = &myBoard;
	myBoard[1][4].currentPiece = &whiteKing;
	cout <<(*pointer)[1][4].currentPiece->MovesInEmptyBoard("e2","e4");
}