#include "HashedEntry.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef HashedEntry<int, int> MyHashedEntry;

shared_ptr<MyHashedEntry> addRecursive(shared_ptr<HashedEntry<int, int>> entry,
                                       int value, int key);
vector<MyHashedEntry> add(vector<MyHashedEntry> entry, int value);
vector<int> minMaxNone(vector<MyHashedEntry> entry);

int main() {
  vector<MyHashedEntry> first;
  first.resize(10);
  vector<MyHashedEntry> second;
  second.resize(11);
  vector<MyHashedEntry> third;
  third.resize(23);
  vector<MyHashedEntry> fourth;
  fourth.resize(40);
  fstream fin;
  fin.open("DataInput.txt",
           ios::in);
  while (fin.good()) {
    int val;
    fin >> val;
    first = add(first, val);
    second=add(second, val);
    third=add(third, val);
    fourth=add(fourth, val);
  }
  vector<int> feedback = minMaxNone(first);

  cout << "First"<<endl<<"Size: " << first.size()
       << "   Maximum Collisions: " << feedback[0]
       << "   Minimum Collisions: " << feedback[1] << "   No Data: " << feedback[2]<<endl<<endl;

  feedback = minMaxNone(second);
  cout << "Second"<<endl<<"Size: " << second.size()
       << "   Maximum Collisions: " << feedback[0]
       << "   Minimum Collisions: " << feedback[1] << "   No Data: " << feedback[2]<<endl<<endl;

  feedback = minMaxNone(third);
  cout << "Third"<<endl<<"Size: " << third.size()
       << "   Maximum Collisions: " << feedback[0]
       << "   Minimum Collisions: " << feedback[1] << "   No Data: " << feedback[2]<<endl<<endl;

  feedback = minMaxNone(fourth);
  cout << "Fourth"<<endl<<"Size: " << fourth.size()
       << "   Maximum Collisions: " << feedback[0]
       << "   Minimum Collisions: " << feedback[1] << "   No Data: " << feedback[2];
  return 0;
}

vector<int> minMaxNone(vector<MyHashedEntry> entry) {
  int noneCount = 0;
  int min = entry[0].getCollision();
  int max = entry[0].getCollision();
  for (int i = 0; i < entry.size(); i++) {
    if (!entry[i].getStatus())
      noneCount++;
    if (entry[i].getCollision() < min)
      min = entry[i].getCollision();
    if (entry[i].getCollision() > max)
      max = entry[i].getCollision();
  }
  return vector<int>{max, min, noneCount};
}


vector<MyHashedEntry> add(vector<MyHashedEntry> entry, int value) {
  int size = entry.size();
  int key = value % size;
  if (!entry[key].getStatus())
    entry[key] = HashedEntry<int, int>(key, value);
  else
    entry[key].setNext(addRecursive(entry[key].getNext(), value, key));
  return entry;
}

shared_ptr<MyHashedEntry> addRecursive(shared_ptr<MyHashedEntry> entry,
                                       int value, int key) {
  if (entry == nullptr)
    entry = make_shared<MyHashedEntry>(key, value);
  else
    entry->setNext(addRecursive(entry->getNext(), value, key));
  return entry;
}
