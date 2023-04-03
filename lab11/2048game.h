// Lab 11: Choose your own adventure(2048game.h)
//COSC140
//SiCheng Yi
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <curses.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>


using namespace std;

#define   N    4  //The length and width of the game grid
#define WIDTH  4

#define STNUM   1  //Set the number of initialized new numbers

#define TARGET  2048  //Set the game victory conditions


#define WIN  0  //Set the status table
#define LOSE 1
#define NORM 2
#define QUIT 3

class Game2048
{
public:
	Game2048() {
    Game2048(); // constructor
	int getStatus();  //Simply get the game status

	void getChar();  //Get user input, and set the state according to the user input (move up, down, left and right to play the game, status update, exit and refresh)

	void draw();  //Draw the game interface (clean up the screen, set the offset, draw the numbers, align the numbers to the right, draw the game operation method and score, draw the status information, remind the user of input and output errors)

     void setData(); //The number of the game interface when the class is initialized

     void drawNum(int x, int y, int num); //Right align drawing numbers

     void restart();  //Restart the game settings

	bool randNew(int num); //Randomly generate any number

	bool moveLeft();  //Game left operation

	void rotate(); //Rotate 90 degrees clockwise

	bool isOver();  //Determine whether the game is over or not

	void dataSave(); //Save the current game state

	void dataLoad(); //Load the previous game state

	private:
	int data[N][N];  //Game state
	int save[N][N];  //A place to save the game state
	int status = -1;  //The current state of the grid, initialized to -1.
	int score = 0;  // The score
	bool start = true;  //The start state

};


#endif
