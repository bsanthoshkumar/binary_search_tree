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
    if (current->value < value)
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

Bool search(Node_ptr tree, int value)
{
  Bool flag = False;
  Node_ptr current = tree;
  while (current != NULL)
  {
    if (current->value == value)
    {
      flag = True;
      break;
    }
    else if (current->value < value)
    {
      current = current->right;
    }
    else
    {
      current = current->left;
    }
  }

  return flag;
}

void search_node(Node_ptr tree, int value)
{

  if (search(tree, value) == True)
  {
    printf("%d found in tree\n", value);
  }
  else
  {
    printf("%d not found in tree\n", value);
  }
}

Node_ptr find_minimum(Node_ptr tree)
{
  if (tree->left == NULL)
  {
    return tree;
  }
  return find_minimum(tree->left);
}

Node_ptr delete_node(Node_ptr tree, int value)
{
  if (tree == NULL)
  {
    return tree;
  }
  if (tree->value < value)
  {
    tree->right = delete_node(tree->right, value);
    return tree;
  }
  if (tree->value > value)
  {
    tree->left = delete_node(tree->left, value);
    return tree;
  }

  if (tree->left == NULL)
  {
    Node_ptr temp = tree->right;
    free(tree);
    return temp;
  }
  if (tree->right == NULL)
  {
    Node_ptr temp = tree->left;
    free(tree);
    return temp;
  }

  Node_ptr min_node = find_minimum(tree->right);
  tree->value = min_node->value;
  tree->right = delete_node(tree->right, min_node->value);
  return tree;
}

Node_ptr rotate_right(Node_ptr tree, Node_ptr pivot)
{
  if (tree == NULL)
  {
    return tree;
  }
  if (tree->value < pivot->value)
  {
    tree->right = rotate_right(tree->right, pivot);
    return tree;
  }
  if (tree->value > pivot->value)
  {
    tree->left = rotate_right(tree->left, pivot);
    return tree;
  }

  Node_ptr temp = pivot->left;
  if (pivot == NULL)
  {
    return tree;
  }
  pivot->left = temp->right;
  temp->right = pivot;

  return temp;
}