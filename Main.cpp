// Main.cpp
#include "Hash.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(){
	char firsts[100][20];
	char lasts[100][20];
	int numfirsts = 0;
	int numlasts = 0;
	bool go = true;
	Hash* studentRecords = new Hash();
	
	while(go == true){
		cout << "What command? ADD DELETE PRINT FILE or QUIT"<< endl;
		char input[7];
		cin >> input;
		char first[20];
		char last[20];
		int id;
		float gpa;
		if(input[1] == 'D'){
			cout << "Enter first name" << endl;
			cin >> first;
			cout << "Enter last name" << endl;
			cin >> last;
			cout << "Enter ID" << endl;
			cin >> id;
			cout << "Enter GPA" << endl;
			cin >> gpa;
			if (!studentRecords->find(id)) {
				studentRecords->add(id, first, last, gpa);
				cout << "Student added." << endl;
			}
			else {
				cout << "Student with ID " << id << " already exists" << endl;
			}
		}
		if(input[1] == 'E'){
			cout << "Enter ID" << endl;
			cin >> id;
			if (studentRecords->del(id)) 
				cout << "Student with ID " << id << " deleted" << endl;
			else
				cout << "Student with ID " << id << " does not exist" << endl;
		}
		else if(input[1] == 'R'){
			studentRecords->print();
		}
		else if(input[1] == 'I'){
			numfirsts = 0;
			numlasts = 0;
			cout<<"what is the file name for first names"<<endl;
			cin>>input;
			fstream myFile(input);
			while(myFile>>first){
				strcpy(firsts[numfirsts++], first);
			}
			myFile.close();
			cout << numfirsts << " first names loaded" << endl;
			cout<<"what is the file name for last names"<<endl;
			cin>>input;
			myFile.open(input);
			while(myFile>>last){
				strcpy(lasts[numlasts++], last);
			}
			myFile.close();
			cout << numlasts << " last names loaded" << endl;
			cout<<"How many students do you want to generate"<<endl;
			int num;
			cin>>num;
			
			id = 0;
			for (int k = 0; k < num; k++) {
				while (studentRecords->find(id)) id++;
				int findex = rand() % numfirsts;
			    int lindex = rand() % numlasts;
				float rgpa = 4.0 * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				cout << "add (" << id << " " << firsts[findex] << " " << lasts[lindex] << " " << fixed << setprecision(2) << rgpa << ")" << endl;
				studentRecords->add(id, firsts[findex], lasts[lindex], rgpa);
			}
		}
		else if(input[1] == 'U'){
			go = false;
		}
	}
}
