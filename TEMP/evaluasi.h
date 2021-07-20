#ifndef evaluasi_H_INCLUDED
#define evaluasi_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/** Struct untuk membedakan operator dan operand **/
 typedef struct
 {
 	double val;
 	int operand; /*booléen 1 => opérande */
 }Elm;

 /*les fonctions d'aide à l'étude syntaxique et lexique de l'expression*/

 /*langueur max de l'expression*/
 #define L_MAX 100

 /** Memeriksa karakter **/
int charAdmis(char c);

/** Analisis dari char*exp **/
int lexiqueJuste(char* exp);

/** Return 1 jika c merupakan operand**/
int charOperande(char c);

/** Return 1 jika c merupakan operator**/
int charOperateur(char c);


/** Syntax expression **/
int syntaxiqueJuste(char* exp);


/** Mengubah string menjadi float**/
void chaineAuFloat(char *ch, Elm *t, int *n);


/** Menentukan e apakah operator**/
int operateur(Elm e);


/** Menentukan e apakah operand **/
int operande(Elm e);


/**
 Mengembalikan prioritas operator contoh:
 * 1 => { *, /, % }
 * 2 => { +, - }
 */
int priorite(Elm e);


/** Melakukan operasi  */
double operation(Elm x1, Elm op, Elm x2);

/** Menampilkan elemen **/
void afficheElm(Elm e);

#endif // EXPRESSION_H_INCLUDED
