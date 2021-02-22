#include "hashMap.h"

#include <cmath>
using namespace std;

HashMap::HashMap(int size) : table(size) {
  // FIXME: set the member variable p to the first prime smaller than size
}

// FIXME: copy your implementation from lab00
// Use this in the constructor above.
bool HashMap::isPrime(int n) const {
  return false;
}

// the two hashes needed for double hashing
int HashMap::hash1(int key) const { return key % table.size(); }
int HashMap::hash2(int key) const { return p - (key % p); }

// FIXME: implement this method
// Return an index in the table that is not yet Filled.
// You can assume there is at least one empty index when this method is called.
// Use the double hashing probing strategy to find an empty index:
//   (hash1(key) + i * hash2(key)) % table.size()
int HashMap::findEmptyIndex(int key) const {
  return -42;
}

// FIXME: implement this method
// Return the index in the table that contains the key, or -1 if it doesn't exist.
// 
// Use the double hashing probing strategy:
//   (hash1(key) + i * hash2(key)) % table.size()
//
// Remember to keep looking if an entry is EmptyAfterRemoval and stop looking if
// an entry is EmptySinceStart
// 
// But, watch out for the case where the table no longer contains any
// EmptySinceStart entries--it's possible that every entry is
// EmptyAfterRemoval or Filled. In that case, you should stop your
// search after visiting table.size() entries.
int HashMap::findIndexOfKey(int key) const {
  return -42;
}

// FIXME: implement this method
void HashMap::insert(int key, std::string value) {
  // if the key already exists, just update its value

  // Otherwise, find an empty index using the findEmptyIndex method to put 
  // the key and value
  // Set the key and value at the empty slot
  // Set the status of the slot to Filled
}

// FIXME: return true if the given key maps to *some* value in the hash table
bool HashMap::exists(int key) const { 
  return false;
}

// FIXME: return the value that is mapped to by the given key.
// Use the findIndexOfKey method.
// If the index is -1, you can let table.at throw an exception--
// that's the user's fault for not checking that the key exists first!
std::string& HashMap::at(int key) {
  return "";
}

// FIXME: implement this method
void HashMap::remove(int key) {
  // Find the index of the key you're trying to remove
  // Go to that index in the table, and set the status to EmptyAfterRemoval
  // (There's no need to change the value that is there, since we
  // skip all Empty buckets)
}
