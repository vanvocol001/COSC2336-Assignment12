/** @file KeyValuePair.cpp
 * @brief Implementation file with implementations of KeyValuePair
 * template abstraction
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionaries and Hashing
 * @date   June 1, 2021
 *
 * Template class for definining Key/Value pairs, suitable for dictionary and
 * hash table implementations. Based on Shaffer KVPair ADT definition, pg. 139
 * Fig 4.31.
 */
#include "KeyValuePair.hpp"
#include "Employee.hpp"
#include <string>
using namespace std;

/**
 * @brief Default constructor
 *
 * Default constructor for a KeyValuePair.
 */
template<class Key, class Value>
KeyValuePair<Key, Value>::KeyValuePair()
{
  // ensure that values are constructed with defaults for the Key
  // Value type
  this->setEmpty();
}

/**
 * @brief Standard constructor
 *
 * Standard constructor for a KeyValuePair.
 *
 * @param key The key portion that is to be stored in this pair.
 * @param value The value portion that is to be stored in this pair.
 */
template<class Key, class Value>
KeyValuePair<Key, Value>::KeyValuePair(Key key, Value value)
{
  this->key = key;
  this->value = value;
  this->empty = false;
  this->missing = false;
}

/**
 * @brief key accessor
 *
 * Accessor method to get and return the key for this key/value pair
 *
 * @returns Key Returns an object of template type Key, which is the
 *   key portion of the pair in this container.
 */
template<class Key, class Value>
Key KeyValuePair<Key, Value>::getKey() const
{
  return this->key;
}

/**
 * @brief value accessor
 *
 * Accessor method to get and return the value for this key/value pair.
 *
 * @returns Value& Returns a reference to the value object in this
 *   key value pair container.
 */
template<class Key, class Value>
Value& KeyValuePair<Key, Value>::getValue()
{
  return this->value;
}

/**
 * @brief Set slot to emptyy
 * Mutator method to set the key/value pair as being empty.
 * The key and value are set to default values, the empty flag
 * is set to true and the missing flag is false.
 */
template<class Key, class Value>
void KeyValuePair<Key, Value>::setEmpty()
{
  this->key = Key();
  this->value = Value();
  this->empty = true;
  this->missing = false;
}

/**
 * @brief Set slot as missing
 *
 * Mutator method to set this key/value pair slot to be missing.
 * The key and value are set to default values, the empty flag is set
 * to false, but the missing flag is set to true.
 */
template<class Key, class Value>
void KeyValuePair<Key, Value>::setMissing()
{
  this->key = Key();
  this->value = Value();
  this->empty = false;
  this->missing = true;
}

/**
 * @brief Is slot empty
 *
 * Accessor method, returns true if the key/value pair slot is empty,
 * false if it is not. An empty slot means it can be assinged a
 * key/value pair in the container in this memory allocation.
 */
template<class Key, class Value>
bool KeyValuePair<Key, Value>::isEmpty() const
{
  return this->empty;
}

/**
 * @brief Is slot missing
 *
 * Accessor method, returns true if the key/value pair slot is missing,
 * false if it is not.  A missing slot is a slot that had a value but
 * was removed.  For purposes of search, a missing slot is not empty,
 * so may need to keep searching if probing at a missing slot.
 */
template<class Key, class Value>
bool KeyValuePair<Key, Value>::isMissing() const
{
  return this->missing;
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class
 * KeyValuePair<needed_key_type, needed_value_type> here of any types
 * we are going to be instantianting with the template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class KeyValuePair<int, int>;
template class KeyValuePair<int, Employee>;
// template class KeyValuePair<string, double>;
