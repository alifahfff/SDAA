#include "Tree.h"

int MakeEmptyTree(bTree* T)
{
	if (a == NULL)
		return 1;
	else
		return 0;
}

bTree* Left(bTree* T)
{
	return T->Left;
}

bTree* Right(bTree* T)
{
	return T->Right;
}

int IsAvailableNode(bTree* T)
{
	if (( Right(T) == NULL )&&( Left(T) == NULL ))
		return 1;
	else
		return 0;
}

bTree* CreateNode(Elm X)
{
	bTree* T;
	T = (bTree*)malloc(sizeof(bTree));
	T->info = X;
	T->Left = NULL;
	T->Right = NULL;
	return T;
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

void PushStackrA(StackATree** p, bTree* T)
{
	StackATree* q;
	q = (StackATree*)malloc(sizeof(StackATree));
	q->info = T;
	q->svt = (*p);
	(*p) = q;
}

void PopStackrA(StackATree** p, bTree** T)
{
	StackATree* q;
	q = (*p);
	(*p) = q->svt;
	(*T) = q->info;
	free(q);
}

bTree* constTree(Elm* X, int n)
{
	/*Transformation de forme infixée au forme postfixée*/
	Stack *p;
	initStack(&p);
	p = infixtoPostfix(X, n);
	/*création de l'Tree*/
	Tree* f;
	Tree* f1;
	Tree* f2;
	/*initialiser la Stack Pops Trees*/
	StackATree* pTree;
	initStackA(&pTree);

	Elm I;
	while(!StackEmpty(p))
	{
		PopStackr(&p, &I);
		if(operande(I))
		{
			f = CreateNode(I);
			PushStackrA(&pTree, f);
		}
		else
		{
			/*construire une sous Tree*/
			f = CreateNode(I);
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


double EvaluateTree(bTree* T)
{
	Elm x, y;
	if(!TreeEmpty(T))
	{
		if(operateur(T->info))
		{
			x.val = EvaluateTree(Left(T));
			y.val = EvaluateTree(Right(T));
			return operation(x, T->info, y);
		}
		else
			return T->info.val;
	}
}


void PrintTree(bTree* T)
{
	if(!TreeEmpty(T))
	{
        printf("Node saat ini : ");
        PrintElm(T->info);
        printf(".....Kiri: ");
        if(Left(T))
			PrintElm(Left(T)->info);
		else
			printf("[NULL]");
        printf(".....Kanan: ");
        if(Right(T))
			PrintElm(Right(T)->info);
		else
			printf("[NULL]");
        printf("\n");
        PrintTree(Left(T));
        PrintTree(Right(T));
	}
}

void InOrder(bTree* T)
{
	if(T != NULL){
		InOrder(T->Left);
		printf("%s ",T->info);
		InOrder(T->Right);
	}
}

void PostOrder(bTree* T)
{
	if(T != NULL){
		PostOrder(T->Left);
		PostOrder(T->Right);
		printf("%s ",T->info);
	}
}

void PreOrder(bTree* T)
{
	if(T != NULL){
		printf("%s ",T->info);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}
