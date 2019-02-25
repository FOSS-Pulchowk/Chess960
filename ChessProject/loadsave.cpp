#include "piece.h"
#include "chess.h"
#include "board.h"
#include<fstream>

void Chess::check()
{
	string color, piece;
   string file_name;
   cout << "Type file name to be saved(no extension):";

   getline(cin, filename);
   file_name += ".dat";

   std:: ofstream ofs(file_name);
   if (ofs.is_open())
   {
      // Write the date and time of save operation
      auto time_now = std::chron
      o::system_clock::now();
      std::time_t end_time = std::chrono::system_clock::to_time_t(time_now);
      ofs << "[Chess console] Saved at: " << std::ctime(&end_time);


    // Write the moves

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((*currentBoard)[i][j].currentPiece->getColor())
         {
            color = "white";
            piece = (*currentBoard)[i][j].currentPiece->myName();
            if (myName() == "Rook") {ofs<<"wR"<<i<<j<<endl; }
            if (myName() == "King") {ofs<<"wK"<<i<<j<<endl; }
            if (myName() == "Pawn") {ofs<<"wP"<<i<<j<<endl; }
            if (myName() == "Knight") {ofs<<"wG"<<i<<j<<endl; }
            if (myName() == "Queen") {ofs<<"wQ"<<i<<j<<endl; }
            if (myName() == "Bishop") {ofs<<"wB"<<i<<j<<endl; }
         }
			else 
         {
             color = "black"; 
             piece = (*currentBoard)[i][j].currentPiece->myName();
            if (myName() == "Rook") {ofs<<"bR"<<i<<j<<endl; }
            if (myName() == "King") {ofs<<"bK"<<i<<j<<endl; }
            if (myName() == "Pawn") {ofs<<"bP"<<i<<j<<endl; }
            if (myName() == "Knight") {ofs<<"bG"<<i<<j<<endl; }
            if (myName() == "Queen") {ofs<<"bQ"<<i<<j<<endl; }
            if (myName() == "Bishop") {ofs<<"bB"<<i<<j<<endl; }
         }
		}
	}
   createNextMessage("Game saved as " + file_name + "\n");
   else
   {
      cout << "Error creating file! Save failed\n";
   }
   ofs.close(); 
return;
}
