// Lab 2: neg.cpp
//COSC140
//SiCheng Yi


#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main (){

	string type;
	int rows=0, columns=0,temp=0, number = 0;
	cin >> type >> columns >> rows;
	
	//Error checking for the first input being P2.
	if(type != "P2"){
		cerr << "Bad PGM file -- first word is not P2"<< endl;
		return -1;
	}

	//Error checking for valid row and column inputs.
	if(rows <= 0){
		cerr << "Bad PGM file -- No row specification" << endl;
		return -1;
	}
	if(columns <= 0){
		cerr << "Bad PGM file -- No column specification" << endl;
	}
	//Inputting and checking whether there is a 255 after the columns and rows.
	cin >> temp;
	if(temp != 255){
		cerr << "Bad PGM file -- No 255 following the rows and columns" << endl;
		return -1;
	}

	//Outputting the negative pgm file.
	cout << "P2\n";
	cout << columns << " "<< rows<<endl;
	cout<< "255\n";

	for (int i=0;i < rows;i++){	
		for (int j=0;j<columns;j++){

			cin >> temp;

			//Error checking the validity of each pixel's values.
			if(temp >255 || temp < 0||cin.fail()){
				cerr << "Bad PGM file -- pixel " << number << " is not a number between 0 and 255" << endl;
				return -1;
			}
			number++;

			//Calculating and printing out the negative pixel.
			cout << 255-temp << endl;
		}
	}	

	//Error checking for stuff.
	if(cin >> type){
		cerr << "Bad PGM file -- Extra stuff after the pixels"<<endl;
		return -1;
	}

	return 0;


}