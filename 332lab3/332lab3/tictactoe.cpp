#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "332lab3.h"
#include "tictactoe.h"


ostream &operator<< (ostream &out, const tictactoe_game &game) {
	cout << "Tic Tac Toe:" << endl;
	for (unsigned int row = (game.height - 1); row >= 0; --row) {
		string line = to_string(row);
		for (unsigned int column = 0; column < (game.width); ++column) {
			unsigned int index = (game.width*row) + column;
			line += (game.board[index].display + " "); 
		}
		cout << line << endl; 
		if (row == 0) {
			break; 
		}
	}
	cout << " 0 1 2 3 4" << endl;
	return out;
}

tictactoe_game::tictactoe_game(){
	for (int i = 0; i < 25; i++) {
		board.push_back(game_piece::game_piece());
	}
};

int tictactoe_game::play() {
	bool drawValue;
	bool doneValue;
	int turnValue; 
	bool retry = true; 
	//repeatedly call turn, then done, then draw 
	while (retry)
	{
		turnValue = turn(); 
		if (turnValue == userQuits) {
			retry = false;
		}
		cout << *this << endl;
		//cout << endl; 

		//print valid moves for X and O 
		cout << "Player O: " << validO << endl; 
		cout << "Player X: " << validX << endl; 


		doneValue = done(); 
		if (doneValue == true) {
			retry = false; 
		}
		drawValue = draw(); 
		if (drawValue == true) {
			retry = false; 
		}
	}

	//winner 
	if (doneValue == true) {
		cout << "Player " << winner << " wins the game!" << endl;
		return win;
	}

	//print how many turns were played + that the game was a draw 
	if (drawValue == true) {
		cout << "There were " << turnCount << " turns played in this game and no winner. The match is a draw." << endl;
		return matchDraw; 
	}
	//user has decided to quit 
	if (turnValue == userQuits) {
		if (turnCount != 1) {
			if ((turnCount % 2) == 0) {
				cout << "Player X has decided to quit the game. There were " << turnCount << " turns played in this game." << endl;
			}
			else {
				cout << "Player O has decided to quit the game. There were " << turnCount << " turns played in this game." << endl;
			}
		}
		else {
			cout << "Player O has decided to quit the game. There was " << turnCount << " turn played in this game." << endl;
		}
		return quit; 
	}
	
}


int tictactoe_game::turn() {
	unsigned int x; 
	unsigned int y; 
	unsigned int index; 
	int returnVal = 9; 
	bool retry = true; 
	bool retry2 = true; 
	
	while (retry) {
		while (retry2){
			returnVal = prompt(x, y);
			if (returnVal == userQuit) {
				return userQuit; 
			}
			if (returnVal == coordinatesSuccess) {
				retry2 = false; 
			}
		}

		if (returnVal == coordinatesSuccess) { 
			index = (y*width) + x; 
			bool xCheck = (x >= 1 && x <= 3); 
			bool yCheck = (y >= 1 && y <= 3); 
			//checking valid moves 
			if (xCheck && yCheck && (board[index].display == " ")) {
				game_piece newPiece;
				string xToString; 
				string yToString; 
				string validMove; 
				//valid move, declare a piece 
				if ((turnCount % 2) == 0) {
					newPiece = game_piece(noColor, "", "X");
					//to keep track of valid moves made for each piece/player
					xToString = to_string(x); 
					yToString = to_string(y); 
					validMove = xToString + "," + yToString + "; "; 
					validX += validMove; 
				}
				else {
					newPiece = game_piece(noColor, "", "O");
					//to keep track of valid moves made for each piece/player
					xToString = to_string(x); 
					yToString = to_string(y); 
					validMove = xToString + "," + yToString + "; ";
					validO += validMove; 
				} 
				//increment turnCount
				turnCount++; 
				board[index] = newPiece;
				retry = false; 
			}
			else {
				//requires one valid move to be made 
				retry2 = true; 
			}
		}
	}
	return turnSuccess;
}

