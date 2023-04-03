// Lab 3:Connect Four(C4Col.h)
//COSC140
//SiCheng Yi
#ifndef C4COL_H
#define C4COL_H

#include <iostream>

class C4Col {
public:
    C4Col();
    int isFull();   //determines if the column is full  (nn = nm)
    char getDisc(int i);  //returns the requested element of the private character array (i.e., getDisc(0) will return Discs[0]);
    int getMaxDiscs();  //returns the maximum number of discs (i.e., number of rows)
    void addDisc(char i);  // adds the character representing a disc to the next open slot in the Disc array (i.e., Discs[numDiscs++] = newDisc)
    int getNowDiscs();   // Take nn for C4Board

private:
    int nn;   //Number now  of a col
    int nm;   //Number max of a col
    char Disc[6]; //array to save
};

#endif
