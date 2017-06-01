//  HashTable.cpp
//  This header file contains the Hash Table class definition.
//  Hash Table array elements consist of Linked List objects.
#include "HashTable.h"
#include <math.h>
#include <stdlib.h>     /* calloc, exit, free */
#include <iostream>

using namespace std;
// Constructs the empty Hash Table object.
// Array length is set to 13 by default.
HashTable::HashTable(int tableLength)
{
    if (tableLength <= 0) tableLength = 13;
    array = new LinkedList[ tableLength ];
    length = tableLength;
}

// Returns an array location (hash location) for a given student id
int HashTable::hash(int id)
{
    int n = log10(id) + 1;
    int i;
    char* numberArray = new char[80];
    for ( i = 0; i < n; ++i, id /= 10 )
      {
          numberArray[i] = id % 10;
    }
    long hash = 5381;
    int c;
    while (c = *numberArray++) hash = ((hash << 5) + hash) + c; // hash*33 + c
    hash = hash % 100;
    return hash;
}

// Adds an item to the Hash Table.
void HashTable::insertStudent(Student * newStudent )
{
    int index = hash( newStudent -> id );
    array[ index ].insertStudent( newStudent );
}

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.
bool HashTable::removeStudent(int id)
{
    int index = hash( id );
    return array[ index ].removeStudent( id );
}

// Returns an item from the Hash Table by key.
// If the student isn't found, a null pointer is returned.
Student * HashTable::getStudentById( int id )
{
    int index = hash( id );
    return array[ index ].getStudent( id );
}

// Display the contents of the Hash Table to console window.
void HashTable::printTable()
{
    cout << "\n\nHash Table:\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

// Prints a histogram illustrating the Item distribution.
void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << numStudents() << " Students total\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < array[i].getLength(); j++ )
            cout << " X";
        cout << "\n";
    }
}

// Returns the number of locations in the Hash Table.
int HashTable::getLength()
{
    return length;
}

// Returns the number of Items in the Hash Table.
int HashTable::numStudents()
{
    int studentCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        studentCount += array[i].getLength();
    }
    return studentCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
    delete [] array;
}
