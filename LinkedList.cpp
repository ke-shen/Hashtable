#include "LinkedList.h"
#include <iostream>
using namespace std;

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
    head = NULL;
    length = 0;
}

// Inserts an Student at the end of the list.
void LinkedList::insertStudent(Student * newStudent)
{
    if (!head)
    {
        head = newStudent;
        length++;
        return;
    }
    Student* p = head;
    while (p->next)
    {
        p = p->next;
    }
    p->next = newStudent;
    newStudent->next = NULL;
    length++;
}

// Removes an Student from the list by Student id.
// Returns true if the operation is successful.
bool LinkedList::removeStudent(int id)
{
    if (!head->next) return false;
    Student* p = head;
    Student* q = head;
    while (q)
    {
        if (q->id == id)
        {
            p-> next = q->next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p->next;
    }
    return false;
}

// Searches for an Student by its id.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Student* LinkedList::getStudent(int id)
{
    Student * p = head;
    Student * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p->id == id))
            return p;
        q = p -> next;
    }
    return NULL;
}

// Displays list contents to the console window.
void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Student * p = head;
    Student * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p->id;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
    Student * p = head;
    Student * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}
