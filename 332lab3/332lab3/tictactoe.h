#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include "gamePieces.h"
#include "gameBoardd.h"

//enums for print board function
enum printBoardEnums { printSuccess, dimensionMismatch };
enum prompt {coordinatesSuccess, userQuit, coordinateExtractionFail, improperlyFormattedString};
enum turn {turnSuccess, userQuits};
enum play {win, matchDraw, quit};


class tictactoe_game {
	//declare ostream operator as friend so it has access to private variables 
	friend ostream &operator<< (ostream &out, const tictactoe_game &game);
	vector<game_piece> board;
	unsigned int width = 5;
	unsigned int height = 5;
	unsigned int turnCount = 0; 
	string winner = ""; 
	string validO; 
	string validX;

	public:
		tictactoe_game();
		bool done(); 
		bool draw(); 
		int turn(); 
		int prompt(unsigned int& x, unsigned int& y); 
		int play(); 
};

ostream &operator<< (ostream &out, const tictactoe_game &game);

