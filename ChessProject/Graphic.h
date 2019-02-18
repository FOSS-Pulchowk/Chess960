#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "chess.h"
class Graphic
{
	SDL_Surface* chessBoard;
	SDL_Surface* whiteKing;
	SDL_Window *window;
	SDL_Surface*screenSurface;
	SDL_Rect posBoard[8][8];
	SDL_Rect chessBoardPos;
public:
	SDL_Event graphicEvents;
	//SDL_Event e;
	Graphic();
	/*~Graphic();
	int createMenu();
	void createGame();
	void close();*/
	void run(Chess &myChess);
	string input(SDL_Event *e);
	int getInput(Chess &myChess, SDL_Event *e, string &myMove);
private:
	//bool init();
	//bool loadImg();
	
	
	
};

