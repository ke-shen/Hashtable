// StudentNode.cpp
#include "StudentNode.h"
#include "string.h"
StudentNode::StudentNode(int i, char* f, char* l, float g){
  id = i;
  strcpy(first, f);
  strcpy(last, l);
  gpa = g;
  next = NULL;
};

int StudentNode::getId(){
  return id;
};
char* StudentNode::getFirst(){
  return first;
};
char* StudentNode::getLast(){
  return last;
};
float StudentNode::getGpa(){
  return gpa;
};

StudentNode* StudentNode::getNext(){
  return next;
};
void StudentNode::setNext(StudentNode* n){
  next = n;
};
