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
	if (x > 18 && x < (18 + 123) && y>357 && y < (357 + 118)) { return "3"; }
	else if (x > (18 + 123 + 16) && x < (18 + 123 * 2 + 16) && y>357 && y < (357 + 118)) { return "4"; }
	else if (x > 18 && x < (18 + 123) && y>(357 + 118 + 16) && y < (357 + 118 * 2 + 16)) { return "5"; }
	else if (x > (18 + 123 + 16) && x < (18 + 123 * 2 + 16) && y>(357 + 118 + 16) && y < (357 + 118 * 2 + 16)) { return "6"; }
	else if (x > 18 && x < (18 + 123) && y>(357 + 118 * 2 + 16 * 2) && y < (357 + 118 * 3 + 16 * 2)) { return "7"; }
	else if (x > (18 + 123 + 16) && x < (18 + 123 * 2 + 16) && y>(357 + 118 * 2 + 16 * 2) && y < (357 + 118 * 3 + 16 * 2)) { return "8"; }
	else if (x < 323 || x > 323 + 86 * 8 || y < 27 || y > 27 + 8 * 91) { return ""; }
	finalValue.push_back(boxX + 'a');
	finalValue.push_back(boxY + '1');
	return finalValue;
}
int getMenuSelection(int x, int y)
{
	if (x > 1050 && x < 1331 && y > 328 && y < 407) { return 1; }
	else if (x > 1050 && x < 1331 && y > 407 && y < 486) { return 2; }
	else if (x > 1050 && x < 1331 && y > 486 && y < 565) { return 3; }
	else if (x > 1050 && x < 1331 && y > 565 && y < 644) { return 4; }
	return 0;
}
int getSettingSelection(int x, int y)
{
	if (x > 93 && x < 393 && y > 209 && y < 509) { return 0; }
	else if (x > 508 && x < 808 && y > 209 && y < 509) { return 1; }
	else if (x > 923 && x < 1223 && y > 209 && y < 509) { return 2; }
	else if (x > 1203 && x < 1328 && y > 24 && y < 149) { return 9; }
	return 8;
}

