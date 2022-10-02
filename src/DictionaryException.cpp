/** @file DictionaryException.cpp
 * @brief Implement Exceptions that can be thrown by Dictionary instances.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionaries and Hashing
 * @date   June 1, 2021
 *
 * Implement all exception methods that can be generated and thrown by Dictionary
 * instances.
 */
#include "DictionaryException.hpp"
#include <string>
using namespace std;

/**
 * @brief DictionaryKeyNotFoundException constructor
 *
 * Constructor for exceptions used for our
 * Dictionary class.
 *
 * @param message The exception message thrown when an error occurs.
 */
DictionaryKeyNotFoundException::DictionaryKeyNotFoundException(const string& message)
{
  this->message = message;
}

/**
 * @brief DictionaryKeyNotFoundException destructor
 *
 * Destructor for exceptions used for our DictionaryKeyNotFoundException
 * class.
 */
DictionaryKeyNotFoundException::~DictionaryKeyNotFoundException() {}

/**
 * @brief DictionaryKeyNotFoundException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* DictionaryKeyNotFoundException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}

/**
 * @brief DictionaryKeyFormattingException constructor
 *
 * Constructor for exceptions used for our
 * Dictionary class.
 *
 * @param message The exception message thrown when an error occurs.
 */
DictionaryKeyFormattingException::DictionaryKeyFormattingException(const string& message)
{
  this->message = message;
}

/**
 * @brief DictionaryKeyFormattingException destructor
 *
 * Destructor for exceptions used for our DictionaryKeyFormattingException
 * class.
 */
DictionaryKeyFormattingException::~DictionaryKeyFormattingException() {}

/**
 * @brief DictionaryKeyFormattingException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* DictionaryKeyFormattingException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}

/**
 * @brief DictionaryDuplicateKeyInsertionException constructor
 *
 * Constructor for exceptions used for our
 * Dictionary class.
 *
 * @param message The exception message thrown when an error occurs.
 */
DictionaryDuplicateKeyInsertionException::DictionaryDuplicateKeyInsertionException(const string& message)
{
  this->message = message;
}

/**
 * @brief DictionaryDuplicateKeyInsertionException destructor
 *
 * Destructor for exceptions used for our DictionaryDuplicateKeyInsertionException
 * class.
 */
DictionaryDuplicateKeyInsertionException::~DictionaryDuplicateKeyInsertionException() {}

/**
 * @brief DictionaryDuplicateKeyInsertionException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* DictionaryDuplicateKeyInsertionException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}

/**
 * @brief DictionaryMemoryBoundsException constructor
 *
 * Constructor for exceptions used for our
 * Dictionary class.
 *
 * @param message The exception message thrown when an error occurs.
 */
DictionaryMemoryBoundsException::DictionaryMemoryBoundsException(const string& message)
{
  this->message = message;
}

/**
 * @brief DictionaryMemoryBoundsException destructor
 *
 * Destructor for exceptions used for our DictionaryMemoryBoundsException
 * class.
 */
DictionaryMemoryBoundsException::~DictionaryMemoryBoundsException() {}

/**
 * @brief DictionaryMemoryBoundsException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* DictionaryMemoryBoundsException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}