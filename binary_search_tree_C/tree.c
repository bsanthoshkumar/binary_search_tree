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
    tree = create_node(value);
    return tree;
  }
  Node_ptr current = tree;
  Node_ptr previous = current;
  while (current != NULL)
  {
    if (tree->value < value)
    {
      previous = current;
      current = current->right;
    }
    else
    {
      previous = current;
      current = current->left;
    }
  }
  if (previous->value < value)
  {
    previous->right = create_node(value);
  }
  else
  {
    previous->left = create_node(value);
  }

  return tree;
}

void print_inorder(Node_ptr tree)
{
  if (tree == NULL)
  {
    return;
  }
  print_inorder(tree->left);
  printf("%d ", tree->value);
  print_inorder(tree->right);
}

void print_preorder(Node_ptr tree)
{
  if (tree == NULL)
  {
    return;
  }
  printf("%d ", tree->value);
  print_preorder(tree->left);
  print_preorder(tree->right);
}

void print_postorder(Node_ptr tree)
{
  if (tree == NULL)
  {
    return;
  }
  print_postorder(tree->left);
  print_postorder(tree->right);
  printf("%d ", tree->value);
}

void search_node(Node_ptr tree, int value)
{
  if (tree == NULL)
  {
    printf("%d not found in tree\n", value);
    return;
  }
  if (tree->value == value)
  {
    printf("%d found in tree\n", value);
  }
  else if (tree->value < value)
  {
    search_node(tree->right, value);
  }
  else
  {
    search_node(tree->left, value);
  }
}