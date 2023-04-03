// Lab 8: Hash tables(hash_140.cpp)
//COSC140
//SiCheng Yi
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "hash_140.hpp"

using namespace std;



// Declare our two hash functions
int Last7 (const string key, int table_size);
int XOR (const string key,int table_size);

// Constructor for the HashTable
string Hash_140::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision)
{

	//Error checking.
	if ((Keys.size()!=0) || Vals.size()!=0)
		return "Hash table already set up";

	if(table_size <=0)
		return "Bad table size";

	if((fxn != "XOR") && (fxn != "Last7"))
		return "Bad hash function";

	if((collision != "Linear") && (collision != "Double"))
		return "Bad collision resolution strategy";

	Keys.resize(table_size,"");
	Vals.resize(table_size,"");

	if(fxn == "XOR")
		Fxn = 0;
	else
		Fxn = 1;

	if(collision == "Linear")
		Coll = 'L';
	else
		Coll = 'D';

		return "";
}

//Function that adds values to the hash table.
string Hash_140::Add(const string &key, const string &val)
{
	//Error input.
	if ((Keys.size()==0) ||  Vals.size()==0)
		return "Hash table not set up";
	if (key == "")
		return "Empty key";


	for (unsigned int i = 0;i<key.size();i++){

		char k = key[i];
		//Error checking
		switch (k){
			case '0': break;
			case '1': break;
			case '2': break;
			case '3': break;
			case '4': break;
			case '5': break;
			case '6': break;
			case '7': break;
			case '8': break;
			case '9': break;
			case 'a': break;
			case 'b': break;
			case 'c': break;
			case 'd': break;
			case 'e': break;
			case 'f': break;
			case 'A': break;
			case 'B': break;
			case 'C': break;
			case 'D': break;
			case 'E': break;
			case 'F': break;
			default: return "Bad key (not all hex digits)";
		}
	}

	if (val == "")
		return "Empty val";
	int spaces = 0;
	for (unsigned int i  = 0; i < Keys.size();i++){
		if (Keys[i] ==""){
			spaces++;
		}
	}
	if (spaces == 0)
		return "Hash table full";

//The index of hash
	int index = 0;
	int index2 = 0;
	int newIndex = 0;

//Use the Last7 and XOR.
	if (Fxn == 1){
		if (Coll == 'L'){
			index = Last7 (key, Keys.size());
			while (Keys[index] != ""){    			//Making sure that the searching continues until a space is found.
				index = (index + 1) % Keys.size();
				if (key == Keys[index])
					return "Key already in the table";
			}
			newIndex = index;

		}else {
			int count = 0;
			//Calculating both index
			index = Last7 (key, Keys.size());
			index2 = XOR(key, Keys.size());
			if (index2 ==0 )
				index2 = 1;
			newIndex = (index + (count * index2)) % Keys.size();         //Get the new index.
			while (Keys[newIndex] != ""){
				newIndex = (index + (index2 * count)) % Keys.size();

				if (count >= (int)Keys.size())
					return "Cannot insert key";
				if (key == Keys[newIndex])
					return "Key already in the table";

				count++;
			}
		}

	}else{
		if (Coll == 'L'){
			index = XOR (key, Keys.size());
			while (Keys[index] != ""){
				index = (index +1) % Keys.size();
				index = index % Keys.size();
				if (key == Keys[index])
					return "Key already in the table";
			}
			newIndex = index;
		}else{
			int count = 0;
			index = XOR(key, Keys.size());
			index2 = Last7(key, Keys.size());
			if (index2 ==0)
				index2 = 1;

			newIndex = (index + (count * index2)) % Keys.size();
			while (Keys[newIndex] != ""){
				newIndex = (index + (index2 * count)) % Keys.size();

				if (count >= (int)Keys.size())
					return "Cannot insert key";
				if (key == Keys[newIndex])
					return "Key already in the table";

				count++;
			}
		}
	}
	//Inputting the keys and vals.
	Keys[newIndex] = key;
	Vals[newIndex] = val;
	return "";
}

