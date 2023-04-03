// Challenge 2 (palindrome)
//cosc140
//SiCheng Yi
#include<iostream>
#include<cstring>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    int top = 0;// The top which we get.
    int mid = 0;//The mid of the number.
    int len = 0;// How long of the number
    int next;  //The place of next char.
	int n;

	cin >> n; // con the long
	len = n;

    vector <int>  ori(n);  //orginal vector
    vector <double> s(n);  // check vector


for(int i=0; i<n; i++){
	cin >> s[i];    // put in to the vector
}

	mid = len / 2;  //get the mid space.
	for(int i = 0; i < mid; i++){  // save the number
		ori[i] = s[i];
		top++;
	}
	if(len % 2 == 0){ //We are in mid place now. Set the next of the mid.
		next = mid ;
	}else{
		next = mid + 1;
	}
	for(int i = next; i < len; i++){  // check if it is palindrome.
            		while(ori[top - 1] != s[i] && top != 0){
			cout << "Not a palindrome"<<endl;
			return 0;
		}
		top--;
	}
	cout << "Palindrome"<<endl;
	return 0;
}
