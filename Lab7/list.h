// Lab 3:Connect Four(C4Col.h)
//COSC140
//SiCheng Yi
#ifndef C4COL_H
#define C4COL_H

#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>

using namespace std;

class List {
public:
    struct node{
        int data;
        node * next;
    };
    List();
    void makelistl1(int);
    void makelistl2(int);
    void getsum();




private:
       node * l1;
       node * l2;
       int carry;
};

#endif
