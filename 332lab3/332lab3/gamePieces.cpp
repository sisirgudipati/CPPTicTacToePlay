#include  "stdafx.h"
#include <iostream>
#include <string>
#include "gamePieces.h"
using namespace std;


game_piece::game_piece (piece_color color, string name, string display)
	: color(color), name(name), display(display) {}

//default empty game pieces 
game_piece::game_piece() 
	: color(noColor), name(" "), display(" ") {}


bool operator == (const game_piece& x, const game_piece& y) {
	//testing for piece equality 
	if (x.display == y.display) {
		return true; 
	}
	else {
		return false; 
	}
}

string lowerColor(piece_color color) {
	if (color == red) {
		return "red"; 
	}
	if (color == black) {

		return "black"; 
	}
	if (color == white) {
		return "white"; 
	}

	if (color == blue) {
		return "blue"; 
	}
	else {
		return "invalidColor"; 
	}
}

piece_color colorStringToEnum(string color) {
	string convertedColor = color; 
	if (convertedColor == "red") {
		return red; 
	}
	if (convertedColor == "black") {
		return black;
	}
	if (convertedColor == "white") {
		return white; 
	}
	if (convertedColor == " ") {
		return noColor; 
	}
	if (convertedColor == "blue") {
		return blue; 
	}
	else {
		return invalidColor; 
	}
}

