// Lab 07: Adding List-Based Integers
#include "list.h"
#include "list.cpp"

using namespace std;
int main() {
    string numbera,numberb;
    while(cin>>numbera){
    cin>>numberb;
    List A;
    for(int c: numbera) A.makelistl1(c);
    for(int d: numberb) A.makelistl2(d);
    A.getsum();
    }
    return 0;
}


