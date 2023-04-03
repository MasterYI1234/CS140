// Lab 1:  Tic-tac-toe solver(toe.cpp)
//COSC140
//SiCheng Yi

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <math.h>

using namespace std;

int main() {

int siz;//set the size of the chessboard.

cout << "Input size:" << endl;

cin>>siz;//User input size

 while (siz <= 0) //Prevents a player from entering an invalid cell.
        {
           cout << "Invalid cell." << endl;
           cout << "Input size:";
           cin >> siz;
        }

char board[siz][siz];	//Initializes a two-dimensional array

for(int i=0;i<siz;i++) {
			for(int j=0;j<siz;j++) {
				board[i][j] = { '-' };
			}
		}


    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) cout<< board[i][j];
        cout << endl;
    }





int choose_x, choose_y;//Choose position.
int who = 0;//Confirm the round
char player;//Confirm the round
int b=0;//round
  for (int a = 0; a < siz*siz; a++)
     {
      cout << "Please enter the number of the position to play chess(Start at 0):";
      cin >> choose_x;
      cin >> choose_y;
     while (choose_x >= siz || choose_y >= siz) //Prevents a player from entering an invalid cell.
        {
           cout << "Invalid cell." << endl;
           cout << "Please enter the number of the position to play chess(Start at 0):";
           cin >> choose_x;
           cin >> choose_y;
        }

     while (board[choose_x][choose_y] != '-') //Prevents a player from changing a previously chosen cell.
        {
           cout << "There are already pieces on the board, please reenter." << endl;
           cout << "Please enter the number of the position to play chess(Start at 0):";
           cin >> choose_x;
           cin >> choose_y;
        }
         if (who == 0){
             player ='X';
         }
         else{
               player = 'O';
         }

         if (who == 0){
             board[choose_x][choose_y] = 'X';
             who = 1;
         }
         else{
               board[choose_x][choose_y] = 'O';
               who = 0;
         }
    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) cout<< board[i][j];
        cout << endl;
    }


        int i = 0, j = 0,n = siz;
        //Check Who wins.
        for (j = 1; j < n; ++j) {
            if (board[choose_x][j] != board[choose_x][j - 1]) break;
        }
        if (j == n) {
                    cout <<player<<" wins"<<endl;
                    break;
            }

        for (i = 1; i < n; ++i) {
            if (board[i][choose_y] != board[i - 1][choose_y]) break;
        }
        if (i == n) {
                    cout <<player<<" wins"<<endl;
                    break;
            }
        if (choose_x == choose_y) {
            for (i = 1; i < n; ++i) {
                if (board[i][i] != board[i - 1][i - 1]) break;
            }
            if (i == n) {
                    cout <<player<<" wins"<<endl;
                    break;
            }
        }
        if (choose_x + choose_y == n - 1) {
            for (i = 1; i < n; ++i) {
                if (board[n - i - 1][i] != board[n - i][i - 1]) break;
            }
            if (i == n) {
                    cout <<player<<" wins"<<endl;
                    break;
            }
        }
            b = b + 1;
     }
            if(b == siz*siz){    //Tie
            cout<<"Tie"<<endl;
         }
return 0;
}



