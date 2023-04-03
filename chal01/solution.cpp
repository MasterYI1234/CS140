// Challenge 1:  Tic-tac-toe input validator
//cosc140
//SiCheng Yi

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <ctime>
#include <math.h>
#include <sstream>

using namespace std;

int main(int argc, char **arg)
{
    vector< char > board;
    istringstream word;
    int i = 0; //place of input board
    int line; // line number.
    int  Turn;// board place number.
    char chess; // the input of board
if (argc != 2) {          // check if it not input a line number.
    cout<<"Error!  Invalid no. of command line arguments!"<<endl;  // output error.
    return 0;
  }
    word.str(arg[1]);   // get the input of line number.
    if (word >> line) {
       Turn =  line * line;  //Get how many place should be.
  }
    while ( cin >> chess ) {
           board.push_back( chess );    // push into vector board.
           i++;     //get the place of input board
        }
        if(i == Turn){
            cout<<"Valid board"<<endl;  //right board.
        }
        else if(i > Turn){
            cout<< "Too many cells for a "<<line<<" x "<<line<< " board"<<endl;   // output error.
        }
        else if(i < Turn){
            cout<< "Too few cells for a "<<line<<" x "<<line<< " board"<<endl;   // output error.
        }

return 0;
}


