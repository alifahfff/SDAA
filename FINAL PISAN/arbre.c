#include "arbre.h"

int TreeVide(Tree* a)
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
	q->svt = (*p);
	(*p) = q;
}

void popA(StackTree** p, Tree** a)
{
	StackTree* q;
	q = (*p);
	(*p) = q->svt;
	(*a) = q->info;
	free(q);
}

Tree* constTree(Infotype* t, int n)
{
	/*Transformation de forme infixée au forme postfixée*/
	Stack *p;
	initStack(&p);
	p = infixtoPostfix(t, n);
	/*création de l'Tree*/
	Tree* f;
	Tree* f1;
	Tree* f2;
	/*initialiser la pile des Trees*/
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
			/*construire une sous Tree*/
			f = CreateNode(x);
			popA(&pTree, &f1);
			popA(&pTree, &f2);
			f->pointerRight = f1;
			f->pointerLeft = f2;
			pushA(&pTree, f);
		}
	}
	/*la racine de l'Tree se trouve a la pile des Trees et la pile p est vide*/
	return TopStack(pTree);
}


double EvaluateTree(Tree* a)
{
	Infotype x, y;
	if(!TreeVide(a))
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
	if(!TreeVide(a))
	{
        printf("Simpul saat ini : ");
        PrintInfotype(a->info);
        printf(".....anak kiri : ");
        if(LeftNode(a))
			PrintInfotype(LeftNode(a)->info);
		else
			printf("[NULL]");
        printf(".....anak kanan : ");
        if(RightNode(a))
			PrintInfotype(RightNode(a)->info);
		else
			printf("[NULL]");
        printf("\n");
        PrintTree(LeftNode(a));
        PrintTree(RightNode(a));
	}
}

