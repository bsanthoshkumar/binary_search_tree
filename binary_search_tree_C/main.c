#include "tree.h"

int main(void)
{
  Node_ptr tree = insert_node(NULL, 15);
  insert_node(tree, 10);
  insert_node(tree, 13);
  insert_node(tree, 25);
  insert_node(tree, 19);
  insert_node(tree, 28);
  insert_node(tree, 7);
  
  return 0;
}