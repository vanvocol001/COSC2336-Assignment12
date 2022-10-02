/** @file test-HashDictionary.cpp
 * @brief Unit tests for Assignment Dictionaries and Hashing
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionaries and Hashing
 * @date   June 1, 2021
 *
 * Tests of the HashDictionary hash table implementation of the Dictionary API.
 */
#include "DictionaryException.hpp"
#include "catch.hpp"
#include <iostream>
#include <string>
// a testing kludge so we can test some private members you are to implement for this task
#define private public
#include "HashDictionary.hpp"
#undef private
#include "Employee.hpp"
using namespace std;

// multiline string literal expected for empty tables
const string emptyTable = "<HashDictionary> size: 0\n"
                          "Slot: 0\n"
                          "     Key  : EMPTY\n"
                          "     Value:\n"
                          "Slot: 1\n"
                          "     Key  : EMPTY\n"
                          "     Value:\n"
                          "Slot: 2\n"
                          "     Key  : EMPTY\n"
                          "     Value:\n"
                          "Slot: 3\n"
                          "     Key  : EMPTY\n"
                          "     Value:\n"
                          "Slot: 4\n"
                          "     Key  : EMPTY\n"
                          "     Value:\n";

/** Test HashDictionary construction and basic operations
 */
TEST_CASE("HashDictionaryNode<int, int> test hash dictionary construction <int,int> key/value types", "[task0]")
{
  // test empty tree construction
  HashDictionary<int, int> empty;
  CHECK(empty.getSize() == 0);
  CHECK(empty.getAllocationSize() == 5);
  CHECK(empty.isEmpty());
  CHECK(empty.str() == emptyTable);
}

/** Test HashDictionary construction and basic operations
 */
TEST_CASE("HashDictionaryNode<int, Employee> test hash dictionaryconstruction <int,Employee> key/value types", "[task0]")
{
  // test empty tree construction
  HashDictionary<int, Employee> empty;
  CHECK(empty.getSize() == 0);
  CHECK(empty.getAllocationSize() == 5);
  CHECK(empty.isEmpty());
  CHECK(empty.str() == emptyTable);
}

