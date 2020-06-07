#include <stdio.h>
#include <stdlib.h>

#ifndef __TREE_H_
#define __TREE_H_

typedef struct node
{
  struct node *left;
  int value;
  struct node *right;
} Node;
typedef Node *Node_ptr;

typedef enum
{
  False,
  True
} Bool;

Node_ptr insert_node(Node_ptr, int);
void print_inorder(Node_ptr);
void print_preorder(Node_ptr);
void print_postorder(Node_ptr);
void search_node(Node_ptr, int);
Node_ptr delete_node(Node_ptr, int);
Node_ptr rotate_right(Node_ptr, Node_ptr);

#endif