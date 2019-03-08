
#include "chess.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

Chess::Chess(string name1, string name2)
{
	ptrToWhiteKing = new King("white");
	ptrToBlackKing = new King("black");
	ptrToWhiteQueen = new Queen("white");
	ptrToBlackQueen = new Queen("black");
	ptrToWhiteBishop1 = new Bishop("white");
	ptrToWhiteBishop2 = new Bishop("white");
	ptrToBlackBishop1 = new Bishop("black");
	ptrToBlackBishop2 = new Bishop("black");
	ptrToWhiteKnight1 = new Knight("white");
	ptrToWhiteKnight2 = new Knight("white");
	ptrToBlackKnight1 = new Knight("black");
	ptrToBlackKnight2 = new Knight("black");
	ptrToWhiteRook1 = new Rook("white");
	ptrToWhiteRook2 = new Rook("white");
	ptrToBlackRook1 = new Rook("black");
	ptrToBlackRook2 = new Rook("black");
	ptrToBoard = new Board[1][8][8];
	for (int i = 0; i < 8; i++)
	{
		whitePawns[i] = new Pawn("white");
	}
	for (int i = 0; i < 8; i++)
	{
		blackPawns[i] = new Pawn("black");
	}
	whitePieces[0] = ptrToWhiteRook1;
	whitePieces[1] = ptrToWhiteKnight1;
	whitePieces[2] = ptrToWhiteBishop1;
	whitePieces[3] = ptrToWhiteQueen;
	whitePieces[4] = ptrToWhiteKing;
	whitePieces[5] = ptrToWhiteBishop2;
	whitePieces[6] = ptrToWhiteKnight2;
	whitePieces[7] = ptrToWhiteRook2;

	blackPieces[0] = ptrToBlackRook1;
	blackPieces[1] = ptrToBlackKnight1;
	blackPieces[2] = ptrToBlackBishop1;
	blackPieces[3] = ptrToBlackQueen;
	blackPieces[4] = ptrToBlackKing;
	blackPieces[5] = ptrToBlackBishop2;
	blackPieces[6] = ptrToBlackKnight2;
	blackPieces[7] = ptrToBlackRook2;
	for (int i = 0; i < 8; i++)
	{
		blackPieces[8 + i] = blackPawns[i];
		whitePieces[8 + i] = whitePawns[i];
	}
	/*ptrToWhitePawn1 = new Pawn("white");
	ptrToWhitePawn2 = new Pawn("white");
	ptrToWhitePawn3 = new Pawn("white");
	ptrToWhitePawn4 = new Pawn("white");
	ptrToWhitePawn5 = new Pawn("white");
	ptrToWhitePawn6 = new Pawn("white");
	ptrToWhitePawn7 = new Pawn("white");
	ptrToWhitePawn8 = new Pawn("white");
	ptrToBlackPawn1 = new Pawn("black");
	ptrToBlackPawn2 = new Pawn("black");
	ptrToBlackPawn3 = new Pawn("black");
	ptrToBlackPawn4 = new Pawn("black");
	ptrToBlackPawn5 = new Pawn("black");
	ptrToBlackPawn6 = new Pawn("black");
	ptrToBlackPawn7 = new Pawn("black");
	ptrToBlackPawn8 = new Pawn("black");*/
	whiteToPlay = true;
	isOver = false;
	whitePlayerName = name1;
	blackPlayerName = name2;
	limboPiece = ptrToNoPiece;
	lastMove = "NULL";
	this->currentBoard = ptrToBoard;
	pawnDoubleStep = false;
	initializeBoard();
}
Chess::~Chess()
{
	for (int i = 0; i < 16; i++)
	{
		delete whitePieces[i];
		delete blackPieces[i];
	}
	delete ptrToBoard;
}
Chess::Chess(Chess&obj) 
{
	//std::cout << "copy construtor called.";
	ptrToWhiteKing = new King(*obj.ptrToWhiteKing);
	ptrToBlackKing = new King(*obj.ptrToBlackKing);
	ptrToWhiteQueen = new Queen(*obj.ptrToWhiteQueen);
	ptrToBlackQueen = new Queen(*obj.ptrToBlackQueen);
	ptrToWhiteBishop1 = new Bishop(*obj.ptrToWhiteBishop1);
	ptrToWhiteBishop2 = new Bishop(*obj.ptrToWhiteBishop2);
	ptrToBlackBishop1 = new Bishop(*obj.ptrToBlackBishop1);
	ptrToBlackBishop2 = new Bishop(*obj.ptrToBlackBishop2);
	ptrToWhiteKnight1 = new Knight(*obj.ptrToWhiteKnight1);
	ptrToWhiteKnight2 = new Knight(*obj.ptrToWhiteKnight2);
	ptrToBlackKnight1 = new Knight(*obj.ptrToBlackKnight1);
	ptrToBlackKnight2 = new Knight(*obj.ptrToBlackKnight2);
	ptrToWhiteRook1 = new Rook(*obj.ptrToWhiteRook1);
	ptrToWhiteRook2 = new Rook(*obj.ptrToWhiteRook2);
	ptrToBlackRook1 = new Rook(*obj.ptrToBlackRook1);
	ptrToBlackRook2 = new Rook(*obj.ptrToBlackRook2);
	
	ptrToBoard = new Board[1][8][8];
	moveSet = obj.moveSet;
	//checking 
	//std::cout <<"Rookas name: " <<(obj.ptrToBlackRook2)->myName();
	//(*ptrToBoard)[0][0].currentPiece = obj.ptrToBlackRook1;
	//SDL_Delay(1000);
	for (int i = 0; i < 8; i++)
	{
		whitePawns[i] = new Pawn(*obj.whitePawns[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		blackPawns[i] = new Pawn(*obj.blackPawns[i]);
	}

	whitePieces[0] = ptrToWhiteRook1;
	whitePieces[1] = ptrToWhiteKnight1;
	whitePieces[2] = ptrToWhiteBishop1;
	whitePieces[3] = ptrToWhiteQueen;
	whitePieces[4] = ptrToWhiteKing;
	whitePieces[5] = ptrToWhiteBishop2;
	whitePieces[6] = ptrToWhiteKnight2;
	whitePieces[7] = ptrToWhiteRook2;

	blackPieces[0] = ptrToBlackRook1;
	blackPieces[1] = ptrToBlackKnight1;
	blackPieces[2] = ptrToBlackBishop1;
	blackPieces[3] = ptrToBlackQueen;
	blackPieces[4] = ptrToBlackKing;
	blackPieces[5] = ptrToBlackBishop2;
	blackPieces[6] = ptrToBlackKnight2;
	blackPieces[7] = ptrToBlackRook2;
	for (int i = 0; i < 8; i++)
	{
		blackPieces[8 + i] = blackPawns[i];
		whitePieces[8 + i] = whitePawns[i];
	}


	whiteToPlay = obj.whiteToPlay;
	isOver = obj.isOver;
	whitePlayerName = obj.whitePlayerName;
	blackPlayerName = obj.blackPlayerName;
	limboPiece = obj.limboPiece;
	lastMove = obj.lastMove;
	//Emptying Board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			(*ptrToBoard)[i][j].currentPiece = ptrToNoPiece;
		}
	}

	//copyBoard(obj.ptrToBoard);
	//initializeBoard();

	int wrook=0;
	int wknight=0;
	int wbishop = 0;
	int brook = 0;
	int bknight = 0;
	int bbishop = 0;
	int wpawn = 0;
	int bpawn = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((*obj.ptrToBoard)[i][j].currentPiece->myName() == "OnePiece")
			{
				//(*ptrToBoard)[8][8].currentPiece = ptrToNoPiece;
			}
			else if ((*obj.ptrToBoard)[i][j].currentPiece->myName() == "King")
			{
				if ((*obj.ptrToBoard)[i][j].currentPiece->getColor())
					(*ptrToBoard)[i][j].currentPiece = ptrToWhiteKing;
				else
					(*ptrToBoard)[i][j].currentPiece = ptrToBlackKing;
			}
			else if ((*obj.ptrToBoard)[i][j].currentPiece->myName() == "Queen")
			{
				if ((*obj.ptrToBoard)[i][j].currentPiece->getColor())
					(*ptrToBoard)[i][j].currentPiece = ptrToWhiteQueen;
				else
					(*ptrToBoard)[i][j].currentPiece = ptrToBlackQueen;
			}
			else if ((*obj.ptrToBoard)[i][j].currentPiece->myName() == "Bishop")
			{
				
				if ((*obj.ptrToBoard)[i][j].currentPiece->getColor())
				{
					if (wbishop == 0)
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToWhiteBishop1;
						wbishop = 1;
					}
					else
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToWhiteBishop2;
					}
				}

				else
				{
					if (bbishop == 0)
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToBlackBishop1;
						bbishop = 1;
					}
					else
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToBlackBishop2;
					}
				}
			}
			else if ((*obj.ptrToBoard)[i][j].currentPiece->myName() == "Knight")
			{

				if ((*obj.ptrToBoard)[i][j].currentPiece->getColor())
				{
					if (wknight == 0)
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToWhiteKnight1;
						wknight = 1;
					}
					else
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToWhiteKnight2;
					}
				}

				else
				{
					if (bknight == 0)
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToBlackKnight1;
						bknight = 1;
					}
					else
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToBlackKnight2;
					}
				}
			}
			else if ((*obj.ptrToBoard)[i][j].currentPiece->myName() == "Rook")
			{

				if ((*obj.ptrToBoard)[i][j].currentPiece->getColor())
				{
					if (wrook == 0)
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToWhiteRook1;
						wrook = 1;
					}
					else
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToWhiteRook2;
					}
				}

				else
				{
					if (brook == 0)
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToBlackRook1;
						brook = 1;
					}
					else
					{
						(*ptrToBoard)[i][j].currentPiece = ptrToBlackRook2;
					}
				}
			}
			else if ((*obj.ptrToBoard)[i][j].currentPiece->myName() == "Pawn")
			{
				if ((*obj.ptrToBoard)[i][j].currentPiece->getColor())
				{
					(*ptrToBoard)[i][j].currentPiece = whitePawns[wpawn];
					wpawn++;
				}
				else
				{
					(*ptrToBoard)[i][j].currentPiece = blackPawns[bpawn];
					bpawn++;
				}
			}
			
		}
	}
	this->currentBoard = ptrToBoard;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

		}
	}
	//(*ptrToBoard)[0][0].currentPiece = ptrToBlackRook1;
	pawnDoubleStep = obj.pawnDoubleStep;
}


