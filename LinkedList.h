// LinkedList.h
// Hashtable

#ifndef LinkedList_h
#define LinkedList_h

//Student structs are student "nodes" with all the information of a student
//but also with a pointer to the next Student
struct Student {
	char first[80];
	char last[80];
	int id;
	float gpa;
  Student* next;
};

class LinkedList
{
  private:
    //reference to the list of students
    Student* head;

    //number of students
    int length;

  public:
    LinkedList();

    //Insert a Student at the end of the list.
    void insertStudent(Student * newStudent);

    //Removes a student by their id number
    //returns true if successful
    bool removeStudent(int id);

    // Searches for a student by its id
    // Returns NULL pointer if no match is found
    Student* getStudent(int id);

    //prints the entire LinkedList
    void printList();

    int getLength();
    ~LinkedList();

};

#endif
