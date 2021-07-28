#include "tree.h"

int isEmptyTree(Tree* a)
{
	if (a == NULL)
		return 1;
	else
		return 0;
}

Tree* LeftNode(Tree* a)
{
	return a->pointerLeft;
}

Tree* ParentNode(Tree* a)
{
	return a->pointerParent;
}

Tree* RightNode(Tree* a)
{
	return a->pointerRight;
}

int isLeaf(Tree* a)
{
	if (( RightNode(a) == NULL )&&( LeftNode(a) == NULL ))
		return 1;
	else
		return 0;
}

Tree* CreateNode(Infotype e)
{
	Tree* a;
	a = (Tree*)malloc(sizeof(Tree));
	a->info = e;
	a->pointerParent = NULL;
	a->pointerLeft = NULL;
	a->pointerRight = NULL;
	return a;
}


void initStackA(StackTree** p)
{
	(*p) = NULL;
}

int StackAEmpty(StackTree* p)
{
	return p == NULL;
}

Tree* TopStack(StackTree* p)
{
	return p->info;
}

void pushA(StackTree** p, Tree* a)
{
	StackTree* q;
	q = (StackTree*)malloc(sizeof(StackTree));
	q->info = a;
	q->next = (*p);
	(*p) = q;
}

void popA(StackTree** p, Tree** a)
{
	StackTree* q;
	q = (*p);
	(*p) = q->next;
	(*a) = q->info;
	free(q);
}

Tree* constTree(Infotype* t, int n)
{
	Stack *p;
	initStack(&p);
	p = infixtoPostfix(t, n);
	Tree* f;
	Tree* f1;
	Tree* f2;
	StackTree* pTree;
	initStackA(&pTree);
	Infotype x;
	
	while(!EmptyStack(p))
	{
		pop(&p, &x);
		if(isOperand(x))
		{
			f = CreateNode(x);
			pushA(&pTree, f);
		}
		else
		{
			f = CreateNode(x);
			popA(&pTree, &f1);
			popA(&pTree, &f2);
			f1->pointerParent = f;
			f2->pointerParent = f;
			f->pointerRight = f1;
			f->pointerLeft = f2;
			pushA(&pTree, f);
		}
	}
	return TopStack(pTree);
}


double EvaluateTree(Tree* a)
{
	Infotype x, y;
	if(!isEmptyTree(a))
	{
		if(isOperator(a->info))
		{
			x.val = EvaluateTree(LeftNode(a));
			y.val = EvaluateTree(RightNode(a));
			return operation(x, a->info, y);
		}
		else
			return a->info.val;
	}
}


void PrintTree(Tree* a)
{
	if(!isEmptyTree(a))
	{	
        printf("\tSimpul(Node) : ");			
        PrintInfotype(a->info);
        printf("  Pointer Left  : ");
        if(LeftNode(a))
			PrintInfotype(LeftNode(a)->info);
		else
			printf("[NULL ]");
        printf("  Pointer Right : ");
        if(RightNode(a))
			PrintInfotype(RightNode(a)->info);
		else
			printf("[NULL ]");
		printf("  Parent : ");
		if(ParentNode(a))
			PrintInfotype(ParentNode(a)->info);
		else
			printf("[NULL ]");
        printf("\n\n");
        PrintTree(LeftNode(a));
        PrintTree(RightNode(a));
	}
}

void PostOrder(Tree* a)
{
	if(!isEmptyTree(a))
	{
        PostOrder(LeftNode(a));
        PostOrder(RightNode(a));
        PrintInfotype(a->info);
        printf("\t");
	}
}

void PreOrder(Tree* a)
{
	if(!isEmptyTree(a))
	{
		PrintInfotype(a->info);
		printf("\t");
        PreOrder(LeftNode(a));
        PreOrder(RightNode(a));
	}
}

void InOrder(Tree* a)
{
	if(!isEmptyTree(a))
	{
        InOrder(LeftNode(a));
        PrintInfotype(a->info);
        printf("\t");
        InOrder(RightNode(a));
	}
}
