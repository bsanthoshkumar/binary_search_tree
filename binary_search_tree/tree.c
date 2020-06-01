#include "tree.h"

Node_ptr create_node(int value)
{
  Node_ptr tree = malloc(sizeof(Node));
  tree->left = NULL;
  tree->right = NULL;
  tree->value = value;
  return tree;
}

Node_ptr insert_node(Node_ptr tree, int value)
{
  if (tree == NULL)
  {
    return create_node(value);
  }
  if (tree->value < value)
  {
    tree->right = insert_node(tree->right, value);
  }
  else
  {
    tree->left = insert_node(tree->left, value);
  }
  return tree;
}