auto Chess::getBoard()
{
	return ptrToBoard;
}
bool Chess::getCurrentPlayer() const { return whiteToPlay; }
bool Chess::isChessOver() const
{
	return isOver;
}

void Chess::changeTurn()
{
	whiteToPlay = !whiteToPlay;
}
void Chess::reset()
{
	whiteToPlay = true;
	lastMove = "";
	pawnDoubleStep = false;
	pawnEnPassant = false;
	enPassantPawnPosforRessurect = "";
}
int Chess::moveToEmptySquare(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow= source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	Piece *sourcePiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	bool canMove = 0;
	if (sourcePiece->movesInEmptyBoard(source, destination) == 1) { canMove = 1; }
	int pathIsNotBlocked = isNotBlocked(choosenMove);
	if (!canMove)
	{
		//std::cout << "I cant move " << sourcePiece->myName() << "in here" << "from " << source << "to " << destination << "\n";
	}
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	string sourcePieceName = sourcePiece->myName();
	//std::cout << canMove;
	bool resultsInCheck = 0;
	
	if (canMove && playerMatchesPiece && pathIsNotBlocked)
	{
		//std::cerr << "I am in move to empty square";
		(*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
		(*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece = ptrToNoPiece;
		limboPiece = ptrToNoPiece;
		lastMove = choosenMove;
		//string destinationPosition = (*currentBoard)[destinationRow-1][destinationFile-1].getMyLocation();
		//(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece->setCurrentPosition(destinationPosition);
		//std::cout << "Move done Successfully\n";
		//std::cout << sourcePieceName << " moved from " << source << " to " << destination << "\n";
		return 1;
	}
	else
	{
		if (playerMatchesPiece == 0)
		{
			std::cout << "You cant move piece of opponent. \n";
		}
		else if (canMove == 0)
		{
			//std::cout << "Not a Valid Move\n";
		}
		else if (!pathIsNotBlocked)
		{
			std::cout << "There is something in the path";
		}
		return 0;
	}
	
}
int Chess::canMoveHere(string choosenMove)
{
	/*string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow = source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	*/
	Position source(choosenMove.substr(0, 2));
	Position destination(choosenMove.substr(2, 2));
	Piece *sourcePiece = (*currentBoard)[source.x - 1][source.y - 1].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destination.x - 1][destination.y - 1].currentPiece;
	bool canMove = 0;
	if (sourcePiece->movesInEmptyBoard(source.getString(), destination.getString()) == 1) { canMove = 1; }
	int pathIsNotBlocked = isNotBlocked(choosenMove);
	int destinationIsEmpty = (destinationPiece->myName() =="OnePiece");
	if (!canMove)
	{
		//std::cout << "I cant move " << sourcePiece->myName() << "in here" << "from " << source.getString() << "to " << destination.getString() << "\n";
	}
bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
string sourcePieceName = sourcePiece->myName();
//std::cout << canMove;

return (canMove && playerMatchesPiece && pathIsNotBlocked && destinationIsEmpty);
}
int Chess::capture(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow = source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	Piece *sourcePiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece;
	bool canMove;
	dynamic_cast <Pawn*>(sourcePiece)->promoted;
	if (sourcePiece->myName() == "Pawn" && !(dynamic_cast <Pawn*>(sourcePiece)->promoted))
	{
		std::cout << "I am here pawn capture";
		std::cout << "The function returns " << (sourcePiece->movesInEmptyBoard(source, destination) == 2);
		canMove = (sourcePiece->movesInEmptyBoard(source, destination) == 2);
	}
	else
	{
		canMove = (sourcePiece->movesInEmptyBoard(source, destination));
	}
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	bool isOpponentPiece = (getCurrentPlayer() != destinationPiece->getColor());
	//std::cout << canMove;

	if (canMove && playerMatchesPiece && isOpponentPiece && isNotBlocked(choosenMove))
	{

		destinationPiece->kill();
		limboPiece = destinationPiece;
		//(*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece = ptrToNoPiece;
		(*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
		(*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece = ptrToNoPiece;
		//string destinationPosition = (*currentBoard)[destinationRow-1][destinationFile-1].getMyLocation();
		//(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece->setCurrentPosition(destinationPosition);
		std::cout << "Move done Successfully\n";
		std::cout << "you captured " << destinationPiece->myName() << " in " << destination << "with " << sourcePiece->myName() << " in " << source << "\n";
		return 1;
	}
	else
	{
		if (playerMatchesPiece == 0)
		{
			std::cout << "You cant move piece of opponent. \n";
		}
		else if (canMove == 0)
		{
			std::cout << "Not a Valid Move\n";
		}
		return 0;
	}
}
int Chess::castle(string choosenMove)
{
	Position source;
	return 0;
}

int Chess::undo()
{
	if (!lastMove.empty() && canUndo)
	{
		Position source(lastMove.substr(0, 2));
		Position destination(lastMove.substr(2, 2));
		limboPiece->resurrect();
		(*currentBoard)[source.x - 1][source.y - 1].currentPiece = (*currentBoard)[destination.x - 1][destination.y - 1].currentPiece;
		(*currentBoard)[destination.x - 1][destination.y - 1].currentPiece = ptrToNoPiece;
		if (pawnEnPassant) { (*currentBoard)[enPassantPawnPosforRessurect[1] - '1'][enPassantPawnPosforRessurect[0] - 'a'].currentPiece = limboPiece; }
		else { (*currentBoard)[destination.x - 1][destination.y - 1].currentPiece = limboPiece; }
		//lastMove = "";
		lastMove = lastMove2;
		pawnDoubleStep = pawnDoubleStep2;
		//if (pawnEnPassant) { pawnDoubleStep = true; }
		changeTurn();
		canUndo = false;
		return 1;
	}
	else
	{
		std::cout << "Cant undo\n";
		return 0;
	}

}
string Chess::getKing(Color color)
{
	string king;
	int k = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((*ptrToBoard)[i][j].currentPiece->myName() == "King")
			{
				if ((*ptrToBoard)[i][j].currentPiece->getColor()==color)
				{
					king.push_back(j + 'a');
					king.push_back(i + '1');
					k++;
				}
				if (k == 2) break;
			}
		}
		if (k == 2) break;
	}
	return king;
}
int Chess::execute(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	Position sourcePos(source);
	Position destinationPos(destination);
	int sourceFile = source[0] - 'a';
	int sourceRow = source[1] - '1';
	int destinationFile = destination[0] - 'a';
	int destinationRow = destination[1] - '1';
	Piece *sourcePiece = (*currentBoard)[sourceRow][sourceFile].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destinationRow][destinationFile].currentPiece;
	pawnEnPassant2 = pawnEnPassant;
	pawnEnPassant = false;
	/*if (sourcePiece->myName() == "King" && sourcePos.x == destinationPos.x && abs(sourcePos.y - destinationPos.y) == 2)
	{
		std::cout << "Castle Selected\n";
		if (castle(choosenMove))
		{
			return 1;
		}
		else
		{
			std::cerr << "Cant castle\n";
		}
	}
	else */
	if (destinationPiece->myName() == "OnePiece")
	{
		//std::cout << "Sending move to empty square\n";
		if (pawnDoubleStep && choosenMove[1] == lastMove[3] && abs(choosenMove[0] - lastMove[2]) == 1 && choosenMove[2] == lastMove[2] )
		{
			//std::cout << "first condiyion000000000";
			if ((sourcePiece->getColor() && sourceRow == 4 /*&& choosenMove[2] == lastMove2[2]*/ && choosenMove[3] - lastMove[3] == 1) || (!sourcePiece->getColor() && sourceRow == 3 /*&& choosenMove[2] == lastMove2[2]*/ && lastMove[3] - choosenMove[3] == 1))
			{
				//std::cout << "second condiyion000000000";
				(*currentBoard)[destinationRow][destinationFile].currentPiece = (*currentBoard)[sourceRow][sourceFile].currentPiece;
				(*currentBoard)[sourceRow][sourceFile].currentPiece = ptrToNoPiece;
				limboPiece = (*currentBoard)[lastMove[3] - '1'][lastMove[2] - 'a'].currentPiece;
				(*currentBoard)[lastMove[3] - '1'][lastMove[2] - 'a'].currentPiece = ptrToNoPiece;
				enPassantPawnPosforRessurect = lastMove.substr(2, 2);
				pawnEnPassant2 = pawnEnPassant;
				pawnEnPassant = true;
				return 1;
			}
			/*else if (!sourcePiece->getColor() && sourceRow == 3 && choosenMove[2] == lastMove2[2] && lastMove2[3] - choosenMove[3] == 1) { return true; }
			return false;
			if (enPassantValidity(choosenMove))
			{
				(*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
				(*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece = ptrToNoPiece;
				(*currentBoard)[lastMove[3] - '1'][lastMove[2] - 'a'].currentPiece = ptrToNoPiece;
				return 1;
			}*/
		}
		else if (moveToEmptySquare(choosenMove))
		{
			if (destinationPiece->myName() == "Pawn")
			{
				if (destinationPiece->getColor())
				{
					if (destinationRow == 7)
					{
						dynamic_cast<Pawn*>(destinationPiece)->promote("Queen");
					}
				}
				else
				{
					if (destinationRow == 0)
					{
						dynamic_cast<Pawn*>(destinationPiece)->promote("Queen");
					}
				}
			}
			if (isKingInCheck(getCurrentPlayer()))
			{
				std::cout << "King is checked. Undoing\n";
				return 2;
			}
			
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (destinationPiece->myName()!="OnePiece" && destinationPiece->getColor()!=getCurrentPlayer())
	{
		//std::cout << "Sending move to capture\n";
		if (capture(choosenMove))
		{
			if (destinationPiece->myName() == "Pawn")
			{
				if (destinationPiece->getColor())
				{
					if (destinationRow == 7)
					{
						dynamic_cast<Pawn*>(destinationPiece)->promote("Queen");
					}
				}
				else
				{
					if (destinationRow == 0)
					{
						dynamic_cast<Pawn*>(destinationPiece)->promote("Queen");
					}
				}
			}
			if (isKingInCheck(getCurrentPlayer()))
			{
				std::cout << "King is checked. Undoing\n";
				return 2;
			}
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		std::cout << "It is neither capture nor move";
		return 0;
	}
	
	bool canMove = sourcePiece->movesInEmptyBoard(source, destination);
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	bool isOpponentPiece = (getCurrentPlayer() != destinationPiece->getColor());


}
int Chess::checkState()
{
	int player = getCurrentPlayer();
	//std::cout << "Current turn: " << (getCurrentPlayer() ? "White" : "Black") << "\n";
	string king = getKing(static_cast<Color>(player));
	//std::cout << "I got kings position in checking state as : " << king << "\n";
	vector<string> moves = validMoves(king);
	/*std::cout << "\n\n***********************************\n\n";
	for (int i = 0; i < moves.size(); i++)
	{
		
		std::cout << moves[i] << "\n";
	}
	std::cout << "******************************\n";*/
	if (isKingInCheck(player) && moves.empty())
	{
		return !getCurrentPlayer();
	}
	else
	{
		return 2;
	}
	//if (*currentBoard)[0][5].currentPiece != noPiece;
}
void Chess::endChess()
{
	isOver = true;
}
int Chess::isNotBlocked(string choosenMove)
{
	string sourceString = choosenMove.substr(0, 2);
	string destinationString = choosenMove.substr(2, 2);
	Position source(sourceString);
	Position destination(destinationString);
	bool inStraightLine = (source.x == destination.x) || (source.y == destination.y);
	int verticalDifference = abs(source.x - destination.x);
	int horizontalDifference = abs(source.y - destination.y);
	bool inDiagonalLine = (verticalDifference == horizontalDifference);
	bool blocked = false;
	if (inStraightLine)
	{
		//std::cout << "Source and destination " << source.x << "," << source.y << ":"<<destination.x << "," << destination.y<<"\n";
		int currX;
		int currY;
		if (source.x == destination.x && source.y == destination.y)
		{
			blocked = false;
		}
		else if (source.x == destination.x)
		{
			//std::cout << "Here the rows of source and destiantion are same.";
			if (abs(source.y - destination.y) == 1)
			{
				//std::cout << "The move takes place in adjacent square so block is false.";
				blocked = false;
			}
			else
			{
				
				if (source.y < destination.y)
				{
					currX = source.x;
					currY = source.y+1;
				
					
					while (currY < destination.y)
					{
						if ((*currentBoard)[currX-1][currY-1].currentPiece != ptrToNoPiece)
						{
							//std::cout << ((*currentBoard)[currX-1][currY-1].currentPiece->myName());
							//std::cout << " blocks the path first \n";
							blocked = true;
							break;
						}
						currY++;
					}
				}
				else if (source.y > destination.y)
				{
					currX = source.x;
					currY = source.y - 1;
					//std::cout << "Here currX and y" << currX << " " << currY;
					while (currY > destination.y)
					{
						if ((*currentBoard)[currX-1][currY-1].currentPiece != ptrToNoPiece)
						{
							//std::cout << ((*currentBoard)[currX-1][currY-1].currentPiece->myName());
							//std::cout << " blocks the 2nd  path\n";
							blocked = true;
							break;
						}
						currY--;
					}
				}
				else if (source.y==destination.y)
				{
					std::cout << "This place shouldnt be reached. ";
				}
			}

			
		}
		else if (source.y == destination.y)
		{
			//std::cout << "Here the column are equal";
			//std::cout << "pawn double step here?\n";
			if (abs(source.x - destination.x) == 1)
			{
				//std::cout << "The move takes place in adjacent square so block is false.";
				blocked = false;
			}
			else
			{
				//std::cout << "Address of ptrToNoPiece inside isNotBlocked: " << ptrToNoPiece << "||\n";
				if (source.x < destination.x)
				{
					//std::cout << "source row is less\n";
					currX = source.x  +1;
					currY = source.y;
					//currX += 1;
					while (currX < destination.x)
					{
						//std::cout << "CurrX :" << currX << "\n";
						if ((*currentBoard)[currX-1][currY-1].currentPiece != ptrToNoPiece)
						{
							//std::cout << ((*currentBoard)[currX-1][currY-1].currentPiece->myName());
							//std::cout << " blocks the path column \n";
							//std::cout << "I am blocked here\n";
							blocked = true;
							break;
						}
						currX++;
					}
				}
				else if (source.x > destination.x)
				{
					currX = source.x-1;
					currY = source.y;
					while (currX > destination.x)
					{
						if ((*currentBoard)[currX-1][currY-1].currentPiece != ptrToNoPiece)
						{
							//std::cout << ((*currentBoard)[currX-1][currY-1].currentPiece->myName());
							//std::cout << currX << " " << currY << " ";
							//std::cout << " blocks the path pathe\n";
							blocked = true;
							
						}
						currX--;
					}
				}
				else if (source.x == destination.x)
				{
					std::cout << "This place shouldnt be reached. ";
				}
			}

		}
	}
	else if (inDiagonalLine)
	{
		//std::cout << "Source and destination " << source.x << "," << source.y << "\n";
		int currX;
		int currY;
		if (source.x == destination.x && source.y == destination.y)
		{
			blocked = false;
		}
		else if (abs(source.x-destination.x)==1)
		{
			blocked = false;
		}
		else
		{
			int movX;
			int movY;
			movX = (source.x < destination.x) ? 1 : -1;
			movY = (source.y < destination.y) ? 1 : -1;
			currX = source.x+ movX;
			currY = source.y + movY;
			//std::cout << "movX:" << movX << " movY:" << movY << " currX:" << currX << " currY" << currY << "\n";
			while (abs(currX - destination.x) > 0)
			{
				if (((*currentBoard)[currX - 1][currY - 1].currentPiece != ptrToNoPiece))
				{
					//std::cout << (*currentBoard)[currX - 1][currY - 1].currentPiece->myName() << " blocks the path\n";
					//std::cout << "I am inside if";
					blocked = true;
					break;
				}
				currX = currX+ movX;
				currY = currY + movY;
				//std::cout << "I am inside while after incrementing. " << "currX:" << currX << " currY:" << currY << " \n";
				//SDL_Delay(1000);
			}
		}
	}
	else
	{
	blocked = false;
	}
	
	return !blocked;
}

bool rookRepeatDecider(string temp, int tempNum)
{
	bool repeat;
	if (tempNum == 0)
	{
		if (temp[1] == 'R')
		{
			repeat = true;
		}
		else { repeat = false; }
	}
	else if (tempNum == 7)
	{
		if (temp[6] == 'R')
		{
			repeat = true;
		}
		else { repeat = false; }
	}
	else
	{
		if (temp[tempNum - 1] == 'R' || temp[tempNum + 1] == 'R')
		{
			repeat = true;
		}
		else { repeat = false; }
	}
	return repeat;
}
string Chess::getPiecesConfig()
{

	string temp = "00000000";
	int tempNum, posTemp[2];
	bool rookPosGenRepeat = false;
	srand(time(NULL));
	tempNum = rand() % 8;
	temp[tempNum] = 'R';
	posTemp[0] = tempNum;
	piecesIntValue[0] = tempNum;
	tempNum = rand() % 8;
	rookPosGenRepeat = rookRepeatDecider(temp, tempNum);
	while (temp[tempNum] != '0' || rookPosGenRepeat)
	{
		tempNum = rand() % 8;
		rookPosGenRepeat = rookRepeatDecider(temp, tempNum);
	}
	temp[tempNum] = 'R';
	piecesIntValue[1] = tempNum;
	posTemp[1] = tempNum;
	tempNum = rand() % (abs(posTemp[1] - posTemp[0]) - 1);
	if (posTemp[1] > posTemp[0])
	{
		temp[posTemp[0] + tempNum + 1] = 'K';
		piecesIntValue[2] = posTemp[0] + tempNum + 1;
	}
	else
	{
		temp[posTemp[1] + tempNum + 1] = 'K';
		piecesIntValue[2] = posTemp[1] + tempNum + 1;
	}
	tempNum = rand() % 4;
	while (temp[2 * tempNum] != '0')
	{
		tempNum = rand() % 4;
	}
	temp[2 * tempNum] = 'B';
	piecesIntValue[3] = tempNum * 2;
	tempNum = rand() % 4;
	while (temp[2 * tempNum + 1] != '0')
	{
		tempNum = rand() % 4;
	}
	temp[2 * tempNum + 1] = 'B';
	piecesIntValue[4] = tempNum * 2 + 1;
	tempNum = rand() % 8;
	for (int i = 0; i < 2; i++)
	{
		while (temp[tempNum] != '0')
		{
			tempNum = rand() % 8;
		}
		temp[tempNum] = 'N';
		piecesIntValue[5 + i] = tempNum;
		tempNum = rand() % 8;
	}
	for (int i = 0; i < 8; i++)
	{
		if (temp[i] == '0')
		{
			temp[i] = 'Q';
			piecesIntValue[7] = i;
			break;
		}
	}
	return temp;
}

int Chess::initializeBoard()
{
	//setBoard(*ptrToBoard, ptrToNoPiece);
	string locationData = (*this).getPiecesConfig();
	Board(*myBoard)[8][8] = ptrToBoard;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			(*myBoard)[i][j].currentPiece = ptrToNoPiece;
		}
	}
	std::cout << "Value of ptrToNoPiece in intitializeBoard:" << ptrToNoPiece;

	/*(*myBoard)[0][4].currentPiece = ptrToWhiteKing;
	(*myBoard)[7][4].currentPiece = ptrToBlackKing;
	(*myBoard)[0][3].currentPiece = ptrToWhiteQueen;
	(*myBoard)[7][3].currentPiece = ptrToBlackQueen;
	(*myBoard)[0][2].currentPiece = ptrToWhiteBishop1;
	(*myBoard)[0][5].currentPiece = ptrToWhiteBishop2;
	(*myBoard)[7][2].currentPiece = ptrToBlackBishop1;
	(*myBoard)[7][5].currentPiece = ptrToBlackBishop2;
	(*myBoard)[0][1].currentPiece = ptrToWhiteKnight1;
	(*myBoard)[0][6].currentPiece = ptrToWhiteKnight2;
	(*myBoard)[7][1].currentPiece = ptrToBlackKnight1;
	(*myBoard)[7][6].currentPiece = ptrToBlackKnight2;
	(*myBoard)[0][0].currentPiece = ptrToWhiteRook1;
	(*myBoard)[0][7].currentPiece = ptrToWhiteRook2;
	(*myBoard)[7][0].currentPiece = ptrToBlackRook1;
	(*myBoard)[7][7].currentPiece = ptrToBlackRook2;
	(*myBoard)[7][7].currentPiece = ptrToBlackRook2;*/

	
	(*myBoard)[0][piecesIntValue[2]].currentPiece = ptrToWhiteKing;
	(*myBoard)[7][piecesIntValue[2]].currentPiece = ptrToBlackKing;
	(*myBoard)[0][piecesIntValue[7]].currentPiece = ptrToWhiteQueen;
	(*myBoard)[7][piecesIntValue[7]].currentPiece = ptrToBlackQueen;
	(*myBoard)[0][piecesIntValue[3]].currentPiece = ptrToWhiteBishop1;
	(*myBoard)[0][piecesIntValue[4]].currentPiece = ptrToWhiteBishop2;
	(*myBoard)[7][piecesIntValue[3]].currentPiece = ptrToBlackBishop1;
	(*myBoard)[7][piecesIntValue[4]].currentPiece = ptrToBlackBishop2;
	(*myBoard)[0][piecesIntValue[5]].currentPiece = ptrToWhiteKnight1;
	(*myBoard)[0][piecesIntValue[6]].currentPiece = ptrToWhiteKnight2;
	(*myBoard)[7][piecesIntValue[5]].currentPiece = ptrToBlackKnight1;
	(*myBoard)[7][piecesIntValue[6]].currentPiece = ptrToBlackKnight2;
	(*myBoard)[0][piecesIntValue[0]].currentPiece = ptrToWhiteRook1;
	(*myBoard)[0][piecesIntValue[1]].currentPiece = ptrToWhiteRook2;
	(*myBoard)[7][piecesIntValue[0]].currentPiece = ptrToBlackRook1;
	(*myBoard)[7][piecesIntValue[1]].currentPiece = ptrToBlackRook2;
	
	for (int i = 0; i < 8; i++)
	{
		(*myBoard)[1][i].currentPiece = whitePawns[i];
	}
	for (int i = 0; i < 8; i++)
	{
		(*myBoard)[6][i].currentPiece = blackPawns[i];
	}
	return 1;
}
int Chess::isAttacked(bool colorOfAttacker,string position)
{
	Position pos(position);
	bool result=0;
	for (char row = 0; row < 8; row++)
	{
		for (char col = 0; col < 8; col++)
		{
			string source;
			source.push_back(col + 'a');
			source.push_back(row + '1');
			if (result = canCapture(colorOfAttacker, source + position)) //This is assignment and not comparision
			{
				//std::cout << (*currentBoard)[row][col].currentPiece->myName() << " can captrue on e1 from isAttacked\n";
				result = 1;
				return 1;
				break;
			}
			else
			{
				//std::cout << "Cant capture reutrned 0;";
				//std::cout << (*currentBoard)[row][col].currentPiece->myName() << " cant captrue on e1\n";

			}
			
		}
	}
	return result;
}
int Chess::canCapture(bool colorOfAttacker,string choosenMove)
{
	Position source(choosenMove.substr(0, 2));
	Position destination(choosenMove.substr(2, 2));
	//std::cout << "current string in loop" << choosenMove;

	Piece *sourcePiece = (*currentBoard)[source.x - 1][source.y - 1].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destination.x - 1][destination.y - 1].currentPiece;
	bool canMove;
	if (sourcePiece->myName() == "Pawn")
	{
		//std::cout << "I am here pawn capture";
		//std::cout << "The function returns " << (sourcePiece->movesInEmptyBoard(choosenMove.substr(0,2),choosenMove.substr(1,2)) == 2);
		canMove = (sourcePiece->movesInEmptyBoard(choosenMove.substr(0, 2), choosenMove.substr(2, 2)) == 2);
	}
	else
	{
		canMove = (sourcePiece->movesInEmptyBoard(choosenMove.substr(0, 2), choosenMove.substr(2, 2)));
	}
	bool playerMatchesPiece = (colorOfAttacker == sourcePiece->getColor());
	bool isOpponentPiece = (sourcePiece->getColor() != destinationPiece->getColor());
	if (canMove  && playerMatchesPiece && isOpponentPiece && isNotBlocked(choosenMove))
	{
		//std::cout << "I am in capture checking. \n";
		return 1;
	}
	else
	{
		return 0;
	}
}

