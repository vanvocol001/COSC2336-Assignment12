/** @file HashDictionary.hpp
 * @brief Header file with definitions of concrte HashDictionary implementation
 *   of the Dictionary container abstraction
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionaries and Hashing
 * @date   June 1, 2021
 *
 * Assignment Dictionaries and Hashing.  Implement member functions
 * for a HashDictionary class for an open hashing scheme with a
 * quadratic probe sequence. This header file contains the declaration
 * of the HashDictionary class data structure.  This file is derived
 * from and implements the defined ADT of a Dictionary class.  You
 * need to add the member function prototypes to this file for this
 * assignment.
 */
#ifndef HASHDICTIONARY_HPP
#define HASHDICTIONARY_HPP
#include "Dictionary.hpp"
#include "KeyValuePair.hpp"
#include <string>
using namespace std;

/** @class HashDictionary
 * @brief Concrete array based implementation of Dictionary API
 *
 * An implementation of a dictionary that uses a hash table to insert, search
 * and delete a set of KeyValuePair items.  In the assignment, we will be
 * implementing a closed hashing table with quadratic probing.  The hash function
 * will implement a version of the mid-square hashing function described in
 * our Shaffer textbook.
 */
template<class Key, class Value>
class HashDictionary : public Dictionary<Key, Value>
{
public:
  // constructors and destructors
  HashDictionary(int allocationSize = INITIAL_ALLOCATION_SIZE);
  HashDictionary(int size, const Key keys[], const Value values[]);
  ~HashDictionary();

  // accessor and informaton methods
  int getAllocationSize() const;
  string str() const;

  // adding, accessing and removing values from the Dictionary (Dictionary API)
  void clear();

  // overloaded operators and other functions for testing
  KeyValuePair<Key, Value>& operator[](int index);

  void insert(const Key& key, const Value& value);
  Value find(const Key& key) const;
  Value remove(const Key& key);
private:
  /// @brief private constant, initial allocation size for empty hash
  ///   dictionaries if not specified
  const static int INITIAL_ALLOCATION_SIZE = 5;

  /// @brief  An array of KeyValuePair items, the hash table this
  ///   class/container is managing.
  KeyValuePair<Key, Value>* hashTable;

  /// @brief  The actual allocated memory size of the hashTable array
  int allocationSize;

  // private member methods for managing the HashDictionary internally
  void growHashDictionaryIfNeeded();
  int probe(const Key& key, int index) const;
  int hash(const Key& key) const;
  int probeForAvailableSlot(const Key& key) const;
  int probeForKeySlot(const Key& key) const;
};

#endif // HASHDICTIONARY_HPP
