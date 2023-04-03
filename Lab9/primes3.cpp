// Lab 9: Is it prime?(Determining the performance of your solution)
//COSC140
//SiCheng Yi
#include <iostream>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {
map<int,int> m;  //make a map to save the prime just like the vector.

int num;  //the number
int n,i;
int check = 1;    //A data to help me check is the number in the vector?
int round = 0;    //The turn.


while(cin>> num){           //Check is it a prime?(copy from primes2.cpp

		for (n = 2; n < num; n++) {
			if (num % n == 0){
             cout << "not prime" << endl;
				break;
			}
		}
		if (n == num){
			cout << "prime" << endl;
		}




if(num > check){                 //Here is the part if num is larger than old number( check is 1 on first time, so first time also in here.) save the prime from the old largest number to this number.
for (int start = check; start <= num; start++)  //check all the prime from the old number to num.
{
for (i = 2; i <= sqrt(start); i++)
if (start%i == 0)
break;
if (i>sqrt(start)){
        round++;
        m[round] = num;  // save the prime to the map.
}

}
check = num;
}


if(num < check){

   if(m[num] != 0){  //find the num?
cout<<"Find it."<<endl;
   }
   else{
    cout<<"Not find it."<<endl;
   }


}

}
  return 0;

}

