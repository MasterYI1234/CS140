// Lab 10:  N-queens using "constrained" backtracking(nqueen2.cpp)
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
int Place(int board[],int pos);  //this is just a check for is the place of queen is well?
int sum = 0;         //This is just a sum to get the total of the solve ways, for debug.
int error = 0;



int main(int argc, char *argv[]) {
//istringstream number;  //get the size
int size;  // The size of board

//number.str(argv[1]);
//number >> size;

cin>>size;  //for debug by my computer

int board[size];    //make the board array.

nqueens(board, 0, size);
//cout<<"there are "<<sum<<" total."<<endl;   //for debug to check the total
cout<<"The standard error is "<<error<<" ."<<endl;

  return 0;

}

int nqueens (int board[],int pos,int size){
    int i;
    if(pos>=size){               //if all queens put on the board, cout it.
            for( i = 0; i < size-1; i++)
                {
                    cout<<board[i]<<", ";
                }
                cout<<board[size - 1]<<endl;
        sum++;
    }else{                                  //If not all queens put on the board, put the next board and check is it well?
        for(i=0;i<size;i++){
            board[pos]=i;
            error++;
            if(Place(board, pos)) nqueens (board, pos + 1, size);  // if it is well put the next queen.
        }
    }
return 0;
}






int Place(int board[], int pos)              //Check is the place of this queen is well?
{   int i;
    for(i=0;i<pos;i++){
        if(board[pos]==board[i] || abs(pos-i)==abs(board[pos]-board[i]))
            return 0;
    }
    return 1;
}
