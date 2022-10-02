/** @file Dictionary.hpp
 * @brief Abstract base class definition of Dictionary abstract data type.
 *   This header defines the abstraction/interface for concrete
 *   Dictionary implementations.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionaries and Hashing
 * @date   June 1, 2021
 *
 * Definition of Dictionary abstraction.  Concrete implementations of
 * this Dictionary interface must inherit from this abstract base class
 * and implement all defined virtual functions.
 */
#ifndef _DICTIONARY_HPP_
#define _DICTIONARY_HPP_
#include <iostream>
using namespace std;

/** @class Dictionary
 * @brief The Dictionary data type abstraction
 *
 * The defined ADT interface for a Dictionary data type.  This abstraction
 * provides the ability to perform the most common tasks we want to
 * perform with dictionarys, such as insert items and search for items
 * in the collection of key/value pairs.
 */
template<class Key, class Value>
class Dictionary
{
public:
  // accessor and information methods
  int getSize() const;
  bool isEmpty() const;
  virtual string str() const = 0;

  // adding, accessing and removing values from the dictionary
  virtual void clear() = 0;
  virtual void insert(const Key& key, const Value& value) = 0;
  virtual Value find(const Key& key) const = 0;
  virtual Value remove(const Key& key) = 0;

  // friend functions and friend operators
  template<typename K, typename V>
  friend ostream& operator<<(ostream& out, const Dictionary<K, V>& rhs);

protected:
  /// @brief the current size of the Dictionary of values, this is
  ///   protected so derived classes can access it
  int size;
};

#endif // _DICTIONARY_HPP_
