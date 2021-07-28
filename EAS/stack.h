#ifndef stack_H_INCLUDED
#define stack_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "evaluasi.h"

/** struct stack **/
typedef struct InfotypeStack
{
	Infotype info;
	struct InfotypeStack* next;
}Stack;

/* Inisialisasi stack */
void initStack(Stack** p);


/** Memeriksa isi stack **/
int EmptyStack(Stack* p);


/** Return nilai pada top stack**/
Infotype top(Stack* p);


/** Push **/
void push(Stack** p, Infotype e);


/** Pop **/
void pop(Stack** p, Infotype* e);

/** Kembalikan elemen stack dari array ke dalam bentuk postfix**/
Stack* infixtoPostfix(Infotype* t, int n);

/** Menampilkan isi stack **/
void PrintStack(Stack* p, Stack* r);


/** Evaluasi stack  **/
double Evaluate(Stack** p);

/** aturan program **/
void aturan();

#endif 
