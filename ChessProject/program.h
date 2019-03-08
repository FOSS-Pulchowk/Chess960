#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "board.h"
#include "piece.h"
#include "chess.h"
#include "Graphic.h"
class Program
{
private:
	Graphic *ptrToGraphic;
	Chess *ptrToChess;
	string myMove;
	int canRevert = 0;
	Chess *lastState = NULL;
	Chess *backUpState = NULL;
	//OnePiece *ptrToNoPiece;

public:
	bool isRunning;

	Program();
	void init();
	void quit();
};
