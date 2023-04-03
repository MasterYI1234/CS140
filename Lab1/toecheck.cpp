// Lab 1:  Tic-tac-toe solver(toecheck.cpp)
//COSC140
//SiCheng Yi

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {

int siz;//set the size of the chessboard.
char save;//Just a place to save.
char player;//Confirm the round
int T = 0;//Check Tie.


cin>>siz;//User input size

 while (siz <= 0) //Prevents a player from entering an invalid cell.
        {
           cout << "Invalid cell." << endl;
           cout << "Input size:";
           cin >> siz;
        }
char board[siz][siz];
for(int i=0;i<siz;i++) {
			for(int j=0;j<siz;j++) {
                cin >> save;
				board[i][j] = save;
			}
		}



        //Check Who wins.
        int i = 0, j = 0,n = siz;
        for(i = 0; i < siz; i++){
            if(board[i][0] != '-'){
        for (j = 1; j < n; ++j) {
            if (board[i][j] != board[i][j - 1]) break;
        }
        if (j == n) {
                    player = board[i][0];
                    cout <<player<<" wins"<<endl;
                    T = 1;
                    break;
            }
            }
        }

        for(j = 0; j<siz; j++){
            if(board[0][j] != '-'){
     for (i = 1; i < n; ++i) {
            if (board[i][j] != board[i - 1][j]) break;
        }
        if (i == n) {
              if(T == 1){
                break;
              }else
                    player = board[0][j];
                    cout <<player<<" wins"<<endl;
                    T = 1;
                    break;

            }
        }
    }
       if ((board[0][0] != '-')&& (T == 0)) {
            for (i = 1; i < n; ++i) {
                if (board[i][i] != board[i - 1][i - 1]) break;
            }
            if (i == n) {

                    player = board[0][0];
                    cout <<player<<" wins"<<endl;
                    T = 1;
            }
        }
        if ((board[0][n] != '-') && (T == 0)) {
            for (i = 1; i < n; ++i) {
                if (board[n - i - 1][i] != board[n - i][i - 1]) break;
            }
            if (i == n) {
                     player = board[0][n];
                    cout <<player<<" wins"<<endl;
                    T = 1;
            }
        }

            if(T == 0){
                cout<<"Tie"<<endl;
            }


  return 0;

}


