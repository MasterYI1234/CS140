// Lab 3:Connect Four(C4Board.cpp)
//COSC140
//SiCheng Yi
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "C4Board.h"
#include "C4Col.h"
#include "C4Col.cpp"

using namespace std;

C4Board::C4Board(){
     nc = 7;

}

void C4Board::display(){
  for (int i = board[0].getMaxDiscs() - 1; i >= 0; i--) {
    for (int j = 0; j < 7; j++) {
      cout << board[j].getDisc(i) << " ";
    }
    cout << endl;
  }
}


void C4Board::play() {
for (int a = 0; a < 42; a++)
     {
    if(a % 2 == 0){
               display();
    cout << "Enter in which col you want(0-6):" <<endl;
    cin >> nc;
    while (nc >= 7) //Prevents a player from entering an invalid cell.
        {
           cout << "Invalid cell." << endl;
           cout << "Enter in which col you want(0-6):" <<endl;
           cin >> nc;
        }
    }

        if(a % 2 == 1){
        nc = computer();
        }
        if (a % 2 == 0){
             board[nc].addDisc('X');
         }
         else{
               board[nc].addDisc('O');
         }
           if(helper(nc, board[nc].getNowDiscs()) == true){
                display();
                 break;
    }
      if(board[nc].isFull() == 1){
        a--;
    }
            if(a == 42){
        cout<<"Tie"<<endl;
        break;
     }

     }
}

bool C4Board::helper(int x, int y){
    int a = 1; //Check the same chess.
     for(int i=x;i<6;i++)          //Check the row.
        {
             if(board[i+1].getDisc(y) != board[x].getDisc(y)){
                    break;
        }
        a++;
    }
    for(int i=x; i>0; i--){
        if(board[i-1].getDisc(y) != board[x].getDisc(y)){
                    break;
        }
        a++;
    }

 if(a>=4)
                        {
                    cout << board[x].getDisc(y) << " win." << endl;
                               return true;
                        }
                        else{
                            a = 1;
                        }

    for(int i=y; i>0; i--){      //Check the col.
        if(board[x].getDisc(i-1) != board[x].getDisc(y)){
                    break;
        }
        a++;

    }
 if(a>=4)
                        {
                    cout << board[x].getDisc(y) << " win." << endl;
                               return true;
                        }
                        else{
                            a = 1;
                        }

 for(int i=x, j = y;i > 0 && j < 5;i--, j++)     // check the left bevel edge.
        {
             if(board[i-1].getDisc(j+1) != board[x].getDisc(y)){
                    break;
        }
        a++;
    }
    for(int i=x, j=y; i < 6 && j > 0; i++, j--){
        if(board[i+1].getDisc(j-1) != board[x].getDisc(y)){
                    break;
        }
        a++;
    }

 if(a>=4)
                        {
                    cout << board[x].getDisc(y) << " win." << endl;
                               return true;
                        }
                        else{
                            a = 1;
                        }


  for(int i=x, j = y;i < 6 && j < 5;i++, j++)     // check the right bevel edge.
        {
             if(board[i+1].getDisc(j+1) != board[x].getDisc(y)){
                    break;
        }
        a++;
    }
    for(int i=x, j=y; i > 0 && j > 0; i--, j--){
        if(board[i-1].getDisc(j-1) != board[x].getDisc(y)){
                    break;
        }
        a++;
    }

 if(a>=4)
                        {
                    cout << board[x].getDisc(y) << " win." << endl;
                               return true;
                        }

return false;
}


int C4Board::computer(){
    while(1){
         int nc = rand() % 7;
         if(board[nc].isFull() != 1){
                return nc;
         }
    }
}

