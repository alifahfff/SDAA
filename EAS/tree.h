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
	struct InfotypeTree* pointerParent;
	struct InfotypeTree* pointerRight;
}Tree;

//Fungsi Mengecek Tree
int isEmptyTree(Tree* a);

//Fungsi Memanggil Pointer kiri
Tree* LeftNode(Tree* a);

//Fungsi Memanggil Pointer Parent
Tree* ParentNode(Tree* a);

//Fungsi Memanggil Pointer Kanan
Tree* RightNode(Tree* a);

//Fungsi Mengetahui leaf(daun)
int isLeaf(Tree* a);

//Fungsi untuk membuat node
Tree* CreateNode(Infotype e);


typedef struct InfotypeStackTree
{
	Tree* info;
	struct InfotypeStackTree* next;
}StackTree;

//Prosedur Inisialisasi Stack 
void initStackA(StackTree** p);

//Fungsi Pengecekan stack
int StackAEmpty(StackTree* p);

Tree* TopStack(StackTree* p);

void pushA(StackTree** p, Tree* a);

void popA(StackTree** p, Tree** a);


Tree* constTree(Infotype* t, int n);


double EvaluateTree(Tree* a);

void PrintTree(Tree* a);

void PostOrder(Tree* a);

void PreOrder(Tree* a);

void InOrder(Tree* a);
#endif 