int Chess::isKingInCheck(bool color)
{
	Position kingPosition;
	for (char row = 0; row< 8; row++)
	{
		for (char col = 0; col < 8; col++)
		{
			Piece *currentPiece = (*currentBoard)[row][col].currentPiece;
			if (currentPiece->myName() == "King" && currentPiece->getColor() == color)
			{
				kingPosition.x = row + 1;
				kingPosition.y = col + 1;
			}
		}
	}
	
	//std::cout << "King is in " << kingPosition.getString() << "\n";
	int result= isAttacked(!color, kingPosition.getString());
	//std::cout << "is attacked returns " << result << "\n";
	return result;

}
vector <string> Chess:: validMoves(string source)
{
	vector <string> moves;
	vector <string>validatedMoves;
	for (int i = 0; i < 8; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			string move = source;
			move.push_back(j + 'a');
			move.push_back(i + '1');
			//std::cout << "Move: " << move << "\n";
			if (canMoveHere(move) || canCapture(getCurrentPlayer(), move))
			{
				moves.push_back(move);
			}
			else
			{
				//std::cout << "i cant";
			}

		}
	}
	/*std::cout << "Without validating Moves\n";
	std::cout << "\n\n***********************************\n\n";
	for (int i = 0; i < moves.size(); i++)
	{

		std::cout << moves[i] << "\n";
	}
	std::cout << "******************************\n";*/
	for (int i = 0; i < moves.size(); i++)
	{
		Chess *temp = new Chess(*this);
		if (temp->execute(moves[i]) != 2)
		{
			validatedMoves.push_back(moves[i]);
		}
		delete temp;

	}
	//int temp;
	//std::cin >> temp;
	return validatedMoves;
}

