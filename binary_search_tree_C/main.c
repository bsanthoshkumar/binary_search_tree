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

  print_preorder(tree);
  rotate_right(tree, tree->left);
  printf("\n");
  print_preorder(tree);
  return 0;
}