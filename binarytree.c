#include "binarytree.h"

void MakeEmptyTree(bTree *P)
{
		P->root = NULL;
}

boolean isEmptyTree(bTree P){
	if(P.root == NULL){
		return true;
	}else{
		return false;
	}
}

boolean isEmptyNode(NodeTree node)
{
	if(node == NULL){
		return true;
	}else{
		return false;
	}
}

NodeTree CreateNode(infotype X)
{
	NodeTree P;
	
	P = (NodeTree)malloc(sizeof(node));
	
	if(!isEmptyNode(P)){
		P->isNum = NULL;
		P->info = X;
		P->Left = NULL;
		P->Right = NULL;
		P->Parent = NULL;
	}else{
		printf("Node belum dialokasi!");
	}
	return P;
}

/*
void SetLeft(NodeTree Parent, NodeTree X)
{
	if(isEmptyNode(Parent->Left))
	{
		X->Parent = Parent;
		Parent->Left = X;
	}
	else
	{
		printf("Node sudah ada!");
	}
}
*/

/*
void SetRight(NodeTree Parent, NodeTree X)
{
	if(isEmptyNode(Parent->Right))
	{
		X->Parent = Parent;
		Parent->Right = X;
	}
	else
	{
		printf("Node sudah ada!");
	}
}

*/

/*
void SetParent(NodeTree Parent, NodeTree Left, NodeTree Right)
{
	SetRight(Parent,Right);
	SetLeft(Parent,Left);
}

*/
void InOrder(NodeTree tr)
{
	if(tr != NULL){
		InOrder(tr->Left);
		printf("%s ",tr->info);
		InOrder(tr->Right);
	}
}

void PostOrder(NodeTree tr)
{
	if(tr != NULL){
		PostOrder(tr->Left);
		PostOrder(tr->Right);
		printf("%s ",tr->info);
	}
}

void PreOrder(Nodetree tr)
{
	if(tr != NULL){
		printf("%s ",tr->info);
		PreOrder(tr->Left);
		PreOrder(tr->Right);
	}
}
