#include <string>
#include <vector>
using std::string;
using std::vector;
class Piece;

class Board
{
	string myLocation;
	Piece *currentPiece;
public:
	void setMyLocation(string location);
	string getMyLocation();
	bool setPiece(Piece *pieceptr);
	friend void setBoard(Board currentBoard[8][8]);
};
void setBoard(Board currentBoard[8][8]);
