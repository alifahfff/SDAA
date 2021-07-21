#ifndef evaluasi_H_INCLUDED
#define evaluasi_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/** Struct untuk membedakan isOperator dan operand **/
 typedef struct
 {
 	double val;
 	int operand; /*booléen 1 => opérande */
 }Elm;

 /*les fonctions d'aide à l'étude syntaxique et lexique de l'expression*/

 /*langueur max de l'expression*/
 #define L_MAX 100

 /** Memeriksa karakter **/
int charValidation(char c);

/** Analisis dari char*exp **/
int verify(char* exp);

/** Return 1 jika c merupakan operand**/
int isCharOperand(char c);

/** Return 1 jika c merupakan isOperator**/
int isCharOperator(char c);


/** Syntax expression **/
int parenthesis(char* exp);


/** Mengubah string menjadi float**/
void StringtoFloat(char *ch, Elm *t, int *n);


/** Menentukan e apakah Operator**/
int isOperator(Elm e);


/** Menentukan e apakah operand **/
int isOperand(Elm e);


/**
 Mengembalikan prioritas Operator contoh:
 * 1 => { *, /, % }
 * 2 => { +, - }
 */
int priority(Elm e);


/** Melakukan operasi  */
double operation(Elm x1, Elm op, Elm x2);

/** Menampilkan elemen **/
void PrintElm(Elm e);

#endif // EXPRESSION_H_INCLUDED
