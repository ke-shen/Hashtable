//  HashTable.cpp
//  This header file contains the Hash Table class definition.
//  Hash Table array elements consist of Linked List objects.
#include "HashTable.h"
#include <math.h>
#include <stdlib.h>     /* calloc, exit, free */
#include <iostream>
#include <string.h>

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

unsigned int HashTable::hash(char* name)
{
    unsigned int hash = 0;
    unsigned char* p;

    for(p = (unsigned char*)name; *p != '\0'; p++) {
      hash = 37 * hash + *p;
    }

    return hash % 100;
}

// Adds an item to the Hash Table.
void HashTable::insertStudent(Student * newStudent)
{
    char* name = new char[100];
    strncat(name, newStudent->first, strlen(newStudent->first));
    strncat(name, newStudent->last, strlen(newStudent->last));

    int index = hash(name);
    cout << "Index : " << index << endl;

    array[ index ].insertStudent( newStudent );
    delete [] name;
}

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.

bool HashTable::removeStudent(char* name)
{
    int index = hash( name );
    return array[ index ].removeStudent( name );
}

// Returns an student from the Hash Table by key.
// If the student isn't found, a null pointer is returned.
Student * HashTable::getStudentById(char* name)
{
    int index = hash( name );
    return array[ index ].getStudent( name );
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