int tictactoe_game::prompt(unsigned int& x, unsigned int& y) {
	string input;
	bool cinner = false; 
	//continuously prompt user for input until something is extracted 
	while (cinner == false) {
		cout << "Please enter a valid input, either coordinates or 'quit'." << endl;
		if (getline(cin, input)) {
			cinner = true;
			
		}
	} 
	//test whether string is quit or not 
	if (!input.compare("quit")) {
		//return value indicating user would like to quit 
		return userQuit; 
	}
	char letter; 
	bool commaCheck = false; 
	for (unsigned int i = 0; i < input.length(); i++) {
		letter = input[i];
		if (letter == ',') {
			input[i] = ' '; 
			commaCheck = true; 
		}
	}

	if (commaCheck == false){
		return improperlyFormattedString; 
	}

	istringstream iss(input); 
	if (iss >> x >> y) {
		return coordinatesSuccess; 
	}
	else {
		return coordinateExtractionFail; 
	}
}

bool tictactoe_game::draw() {
	//if done method returns true, return false 
	if (done()) {
		return false; 
	}
	unsigned int index = 0; 
	//check if valid moves are left in board 
	for (unsigned int i = 1; i < width - 1; i++) {
		for (unsigned int j = 1; j < height - 1; j++) {
			index = (j*width) + i; 
			if (board[index].display == " ") {
				return false; 
			}

		}
	}
	return true; 
}

bool tictactoe_game::done() {
	unsigned int xCounter = 0;
	unsigned int oCounter = 0; 
	unsigned int index; 
	char x = 'X'; 
	char o = 'O'; 
	string xPiece = string(1, x); 
	string oPiece = string(1, o); 

	//check for each column 
	for (unsigned int i = 1; i < width - 1; i++) {
		if ((xCounter == 3) || (oCounter == 3)) {
			//found 3 in a row 
			if (xCounter == 3) {
				winner = "X";
			}
			else if (oCounter == 3) {
				winner = "O";
			}
			return true;
		}
		else {
			xCounter = 0; 
			oCounter = 0; 
			for (unsigned int x = 1; x < height - 1; x++) {
				index = (width*x) + i;
				if (board[index].display == xPiece) {
					xCounter++;
				}
				if (board[index].display == oPiece) {
					oCounter++;

				}
			}
		}
	}
	//check for each row
	for (unsigned int z = 1; z < height - 1; z++) {
		if ((xCounter == 3) || (oCounter == 3)) {
			//found 3 in a row 
			if (xCounter == 3) {
				winner = "X"; 
			}
			else if (oCounter == 3) {
				winner = "O"; 
			}
			return true;
		}
		else {
			xCounter = 0;
			oCounter = 0;
			for (unsigned int q = 1; q < width - 1; q++) {
				index = (width*z) + q;
				if (board[index].display == xPiece) {
					xCounter++;
				}
				if (board[index].display == oPiece) {
					oCounter++;
				}
			}
		}	
	}

	xCounter = 0; 
	oCounter = 0; 
	//check one diagonal from left to right 
	unsigned int diagX = 1; 
	for (unsigned int diagY = 1; diagY < height - 1; diagY++) {
		index = (diagY*width) + diagX;
		if (board[index].display == xPiece) {
			xCounter++;
		}
		if (board[index].display == oPiece) {
			oCounter++;
		}
		diagX++;
	}

	//checking diagonal count after it exits the for loop 
	if ((xCounter == 3) || (oCounter == 3)) {
		//found 3 in a row 
		if (xCounter == 3) {
			winner = "X";
		}
		else if (oCounter == 3) {
			winner = "O";
		}
		return true;
	}

	
	//check other diagonal from right to left (reset x + o counters)
	xCounter = 0;
	oCounter = 0;
	unsigned int diag2X = width - 2; 
	for (unsigned int diag2Y = 1; diag2Y < height - 1; diag2Y++) {
		index = (diag2Y*width) + diag2X; 
		if (board[index].display == xPiece) {
			xCounter++;
		}
		if (board[index].display == oPiece) {
			oCounter++;
		}
		diag2X--; 	
	}
	//checking count of other diagonal after it exits for loop 
	if ((xCounter == 3) || (oCounter == 3)) {
		//found 3 in a row 
		if (xCounter == 3) {
			winner = "X";
		}
		else if (oCounter == 3) {
			winner = "O";
		}
		return true;
	}
	return false; 
}



