#include "tree.h"

int main(void)
{
  Node_ptr tree = insert_node(NULL, 20);
  insert_node(tree, 25);
  insert_node(tree, 10);
  insert_node(tree, 15);
  insert_node(tree, 5);
  insert_node(tree, 8);
  insert_node(tree, 1);

  print_inorder(tree);
  printf("\n");
  tree = balance_tree(tree);
  print_inorder(tree);
  return 0;
}