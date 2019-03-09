========================================================================
    CONSOLE APPLICATION : 332lab3 Project Overview
========================================================================

AppWizard has created this 332lab3 application for you.

This file contains a summary of what you will find in each of the files that
make up your 332lab3 application.


332lab3.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

332lab3.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

332lab3.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named 332lab3.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
Sisir Gudipati 
Lab 3 

332lab3.cpp: 
	- Checks number of arguments and whether the command line argument is well-formed. 

tictactoe.h: 
	- ostream operator declared
	- empty tictactoe_game constructor declared 
	- play funtion declared
	- turn function declared
	- prompt function declared
	- draw function declared
	- done function declared

tictactoe.cpp: 
	- ostream operator defined 
	- empty tictactoe_game constructor defined, pieces pushed back 
	- play function defined: ran into an warning that not all of the control paths returned a value. Was not able to get rid of it, 
	  but I think it is due to the fact that the return values are inside if statements that are based on external values. But logically, 
	  my while loop takes care of the fact that it won't be able to exit and return until it gets one of the values required for the function
	  to return. Play function terminates on three different values, whether the player wins, if it's a draw, or if the user has decided to quit. 
	  There is a turnCount value that keeps track of who's move it is (if (turnCount % 2 == 0), it is player X's move) and how many moves have been played. This function
	  calls turn(), then done() and draw() on repeat until it gets one of the values required to terminate. 
	- turn function defined: This function repeatedly calls prompt function until either the user has decided to quit or the prompt function has been able to successfully extract coordinates
	  into x and y.  At any time if it receives 'quit' from prompt, the function will return the userQuits enumeration to the play function. If the function receives valid coordinates from prompt, 
	  it exits that while loop and checks the validity of the input. If the x & y coordinates are between 1 & 3 (inclusive) and the piece at that coordinate is empty, it checks turnCount for whose turn and places the appropriate piece at that index in the vector. 
	  If the move is not valid, the function doesn't exit the outer while loop and prompts the user for an input again. 
	- prompt function defined: This function takes care of the fact that if the user just presses enter without any input, command line will continuously 
	  prompt user to input something. To extract the input, the function replaces the comma with a blank space, and then wraps the line in an input string stream. 
	  Then pulls of each of the numbers into x and y for the coordinates. The values of x and y are passed in by reference. 
	- draw function defined: Returns true if there are no more blank spaces left on the 3x3 inner game board. It calls the done() method, if that returns true, then 
	  draw will return false. If there is a blank space, it returns false. Iterates through the board vector of gamepieces. 
	- done function defined: Checks all columns and rows and the two diagonals with an xCounter and oCounter. If either of them equal 3 during any of the checks, the function
	  returns true back to play. 

Test-cases: 
1). badly formed command line arguments: 
		-332lab3.exe tictactoe (output: Run the program in the following way: 332lab3.exe TicTacToe )
		-332lab3.exe tic-tac-toe (output: Run the program in the following way: 332lab3.exe TicTacToe )
2). wrong number of command line arguments: 
		-332lab3.exe TicTacToe hey (output: Run the program in the following way: 332lab3.exe TicTacToe )
		-332lab3.exe T i c T a c T o e s (output: Run the program in the following way: 332lab3.exe TicTacToe )
3). quitting on turn 1 
		- Tic Tac Toe:
				4
				3
				2  X
				1
				0
				 0 1 2 3 4

				Player O:
				Player X: 1,2;
				Player O has decided to quit the game. There was 1 turn played in this game.
4). quitting on turn 0 
		- output: 
		Tic Tac Toe:
				4
				3
				2
				1
				0
				 0 1 2 3 4

				Player O:
				Player X:
				Player X has decided to quit the game. There were 0 turns played in this game.
5). Badly formed inputs, re-prompts you to input coordinates again. 
