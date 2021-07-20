#include "Tree.h"

int TreeEmpty(Tree* a)
{
	if (a == NULL)
		return 1;
	else
		return 0;
}

Tree* Left(Tree* a)
{
	return a->Left;
}

Tree* Right(Tree* a)
{
	return a->Right;
}

int IsAvailableNode(Tree* a)
{
	if (( Right(a) == NULL )&&( Left(a) == NULL ))
		return 1;
	else
		return 0;
}

Tree* CreateNode(Elm e)
{
	Tree* a;
	a = (Tree*)malloc(sizeof(Tree));
	a->info = e;
	a->Left = NULL;
	a->Right = NULL;
	return a;
}


void initStackA(StackATree** p)
{
	(*p) = NULL;
}

int StackAEmpty(StackATree* p)
{
	return p == NULL;
}

Tree* TopStackA(StackATree* p)
{
	return p->info;
}

void PushStackrA(StackATree** p, Tree* a)
{
	StackATree* q;
	q = (StackATree*)malloc(sizeof(StackATree));
	q->info = a;
	q->svt = (*p);
	(*p) = q;
}

void PopStackrA(StackATree** p, Tree** a)
{
	StackATree* q;
	q = (*p);
	(*p) = q->svt;
	(*a) = q->info;
	free(q);
}

Tree* constTree(Elm* t, int n)
{
	/*Transformation de forme infixée au forme postfixée*/
	Stack *p;
	initStack(&p);
	p = infixtoPostfix(t, n);
	/*création de l'Tree*/
	Tree* f;
	Tree* f1;
	Tree* f2;
	/*initialiser la Stack Pops Trees*/
	StackATree* pTree;
	initStackA(&pTree);

	Elm x;
	while(!StackEmpty(p))
	{
		PopStackr(&p, &x);
		if(operande(x))
		{
			f = CreateNode(x);
			PushStackrA(&pTree, f);
		}
		else
		{
			/*construire une sous Tree*/
			f = CreateNode(x);
			PopStackrA(&pTree, &f1);
			PopStackrA(&pTree, &f2);
			f->Right = f1;
			f->Left = f2;
			PushStackrA(&pTree, f);
		}
	}
	/*la racine de l'Tree se trouve a la Stack des Trees et la Stack p est Empty*/
	return TopStackA(pTree);
}


double EvaluateTree(Tree* a)
{
	Elm x, y;
	if(!TreeEmpty(a))
	{
		if(operateur(a->info))
		{
			x.val = EvaluateTree(Left(a));
			y.val = EvaluateTree(Right(a));
			return operation(x, a->info, y);
		}
		else
			return a->info.val;
	}
}


void PrintTree(Tree* a)
{
	if(!TreeEmpty(a))
	{
        printf("Node saat ini : ");
        PrintElm(a->info);
        printf(".....Kiri: ");
        if(Left(a))
			PrintElm(Left(a)->info);
		else
			printf("[NULL]");
        printf(".....Kanan: ");
        if(Right(a))
			PrintElm(Right(a)->info);
		else
			printf("[NULL]");
        printf("\n");
        PrintTree(Left(a));
        PrintTree(Right(a));
	}
}
