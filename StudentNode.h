
#ifndef StudentNode_h
#define StudentNode_h
#include <string.h>

class StudentNode {
private:
    int id;
    char first[20];
    char last[20];
    float gpa;
    StudentNode* next;
public:
    StudentNode(int, char*, char*, float);
    int getId();
    char* getFirst();
    char* getLast();
    float getGpa();
    StudentNode* getNext();
    void setNext(StudentNode*);
};
#endif
