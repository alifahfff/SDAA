#ifndef stack_H_INCLUDED
#define stack_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "evaluasi.h"

/** struct stack **/
typedef struct elmPile
{
	Elm info;
	struct elmPile* svt;
}Stack;

/* Inisialisasi stack */
void initStack(Stack** p);


/** Memeriksa isi stack **/
int EmptyStack(Stack* p);


/** Return nilai pada top stack**/
Elm top(Stack* p);


/** Push **/
void push(Stack** p, Elm e);


/** Pop **/
void pop(Stack** p, Elm* e);

/** Kembalikan elemen stack dari array ke dalam bentuk postfix**/
Stack* infixtoPostfix(Elm* t, int n);

/** Menampilkan isi stack **/
void PrintStack(Stack* p, Stack* r);


/** Evaluasi stack  **/
double Evaluate(Stack** p);


#endif // STACK_H_INCLUDED
