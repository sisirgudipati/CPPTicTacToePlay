// 332lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "tictactoe.h"
#include "generalFunctionss.h"
using namespace std; 

int main(int argc, char * argv[])
{
	char * tictactoe = argv[input];
	if (argc != CorrectNumberOfArguments) {
		return helpfulArgument(argv[programName], "TicTacToe");
	}
	else if ((strcmp(tictactoe, "TicTacToe"))) {
		return helpfulArgument(argv[programName], "TicTacToe");
	}

	tictactoe_game game = tictactoe_game(); 
	cout << game << endl; 
	int returnValue = game.play(); 

    return returnValue;
}

