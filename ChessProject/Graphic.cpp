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
	string finalValue="";
	boxY = (27 + 8 * 90 - y) / 91;
	boxX = (x - 323) / 91;
	if (x < 323 || x > 323 + 86 * 8 || y < 27 || y > 27 + 8 * 91) { return ""; }
	finalValue.push_back(boxX + 'a');
	finalValue.push_back(boxY + '1');
	return finalValue;
}

Graphic::Graphic()
{
	SDL_Init(SDL_INIT_VIDEO);
	
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_FULLSCREEN);
	screenSurface = SDL_GetWindowSurface(window);
	chessBoard = IMG_Load("chessboard.png");
	whiteKing = IMG_Load("ChessPieces/WhiteKing.png");
	inputMove = "";
	highlight = IMG_Load("highlight.png");
	chessBoardPos.x = 0; chessBoardPos.y = 0;
	int initialPosX = 322, initialPosY = 26, boxPosDiff = 91;
	
	for (int i=7; i >= 0; i--) {
		for (int j=0; j < 8; j++) {
			posBoard[i][j].y = initialPosY + (boxPosDiff*(7 - i));
			posBoard[i][j].x = initialPosX + (boxPosDiff*j);
		}
	}
}
//string Graphic::input(Chess &myChess,SDL_Event &eve)
int Graphic::getInput(Chess &myChess,SDL_Event *e,string &myMove)
{

	SDL_Event events = *e;
	int posX, posY;
	if (SDL_PollEvent(&events))
	{
		
		/*if (events.type==SDL_MOUSEBUTTONDOWN)
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
		}*/
		
		//If the user has Xed out the window
		if (events.type == SDL_QUIT)
		{
			//Quit the program
			myChess.endChess();
			return 0;
			
		}
		else if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&posX, &posY);
			std::cout << "2. inMouse event:"<<posX << " " << posY <<"\n";
			//return "e1e2";
			string boxVar = getBoxSelection(posX, posY);
			if (boxVar != "")
			{
				if (inputMove.size() != 2)
				{
					//string click = getBoxSelection(posX, posY);
					inputMove = boxVar;;
					std::cout << "I got " << inputMove << " as first move\n";
					return 0;
				}
				else if (inputMove.size() == 2)
				{
					string click = getBoxSelection(posX, posY);
					if (click == inputMove)
					{
						inputMove = "";
						return 0;
					}
					inputMove = inputMove + getBoxSelection(posX, posY);
					return 1;
				}
			}
		}
		else if (events.type == SDL_KEYDOWN)
		{
			return 2;
		}
		else
		{
			return 0;
		}
				//return inputMove;

			//}
			
			

		
		/*else
		{
			string tempMove;
			std::cout << myChess.getCurrentPlayer() << " ";
			std::cout << "Enter move: ";
			std::cin >> tempMove;
			if (myChess.execute(tempMove))
			{
				myChess.changeTurn();
				return 1;
			}
			else
			{
				std::cout << "I cant execute the given move\n";
			}
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
	if (inputMove != "")
	{
		SDL_BlitSurface(highlight, NULL, screenSurface, &posBoard[(int)(inputMove[1] - '1')][(int)(inputMove[0] - 'a')]);
	}
	
	for (int i=7; i >= 0; i--) {
		for (int j=0; j < 8; j++) {
			SDL_BlitSurface((*myChess.currentBoard)[i][j].currentPiece->image, NULL, screenSurface, &posBoard[i][j]);
		}
	}

	
	
	SDL_UpdateWindowSurface(window);
	SDL_Delay(1);

}