void Chess::save()
{
	string color, piece;
	string file_name;
	/*cout << "Type file name to be saved(no extension):";

	getline(cin, filename);*/
	file_name = "state.dat";

	std::ofstream ofs(file_name);
	if (ofs.is_open())
	{
		// Write the date and time of save operation 
		/*auto time_now = std::chrono::system_clock::now();
		std::time_t end_time = std::chrono::system_clock::to_time_t(time_now);
		ofs << "[Chess console] Saved at: " << std::ctime(&end_time);*/

		// Write the moves

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((*currentBoard)[i][j].currentPiece->getColor())
				{
					//color = "white";
					piece = (*currentBoard)[i][j].currentPiece->myName();
					if (piece == "Rook") { ofs << "wR" << i << j << std::endl; }
					if (piece == "King") { ofs << "wK" << i << j << std::endl; }
					if (piece == "Pawn") { ofs << "wP" << i << j << std::endl; }
					if (piece == "Knight") { ofs << "wG" << i << j << std::endl; }
					if (piece == "Queen") { ofs << "wQ" << i << j << std::endl; }
					if (piece == "Bishop") { ofs << "wB" << i << j << std::endl; }
				}
				else
				{
					//color = "black";
					piece = (*currentBoard)[i][j].currentPiece->myName();
					if (piece == "Rook") { ofs << "bR" << i << j << std::endl; }
					if (piece == "King") { ofs << "bK" << i << j << std::endl; }
					if (piece == "Pawn") { ofs << "bP" << i << j << std::endl; }
					if (piece == "Knight") { ofs << "bG" << i << j << std::endl; }
					if (piece == "Queen") { ofs << "bQ" << i << j << std::endl; }
					if (piece == "Bishop") { ofs << "bB" << i << j << std::endl; }
				}
			}
		}
		std::cout << "Game saved as " << file_name;
	}
	else
	{
		std::cout << "Error creating file! Save failed\n";
	}
	ofs.close();
	return;
}

