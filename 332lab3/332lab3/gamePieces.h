#pragma once
#include <string>
#include <ostream>
using namespace std; 

enum piece_color {red, black, white, blue, invalidColor, noColor};

string lowerColor(piece_color color);

piece_color colorStringToEnum(string color); 

struct game_piece {
	piece_color color; 
	string name;
	string display; 
	game_piece(); 
	game_piece(piece_color color, string name, string display);
};

bool operator == (const game_piece& , const game_piece&);

