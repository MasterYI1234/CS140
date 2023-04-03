// Lab 2: hflip.cpp
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
		vector<int> pixels;
		int column, row, color, numPixels;
		string p2;
		PGMFile();
		void flipImage();
};

int main(int argc, char **argv) {
	PGMFile pgm;
	int currentPixel = 0, tempNumber = 0;
	string input;

	cin >> pgm.p2;
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

	pgm.flipImage();

	return 0;
}

PGMFile::PGMFile()
	: column(0), row(0), color(0), numPixels(0) {}

void PGMFile::flipImage() {
	int x, y, pixelTmp;

	printf("%s\n%d %d\n%d\n", p2.c_str(), column, row, color);

	for (y = 0; y < row; y++) {
		for(x = column; x > 0; x--) {
			int index = ((y * column) + x - 1);
			pixelTmp = pixels[index];
			printf("%d ", pixelTmp);
		}
		printf("\n");
	}
}