/*bool Chess::enPassantValidity(string piece)
{
	int sourceFile = piece[0] - 'a';
	int sourceRow = piece[1] - '1';
	int destinationFile = piece[2] - 'a';
	int destinationRow = piece[3] - '1';
	Piece *sourcePiece = (*currentBoard)[sourceRow][sourceFile].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destinationRow][destinationFile].currentPiece;
	if (sourcePiece->getColor() && sourceRow == 4 && piece[2] == lastMove[2] && piece[3]-lastMove[3] == 1){ return true; }
	else if (!sourcePiece->getColor() && sourceRow == 3 && piece[2] == lastMove[2] && lastMove[3] - piece[3] == 1) { return true; }
	return false;
}*/

int Chess::score()
{
	int count = 0,black = 0, white = 0;
	for (int i = 0; i < 8; i++) { for (int j = 0; j < 8; j++) { if ((*currentBoard)[i][j].currentPiece->isAlive()) { count++; } } }
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((*currentBoard)[i][j].currentPiece->getColor())
			{
				if ((*currentBoard)[i][j].currentPiece->myName() == "Pawn")
				{
					if (i == 6) { white += 3; }
					if (i < 6) { white += 1; }
				}
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Bishop")
				{
					if (count > 20) { white += 35; }
					else { white += 30; }
				}
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Knight")
				{
					if (count > 20) { white += 30; }
					else { white += 35; }
				}
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Rook") { white += 50; }
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Queen") { white += 90; }
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Pawn") { white += 100; }
			}
			else
			{
				if ((*currentBoard)[i][j].currentPiece->myName() == "Pawn")
				{
					if (i == 1) { black -= 3; }
					if (i > 1) { black -= 1; }
				}
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Bishop")
				{
					if (count > 20) { black -= 35; }
					else { black -= 30; }
				}
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Knight")
				{
					if (count > 20) { black -= 30; }
					else { black -= 35; }
				}
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Rook") { black -= 50; }
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Queen") { black -= 90; }
				else if ((*currentBoard)[i][j].currentPiece->myName() == "Pawn") { black -= 100; }
			}
		}
	}
	return white + black;
}

