/** @file Dictionary.cpp
 * @brief Implementation of the Dictionary class used by Dictionary
 *    pointer/dynamic node based concrete implementations.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionaries and Hashing
 * @date   June 1, 2021
 *
 * Implementation of the Dictionary base class concrete member functions
 * and friend functions.
 */
#include "Dictionary.hpp"
#include "Employee.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Size accessor
 *
 * Accessor method to get the current size of this Dictionary of values.
 *
 * @returns int Returns the current size of the dictionary of values.
 */
template<class Key, class Value>
int Dictionary<Key, Value>::getSize() const
{
  return size;
}

/**
 * @brief Check if empty dictionary
 *
 * Accessor method to test if the Dictionary is currently
 * empty or not.
 *
 * @returns bool Returns true if the Dictionary is currently
 *   empty, or false if it has 1 or more items.
 */
template<class Key, class Value>
bool Dictionary<Key, Value>::isEmpty() const
{
  // can simply test size, if it is equal to 0, then it is true the
  // dictionary is empty, if it is not equal, then the answer is false
  return size == 0;
}

/**
 * @brief Overload output stream operator for Dictionary type.
 *
 * Overload the output stream operator so that we can display current
 * values of a Dictionary on standard output.  We can define this in the
 * base class because concrete derived classes must implement the
 * actual str() method that is used here to represent the
 * dictionary as a string object output.
 *
 * @param out The output stream we should send the representation
 *   of the current Dictionary to.
 * @param rhs The Dictionary object to create and return a string
 *   representation of on the output stream.
 *
 * @returns ostream& Returns a reference to the originaly provided
 *   output stream, but after we  have inserted current Dictionary
 *   values / representation onto the stream
 */
template<typename K, typename V>
ostream& operator<<(ostream& out, const Dictionary<K, V>& rhs)
{
  // reuse Dictionary str() method to stream to output stream
  out << rhs.str();

  // return the modified output stream as our result
  return out;
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class Dictionary<needed_type>
 * here of any types we are going to be instantianting with the
 * template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template ostream& operator<<<int, int>(ostream&, const Dictionary<int, int>&);
template ostream& operator<<<string, double>(ostream&, const Dictionary<string, double>&);

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class
 * Dictionary<needed_key_type, needed_value_type> here of any types we
 * are going to be instantianting with the template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class Dictionary<int, int>;
template class Dictionary<int, Employee>;
// template class Dictionary<string, double>;
