//
// Created by Simon Aronsky on 6/5/20.
//

#ifndef HOMEWORK5_ENTRY_H
#define HOMEWORK5_ENTRY_H
#include <iostream>

template <class KeyType, class ValueType> class Entry {
private:
  KeyType key;
  ValueType value;
  bool status = false;

protected:
  void setKey(const KeyType &searchKey) { key = searchKey; }

public:
  Entry(){};
  Entry(const KeyType &searchKey, const ValueType &newValue)
      : key(searchKey), value(newValue), status(true){};
  ValueType getValue() const { return value; }
  KeyType getKey() const { return key; }
  void setValue(const ValueType &newValue) { value = newValue; }
  bool getStatus() { return status; }
  void setStatus(bool newStatus) { status = newStatus; }

  bool operator==(const Entry<KeyType, ValueType> &rightHandValue) const {
    return value == rightHandValue.getValue();
  }
  bool operator>(const Entry<KeyType, ValueType> &rightHandValue) const {
    return value < rightHandValue.getValue();
  }
};

#endif // HOMEWORK5_ENTRY_H