/** Task 1: Test HashDictionary probe hashing helper function
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test probe() hashing helper function",
          "[task1]")
   {
   // test probe sequence on table of allocation size 7, though table
   // size does not matter here as only the has function will mode by
   // the allocation size
   const int HASH_TABLE_SIZE = 7;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);
   CHECK(dict.getSize() == 0);
   CHECK(dict.getAllocationSize() == 7);
   CHECK(dict.isEmpty() );

   // we assume implementation of probe() per assignment, with
   // c1 = 1, c2 = 2 and c3 = 2
   int id = 1; // the key is not used by your quadratic probe, so doesn't matter what key we pass in
   CHECK(dict.probe(id, 0) == 2);
   CHECK(dict.probe(id, 1) == 5);
   CHECK(dict.probe(id, 2) == 10);
   CHECK(dict.probe(id, 3) == 17);
   CHECK(dict.probe(id, 4) == 26);
   CHECK(dict.probe(id, 5) == 37);
   CHECK(dict.probe(id, 6) == 50);
   CHECK(dict.probe(id, 7) == 65);

   // arbitrarily larger probe
   CHECK(dict.probe(id, 12345) == 152423717);
   }
 

/** Test HashDictionary hash hashing helper function, for a table of size 7
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test hash() hashing helper function, table size 7",
          "[task1]")
   {
   // test hashing on hash table of size 7
   const int HASH_TABLE_SIZE = 7;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);
   CHECK(dict.getSize() == 0);
   CHECK(dict.getAllocationSize() == 7);
   CHECK(dict.isEmpty() );

   // we assume that we are on a system with 4 byte ()32 bit) ints.  if
   // the following fails, the tests after will not have the correct
   // expected hashes
   REQUIRE(sizeof(int) == 4);

   // test various int hashes.  If you square using key * key (not pow(key,2))
   // you should get these results for a 32 bit int for a table of size 7
   int id;

   // 1 hashes to slot 0
   id = 1;
   CHECK(dict.hash(id) == 0);

   // 25 hashes to slot 2
   id = 25;
   CHECK(dict.hash(id) == 2);

   // 3918 hashes to slot 1
   id = 3918;
   CHECK(dict.hash(id) == 1);

   // 48517 hashes to slot 6
   id = 48517;
   CHECK(dict.hash(id) == 6);

   // 913478 hashes to slot 5
   id = 913478;
   CHECK(dict.hash(id) == 5);

   // 8372915 hashes to slot 4
   id = 8372915;
   CHECK(dict.hash(id) == 4);

   // we will use the following 4 ids to test hash table insertion with
   // probing.  Note the return from the hash() function is only the home
   // or base address.  With quadratic probing even for probe index 0 we
   // need to add something to this returned base address for the probe
   id = 438901234;
   CHECK(dict.hash(id) == 6);
   id = 192834192;
   CHECK(dict.hash(id) == 1);
   // notice a collision would occur when adding this id
   id = 998439281;
   CHECK(dict.hash(id) == 6);
   id = 362817371;
   CHECK(dict.hash(id) == 5);
   // another collission at hash bucket 5
   id = 272349829;
   CHECK(dict.hash(id) == 5);
   }
 

/** Task 1: Test HashDictionary hash hashing helper function, for a table of size 31
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test hash() hashing helper function, table size 31",
          "[task1]")
   {
   // test hashing on hash table of size 31
   const int HASH_TABLE_SIZE = 31;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);
   CHECK(dict.getSize() == 0);
   CHECK(dict.getAllocationSize() == 31);
   CHECK(dict.isEmpty() );

   // we assume that we are on a system with 4 byte ()32 bit) ints.  if
   // the following fails, the tests after will not have the correct
   // expected hashes
   REQUIRE(sizeof(int) == 4);

   // test various int hashes.  If you square using key * key (not pow(key,2))
   // you should get these results for a 32 bit int for a table of size 7
   int id;

   // 1 hashes to slot 0
   id = 1;
   CHECK(dict.hash(id) == 0);

   // 25 hashes to slot 2
   id = 25;
   CHECK(dict.hash(id) == 2);

   // 3918 hashes to slot 9
   id = 3918;
   CHECK(dict.hash(id) == 9);

   // 48517 hashes to slot 8
   id = 48517;
   CHECK(dict.hash(id) == 8);

   // 913478 hashes to slot 22
   id = 913478;
   CHECK(dict.hash(id) == 22);

   // 8372915 hashes to slot 4
   id = 8372915;
   CHECK(dict.hash(id) == 4);

   // we will use the following 4 ids to test hash table insertion with
   // probing.  Note the return from the hash() function is only the home
   // or base address.  With quadratic probing even for probe index 0 we
   // need to add something to this returned base address for the probe
   id = 438901234;
   CHECK(dict.hash(id) == 26);
   id = 192834192;
   CHECK(dict.hash(id) == 20);
   id = 998439281;
   // collision here with id 3918
   CHECK(dict.hash(id) == 1);
   id = 362817371;
   CHECK(dict.hash(id) == 21);
   id = 272349829;
   CHECK(dict.hash(id) == 18);
   }
 

/** Task 2: Test HashDictionary probeForAvailableSlot.  We need to implement
 * insert() before we can create more extensive tests, so we build
 * a table of empty and non empty values by hand here.
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test probeForAvailableSlot() helper function",
          "[task2]")
   {
   // test hashing on hash table of size 7
   const int HASH_TABLE_SIZE = 7;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);
   CHECK(dict.getSize() == 0);
   CHECK(dict.getAllocationSize() == 7);
   CHECK(dict.isEmpty() );

   // all slots are initially available (empty), so it should return
   // the corresponding first probe for probeIndex 0
   int probeSlot;

   // id 1 hashes to home slot 0, which will be slot 2 for probe index 0
   int id1 = 1;
   CHECK(dict.hash(id1) == 0);
   CHECK(dict.probe(id1, 0) == 2);
   probeSlot = dict.probeForAvailableSlot(id1);
   CHECK(probeSlot == 2);

   int id2 = 25;
   CHECK(dict.hash(id2) == 2);
   probeSlot = dict.probeForAvailableSlot(id2);
   CHECK(probeSlot == 4);

   // test when first slot has a key, stops on next slot in probe sequence, for
   // hash home 0, we probe slot 2, 5, 3
   Employee e1(id1, "Archer, Sterling", "123 Spy St. New York NY", 58427.23);
   dict[2] = KeyValuePair<int, Employee>(id1, e1);
   probeSlot = dict.probeForAvailableSlot(id1);
   CHECK(probeSlot == 5);

   // for hash home 2, probe sequence is 4 0 5
   Employee e2(id2, "Krieger, Doctor", "92 Washing Apt 5 Boston MD", 48319.50);
   dict[4] = KeyValuePair<int, Employee>(id2, e2);
   probeSlot = dict.probeForAvailableSlot(id2);
   CHECK(probeSlot == 0);


   // add to next slot so have to go to probe index 2 to find next empty slot
   // again for home 0 we are probeing slots 2 5 3, so add another into slot 5
   int id3 = 3333; // not using for hashing, doesn't matter the id here
   Employee e3(id3, "Krieger, Doctor", "92 Washing Apt 5 Boston MD", 48319.50);
   dict[5] = KeyValuePair<int, Employee>(id3, e3);
   probeSlot = dict.probeForAvailableSlot(id1);
   CHECK(probeSlot == 3);

   // for home in slot 2, probe sequence is 4 0 5 5 0 4 3.  We just put key in slot 5,
   // and key already in 4.  Add key to slot 0.  Should make next available slot in
   // this sequence by slot 3
   int id4 = 4444; // not using for hashing, doesn't matter the id here
   Employee e4(id4, "Poovey, Pam", "8913 Cooper Blvd. Madison WI", 44319.25);
   dict[0] = KeyValuePair<int, Employee>(id4, e4);
   probeSlot = dict.probeForAvailableSlot(id2);
   CHECK(probeSlot == 3);

   // if slot 2 becomes missing, then probe on id1 should again return with first
   // slot in probe sequence
   dict[2].setMissing();
   probeSlot = dict.probeForAvailableSlot(id1);
   CHECK(probeSlot == 2);

   // test stop at missing in a sequence, for id2 if slot 5 goies missing, should
   // probe 4 0 5 and return 5 as next available
   dict[5].setMissing();
   probeSlot = dict.probeForAvailableSlot(id2);
   CHECK(probeSlot == 5);

   // if 0 goes missing, should stop there now
   dict[0].setMissing();
   probeSlot = dict.probeForAvailableSlot(id2);
   CHECK(probeSlot == 0);

   // if 4 at start of sequence goes missing, will stop there again
   dict[4].setMissing();
   probeSlot = dict.probeForAvailableSlot(id2);
   CHECK(probeSlot == 4);
   }
 

/** Task 2: Test HashDictionary probeForKeySlot.  We need to implement
 * insert() before we can create more extensive tests, so we build
 * a table of empty and non empty values by hand here.
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test probeForKeySlot() helper function",
          "[task2]")
   {
   // test hashing on hash table of size 7
   const int HASH_TABLE_SIZE = 7;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);
   CHECK(dict.getSize() == 0);
   CHECK(dict.getAllocationSize() == 7);
   CHECK(dict.isEmpty() );

   // all slots are initially empty, so it should return
   // the corresponding first probe for probeIndex 0 every time
   int probeSlot;

   // id 1 hashes to home slot 0, which will be slot 2 for probe index 0
   int id1 = 1;
   CHECK(dict.hash(id1) == 0);
   CHECK(dict.probe(id1, 0) == 2);
   probeSlot = dict.probeForKeySlot(id1);
   CHECK(probeSlot == 2);
   CHECK(dict[probeSlot].isEmpty() );  // should return an empty slot for failed search

   int id2 = 25;
   CHECK(dict.hash(id2) == 2);
   probeSlot = dict.probeForKeySlot(id2);
   CHECK(probeSlot == 4);
   CHECK(dict[probeSlot].isEmpty() );  // should return an empty slot for failed search

   // test when first slot has the key, stops immediately for successful search
   // hash home 0, we probe slot 2, 5, 3
   Employee e1(id1, "Archer, Sterling", "123 Spy St. New York NY", 58427.23);
   dict[2] = KeyValuePair<int, Employee>(id1, e1);
   probeSlot = dict.probeForKeySlot(id1);
   CHECK(probeSlot == 2);
   CHECK_FALSE(dict[probeSlot].isEmpty() );  // should be successful search now

   // for hash home 2, probe sequence is 4 0 5
   Employee e2(id2, "Krieger, Doctor", "92 Washing Apt 5 Boston MD", 48319.50);
   dict[4] = KeyValuePair<int, Employee>(id2, e2);
   probeSlot = dict.probeForKeySlot(id2);
   CHECK(probeSlot == 4);
   CHECK_FALSE(dict[probeSlot].isEmpty() );  // should be successful search now

   // when searching for a key, should treat a missing as not done yet.
   // set first probe to missing, we should now fail, but return next
   // slot in each probe sequence
   dict[2].setMissing();
   probeSlot = dict.probeForKeySlot(id1);
   CHECK(probeSlot == 5);
   CHECK(dict[probeSlot].isEmpty() );  // should be successful search now

   dict[4].setMissing();
   probeSlot = dict.probeForKeySlot(id2);
   CHECK(probeSlot == 0);
   CHECK(dict[probeSlot].isEmpty() );  // should be successful search now

   // put key back in to next step in probe sequence for id1
   dict[5] = KeyValuePair<int, Employee>(id1, e1);
   probeSlot = dict.probeForKeySlot(id1);
   CHECK(probeSlot == 5);
   CHECK_FALSE(dict[probeSlot].isEmpty() );  // should be successful search now

   // make sequence of missing values longer and put id2 back at end of sequence
   // probe sequence for id2 is 4 0 5 5 0 4 3
   dict[0].setMissing();
   //dict[5].setMissing();  actually slot 5 has the wrong key
   dict[3] = KeyValuePair<int, Employee>(id2, e2);
   probeSlot = dict.probeForKeySlot(id2);
   CHECK(probeSlot == 3);
   CHECK_FALSE(dict[probeSlot].isEmpty() );  // should be successful search now

   // make 5 missing again, so now probe for id2 should fail at slot 5
   dict[5] = KeyValuePair<int, Employee>();
   probeSlot = dict.probeForKeySlot(id2);
   CHECK(probeSlot == 5);
   CHECK(dict[probeSlot].isEmpty() );  // should be successful search now
   }
 

const string tableAfterGrowingTo14Slots = "<HashDictionary> size: 4\n"
                                          "Slot: 0\n"
                                          "     Key  : 362817371\n"
                                          "     Value: ( id: 362817371 | Poovey, Pam | 8913 Cooper Blvd. Madison WI | 44319.25 )\n"
                                          "Slot: 1\n"
                                          "     Key  : 998439281\n"
                                          "     Value: ( id: 998439281 | Krieger, Doctor | 92 Washing Apt 5 Boston MD | 48319.50 )\n"
                                          "Slot: 2\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 3\n"
                                          "     Key  : 192834192\n"
                                          "     Value: ( id: 192834192 | Kane, Lana | 32 Avenue Washington DC | 64381.45 )\n"
                                          "Slot: 4\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 5\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 6\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 7\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 8\n"
                                          "     Key  : 438901234\n"
                                          "     Value: ( id: 438901234 | Archer, Sterling | 123 Spy St. New York NY | 58427.23 )\n"
                                          "Slot: 9\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 10\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 11\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 12\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n"
                                          "Slot: 13\n"
                                          "     Key  : EMPTY\n"
                                          "     Value:\n";

const string finalTableAfterInserts = "<HashDictionary> size: 7\n"
                                      "Slot: 0\n"
                                      "     Key  : 362817371\n"
                                      "     Value: ( id: 362817371 | Poovey, Pam | 8913 Cooper Blvd. Madison WI | 44319.25 )\n"
                                      "Slot: 1\n"
                                      "     Key  : 998439281\n"
                                      "     Value: ( id: 998439281 | Krieger, Doctor | 92 Washing Apt 5 Boston MD | 48319.50 )\n"
                                      "Slot: 2\n"
                                      "     Key  : EMPTY\n"
                                      "     Value:\n"
                                      "Slot: 3\n"
                                      "     Key  : 192834192\n"
                                      "     Value: ( id: 192834192 | Kane, Lana | 32 Avenue Washington DC | 64381.45 )\n"
                                      "Slot: 4\n"
                                      "     Key  : EMPTY\n"
                                      "     Value:\n"
                                      "Slot: 5\n"
                                      "     Key  : EMPTY\n"
                                      "     Value:\n"
                                      "Slot: 6\n"
                                      "     Key  : EMPTY\n"
                                      "     Value:\n"
                                      "Slot: 7\n"
                                      "     Key  : 272349829\n"
                                      "     Value: ( id: 272349829 | Figgis, Cyril | 83 Rodeo Drive Phoenix AZ | 38560.38 )\n"
                                      "Slot: 8\n"
                                      "     Key  : 438901234\n"
                                      "     Value: ( id: 438901234 | Archer, Sterling | 123 Spy St. New York NY | 58427.23 )\n"
                                      "Slot: 9\n"
                                      "     Key  : EMPTY\n"
                                      "     Value:\n"
                                      "Slot: 10\n"
                                      "     Key  : 272349839\n"
                                      "     Value: ( id: 272349839 | Gilette, Ray | 2015 Fm. Rd 98 Mobile AL | 44560.28 )\n"
                                      "Slot: 11\n"
                                      "     Key  : EMPTY\n"
                                      "     Value:\n"
                                      "Slot: 12\n"
                                      "     Key  : EMPTY\n"
                                      "     Value:\n"
                                      "Slot: 13\n"
                                      "     Key  : 272349849\n"
                                      "     Value: ( id: 272349849 | Tunt, Cheryl | Park Ave. New York NY | 22520.45 )\n";

/** Task 3: Test HashDictionary insert API operation
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test insert() API member function",
          "[task3]")
   {
   const int HASH_TABLE_SIZE = 7;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);
   CHECK(dict.getSize() == 0);
   CHECK(dict.getAllocationSize() == 7);
   CHECK(dict.isEmpty() );

   // insert first Employee
   int id1 = 438901234;
   Employee e1(id1, "Archer, Sterling", "123 Spy St. New York NY", 58427.23);
   CHECK(dict.probe(id1, 0) == 2);
   CHECK(dict.hash(id1) == 6);
   dict.insert(id1, e1);
   // shoudl end up in slot 1 (6 + 2 % 7 == 1)
   CHECK(dict.getSize() == 1);
   CHECK(dict[1].getKey() == id1);
   CHECK(dict[1].getValue().getId() == id1);

   // insert second Employee, no collision occurs
   int id2 = 192834192;
   Employee e2(id2, "Kane, Lana", "32 Avenue Washington DC", 64381.45);
   CHECK(dict.probe(id2, 0) == 2);
   CHECK(dict.hash(id2) == 1);
   dict.insert(id2, e2);
   // should end up in slot 3 (1 + 2 % 7 == 3)
   CHECK(dict.getSize() == 2);
   CHECK(dict[3].getKey() == id2);
   CHECK(dict[3].getValue().getId() == id2);

   // insert third Employee, collides with first, needs to go to probe
   // sequence index 1
   int id3 = 998439281;
   Employee e3(id3, "Krieger, Doctor", "92 Washing Apt 5 Boston MD", 48319.50);
   CHECK(dict.probe(id3, 0) == 2);
   CHECK(dict.hash(id3) == 6);
   dict.insert(id3, e3);
   // should colide for probe index 0 at slot 1, so end up with
   // probe index 1 (6 + 5 % 7 == 4)
   CHECK(dict.getSize() == 3);
   CHECK(dict[4].getKey() == id3);
   CHECK(dict[4].getValue().getId() == id3);

   // insert fourth Employee, no collission occurs
   int id4 = 362817371;
   Employee e4(id4, "Poovey, Pam", "8913 Cooper Blvd. Madison WI", 44319.25);
   CHECK(dict.probe(id4, 0) == 2);
   CHECK(dict.hash(id4) == 5);
   dict.insert(id4, e4);
   // should end up in index 0 (5 + 2 % 7 == 0)
   CHECK(dict.getSize() == 4);
   CHECK(dict[0].getKey() == id4);
   CHECK(dict[0].getValue().getId() == id4);

   // after 4th insertion, the table should have been grown from
   // allocation size 7 to allocation size 14, and all values
   // rehashed into new table
   CHECK(dict.getSize() == 4);
   CHECK(dict.getAllocationSize() == 14);
   CHECK(dict.str() == tableAfterGrowingTo14Slots);

   // insert fifth Employee, no collision goes to slot 7
   int id5 = 272349829;
   Employee e5(id5, "Figgis, Cyril", "83 Rodeo Drive Phoenix AZ", 38560.38);
   CHECK(dict.probe(id5, 0) == 2);
   CHECK(dict.hash(id5) == 5);
   dict.insert(id5, e5);
   CHECK(dict.getSize() == 5);
   CHECK(dict[7].getKey() == id5);
   CHECK(dict[7].getValue().getId() == id5);

   // insert 6th Employee, force collission on slot 7 again
   // collision at slot 7 for probe index 1
   // should end up at slot 5 + 5 = 10 for probe index 2
   int id6 = 272349839;
   Employee e6(id6, "Gilette, Ray", "2015 Fm. Rd 98 Mobile AL", 44560.28);
   CHECK(dict.probe(id6, 0) == 2);
   CHECK(dict.probe(id6, 1) == 5);
   CHECK(dict.hash(id6) == 5);
   dict.insert(id6, e6);
   CHECK(dict.getSize() == 6);
   CHECK(dict[10].getKey() == id6);
   CHECK(dict[10].getValue().getId() == id6);

   // insert 7th Employee, first collision on slot 7 again
   // collision at slot 7 for probe index 0
   // collision at slot 10 for probe index 1
   // collision at slot 1 for probe index 2
   // collision at slot 8 for probe index 3
   // collision at slot 3 for probe index 4
   // collision at slot 0 for probe index 5
   // should end up at slot 5 + 50 = 55 % 14 = 13 for probe index 6
   int id7 = 272349849;
   Employee e7(id7, "Tunt, Cheryl", "Park Ave. New York NY", 22520.45);
   CHECK(dict.probe(id7, 3) == 17);
   CHECK(dict.hash(id7) == 5);
   dict.insert(id7, e7);
   CHECK(dict.getSize() == 7);
   CHECK(dict[13].getKey() == id7);
   CHECK(dict[13].getValue().getId() == id7);

   // final check of table slot positions after the insertions
   CHECK(dict.str() == finalTableAfterInserts);

   // duplicate keys are not allowed, try inserting an employee with
   // a duplicate id.  This id requires no probing to find the duplicate
   int id8 = id1;
   Employee e8(id8, "Archer, Malory", "52 Trump Tower Penthouse, New York NY", 31289.54);
   CHECK_THROWS_AS(dict.insert(id8, e8), DictionaryDuplicateKeyInsertionException);
   CHECK(dict.hash(id1) == 6);
   CHECK(dict.hash(id8) == 6);

   // oh and by the way, the dictionary should not have grown in allocation size
   // if we end up not inserting because of duplicate key errors
   CHECK(dict.getAllocationSize() == 14);

   // Cheryl's key id7 needs a probe sequence to find it, check for duplicate key
   // detection along a probe sequence of more than 1 probe
   int id9 = id7;
   Employee e9(id9, "Woodhouse, Butler", "123 Spy St New York NY", 15154.45);
   CHECK_THROWS_AS(dict.insert(id9, e9), DictionaryDuplicateKeyInsertionException);
   CHECK(dict.hash(id7) == 5);
   CHECK(dict.hash(id9) == 5);
   }
 

/** Task 4: Test HashDictionary find API operation
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test find() API member function",
          "[task4]")
   {
   // (re)create dictionary we used when testing insert
   const int HASH_TABLE_SIZE = 7;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);

   // insert first Employee
   int id1 = 438901234;
   Employee e1(id1, "Archer, Sterling", "123 Spy St. New York NY", 58427.23);
   dict.insert(id1, e1);

   int id2 = 192834192;
   Employee e2(id2, "Kane, Lana", "32 Avenue Washington DC", 64381.45);
   dict.insert(id2, e2);

   int id3 = 998439281;
   Employee e3(id3, "Krieger, Doctor", "92 Washing Apt 5 Boston MD", 48319.50);
   dict.insert(id3, e3);

   int id4 = 362817371;
   Employee e4(id4, "Poovey, Pam", "8913 Cooper Blvd. Madison WI", 44319.25);
   dict.insert(id4, e4);

   int id5 = 272349829;
   Employee e5(id5, "Figgis, Cyril", "83 Rodeo Drive Phoenix AZ", 38560.38);
   dict.insert(id5, e5);

   int id6 = 272349839;
   Employee e6(id6, "Gilette, Ray", "2015 Fm. Rd 98 Mobile AL", 44560.28);
   dict.insert(id6, e6);

   int id7 = 272349849;
   Employee e7(id7, "Tunt, Cheryl", "Park Ave. New York NY", 22520.45);
   dict.insert(id7, e7);

   // final check of table slot positions after the insertions
   CHECK(dict.str() == finalTableAfterInserts);

   // test find no probing, we find the key at probe index 0 for these
   Employee employee;
   employee = dict.find(id1);
   CHECK(employee.getId() == id1);
   CHECK(employee.str() == "( id: 438901234 | Archer, Sterling | 123 Spy St. New York NY | 58427.23 )");

   employee = dict.find(id2);
   CHECK(employee.getId() == id2);
   CHECK(employee.str() == "( id: 192834192 | Kane, Lana | 32 Avenue Washington DC | 64381.45 )");

   employee = dict.find(id4);
   CHECK(employee.getId() == id4);
   CHECK(employee.str() == "( id: 362817371 | Poovey, Pam | 8913 Cooper Blvd. Madison WI | 44319.25 )");

   employee = dict.find(id5);
   CHECK(employee.getId() == id5);
   CHECK(employee.str() == "( id: 272349829 | Figgis, Cyril | 83 Rodeo Drive Phoenix AZ | 38560.38 )");

   // test needs a probe, the following are found at probe index 2
   employee = dict.find(id3);
   CHECK(employee.getId() == id3);
   CHECK(employee.str() == "( id: 998439281 | Krieger, Doctor | 92 Washing Apt 5 Boston MD | 48319.50 )");

   // test needs more than 2 probes to find
   employee = dict.find(id6);
   CHECK(employee.getId() == id6);
   CHECK(employee.str() == "( id: 272349839 | Gilette, Ray | 2015 Fm. Rd 98 Mobile AL | 44560.28 )");

   employee = dict.find(id7);
   CHECK(employee.getId() == id7);
   CHECK(employee.str() == "( id: 272349849 | Tunt, Cheryl | Park Ave. New York NY | 22520.45 )");

   // test failed search throws expected exception
   // 42 hashes to empty slot 6, should be easy to detect search fails
   CHECK(dict.hash(42) == 6);
   CHECK_THROWS_AS(dict.find(42), DictionaryKeyNotFoundException);

   // 43 hashes to slot 7, which needs a long probe sequence to determine
   // it is missing
   CHECK(dict.hash(43) == 7);
   CHECK_THROWS_AS(dict.find(43), DictionaryKeyNotFoundException);
   }
 

const string tableAfter3Removals = "<HashDictionary> size: 4\n"
                                   "Slot: 0\n"
                                   "     Key  : 362817371\n"
                                   "     Value: ( id: 362817371 | Poovey, Pam | 8913 Cooper Blvd. Madison WI | 44319.25 )\n"
                                   "Slot: 1\n"
                                   "     Key  : MISSING\n"
                                   "     Value:\n"
                                   "Slot: 2\n"
                                   "     Key  : EMPTY\n"
                                   "     Value:\n"
                                   "Slot: 3\n"
                                   "     Key  : 192834192\n"
                                   "     Value: ( id: 192834192 | Kane, Lana | 32 Avenue Washington DC | 64381.45 )\n"
                                   "Slot: 4\n"
                                   "     Key  : EMPTY\n"
                                   "     Value:\n"
                                   "Slot: 5\n"
                                   "     Key  : EMPTY\n"
                                   "     Value:\n"
                                   "Slot: 6\n"
                                   "     Key  : EMPTY\n"
                                   "     Value:\n"
                                   "Slot: 7\n"
                                   "     Key  : 272349829\n"
                                   "     Value: ( id: 272349829 | Figgis, Cyril | 83 Rodeo Drive Phoenix AZ | 38560.38 )\n"
                                   "Slot: 8\n"
                                   "     Key  : MISSING\n"
                                   "     Value:\n"
                                   "Slot: 9\n"
                                   "     Key  : EMPTY\n"
                                   "     Value:\n"
                                   "Slot: 10\n"
                                   "     Key  : 272349839\n"
                                   "     Value: ( id: 272349839 | Gilette, Ray | 2015 Fm. Rd 98 Mobile AL | 44560.28 )\n"
                                   "Slot: 11\n"
                                   "     Key  : EMPTY\n"
                                   "     Value:\n"
                                   "Slot: 12\n"
                                   "     Key  : EMPTY\n"
                                   "     Value:\n"
                                   "Slot: 13\n"
                                   "     Key  : MISSING\n"
                                   "     Value:\n";

/** Task 5: Test HashDictionary remove API operation
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test remove() API member function",
          "[task5]")
   {
   // (re)create dictionary we used when testing insert/find
   const int HASH_TABLE_SIZE = 7;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);

   // insert first Employee
   int id1 = 438901234;
   Employee e1(id1, "Archer, Sterling", "123 Spy St. New York NY", 58427.23);
   dict.insert(id1, e1);

   int id2 = 192834192;
   Employee e2(id2, "Kane, Lana", "32 Avenue Washington DC", 64381.45);
   dict.insert(id2, e2);

   int id3 = 998439281;
   Employee e3(id3, "Krieger, Doctor", "92 Washing Apt 5 Boston MD", 48319.50);
   dict.insert(id3, e3);

   int id4 = 362817371;
   Employee e4(id4, "Poovey, Pam", "8913 Cooper Blvd. Madison WI", 44319.25);
   dict.insert(id4, e4);

   int id5 = 272349829;
   Employee e5(id5, "Figgis, Cyril", "83 Rodeo Drive Phoenix AZ", 38560.38);
   dict.insert(id5, e5);

   int id6 = 272349839;
   Employee e6(id6, "Gilette, Ray", "2015 Fm. Rd 98 Mobile AL", 44560.28);
   dict.insert(id6, e6);

   int id7 = 272349849;
   Employee e7(id7, "Tunt, Cheryl", "Park Ave. New York NY", 22520.45);
   dict.insert(id7, e7);

   // final check of table slot positions after the insertions
   CHECK(dict.str() == finalTableAfterInserts);

   // remove id1, requires no probing
   Employee employee;
   employee = dict.remove(id1);
   CHECK(dict.getSize() == 6);
   CHECK(dict[8].isMissing() );
   CHECK(employee.getId() == id1);
   CHECK(employee.getName() == "Archer, Sterling");

   // remove id3, requires some probing
   employee = dict.remove(id3);
   CHECK(dict.getSize() == 5);
   CHECK(dict[1].isMissing() );
   CHECK(employee.getId() == id3);
   CHECK(employee.getName() == "Krieger, Doctor");

   // remove id7, requires a lot of probing
   employee = dict.remove(id7);
   CHECK(dict.getSize() == 4);
   CHECK(dict[13].isMissing() );
   CHECK(employee.getId() == id7);
   CHECK(employee.getName() == "Tunt, Cheryl");

   // test failed search for key to remove throws expected exception
   // 42 hashes to empty slot 6, should be easy to detect search fails
   CHECK(dict.hash(42) == 6);
   CHECK_THROWS_AS(dict.find(42), DictionaryKeyNotFoundException);

   // 43 hashes to slot 7, which needs a long probe sequence to determine
   // it is missing
   CHECK(dict.hash(43) == 7);
   CHECK_THROWS_AS(dict.find(43), DictionaryKeyNotFoundException);

   // test table slots look correct after these removals
   CHECK(dict.str() == tableAfter3Removals);

   // remove all remaining keys, in no particular order, test
   // dictionary is empty
   employee = dict.remove(id2);
   employee = dict.remove(id4);
   employee = dict.remove(id5);
   employee = dict.remove(id6);
   CHECK(dict.getSize() == 0);
   CHECK(dict.isEmpty() );
   }
 

/** Task 5: Test HashDictionary remove API operation.  Further tests that if remove
 * a value in a probe sequence, the value is set to MISSING, and find, remove
 * and insert still work if having to explore a probe sequence with a MISSING
 * value along the path.
 */

   TEST_CASE("HashDictionaryNode<int, Employee> test remove() MISSING values handled correctly",
          "[task5]")
   {
   // (re)create dictionary we used when testing insert/find
   const int HASH_TABLE_SIZE = 7;
   HashDictionary<int, Employee> dict(HASH_TABLE_SIZE);

   // insert first Employee
   int id1 = 438901234;
   Employee e1(id1, "Archer, Sterling", "123 Spy St. New York NY", 58427.23);
   dict.insert(id1, e1);

   int id2 = 192834192;
   Employee e2(id2, "Kane, Lana", "32 Avenue Washington DC", 64381.45);
   dict.insert(id2, e2);

   int id3 = 998439281;
   Employee e3(id3, "Krieger, Doctor", "92 Washing Apt 5 Boston MD", 48319.50);
   dict.insert(id3, e3);

   int id4 = 362817371;
   Employee e4(id4, "Poovey, Pam", "8913 Cooper Blvd. Madison WI", 44319.25);
   dict.insert(id4, e4);

   int id5 = 272349829;
   Employee e5(id5, "Figgis, Cyril", "83 Rodeo Drive Phoenix AZ", 38560.38);
   dict.insert(id5, e5);

   int id6 = 272349839;
   Employee e6(id6, "Gilette, Ray", "2015 Fm. Rd 98 Mobile AL", 44560.28);
   dict.insert(id6, e6);

   int id7 = 272349849;
   Employee e7(id7, "Tunt, Cheryl", "Park Ave. New York NY", 22520.45);
   dict.insert(id7, e7);

   // final check of table slot positions after the insertions
   CHECK(dict.str() == finalTableAfterInserts);

   // remove an item in middle of the long probe sequence for Cheryl
   // there is a probe sequence for slots 7, 10, 1, 8, 3, 0, 13
   // remove slot 10, Ray, and slot 3, Lana
   dict.remove(id6); // remove Ray Gilette from slot 10
   CHECK(dict[10].isMissing() );
   dict.remove(id2); // remove Lana Kane from slot 3
   CHECK(dict[3].isMissing() );

   // now, if we probe for any along that probe sequence, they should be found
   Employee employee;
   employee = dict.find(id5); // Cyril Figgis should be found in slot 7
   CHECK(employee.getId() == id5);
   CHECK(employee.getName() == "Figgis, Cyril");

   employee = dict.find(id3); // Doctor Krieger should be found in slot 1
   CHECK(employee.getId() == id3);
   CHECK(employee.getName() == "Krieger, Doctor");

   employee = dict.find(id1); // Archer Sterling should be found in slot 8
   CHECK(employee.getId() == id1);
   CHECK(employee.getName() == "Archer, Sterling");

   employee = dict.find(id4); // Pam Poovey should be found in slot 0
   CHECK(employee.getId() == id4);
   CHECK(employee.getName() == "Poovey, Pam");

   employee = dict.find(id7); // Cheryl Tunt should be found in slot 13
   CHECK(employee.getId() == id7);
   CHECK(employee.getName() == "Tunt, Cheryl");

   // test remove request of missing key results in expected exception
   CHECK_THROWS_AS(dict.remove(id6), DictionaryKeyNotFoundException);
   CHECK_THROWS_AS(dict.remove(id2), DictionaryKeyNotFoundException);

   // remove Cheryl Tunt from slot 13 along the long probe sequence
   dict.remove(id7); // remove Cheryl Tunt from slot 13
   CHECK(dict[13].isMissing() );

   // inserting her back in should put her record sooner in the probe sequence,
   // replacing missing slot 10
   dict.insert(id7, e7);
   CHECK(dict[10].getKey() == id7);
   CHECK(dict[10].getValue().getName() == "Tunt, Cheryl");

   // inserting back in Ray who was in slot 10 should insert him back further up
   // the probe sequence
   dict.insert(id6, e6);
   CHECK(dict[3].getKey() == id6);
   CHECK(dict[3].getValue().getName() == "Gilette, Ray");
   }
 
