#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Common.h"

int isEmpty_stack(Stack *stack);
StackNode* make_stack_node();
Stack* make_stack();
void print_stack_node(StackNode*);
void push(Stack *stack, Data datum, int isChar);
StackNode pop(Stack *stack);
void remove_stack(Stack *stack);

//-----------MODUL TAMBAHAN-----------//
int evaluatePostfix(char* exp);

#endif // STACK_H_INCLUDED

