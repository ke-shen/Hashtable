#include <vector>
#include <string.h>
#include <iostream>
#include <string>

#define ADD 1
#define PRINT 2
#define DELETE 3
#define EXIT 4
#define SEARCH 5
#define GENERATE 6

#include "HashTable.h"
#include "LinkedList.h"
#include <time.h>       /* time */
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

void generateStudents(HashTable* ht, char** first_arr,char ** last_arr,int& idnumber);
int parseCommand(char* input);
void printAll(HashTable* ht);
void addEntry(HashTable* ht);
void deleteEntry(HashTable* ht);
void searchEntry(HashTable* ht);
void printInfo(Student* stu);
HashTable* makeNewThing(HashTable* ht);

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
		cout << "Do you want to: ADD, DELETE, SEARCH, PRINT or EXIT?" << endl;
        cin >> input;
		switch(parseCommand(input)) {
			case ADD:
				addEntry(ht);
				break;
			case DELETE:
                //if it returns 1, there is such an entry;
				deleteEntry(ht);
				break;
			case SEARCH:
                searchEntry(ht);
				break;
            case PRINT:
                ht->printHistogram();
                break;
			case EXIT:
				done = true;
				break;
            case GENERATE:
                generateStudents(ht, first_arr, last_arr, idnumber);
                break;
			case 0:
				cout << "You didn't enter a valid command. \n";
				break;
		}

	}


 /* generateStudents(ht, first_arr,last_arr,idnumber);
  ht->printHistogram();
  */

  return 0;
}

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

      if(ht->insertStudent(student)) {
          cout << "Too many collisions! Expanding hashtable." << endl;
          ht = makeNewThing(ht);
      }
    cout << "student data: " << student->first << " " << student->last << endl;
      cout << "Student number " << i << endl;
  }

  cout << atoi(input) << " students generated." << endl;
}


//compares the input to known commands
int parseCommand(char *input) {
    for(int i = 0; i < 0; i++) {
        *(input+i) = toupper(*(input+i));
    }
	if(!strcmp(input, "ADD")) {
		return ADD;
	}
	else if(!strcmp(input, "PRINT")) {
		return PRINT;
	}
    else if(!strcmp(input, "SEARCH")) {
        return SEARCH;
    }
	else if(!strcmp(input, "DELETE")) {
		return DELETE;
	}
	else if(!strcmp(input, "EXIT")) {
		return EXIT;
	}
    else if(!strcmp(input, "GENERATE")) {
        return GENERATE;
    }
	else {
		return 0;
	}
}
//adds a student the vector: list.
void addEntry(HashTable* ht) {
	Student *newstudent = new Student;
    newstudent->next = NULL;

    int id;
    float gpa;
    newstudent->first = new char[80];
    newstudent->last = new char[80];

	
    cout << "Enter first name: ";
    cin >> newstudent->first;

	cout << "Enter last name: ";
    cin >> newstudent->last;
    
	cout << "Enter ID number: ";
    cin >> id;
    newstudent->id = id;

	cout << "Enter GPA: ";
    cin >> gpa;
    newstudent->gpa = gpa;

    if(ht->insertStudent(newstudent)) {
        cout << "Too many collisions! Expanding hashtable." << endl;
        ht = makeNewThing(ht);
    }
	cout << "Student added." << endl;
}

HashTable* makeNewThing(HashTable* ht) {
    HashTable* newht = new HashTable(ht->getLength()*2);
    for(int i = 0; i < ht->getLength(); i++) {
        Student* stu = ht->array[i].popStudent();
        Student* temp;
        while(stu!=NULL) {
            Student* newStudent = new Student;
            newStudent->first = new char[80];
            newStudent->last = new char[80];
            
            strcpy(newStudent->first, stu->first);
            strcpy(newStudent->last, stu->last);
            newStudent->id = stu->id;
            newStudent->gpa = stu->gpa;
            
            delete stu;
            newht->insertStudent(newStudent);
            temp = ht->array[i].popStudent();
            stu = temp;
        }
    }
    return newht;
}


//deletes an entry by their last name
//if there is the same last name, returns all students with that name
void deleteEntry(HashTable* ht) {
	char name[100];
	cout << "Enter last name of the student you want to delete: " << endl;
	cin >> name;
  if(ht->removeStudent(name)) {
    cout << "Removed" << endl;
  }
  else {
    cout << "Student not found in the data base.";
  }
}

void searchEntry(HashTable* ht) {
    char name[100];
    cout << "Enter last name of the student you want to search: " << endl;
    cin >> name;
    if(ht->getStudent(name)) {
        cout << "Student found. " << endl;
        printInfo(ht->getStudent(name));
    }
    else {
        cout << "Student with that last name does not exist." << endl;
    }
}

void printInfo(Student* stu) {
    cout << "First: " << stu->first << endl;
    cout << "Last:  " << stu->last << endl;
    cout << "ID: " << stu->last << endl;
    cout << "GPA: " << stu->gpa << endl;
}
   