vector<string> Chess::getAllMoves()
{
	int player = getCurrentPlayer();
	vector<string> allMoves;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((*ptrToBoard)[i][j].currentPiece->getColor() == player && (*ptrToBoard)[i][j].currentPiece->myName()!="OnePiece")
			{
				string position;
				position.push_back(j + 'a');
				position.push_back(i + '1');
				vector<string>moves = validMoves(position);
				allMoves.insert(allMoves.end(), moves.begin(), moves.end());
			}
		}
	}
	
	
	//std::cout << "\nGetting All Moves.\n";
	for (int i = 0; i < allMoves.size(); i++)
	{
		//std::cout << allMoves[i] << ":";
		Chess *temp = new Chess(*this);
		temp->execute(allMoves[i]);
		//std::cout << temp->score() << "\n";
		delete temp;
	}
	return allMoves;

}
string Chess::getSingleMove(bool color)
{
	vector <string> allMoves = getAllMoves();
	auto rng = std::default_random_engine{};
	std::shuffle(allMoves.begin(), allMoves.end(), rng);

	vector <int>allScores;
	for (int i = 0; i < allMoves.size(); i++)
	{
		Chess *temp = new Chess(*this);
		temp->minmax(allMoves[i],3);
		allScores.push_back(temp->score());
		delete temp;
	}
	auto maxIterator = max_element(allScores.begin(), allScores.end());
	auto minIterator = min_element(allScores.begin(), allScores.end());
	int minIndex = distance(allScores.begin(), minIterator);
	int maxIndex = distance(allScores.begin(), maxIterator);
	if (color)
		return allMoves[maxIndex];
	else
		return allMoves[minIndex];
}
int Chess::minmax(string move,int val)
{
	//static int count = 0;
	Chess *temp = new Chess(*this);
	temp->execute(move);
	//count++;
	int player = getCurrentPlayer();
	if (val <1)
	{
		if (player)
			return temp->score();
		else
			return -temp->score();
	}
	else
	{
		if (player)
		{
			int bestVal = -10000;
			Chess *myChess = new Chess(*temp);
			vector <string> allMoves = myChess->getAllMoves();
			//vector <int> allScores;
			for (int i = 0; i < allMoves.size(); i++)
			{
				//Chess *tempChess = new Chess(*myChess);
				int temp = myChess->minmax(allMoves[i],val-1);
				if (temp > bestVal)
					bestVal = temp;
			}
			delete myChess;
			return bestVal;
		}
		else
		{
			int bestVal = 10000;
			Chess *myChess = new Chess(*temp);
			vector <string> allMoves = myChess->getAllMoves();
			for (int i = 0; i < allMoves.size(); i++)
			{
				int temp = myChess->minmax(allMoves[i],val-1);
				if (temp < bestVal)
					bestVal = temp;
			}
			delete myChess;
			return bestVal;
		}
	}
	return 0;
}