//Probes the hash table to find the requested key's value
string Hash_140::Find(const string &key)
{
	//Error checking
	if ((Keys.size()==0) ||  Vals.size()==0)
		return "";
	for (unsigned int i = 0;i<key.size();i++){

		char k = key[i];
		switch (k){
			case '0': break;
			case '1': break;
			case '2': break;
			case '3': break;
			case '4': break;
			case '5': break;
			case '6': break;
			case '7': break;
			case '8': break;
			case '9': break;
			case 'a': break;
			case 'b': break;
			case 'c': break;
			case 'd': break;
			case 'e': break;
			case 'f': break;
			case 'A': break;
			case 'B': break;
			case 'C': break;
			case 'D': break;
			case 'E': break;
			case 'F': break;
			default: return "";
		}
	}
	Nprobes = 0;  	//Making Nprobes as 0.
	int index;
	if (Fxn == 1){  		//Find for last7
		if (Coll=='L'){
			index = Last7(key,Keys.size());
			for (unsigned int i = 0;i<Keys.size();i++){     //Searches entire table for key.
				if (Keys[index] == key)
					return Vals[index];
				index = (index + 1) % Keys.size();
				Nprobes++;
			}
		}else{             			//Find for Last7.
			index = Last7(key, Keys.size());
			int index2 = XOR(key, Keys.size());
			if (index2 == 0)
				index2 =1;
			for (unsigned int i  = 0; i < Keys.size(); i++){
				int newIndex = (index + (i * index2)) % Keys.size();
				if (Keys[newIndex] == key){
					return Vals[newIndex];
			   }
				Nprobes++;

			}
		}
	}else{    //Find for XOR
		if (Coll =='L'){
			index = XOR(key,Keys.size());
			for (unsigned int i  = 0; i< Keys.size();i++){
				if (Keys[index] == key)
					return Vals[index];
				index =  (index + 1) % Keys.size();
				Nprobes++;
			}
		}else{
			index = XOR(key, Keys.size());
			int index2 = Last7(key, Keys.size());
			if (index2 == 0)
				index2 = 1;
			for (unsigned int i  = 0; i < Keys.size(); i++){        			//Checks a reasonable number of time.
				int newIndex = ((index + (i * index2)) % Keys.size());
				if (Keys[newIndex] == key)
					return Vals[newIndex];
				Nprobes++;
			}
		}
	}
	Nprobes = 0;     	//Sets nprobes to 0 if it couldnt find the key.
	return "";
}

//The print function.
void Hash_140::Print() const
{
	for (unsigned int i = 0; i < Keys.size();i++){
		if (Keys[i] != "")
			printf ("%5d %s %s\n", i, Keys[i].c_str(), Vals[i].c_str());
	}
}


//Counts the total collisions.
size_t Hash_140::Total_Probes()
{
	Nprobes = 0;
	int count = 0;


//Resets Nprobes.
	for (unsigned int i = 0; i < Keys.size();i++){
		if (Keys[i] != ""){
			Find(Keys[i]);
		count += Nprobes;
		}
	}
	return count;
}

//Hashes a given code by using the last 7 characters as hex digits, and representing them as a decimal number
int Last7 (const string key, int table_size){

	string keyc = key;
	stringstream ss;
	int index = 0;

	//If the key < 8.
	if (key.size()>7)
		keyc = keyc.substr(keyc.size()-7,7);

	ss.str(keyc);
	ss >> hex >> index;
	index = index % table_size;
	return index;
}
// This function hashes a given code by separating the string into 7 character hex strings and performing an exclusive OR on them
int XOR (string key, int table_size){


	int temp = 0;
	int xsize = key.size()/7;
	vector <string> xs;
	vector <int> xi;
	stringstream ss;

	//Get key
	for(int i = 0; i <xsize; i++)
		xs.push_back(key.substr(i*7,7));

		//Getting the last part.
		if(key.size() % 7 !=0){
			xs.push_back(key.substr(7*xsize,key.size()%7));
		}

		xi.resize(xs.size());

		for (unsigned int i = 0;i<xs.size();i++){
			ss.clear();
			ss.str(xs[i]);
			ss >> hex >> xi[i];
			temp = xi[i] ^ temp;
		}
		//Making sure it is in temp.
		temp = temp % table_size;
		return temp;
	}
