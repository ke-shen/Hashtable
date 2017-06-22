// Hash.h

#include <string.h>
#include "StudentNode.h"


class Hash {
public:
   int tablesize;
   StudentNode **table;
   Hash();
   int hashFun(int); // map a key to an array index
   void rehash(); // expand the hash table
   StudentNode *find(int); // find the student record for a given id
   void add(int, char*, char*, float); // insert a data
   bool del(int); // delete a data with a key
   void print(); 
};
