#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <vector>

// every element in the hash table needs a Status tag
enum Status { EmptySinceStart, EmptyAfterRemoval, Filled };

// we'll store (int, string) key/value pairs in our HashMap
struct HashTableItem {
  int key;
  std::string value;
  Status status = EmptySinceStart; // default initial tag
};

// The HashMap ADT is implemented with a hash table data structure
class HashMap {
 public:
  // constructor: create a HashMap with a given table size
  HashMap(int size);
  // insert a key/value pair
  void insert(int key, std::string value);
  // check if a key exists in the map
  bool exists(int key) const;
  // get the value for a certain key
  // (throws an exception if the key isn't found)
  std::string& at(int key);
  // gets rid of the value associated with a given key
  void remove(int key);

 private:
  // returns true if n is prime, false otherwise
  bool isPrime(int n) const;
  // the two hash functions for double hashing
  int hash1(int key) const;
  int hash2(int key) const;
  // returns back an index in the table that is EmptySinceStart or EmptyAfterRemoval
  int findEmptyIndex(int key) const;
  // returns the index of the key in the table, and -1 if it doesn't exist
  int findIndexOfKey(int key) const;

  // the actual hash table
  std::vector<HashTableItem> table;
  // p is a prime number smaller than table.size()--it's used in hash2
  int p;
};

#endif /* HASHMAP_H */
