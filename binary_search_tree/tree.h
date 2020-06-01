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

Node_ptr insert_node(Node_ptr, int);
#endif