Graphic::Graphic()
{
	SDL_Init(SDL_INIT_VIDEO);
	
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window);
	chessBoard = IMG_Load("chessboard.png");
	blueBoard = IMG_Load("ChessBoard/chessboardbluestone.png");
	darkBoard = IMG_Load("ChessBoard/chessboardblackstone.png");
	loadingSurface = IMG_Load("loadingscreen.png");
	mainmenuSurface = IMG_Load("mainmenu.png");
	dash = IMG_Load("dash.png");
	settingSurface = IMG_Load("setting.png");
	settingActive = IMG_Load("boardhighlight.png");
	currentWindowView = "loading";
	title = IMG_Load("MainMenu.bmp");
	hover = IMG_Load("buttonHover.png");
	chessBoardNo = 1;
	/*font = TTF_OpenFont("ITCBLKAD.TTF", 24);
	if (font == NULL)
		std::cout << "Returned Null\n";
	colorText = { 200, 200, 200 };
	colorHead = { 50, 100, 60 };*/
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	whiteTurn = IMG_Load("Icons/WhiteTurn.png");
	blackTurn = IMG_Load("Icons/BlackTurn.png");
	whiteWins = IMG_Load("WhiteWins.png");
	blackWins = IMG_Load("BlackWins.png");
	//whiteKing = IMG_Load("ChessPieces/WhiteKing.png");
	inputMove = "";
	for (int i = 0; i < 6; i++){ drawIconState[i] = 1; }
	highlight = IMG_Load("highlight.png");
	chessBoardPos.x = 0; chessBoardPos.y = 0;
	turnPos.x = 80;
	turnPos.y = 315;
	additionChessBoardPos.x = 299; additionChessBoardPos.y = 0;
	int initialPosX = 322, initialPosY = 25, boxPosDiff = 90;

	drawIcon[0][0] = IMG_Load("Icons/newGame-clicked.png");
	drawIcon[0][1] = IMG_Load("Icons/newGame.png");
	drawIcon[0][2] = IMG_Load("Icons/newGame-hover.png");
							   
	drawIcon[1][0] = IMG_Load("Icons/save-clicked.png");
	drawIcon[1][1] = IMG_Load("Icons/save.png");
	drawIcon[1][2] = IMG_Load("Icons/save-hover.png");
							   
	drawIcon[2][0] = IMG_Load("Icons/draw-clicked.png");
	drawIcon[2][1] = IMG_Load("Icons/draw.png");
	drawIcon[2][2] = IMG_Load("Icons/draw-hover.png");
							   
	drawIcon[3][0] = IMG_Load("Icons/resign-clicked.png");
	drawIcon[3][1] = IMG_Load("Icons/resign.png");
	drawIcon[3][2] = IMG_Load("Icons/resign-hover.png");
							   
	drawIcon[4][0] = IMG_Load("Icons/undo-clicked.png");
	drawIcon[4][1] = IMG_Load("Icons/undo.png");
	drawIcon[4][2] = IMG_Load("Icons/undo-hover.png");
							   
	drawIcon[5][0] = IMG_Load("Icons/exit-clicked.png");
	drawIcon[5][1] = IMG_Load("Icons/exit.png");
	drawIcon[5][2] = IMG_Load("Icons/exit-hover.png");

	int initialIconPosX = 18, initialIconPosY = 357, diffIconPos = 16, iconHeight = 118, iconWidth = 123;
	
	for (int i = 0; i < 6; i++) {
		drawIconPos[i].x = initialIconPosX + (i % 2)*iconWidth + (i % 2)*diffIconPos;
		drawIconPos[i].y = initialIconPosY + (i / 2)*iconHeight + (i / 2)*diffIconPos;
	}
	for (int i=7; i >= 0; i--) {
		for (int j=0; j < 8; j++) {
			posBoard[i][j].y = initialPosY + (boxPosDiff*(7 - i));
			posBoard[i][j].x = initialPosX + (boxPosDiff*j);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			deadPos[1][i * 5 + j].x = 1063 + j * 54;
			deadPos[1][i * 5 + j].y = 457 + i * 96;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			deadPos[0][i * 5 + j].x = 7 + j * 54;
			deadPos[0][i * 5 + j].y = 20 + i * 96;
		}
	}
}
//string Graphic::input(Chess &myChess,SDL_Event &eve)
int Graphic::getInput(Chess &myChess, SDL_Event *e, string &myMove)
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
				//std::cout << "2. inMouse event:" << posX << " " << posY << "\n";
				//return "e1e2";
				string boxVar = getBoxSelection(posX, posY);
				if (boxVar.size() == 2)
				{
					if (inputMove.size() != 2)
					{
						//string click = getBoxSelection(posX, posY);
						inputMove = boxVar;
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
				else if (boxVar.size() == 1)
				{
					drawIconState[(int)(boxVar[0] - '3')] = 2;
					return 0;
				}
				return 0;
			}
			else if (events.type == SDL_KEYDOWN)
			{
				std::cout << "i returned \n";
				return 2;
			}
			else if (events.type == SDL_MOUSEBUTTONUP)
			{
				SDL_GetMouseState(&posX, &posY);
				string boxVar = getBoxSelection(posX, posY);
				drawIconState[(int)(boxVar[0] - '3')] = 0;
				if (boxVar.size() == 1) { return (boxVar[0] - '0'); }
				return 0;
			}
			else if (events.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&posX, &posY);
				string boxVar = getBoxSelection(posX, posY);
				if (boxVar.size() == 1) { for (int i = 0; i < 6; i++) { drawIconState[i] = 1; }; drawIconState[(int)(boxVar[0] - '3')] = 0; }
				else { for (int i = 0; i < 6; i++) { drawIconState[i] = 1; } }
				return 0;
			}
			else
			{
				return 0;
			}
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






