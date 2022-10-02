/** @file KeyValuePair.hpp
 * @brief Header file with definitions of KeyValuePair class template abstraction
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
#ifndef KEYVALUEPAIR_HPP
#define KEYVALUEPAIR_HPP

/** @class KeyValuePair
 * @brief Key/Value pair container records
 *
 * Definition of basic key/value pair container.  This container of course
 * associates a value (usually a record like a class or struct), with
 * a key (can be anything).
 *
 * We do not use the comparator Strategy pattern as discussed in
 * Shaffer pg. 144 here.  We assume that the Key type has suitably
 * overloaded operators for <, >, ==, <=, >= operations as needed
 * in order to compare and order keys if needed by dictionaries and
 * hash tables using a KeyValuePair.
 *
 * This template abstraction is designed to work as an object in a slot
 * of an abstract Dictionary container.  Some containers need a way to
 * indicate two separate states, an EMPTY container slot, and a MISSING
 * container slot.  This template class supports determining these
 * states for a KeyaluePair in a container slot where we may need
 * to if the value slot is empty or missing.
 */
template<class Key, class Value>
class KeyValuePair
{
public:
  // constructors
  KeyValuePair();
  KeyValuePair(Key key, Value value);

  // accessors, getters and setters
  Key getKey() const;
  Value& getValue();

  // information methods to manage empty and/or missing slots in a Dictionary
  // container
  void setEmpty();
  void setMissing();
  bool isEmpty() const;
  bool isMissing() const;

private:
  /// @brief The key for a key/value pair item/association.
  Key key;

  /// @brief The value for a key/value pair, usually something like a record
  ///   (a class or struct of data we are hashing or keeping in a dictionary).
  Value value;

  /// @brief The empty boolean flag keeps track of if this key/value pair in a slot
  ///   is empty, which means it currently has no value and can be filled with
  ///   a new value.
  bool empty;

  /// @brief The missing boolean flag indicates a slot was previously filled, but
  ///   the value was removed and is now missing.  This is needed for closed hashing
  ///   schemes to correctly implement probe sequences when values can be removed
  bool missing;
};

#endif // KEYVALUEPAIR_HPP
