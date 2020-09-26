#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <string>
#include <functional>

// The HashTable class maps keys of type K to values of type V.
// Precondition: The function:
//   unsigned int Hash(const K& k);
// exists for the type K. We will use that function to figure out
// which bucket to put the key k into.
template <class K, class V>
class HashTable {
public:
  HashTable(int tableSize);
  void insert(const K& key, const V& val);
  V* search(const K& key);

private:
  // our (key, value) pair type is HashTableItem
  // we hide this type from the user by putting it inside our class
  // and setting its visibility to private
  struct HashTableItem {
    K key;
    V val;
  };

  // our hash table is a vector of lists of HashTableItems
  std::vector<std::list<HashTableItem>> table;
};



// The non-templated Hash functions below really should be implemented
// outside of this .h file, but we're gonna break the rules for simplicity

unsigned int Hash(const int& i) {
  // FIXME: implement a hash function for ints here
  // How can you turn an int into an int? :)
  return _____________;
}

// FIXME: implement a hash function for chars here
// How can you turn a char into an int?

// FIXME: implement a hash function for std::strings here
// How can you turn a string into an int?
// Hint: combine your char hashes

// FIXME: implement a hash function for doubles here
// How can you turn a double into an int?
// Hint: one method is to convert the double to a string



// FIXME: implement the constructor
  // Use the constructor's tableSize parameter to initialize the table
  // vector to have size tableSize.
  // Hint: you can call one of vector's constructors to do this
template <class K, class V>
HashTable<K, V>::HashTable(int tableSize) {}



// FIXME: implement the insert method
  // use the Hash() function that we assume exists for Ks to figure
  // out where this key should go. Remember that the hash is not
  // itself an index into the table yet, so you'll need to shrink down
  // the result you get back.

  // Check if the key already exists in the table. If it does, just update the
  // value there. If not, add a brand new HashTableItem to the list.



// FIXME: implement the search method
  // return a pointer to the value for a given key, or nullptr if the key doesn't exist


#endif /* HASHTABLE_H */
