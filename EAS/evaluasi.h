#ifndef evaluasi_H_INCLUDED
#define evaluasi_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/** Struct untuk membedakan isOperator dan operand **/
 typedef struct
 {
 	double val;
 	int operand; 
 }Infotype;


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


/** Mengubah char menjadi float**/
void ChartoFloat(char *ch, Infotype *t, int *n);


/** Menentukan e apakah Operator**/
int isOperator(Infotype e);


/** Menentukan e apakah operand **/
int isOperand(Infotype e);


/**
 Mengembalikan prioritas Operator contoh:
 * 1 => { *, /, % }
 * 2 => { +, - }
 */
int priority(Infotype e);


/** Melakukan operasi  */
double operation(Infotype x1, Infotype op, Infotype x2);

/** Menampilkan elemen **/
void PrintInfotype(Infotype e);

#endif 
