#include "Graphic.h"
#include "SDL_image.h"
#include "chess.h"
#include <iostream>

extern int i;
//Set the screen resolution


//Set SDL pointers to null

string getBoxSelection(int x, int y)
{
	int boxY, boxX;
	char columnLetter[] = "abcdefgh";
	string finalValue;
	boxY = (44 + 8 * 86 - y) / 86;
	boxX = (x - 365) / 86;
	if (x < 365 || x > 365 + 86 * 8 || y < 44 || y > 44 + 8 * 86) { return "0"; }
	finalValue = columnLetter[boxX] + ((char)(49 + boxY));
	std::cout << finalValue;
	return finalValue;
}

Graphic::Graphic()
{
	SDL_Init(SDL_INIT_VIDEO);
	
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window);
	chessBoard = IMG_Load("chessboard.png");
	whiteKing = IMG_Load("ChessPieces/WhiteKing.png");

	chessBoardPos.x = 302; chessBoardPos.y = 0;
	int initialPosX = 365, initialPosY = 44, boxPosDiff = 86;
	
	for (int i=7; i >= 0; i--) {
		for (int j=0; j < 8; j++) {
			posBoard[i][j].y = initialPosY + (boxPosDiff*(7 - i));
			posBoard[i][j].x = initialPosX + (boxPosDiff*j);
		}
	}
}

int Graphic::getInput(Chess &myChess,SDL_Event *e,string &myMove)
{
	SDL_Event events = *e;
	if (SDL_PollEvent(&events))
	{
		//If a key was pressed
		/*if (events.type == SDL_KEYDOWN)
		{
			//Set the proper message surface
			switch (events.key.keysym.sym)
			{
			case SDLK_UP: myMove = "e1e2"; break;
			case SDLK_DOWN: myMove = "e8e7"; break;
			case SDLK_LEFT: myMove = "e2e3"; break;
			case SDLK_RIGHT: myMove = "e7e6"; break;
			}
			if (myChess.execute(myMove))
			{
				myChess.changeTurn();
				return 1;

			}
		}
		else if (events.type==SDL_MOUSEBUTTONDOWN)
		{
			if (events.button.button== SDL_BUTTON_LEFT)
			{
				string moveList = "e1e2e8e7e2e3e7e6";
				myMove = moveList.substr(i,4);
			}
			if (myChess.execute(myMove))
			{
				myChess.changeTurn();
				i += 4;
				return 1;
			}
		}
		*/
		//If the user has Xed out the window
		if (events.type == SDL_QUIT)
		{
			//Quit the program
			myChess.endChess();
			return 0;
			
		}
		else
		{
			string tempMove;
			std::cout << "Enter move: ";
			std::cin >> tempMove;
			if (myChess.execute(tempMove))
			{
				myChess.changeTurn();
				return 1;
			}
			else
			{
				std::cout << "I cant execute the given move";
			}
		};
	}
}

string Graphic::input(SDL_Event *myEvent)
{
	string moves = "e1e2e8e7e2e3e7e6e3e4e6e5";
	string move,tempMove;
	//int posX, posY;
	while (SDL_PollEvent(myEvent) != 0) {
		std::cout << "1. prnt\n";
		if ((*myEvent).type == SDL_QUIT) 
		{
			
			//(myChess).endChess();
			return "e1e2";
		}
		else if ((*myEvent).type == SDL_KEYDOWN)
		{
			return moves.substr(i, 4);
		}
		/*else if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			//SDL_GetMouseState(&posX, &posY);
			std::cout << "2. prnt\n";
			return "e1e2";
			//return getBoxSelection(posX, posY);

		}*/
		/*else if (e.type==SDL_KEYDOWN)
		{
			if (e.key.keysym.sym==SDLK_3)
			{
				return "e1e2";
			}
		}*/
		else
		{
			return "e1e2";
		}
		//else if (e.type==SDL_KEYDOWN)
		//{
			//std::cout << "Enter move:";
			//std::cin >> move;
			//if (eve)
			//return mov;
			//return moves.substr(i, 4);
			//i = i + 4;
			//std::cin >> move;
			// yo redundant xa jasto layo malai
			/*if (e.type == SDL_QUIT)
				myChess.endChess();*/
			
		//}


		/*else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (x > ButtonPos.x&&x<(ButtonPos.x + Button->w) && y>ButtonPos.y&&y < (ButtonPos.y + Button->h)) {
				SDL_FreeSurface(Button);
				Button = SDL_LoadBMP("button_hover.bmp");
			}
			else {
				SDL_FreeSurface(Button);
				Button = SDL_LoadBMP("button.bmp");
			}*/
	}
}

