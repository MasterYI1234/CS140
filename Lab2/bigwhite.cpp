// Lab 2: bigwhite.cpp
//COSC140
//SiCheng Yi


#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <vector>

using namespace std;

int main (int argc, char* argv[]){

	//Error checking for improper number of arguments given.
	if(argc !=3){
		cerr << "usage: bigwhite rows cols"<< endl;
		return -1;
	}

	//Declaring rows and columns and inputting values.
	int rows=0, columns = 0;
	rows = atoi(argv[1]);
	columns = atoi(argv[2]);

	//Error checking for valid row and column inputs.
	if(rows <1 || columns <1){
		cerr << "usage: bigwhite rows cols"<< endl;
		return -1;
	}

	//Outputs the resulting pgm.
	cout << "P2\n";
	cout << columns << " "<< rows<<endl;
	cout<< "255\n";
	for(int i =0; i<rows;i++){
		for(int j =0; j<columns;j++){
			cout << "255" << endl;
		}
	}

	return 0;
}