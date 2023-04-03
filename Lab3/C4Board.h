// Lab 3:Connect Four(C4Board.h)
//COSC140
//SiCheng Yi


#ifndef C4BOARD_H
#define C4BOARD_H

#include <iostream>
#include "C4Col.h"

class C4Board {

 public:
       C4Board();
  void display();  //Display the current board in simple text.
  void play();  //Allow two players to play a game.
  bool helper(int x, int y) ;  //check who win.
  int computer();  // The computer player(extra credit).

private:
    int nc;  //number of col
    C4Col board[100];  //7 col
};


#endif
