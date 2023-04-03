// Lab 9: Is it prime?(Finding primes)
//COSC140
//SiCheng Yi
#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {  //get number from the arg.

istringstream number;
int num;             //the number.
int round = 0;            //Save the turn.
int n, i;

if (argc != 2) {          // check if it not input a number.
   cout<<"Error! Just enter one number!"<<endl;  // output error.
    return 0;
  }
    number.str(argv[1]); //get the number to num.
number >> num;
//cin>> num;   //Just a cin to help me test the program.

for (n = 2; n <= num; n++)  //Check all primes from 2 to num.
{
for (i = 2; i <= sqrt(n); i++)
if (n%i == 0)
break;
if (i>sqrt(n)){
cout << n << " ";
round++;
}

if(round % 20 == 0){      //20 number in a line.
    cout << endl;
}
}

cout << endl;





  return 0;

}