void Graphic::run(Chess &myChess, vector<string> moveSet)
{

	//std::cout << "After chessBoard blit\n";
	moveTextPos.x = 1100;
	moveTextPos.y = 25;
	SDL_BlitSurface(chessBoard, NULL, screenSurface, &chessBoardPos);
	if (myChess.getCurrentPlayer())
	{
		SDL_BlitSurface(whiteTurn, NULL, screenSurface, &turnPos);
	}
	else
	{
		SDL_BlitSurface(blackTurn, NULL, screenSurface, &turnPos);
	}
	//std::cout << "After chessBoard blit\n";
	if (chessBoardNo == 0) { SDL_BlitSurface(blueBoard, NULL, screenSurface, &additionChessBoardPos); }
	else if (chessBoardNo == 2) { SDL_BlitSurface(darkBoard, NULL, screenSurface, &additionChessBoardPos); }
	
	if (inputMove != "")
	{
		SDL_BlitSurface(highlight, NULL, screenSurface, &posBoard[(int)(inputMove[1] - '1')][(int)(inputMove[0] - 'a')]);
	}
	for (int i = 0; i < 6; i++)
	{
		SDL_BlitSurface(drawIcon[i][drawIconState[i]], NULL, screenSurface, &drawIconPos[i]);
	}
	//std::cout << "Before image loading\n";
	posBoard[7][3].y = 26;
	for (int i=7; i >= 0; i--) {
		for (int j=0; j < 8; j++) {
			SDL_BlitSurface((*myChess.currentBoard)[i][j].currentPiece->image, NULL, screenSurface, &posBoard[i][j]);
			//SDL_BlitSurface(highlight, NULL, screenSurface, &posBoard[i][j]);
		}
	}
	int j = 0;
	for (int i = 0;  i< 16; i++)
	{
		if (!myChess.whitePieces[i]->isAlive() && myChess.whitePieces[i]->myName()!="King")
		{
			SDL_BlitSurface(myChess.whitePieces[i]->image, NULL, screenSurface, &deadPos[0][j]);
			/*if(i!=15)
				SDL_BlitSurface(myChess.whitePieces[i]->image, NULL, screenSurface, &deadPos[1][j]);
			else
				SDL_BlitSurface(myChess.whitePieces[i]->image, NULL, screenSurface, &deadPos[1][4]);*/
			j++;
		}
	}
	int k = 0;
	for (int i = 0;i < 16; i++)
	{
		if (!myChess.blackPieces[i]->isAlive() && myChess.blackPieces[i]->myName() != "King")
		{
			SDL_BlitSurface(myChess.blackPieces[i]->image, NULL, screenSurface, &deadPos[1][k]);
			k++;
			/*if (i != 15)
				SDL_BlitSurface(myChess.blackPieces[i]->image, NULL, screenSurface, &deadPos[0][i]);
			else
				SDL_BlitSurface(myChess.blackPieces[i]->image, NULL, screenSurface, &deadPos[0][4]);*/
		}
	}

	//surfaceMessage = TTF_RenderText_Solid(font, "Moves in the game :", colorText);
	////if (surfaceMessage == NULL) std::cout << "Cant render the given test\n";
	//SDL_BlitSurface(surfaceMessage, NULL, screenSurface, &moveTextPos);
	//SDL_FreeSurface(surfaceMessage);

	moveTextPos.y += 50;
	//for (int i = 0; i < moveSet.size(); i++)
	//{
	//	surfaceMessage = TTF_RenderText_Solid(font, moveSet[i].c_str(), colorText);
	//	SDL_BlitSurface(surfaceMessage, NULL, screenSurface, &moveTextPos);
	//	moveTextPos.y += 27;
	//	SDL_FreeSurface(surfaceMessage);
	//	/*moveText = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//	SDL_RenderCopy(renderer, moveText, NULL, &moveTextPos);*/
	//}
	/*if (myChess.checkState() == 0)
	{
		SDL_BlitSurface(blackWins, NULL, screenSurface, NULL);
		SDL_Delay(2000);
	}
	else if (myChess.checkState()==1)
	{
		SDL_BlitSurface(whiteWins, NULL, screenSurface, NULL);
		SDL_Delay(2000);
	}*/
	
	SDL_UpdateWindowSurface(window);
	SDL_Delay(1);
}

