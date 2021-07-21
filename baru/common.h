#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

/// this header file is consisting of common things

#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define PREORDER	0
#define INORDER		1
#define POSTORDER	2

#define TRUE		1
#define FALSE	 	0


typedef union
{
	double num;
	char opr;
} Data;

typedef struct TreeNode
{
	int isChar;
	Data data;
	struct TreeNode *parent;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct Root
{
	TreeNode *root;
} Root;


//typedef struct StackNode
//{
//	int isChar;
//	Data data;
//	struct StackNode *pNode;
//} StackNode;
//
//typedef struct Stack
//{
//	StackNode *topNode;
//} Stack;

typedef struct Node{
	int data;
	Node *next;
}sNode;

sNode *atas;


typedef struct input{
	double num;
	int isOpr;
	char opr;
}input;

//const static Data dummy_data = {0};

#endif
