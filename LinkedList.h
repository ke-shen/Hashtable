// LinkedList.h
// Hashtable

#ifndef LinkedList_h
#define LinkedList_h

#include <string.h>

//Student structs are student "nodes" with all the information of a student
//but also with a pointer to the next Student
struct Student {
	char* first;
	char* last;
	int id;
	float gpa;
  Student* next;
};

class LinkedList
{
  private:

    //number of students
    int length;

  public:
    
    //reference to the list of students
    Student* head;

    LinkedList();

    //Insert a Student at the end of the list.
    int insertStudent(Student * newStudent);

    Student* popStudent();
    //Removes a student by their last name
    //returns true if successful
    bool removeStudent(char* name);

    // Searches for a student by its id
    // Returns NULL pointer if no match is found
    Student* getStudent(char * name);

    //prints the entire LinkedList
    void printList();

    int getLength();
    ~LinkedList();

};

#endif
