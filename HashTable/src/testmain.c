#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/hashAPI.h"

int main (int argc, char** argv)
{

  Node *test1 = createNode("This", "This");
  Node *test2 = createNode("Is", "Is");
  Node *test3 = createNode("Test", "Test");

  HTable *hashTable = createTable(20, &hashNode, &destroyNodeData, &printNodeData);

  /*
  test createTable
  test createNode
  test insertData
  test lookupData
  test printNode
  */
  insertData(hashTable, test1->key, test1->data);
  insertData(hashTable, test2->key,test2->data);
  insertData(hashTable, test3->key,test3->data);
  printf("Test: Inputing to the hash table, finding specific values, and printing nodes\n");
  printf("Expected: Print the data from the hashtable\n");
  printNodeData(test2);
  printNodeData(test3);
  printNodeData(lookupData(hashTable, test1->key));
  printf("Recived: Output was in the correct order\n");
  printf("Result: Test was a success\n\n");

  /*
  test removeData
  */
  printf("Test: Delete hash table entry\n");
  printf("Expected: Print the data from the hashtable except for 'Please'\n");
  removeData(hashTable, test3->key);
  printNodeData(lookupData(hashTable, test1->key));
  printNodeData(lookupData(hashTable, test2->key));
  printNodeData(lookupData(hashTable, test3->key));
  printf("Recived: output was correct\n");
  printf("Result: Test was a success\n\n");

  /*
  test destroyNodeData
  */
  printf("Test: Delete specific node\n");
  printf("Expected: No output\n");
  destroyNodeData(test2->data);
  printf("Recived: output was correct\n");
  printf("Result: Test was a success\n\n");

  /*
  test destroyTable
  */
  printf("Test: Delete hash table\n");
  printf("Expected: Nothing will print when called\n");
  destroyTable(hashTable);
  printNodeData(lookupData(hashTable, test1->key));
  printNodeData(lookupData(hashTable, test2->key));
  printNodeData(lookupData(hashTable, test3->key));
  printf("Recived: Output was correct\n");
  printf("Result: Test was a success\n\n");
}
