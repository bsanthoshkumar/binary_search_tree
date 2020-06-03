#include "tree.h"

int main(void)
{
  Node_ptr tree = insert_node(NULL, 10);
  insert_node(tree, 5);
  insert_node(tree, 20);
  insert_node(tree, 25);
  insert_node(tree, 8);
  insert_node(tree, 1);
  insert_node(tree, 15);

  printf("Inorder traversal: ");
  print_inorder(tree);
  printf("\nPreorder traversal: ");
  print_preorder(tree);
  printf("\nPostorder traversal: ");
  print_postorder(tree);
  printf("\n\n");

  search_node(tree, 15);
  search_node(tree, 10);
  search_node(tree, 55);

  printf("\n");
  printf("Inorder traversal: ");
  print_inorder(tree);
  delete_node(tree, 10);
  printf("Inorder traversal: ");
  print_inorder(tree);
  return 0;
}