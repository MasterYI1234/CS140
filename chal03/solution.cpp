// Challenge 3 (Monkey sort!)
//cosc140
//SiCheng Yi
#include<iostream>
#include<cstring>
#include <vector>
#include <sstream>
#include <algorithm>  //shuffle
#include <time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;



bool check(vector<int> a, int n)  //Check for ordered
{
    int i;
    for(i = 0; i < n-1; i++) // i+1 can not larger for n so i < n-1;
    {
        if(a[i] > a[i+1])  return false;
    }
    return true;
}


int main(int argc, char *argv[]){
     int n;  //The number we need
     int count = 0;  // The count of shuffle
     istringstream ss;  //The istringstream


    if(argc!=2){    //Just enter one number.
        cout<<"Error! Invalid no. of command line arguments!"<<endl;
    }

   ss.str(argv[1]);
   ss >> n;  //Take the number to n.

    vector<int>  card;  //The vector for card.
 //   srand (time (NULL));   //The seed of rand.

     for(int i = 1; i <= n; i++){  //Put the number in to the vector.
        card.push_back(i);
     }
  while(1){
   random_shuffle(card.begin(),card.end());   // Shuffle it
    count++;
    if(check(card,n) == true){   // If the vector is ordered.
        break;
    }

  }
cout << count <<endl;   //Print the number of shuffle


return 0;

}
