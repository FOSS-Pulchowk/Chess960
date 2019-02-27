#pragma once
#include <string>
#include "board.h"
#include "piece.h"
#include "chess.h"
#include "Graphic.h"
class Program
{
private:
	Graphic *ptrToGraphic;
	Board(*ptrToBoard)[8][8];
	Chess *ptrToChess;
	OnePiece *ptrToNoPiece;

public:
	bool isRunning;

	Program();
	void init();
	void quit();
};
