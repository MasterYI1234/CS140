// Lab 9: Is it prime?(Practicing using STL search functions)
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

using namespace std;

int main() {
vector<int> save;    //make a vector to save the prime.

int num;         //the number.
int n,i;
int check = 1;   //A data to help me check is the number in the vector?


while(cin>> num){   //cin the number.

		for (n = 2; n < num; n++) {   //This loop is check is the num prime?
			if (num % n == 0){
             cout << "not prime" << endl;
				break;
			}
		}
		if (n == num){
			cout << "prime" << endl;
		}
	}                     //Until here, the part of make test output is finish.



if(num > check){                  //Here is the part if num is larger than old number( check is 1 on first time, so first time also in here.) save the prime from the old largest number to this number.
for (int start = check; start <= num; start++)        //check all the prime from the old number to num.
{
for (i = 2; i <= sqrt(start); i++)
if (start%i == 0)
break;
if (i>sqrt(start)){
 save.push_back( start );  //push back the prime to the vector.
}

}

}


if(num < check){   //If the num is smaller than old number, then use the find or binary_search to check the time which use the find() or the binary_search().
vector<int>::iterator it = find(save.begin(), save.end(), num);

if (it == save.end()){
//if(!binary_search(save.begin(), save.end(), num)){
    // save.push_back( num );
    cout<<"not find"<<endl;

}
else{
    cout<<"Find"<<endl;
}
}
  return 0;

}

