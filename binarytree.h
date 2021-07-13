#ifndef binarytree_H
#define binarytree_H

#include <string.h>
#include "boolean.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef char* infotype;
typedef struct node *NodeTree;

typedef struct infotype{
	int num
	char opr
};

struct node 
{
	bool isNum; // operator or operand checker
	Infotype data; // Data Node
	NodeTree Left; //Left Node
	NodeTree Right; //Right Node
	NodeTree Parent; //Parent Node
};
 
struct bTree 
{
	NodeTree root;
};

boolean isEmptyTree(bTree P);

boolean IsFull();

void MakeEmptyTree(bTree *P);

void SetLeft(NodeTree Parent, NodeTree X);

void SetRight(NodeTree Parent, NodeTree X);

void SetParent(NodeTree Parent, NodeTree Left, NodeTree Right);

boolean isEmptyNode(NodeTree node);

NodeTree BCreateNode(Infotype X);

void InOrder(NodeTree tr);

void PostOrder(NodeTree tr);

void PreOrder(NodeTree tr);

#endif
