// Lab 2: pgminfo.cpp
//COSC140
//SiCheng Yi

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

class PGMFile {
	public:
                                //set the date.
		vector<int> pixels;
		int column, row, color, numPixels;
		string p2;
		PGMFile();
};

int main(int argc, char **argv) {
                //Set the variable
	PGMFile pgm;
	double avgPixel = 0;
	int currentPixel = 0, tempNumber = 0;
	string input;
   
	cin >> pgm.p2;
                //Check if it is wrong.
	if (pgm.p2 != "P2" || cin.fail()) {
		fprintf(stderr, "Bad PGM file -- first word is not P2\n");
		return -1;
	}

	cin >> pgm.column;
	if (pgm.column < 1 || cin.fail()) {
		fprintf(stderr, "Bad PGM file -- No column specification\n");
		return -1;
	}

	cin >> pgm.row;
	if (pgm.row < 1 || cin.fail()) {
		fprintf(stderr, "Bad PGM file -- No row specification\n");
		return -1;
	}

	cin >> pgm.color;
	if (pgm.color != 255 || cin.fail()) {
		fprintf(stderr, "Bad PGM file -- No 255 following the rows and columns\n");
		return -1;
	}

	pgm.numPixels = pgm.row * pgm.column;

	for (currentPixel = 0; currentPixel < pgm.numPixels; currentPixel++) {
		cin >> tempNumber;
		if (tempNumber < 0 || tempNumber > 255 || cin.fail()) {
			fprintf(stderr, "Bad PGM file -- pixel %d is not a number between 0 and 255\n", currentPixel);
			return -1;
		}
		pgm.pixels.push_back(tempNumber);
	}

	if (cin >> input) {
		fprintf(stderr, "Bad PGM file -- Extra stuff after the pixels\n");
		return -1;
	}

	for (std::size_t k = 0; k < pgm.pixels.size(); k++) {
		avgPixel += pgm.pixels[k];
	}
	avgPixel /= pgm.numPixels;
            //Output the pgm.
	printf("# Rows: %11d\n", pgm.row);
    printf("# Columns: %8d\n", pgm.column);
    printf("# Pixels: %9d\n", pgm.numPixels);
    printf("Avg Pixel: %8.3f\n", avgPixel);

	return 0;
}

PGMFile::PGMFile()
	: column(0), row(0), color(0), numPixels(0) {}
