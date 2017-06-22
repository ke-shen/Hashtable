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
// returns length to the hashtable function in order to
// know when to expand the hashtable
int LinkedList::insertStudent(Student * newStudent)
{
    if (!head)
    {
        head = newStudent;
        return ++length;
    }
    Student* p = head;
    while (p->next)
    {
        p = p->next;
    }
    p->next = newStudent;
    newStudent->next = NULL;
    return ++length;
}

//returns the student at the head of the LinkedList and also unlinks it from this HT
Student* LinkedList::popStudent() {
    if(head) {
    Student* temp = head;
    head = head->next;
    return temp;
    }
    return NULL;
}

// Removes an Student from the list by Student id.
// Returns true if the operation is successful.
bool LinkedList::removeStudent(char* name)
{
    if (!head) return false;
    if(!strcmp(head->last, name)) {
        Student* p = head;
        head = head->next;
        delete p;
        length--;
        return true;
    }
    
    while (head->next)
    {
        //if the next node is the one to delete
        if (!strcmp(head->next->last, name))
        {
            Student* p = head->next;
            head->next = head->next->next;
            delete p;
            length--;
            return true;
        }
    }
    return false;
}

// Searches for an Student by its id.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Student* LinkedList::getStudent(char* name)
{
    Student * q = head;
    while (q)
    {
        if (!strcmp(q->last, name))
            return q;
        q = q -> next;
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
