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
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << myBoard[i][j].getMyLocation() << "  ";
		}
		cout << "\n";
	}


}