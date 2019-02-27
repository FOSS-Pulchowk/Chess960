#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "chess.h"
class Graphic
{
	SDL_Surface* chessBoard, *blueBoard, *darkBoard;
	//SDL_Surface* whiteKing;
	SDL_Window *window;
	SDL_Surface*screenSurface, *highlight, *drawIcon[6][3], *loadingSurface, *mainmenuSurface, *dash;
	SDL_Surface *title, *hover, *settingSurface, *settingActive;
	SDL_Rect posBoard[8][8], deadPos[2][16];
	SDL_Rect chessBoardPos, additionChessBoardPos;
	SDL_Rect drawIconPos[6];
	int drawIconState[6], currentMousePos[2];
public:
	SDL_Event graphicEvents;
	string inputMove;
	string currentWindowView;
	void freeSurface();
	void loadingScreen();
	int chessBoardNo;
	void mainmenu(Chess &myChess);
	void Setting();
	int highLightMenuItem;
	//SDL_Event e;
	Graphic();
	/*~Graphic();
	int createMenu();
	void createGame();
	void close();*/
	void run(Chess &myChess);
	//string input(Chess &myChess, SDL_Event &eve);
	//string input(SDL_Event *e);
	int getInput(Chess &myChess, SDL_Event *e, string &myMove);
private:
	//bool init();
	//bool loadImg();
	
	
	
};

