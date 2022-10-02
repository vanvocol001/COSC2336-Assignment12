/** @file DictionaryException.hpp
 * @brief Declare Exceptions that can be thrown by Dictionary instances.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionarys and Hashing
 * @date   June 1, 2021
 *
 * Declare all exceptions that can be generated and thrown by Dictionary
 * instances.
 */
#ifndef _DICTIONARY_EXCEPTION_HPP_
#define _DICTIONARY_EXCEPTION_HPP_
#include <string>
using namespace std;

/** @class DictionaryKeyNotFoundException
 * @brief Dictionary Key Not Found Exception for the Dictionary class.
 *
 * Exception to be thrown by our Dictionary class if attempt to find
 * or remove a Key from the tree and that key is not present in the
 * tree.
 *
 */
class DictionaryKeyNotFoundException : public exception
{
public:
  explicit DictionaryKeyNotFoundException(const string& message);
  ~DictionaryKeyNotFoundException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

/** @class DictionaryKeyFormattingException
 * @brief Dictionary Key Not Found Exception for the Dictionary class.
 *
 * Exception to be thrown by our Dictionary class if attempt to find
 * or remove a Key from the tree and that key is not present in the
 * tree.
 *
 */
class DictionaryKeyFormattingException : public exception
{
public:
  explicit DictionaryKeyFormattingException(const string& message);
  ~DictionaryKeyFormattingException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

/** @class DictionaryDuplicateKeyInsertionException
 * @brief Dictionary Key Not Found Exception for the Dictionary class.
 *
 * Exception to be thrown by our Dictionary class if attempt to find
 * or remove a Key from the tree and that key is not present in the
 * tree.
 *
 */
class DictionaryDuplicateKeyInsertionException : public exception
{
public:
  explicit DictionaryDuplicateKeyInsertionException(const string& message);
  ~DictionaryDuplicateKeyInsertionException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

/** @class DictionaryMemoryBoundsException
 * @brief Dictionary Key Not Found Exception for the Dictionary class.
 *
 * Exception to be thrown by our Dictionary class if attempt to find
 * or remove a Key from the tree and that key is not present in the
 * tree.
 *
 */
class DictionaryMemoryBoundsException : public exception
{
public:
  explicit DictionaryMemoryBoundsException(const string& message);
  ~DictionaryMemoryBoundsException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

#endif // _DICTIONARY_EXCEPTION_HPP_