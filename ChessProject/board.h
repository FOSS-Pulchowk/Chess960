#include <string>
#include <vector>
using std::string;
using std::vector;
class Piece;
class Board
{
	string location;
	Piece *currentPiece;
public:
	void setBoard(string location);
	void setBoard(Board[8][8]);

};