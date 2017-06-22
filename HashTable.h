#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

//*****************************************************************
// Hash Table objects store a fixed number of Linked Lists.
//*****************************************************************
class HashTable
{
private:
    // Length is the size of the HashTable array.
    int length;

public:
    // Array is a reference to an array of Linked Lists.
    LinkedList* array;
    
    unsigned int hash( char* name );
    // Constructs the empty Hash Table object.
    // Array length is set to 13 by default.
    HashTable( int tableLength );

    // Adds an item to the Hash Table.
    bool insertStudent(Student * newStudent );

    // Deletes an Item by key from the Hash Table.
    // Returns true if the operation is successful.
    bool removeStudent(char* name);

    // Returns an item from the Hash Table by key.
    // If the item isn't found, a null pointer is returned.
    Student* getStudent(char* name);

    // Display the contents of the Hash Table to console window.
    void printTable();

    // Prints a histogram illustrating the Item distribution.
    void printHistogram();

    // Returns the number of slots in the Hash Table.
    int getLength();

    // Returns the number of Items in the Hash Table.
    int numStudents();

    // De-allocates all memory used for the Hash Table.
    ~HashTable();
};

#endif
