//
// Created by Simon Aronsky on 6/5/20.
//

#ifndef HOMEWORK5_HASHEDENTRY_H
#define HOMEWORK5_HASHEDENTRY_H
#include "Entry.h"
#include <memory>

using namespace std;

template <class KeyType, class ValueType>
class HashedEntry : public Entry<KeyType, ValueType> {

public:
  HashedEntry(){};
  HashedEntry(KeyType searchKey, ValueType newValue){
    this->setKey(searchKey);
    this->setValue(newValue);
    this->setStatus(true);
  }
  HashedEntry(KeyType searchKey, ValueType newValue,
              shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr) {
    setKey(searchKey);
    setValue(newValue);
    nextPtr = nextEntryPtr;
  }

  void setNext(shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr) {
    nextPtr = nextEntryPtr;
    collisionCount++;
  }
  auto getNext() { return nextPtr; }
  int getCollision() { return collisionCount; }

private:
  shared_ptr<HashedEntry<KeyType, ValueType>> nextPtr;
  int collisionCount = 0;
};
#endif // HOMEWORK5_HASHEDENTRY_H
