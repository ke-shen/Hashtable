#include <vector>
#include <string.h>
#include <iostream>
#include <string>

#define ADD 1
#define PRINT 2
#define DELETE 3
#define EXIT 4

#include "HashTable.h"
#include "LinkedList.h"
#include <time.h>       /* time */
#include <math.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void generateStudents(HashTable* ht, char** first_arr,char ** last_arr,int& idnumber);


int main() {



  HashTable* ht = new HashTable(100);
  ifstream fn("first.txt");
  ifstream ln("last.txt");

  char** first_arr = new char*[1000];
  char** last_arr = new char*[1000];

  //reads in names in the files to an an array
  for(int i = 0; i < 310; i++) {
    char* first = new char[80];
    char* last = new char[80];
    fn.getline(first, 80, '\r');
    fn.ignore(1);
    ln.getline(last, 80, '\r');
    ln.ignore(1);
    first_arr[i] = first;
    last_arr[i] = last;
  }

  int idnumber = 100000;

  char input[100];

	bool done = false;
	while(!done) {
		cout << "Do you want to: ADD, DELETE, PRINT or EXIT?" << endl;
		input = getInput();
		switch(parseCommand(input)) {
			case ADD:
				addEntry(list);
				break;
			case DELETE:
			//if it returns 1, there is such an entry;
				deleteEntry(list);
				break;
			case PRINT:
				printAll(list);
				break;
			case EXIT:
				done = true;
				break;
			case 0:
				cout << "You didn't enter a valid command. \n";
				break;
		}

	}


  generateStudents(ht, first_arr,last_arr,idnumber);
  ht->printHistogram();

  return 0;
}

void addStudent(HashTable* ht);

//generates a number of students and puts them into the hashtable
void generateStudents(HashTable* ht, char** first_arr, char** last_arr, int& idnumber)
{
  char input[10];
  cout << "Generate how many students? " << flush;
  cin >> input;

  cout << ht->getLength() << endl;
  srand(time(NULL));
  for(int i = 0; i < atoi(input); i++)
  {
    int rand_index = rand() % 310;

    Student* student = new Student();

    student->first = first_arr[rand_index];
    student->last = last_arr[rand_index];
    student->id = idnumber++;
    student->gpa = rand() % 4;

    ht->insertStudent(student);
    cout << "student data: " << student->first << endl;
  }

  cout << atoi(input) << " students generated." << endl;
}



//prints all the students currently in the directory
void printAll(vector<Student*> *list) {
 	if(list->size() == 0) {
		cout << "No students in the directory." << endl;
	}
	for(int i = 0; i < list->size(); i++) {
		cout << list->at(i)->first << " " << list->at(i)->last << ", " << list->at(i)->id
			<< ", " << list->at(i)->gpa << endl;
	}
}
//compares the input to known commands
int parseCommand(char *input) {
	if(!strcmp(input, "ADD")) {
		return ADD;
	}
	else if(!strcmp(input, "PRINT")) {
		return PRINT;
	}
	else if(!strcmp(input, "DELETE")) {
		return DELETE;
	}
	else if(!strcmp(input, "EXIT")) {
		return EXIT;
	}
	else {
		return 0;
	}
}
//adds a student the vector: list.
void addEntry(HashTable* ht) {
	Student *student = new Student;

	cout << "Enter first name: ";
	cin >> student->first;


	cout << "Enter last name: ";
  cin >> student->last;


	cout << "Enter ID number: ";
	cin >> student->id;

	cout << "Enter GPA: ";
	cin >> student->gpa;

	ht->insert_Student(student);
	cout << "Student added." << endl;
}

//deletes an entry by their last name
//if there is the same last name, returns all students with that name
void deleteEntry(HashTable* ht) {
	char name[100];
	cout << "Enter the last name of the student you want to delete: " << endl;
	cin >> name;
  int index = ht->hash(name);

  Student* student = ht->array(index);

	//if no head
	if(student == NULL) {
		cout << "Student not found";
		return;
	}

  //stops when the next student
  while(student->next != NULL && strcmp(student->next->name, name) {
    student = student->next;
  }
	//if head is the student to delete
  Student* temp = student->next;
  if(!strcmp(temp->name, name)) {

  }
		student = student->next;
		delete temp;
		cout << "Student, " << name << " was just deleted from the system" << endl;
		return;
	}
	else {
		student = student->next;
		deleteNode(temp, id);
		head->setNext(temp);
	}



	cout << "Student was not found in database" << endl;
	cin.ignore();

}
