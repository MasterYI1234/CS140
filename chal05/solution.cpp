#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

// from Dr. Plank's lecture notes from hashing, most simple hash function you can think of
unsigned int bad_hash(const string &s)
{
  size_t i;
  unsigned int h;

  h = 0;

  for (i = 0; i < s.size(); i++) {
    h += s[i];
  }
  return h;
}

int main() {

  string line;
  int cnt;
  vector<list<string> > data;
  data.resize(200000);

  int h;
  int collisions = 0;

  while (getline(cin, line)) {

    h = bad_hash(line);
    data[h].push_back (line);

    if (data[h].size() > 1)
      collisions++;

  }

  // compute load factor of hash table here

}
