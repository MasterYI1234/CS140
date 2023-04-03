// Lab 10:  N-queens using backtracking(nqueens.cpp)
//COSC140
//SiCheng Yi
#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;
int nqueens (int board[],int pos,int size);
bool Place(int board[], int size);  //this is just a check for is the board well?
int sum = 0;         //This is just a sum to get the total of the solve ways, for debug.



int main(int argc, char *argv[]) {
istringstream number;  //get the size
int size;  // The size of board

number.str(argv[1]);
number >> size;

//cin>>size;  //for debug by my computer

int board[size];    //make the board array.

nqueens(board, 0, size);
//cout<<"there are "<<sum<<" total."<<endl;   //for debug to check the total


  return 0;

}

int nqueens (int board[],int pos,int size){
    int i;
    if(pos>=size){               //if all queens put on the board then check the board.
        if(Place(board, size) == false)    // If the board is not wrong, then cout it.
            {            for( i = 0; i < size-1; i++)
                {
                    cout<<board[i]<<", ";
                }
                cout<<board[size - 1]<<endl;
        sum++;
        }

    }else{                                  //If not all queens put on the board, put the queens on it.
        for(i=0;i<size;i++){
            board[pos]=i;
            nqueens (board, pos + 1, size);
        }
    }
return 0;
}



bool Place(int board[], int size)              //Check is the place of this board is well?
{
for (int i = 1; i <= size; ++i){
 for (int j = 0; j <= i-1; j++){
  if (board[i] == board[j]){   //This is check there are the queens on same line.
return true;
}
  if(abs(board[i] - board[j]) == abs(i - j)){   //This is check there are queens on same diagonal.
return true;
    }
   }
 }
return false;
}
