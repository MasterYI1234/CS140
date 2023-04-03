// Lab 5/6: Sudoku
//COSC140
//SiCheng Yi
#include <iostream>
#include <stdlib.h>
#include<vector>
#include <cstdio>
#include <stack>
using namespace std;
// My thoughts on solving Sudoku problems: 1: Input the Sudoku form
                                        //2: Guess one by one, until the whole solution is guessed at the end.
//I define a function check to check whether the possible number conflicts with the row, column and grid, the empty find function findEmpty, the problem solving function solveSudoku, and the display result function showResult.
                                            // 3: And define a 3Dvector "save", it can be used to store possible methods.
                                            //It slove all the suduku, (included  cc1)

vector<vector<int> > m(9, vector<int>(9));// The place to save the values are possible

vector< vector< vector<int> > > save(9,vector<vector<int > >(9,vector<int>(9)));


bool check(int x, int y, int n) {  //Check if there is a number n in the x row, y column, and grid, and return true if it exists
    for (int i = 0; i < 9; ++i)
	if (m[x][i] == n || m[i][y] == n) return true;
    for (int i = 3 * (x / 3); i < 3 * (x / 3) + 3; ++i)  //Check 3x3
	for (int j = 3 * (y / 3); j < 3 * (y / 3) + 3; ++j)
	    if (m[i][j] == n) return true;
    return false;
}

int findEmpty( ) {  //Looking for spaces, no spaces return a negative number, here I picked -10
    for (int i = 0; i < 81; ++i)
        if (!m[i/9][i%9]) return i;
    return -10;
}

bool solveSodoku() {
    stack<int> S;  //Define the stack, number the grids from left to right and top to bottom
    int n, x, y;        //n-number, x-row, y-column
    S.push(findEmpty( ));  //Put the found spaces on the stack
    while (!S.empty() && (S.top() >= 0)) {
	x = S.top() / 9;  y = S.top() % 9;
	for (n = 1 + m[x][y]; n <= 9 && check(x, y, n); ++n);//The spaces at x and y are checked in turn and can be filled
	if (n <= 9) {  //If n <= 9 this number can be filled
        save[x][y][n] = n;
	    m[x][y] = save[x][y][n];
	    S.push(findEmpty());   //find next
	} else {
	    m[x][y] = 0;    //No number can be filled, indicating a contradiction, set m[x][y] to 0
	    S.pop();       //backtrack
	}
    }
    return !S.empty( );
}

void showResult(bool ifdone) {  //print
    if (!ifdone) printf("There's no answer.\n");
    else for (int i = 0; i < 9; ++i) {
	    for (int j = 0; j < 9; ++j) {
	        if(j!=8){

	        cout<<m[i][j]<<" ";
	        }
	        else{

                cout<<m[i][j];
	        }

	    }

cout<<endl;
    }
}

int main( ) {
    for (int i = 0; i < 81; ++i) scanf("%d", &m[i/9][i%9]);   //Enter the Suduku
    showResult(solveSodoku( ));
    return 0;
}