/*
Graphic::~Graphic()
{
}

bool Graphic::init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		Window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT, SDL_WINDOW_SHOWN);
		if (Window == NULL) {
			printf("Windows could not be created! Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			ScreenSurface = SDL_GetWindowSurface(Window);
		}
	}
	return success;

}

bool Graphic::loadImg() {
	bool success = true;
	MenuBackground = SDL_LoadBMP("menu_background.bmp");
	if (MenuBackground == NULL) {
		printf("1:Error: %s\n", SDL_GetError());
		success = false;
	}
	MainMenu = SDL_LoadBMP("mainmenu.bmp");
	if (MainMenu == NULL) {
		printf("2:Error: %s\n", SDL_GetError());
		success = false;
	}
	Button = SDL_LoadBMP("button.bmp");
	if (Button == NULL) {
		printf("2:Error: %s\n", SDL_GetError());
		success = false;
	}
	Button_Hover = SDL_LoadBMP("button_hover.bmp");
	if (Button_Hover == NULL) {
		printf("2:Error: %s\n", SDL_GetError());
		success = false;
	}
	ChessBoard = SDL_LoadBMP("chessboard.bmp");
	if (ChessBoard == NULL) {
		printf("2:Error: %s\n", SDL_GetError());
		success = false;
	}
	WhiteKing = SDL_LoadBMP("WhiteKing.bmp");
	if (WhiteKing == NULL) {
		printf("2:Error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Graphic::close() {
	SDL_FreeSurface(ChessBoard);
	ChessBoard = NULL;
	SDL_FreeSurface(WhiteKing);
	WhiteKing = NULL;
	SDL_FreeSurface(MenuBackground);
	MenuBackground = NULL;
	SDL_FreeSurface(MainMenu);
	MainMenu = NULL;
	SDL_FreeSurface(Button);
	Button = NULL;
	SDL_FreeSurface(Button_Hover);
	Button_Hover = NULL;
	SDL_DestroyWindow(Window);
	Window = NULL;
	SDL_Quit();
}

int Graphic::createMenu() 
{
	SDL_Rect MainMenuPos, ButtonPos;
	MainMenuPos.x = 150; MainMenuPos.y = 10;
	ButtonPos.x = 46; ButtonPos.y = 300;
	bool quit = false;
	SDL_Event e;

	if (!init()) {
		printf("Failed");
	}
	else {
		if (!loadImg()) {
			printf("Failed");
		}
		else {
			SDL_BlitSurface(MenuBackground, NULL, ScreenSurface, NULL);
			SDL_BlitSurface(MainMenu, NULL, ScreenSurface, &MainMenuPos);
			SDL_BlitSurface(Button, NULL, ScreenSurface, &ButtonPos);
			SDL_Delay(100);
		}
	}
	while (!quit) {

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) { quit = true; }
			else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (x > ButtonPos.x&&x<(ButtonPos.x + Button->w) && y>ButtonPos.y&&y < (ButtonPos.y + Button->h)) {
					SDL_FreeSurface(Button);
					Button = SDL_LoadBMP("button_hover.bmp");
				}
				else {
					SDL_FreeSurface(Button);
					Button = SDL_LoadBMP("button.bmp");
				}
			}
			SDL_BlitSurface(MenuBackground, NULL, ScreenSurface, NULL);
			SDL_BlitSurface(MainMenu, NULL, ScreenSurface, &MainMenuPos);
			SDL_BlitSurface(Button, NULL, ScreenSurface, &ButtonPos);
			SDL_UpdateWindowSurface(Window);
		}
	}
	return 0;
}

void Graphic::createGame() {
	bool quit = false;
	SDL_Rect posBoard[8][8], chessBoardPos;
	chessBoardPos.x = 302; chessBoardPos.y = 0;
	int initialPosX = 365, initialPosY = 54,boxPosDiff=86;
	int i = 7, j = 0;
	for (i; i >= 0; i--) {
		for (j; j < 8; j++) {
			posBoard[i][j].x = initialPosX + (boxPosDiff*(7 - i));
			posBoard[i][j].y = initialPosY + (boxPosDiff*j);
		}
	}
	if (!init()) {
		printf("Failed");
	}
	else {
		if (!loadImg()) {
			printf("Failed");
		}
		else {
			SDL_BlitSurface(MenuBackground, NULL, ScreenSurface, &chessBoardPos);
			i = 7; j = 0;
			for (i; i >= 0; i--) {
				for (j; j < 8; j++) {
					SDL_BlitSurface(WhiteKing, NULL, ChessBoard, &posBoard[i][j]);
				}
			}
			SDL_UpdateWindowSurface(Window);
		}
	}
	SDL_Delay(500);
}
*/
void Graphic::run(Chess &myChess)
{

	SDL_BlitSurface(chessBoard, NULL, screenSurface, &chessBoardPos);
	
	for (int i=7; i >= 0; i--) {
		for (int j=0; j < 8; j++) {
			SDL_BlitSurface((*myChess.currentBoard)[i][j].currentPiece->image, NULL, screenSurface, &posBoard[i][j]);
		}
	}
	
	SDL_UpdateWindowSurface(window);
	SDL_Delay(1);

}
