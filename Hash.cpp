// Hash.cpp
#include <iostream>
#include <iomanip>
#include "Hash.h"
using namespace std;

Hash::Hash(){
  tablesize = 100; // hash size
  table = new StudentNode*[tablesize];
  for (int i = 0; i < tablesize; i++){
    table[i] = NULL;
  }
}

int Hash::hashFun(int id) // simple hash function
{
  return id % tablesize;
}

void Hash::rehash(){
  int newSize = tablesize*2;
  cout << "Rehash: expand table size from " << tablesize << " to " << newSize << endl;
  StudentNode** newTable = new StudentNode* [newSize];
  for (int i = 0; i < newSize; i++){
    newTable[i] = NULL;
  }
  for(int i = 0; i < tablesize; i++){

    StudentNode *next = NULL;
    for(StudentNode* node = table[i]; node != NULL; node = next){
      next = node->getNext();
      int newIndex = node->getId()%newSize;
      node->setNext(newTable[newIndex]);
      newTable[newIndex] = node;
    }
  }
  tablesize = newSize;
  delete table;
  table = newTable;
}

StudentNode* Hash::find(int id)
{
  int index = this->hashFun(id);
  StudentNode *node;
  for (node = table[index]; node != NULL && node->getId() != id; 
       node = node->getNext());
  return node;
}

void Hash::add(int id, char* first, char* last, float gpa)
{
  StudentNode *node = new StudentNode(id, first, last, gpa);
  int index = hashFun(id);
  // insert the node to the head of the chain
  node->setNext(table[index]);
  table[index] = node;
  int collisions = 0;
  for(node = table[index]; node != NULL; node = node->getNext()){
    collisions++;
  }
  if(collisions > 3){
    rehash();
  }
}

bool Hash::del(int id)
{
  int index = hashFun(id);
  StudentNode *node = table[index];
  StudentNode *prev = NULL;

  while (node != NULL && node->getId() != id) {
    prev = node;
    node = node->getNext();
  }

  if (node == NULL)
    return false;
  else {
    if (prev == NULL)
      table[index] = node->getNext();
    else
      prev->setNext(node->getNext());
    node->setNext(NULL);
    delete node;
    return true;
  }
}

void Hash::print(){
  for(int i=0; i <tablesize; i++){
    if (table[i]) {
      cout << i << ":" << endl;
      for(StudentNode* n = table[i]; n!=NULL; n=n->getNext()){
        cout<<"ID: " << n->getId()<<" FIRST: "<<n->getFirst()<<" LAST: "<<n->getLast()<<" GPA: "<< fixed << setprecision(2) << n->getGpa() <<endl;
      }
    }
  }
}