void Graphic::freeSurface()
{
	SDL_FreeSurface(chessBoard);
	SDL_FreeSurface(screenSurface);
	SDL_FreeSurface(highlight);
	for (int i = 0; i < 6; i++) { for (int j = 0; j < 3; j++) { SDL_FreeSurface(drawIcon[i][j]); } }
}

void Graphic::loadingScreen()
{
	SDL_Rect dashPos,picPos;
	picPos.x = 0;
	picPos.y = 0;
	dashPos.x = 55;
	dashPos.y = 710;
	SDL_BlitSurface(loadingSurface, NULL, screenSurface, &picPos);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(1000);
	for (int i = 0; i < 9; i++)
	{		
		SDL_BlitSurface(dash, NULL, screenSurface, &dashPos);
		SDL_UpdateWindowSurface(window);
		dashPos.x += 30;
		SDL_Delay(200);
	}
	currentWindowView = "mainmenu";
}

void Graphic::mainmenu(Chess &myChess)
{
	SDL_Rect picPos,titlePos,hoverPos;
	picPos.x = 0;
	picPos.y = 0;
	titlePos.x = 800;
	titlePos.y = 150;
	bool continueLoop = true;
	int x, y;
	while (continueLoop)
	{
		hoverPos.x = 1050;
		hoverPos.y = 328;
		if (SDL_PollEvent(&graphicEvents))
		{
			SDL_BlitSurface(mainmenuSurface, NULL, screenSurface, &picPos);
			SDL_BlitSurface(title, NULL, screenSurface, &titlePos);
			if (graphicEvents.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&x, &y);
				highLightMenuItem = getMenuSelection(x, y);
				hoverPos.y += ((highLightMenuItem-1) * 79);
				if(highLightMenuItem){ SDL_BlitSurface(hover, NULL, screenSurface, &hoverPos); }
			}
			else if (graphicEvents.type == SDL_MOUSEBUTTONDOWN)
			{
				if(highLightMenuItem == 1)
				{
					currentWindowView = "gameplay";
					continueLoop = false;
				}
				else  if (highLightMenuItem == 2)
				{
					currentWindowView = "new";
					continueLoop = false;
				}
				else if (highLightMenuItem == 3)
				{
					currentWindowView = "setting";
					continueLoop = false;
				}
				else if (highLightMenuItem == 4)
				{
					currentWindowView = "gameplay";
					myChess.endChess();
					continueLoop = false;
				}
			}
		}
		SDL_UpdateWindowSurface(window);
	}
}

void Graphic::Setting()
{
	SDL_Rect picPos, activePos;
	picPos.x = 0;
	picPos.y = 0;
	bool continueLoop = true;
	int x, y;
	while (continueLoop)
	{
		activePos.x = 93 + chessBoardNo * 415;
		activePos.y = 209;
		if (SDL_PollEvent(&graphicEvents))
		{
			SDL_BlitSurface(settingSurface, NULL, screenSurface, &picPos);
			SDL_BlitSurface(settingActive, NULL, screenSurface, &activePos);
			if (graphicEvents.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_GetMouseState(&x, &y);
				if (getSettingSelection(x, y) < 3) { chessBoardNo = getSettingSelection(x, y); }
				else if (getSettingSelection(x, y) == 9)
				{
					currentWindowView = "mainmenu";
					continueLoop = false;
				}
			}
		}
		SDL_UpdateWindowSurface(window);
	}
}