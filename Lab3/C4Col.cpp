// Lab 3:Connect Four(C4Col.cpp)
//COSC140
//SiCheng Yi
#include <iostream>
#include "C4Col.h"

using namespace std;


C4Col::C4Col(){
       nn = 0;
       nm = 6;
       for(int i = 0; i < nm ; i++){
        Disc[i] = '-';
       }
}


int C4Col::isFull() {   //Check is it full?
      if(nn == nm){
        return 1;
      }
      return 0;
}

 char C4Col::getDisc(int i) {  //Get the char in the Disc
     if( i < 6 ){
   return Disc[i];
     }
     else
     {
         cout << "Error! Invalid input!"<<endl;
        return ' ';
     }
}

 int C4Col::getNowDiscs(){
   return nn - 1;
}

 int C4Col::getMaxDiscs(){
   return nm;

}

void C4Col::addDisc(char i) {     // Add the char to the disc
    if(isFull() == 1){
        cout << "Error! The column is full."<<endl;
        return;
    }
   Disc[nn] = i;
   nn++;
}

