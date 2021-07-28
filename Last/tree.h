#ifndef Tree_H_INCLUDED
#define Tree_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "evaluasi.h"
#include "stack.h"


typedef struct InfotypeTree
{
	Infotype info;
	struct InfotypeTree* pointerLeft;
	struct InfotypeTree* pointerRight;
}Tree;

int isEmptyTree(Tree* a);

Tree* LeftNode(Tree* a);

Tree* RightNode(Tree* a);

int isLeaf(Tree* a);

Tree* CreateNode(Infotype e);


typedef struct InfotypeStackTree
{
	Tree* info;
	struct InfotypeStackTree* svt;
}StackTree;

void StackAEmpty(StackTree** p);

int StackAEmpty(StackTree* p);

Tree* TopStack(StackTree* p);

void pushA(StackTree** p, Tree* a);

void popA(StackTree** p, Tree** a);


Tree* constTree(Infotype* t, int n);


double EvaluateTree(Tree* a);

void PrintTree(Tree* a);

#endif // Tree_H_INCLUDED

