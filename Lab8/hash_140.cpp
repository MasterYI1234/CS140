#include "hash_140.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

// Declare our two hash functions
int Last7(string &code);
int XOR(string &code);

string Hash_140::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision)
{
  Keys.resize(table_size);
	Vals.resize(table_size);
	if (fxn == "Last7") Fxn = 1;
	else Fxn = 2; // XOR
	if (collision == "Linear") Coll = 1;
	else Coll = 2; // Double
	Nkeys = 0;
	Nprobes = 0;
  return "";
}

string Hash_140::Add(const string &key, const string &val)
{
  if (Nkeys == Keys.size()) fprintf(stderr, "Hash Table Full\n");
	else {
		int i = 0; // Index
		int hash = 0, step = 0, times = 1;
		bool insert = false;
		int repeats = 0;

		if (Fxn == 1) hash = Last7(key);
		else hash = XOR(key);
		i = hash % Keys.size();

// For double hashing, if we get the same value more than once we know it can't be inserted into the table
		repeats = i;
		while (insert == false) {
			if (Keys[i] != "") {
				if (Coll == 1) {
					i = (i + 1) % Keys.size();
					Nprobes++;
				}
				else {
					if (Fxn == 1) step = (XOR(key) % Keys.size());
					else step = (Last7(key) % Keys.size());
					if (step == 0) step = 1;
					i = (hash + (times * step)) % Keys.size();
						if (i == repeats) {
							fprintf(stderr, "Couldn't put %s into the table\n", key.c_str());
							exit(1);
						}
					Nprobes++;
					times++;
				}
			}
			else {
				Keys[i] = key;
				Vals[i] = val;
				insert = true;
				Nkeys++;
				repeats = 0;
			}
		}
	}
  return "";
}

string Hash_140::Find(const string &key)
{
  int i = 0; // Index
	for (i; i < Keys.size(); i++) {
		if (Keys[i] == key) return Vals[i];
	}

  return "";
}

void Hash_140::Print() const
{
    for (int i = 0; i < Keys.size(); i++) {
		if (Keys[i] != "") {
			printf("%5d %s %s\n", i, Keys[i].c_str(), Vals[i].c_str());
		}
	}
}

size_t Hash_140::Total_Probes()
{
  return Nprobes;
}


//Hashes a given code by using the last 7 characters as hex digits, and representing them as a decimal number
int Last7(string &code) {
	int i = 0;
	int length = code.length();
	stringstream ss;
	string temp;

	if (length <= 7) {
		ss << code;
		ss >> hex >> i;
	}
	else {
		for (int j = length - 7; j < length; j++) {
			temp.push_back(code[j]);
		}
		ss << temp;
		ss >> hex >> i;
	}

	return i;
}

// This function hashes a given code by separating the string into 7 character hex strings and performing an exclusive OR on them
int XOR(string &code) {
	int i = 0, j = 0, length = code.length();
	unsigned int hash = 0, nextWord = 0;
	stringstream ss;
	istringstream ss2;
	vector<string> subKeys;

	if (length <= 7) {
		ss << code;
		ss >> hex >> i;
	}
	else {
		for (j = 0; j < length; j++) {
			if (j%7 == 0) subKeys.push_back(code.substr(j, 7));
		}

		for (j = 0; j < subKeys.size(); j++) {
			ss2.clear();
			ss2.str(subKeys[j]);
			ss2 >> hex >> nextWord;
			hash = nextWord ^ hash;
		}
	}

	return hash;
}
