#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "expression.h"
#include "Stack.h"


/** Primitives des Trees binaire **/

/**
 *Définition de la structure
 */
 
typedef struct elmTree
{
	Elm info;
	struct elmTree* Left;
	struct elmTree* Right;
}Tree;

/**
 *TreeEmpty(Tree*)
 *Vérifier si l'Tree est Empty
 *return 0 <=> Tree non Empty
 */
int TreeEmpty(Tree* a);

/**
 *succKiri(Tree*)
 *return adresse du successeur Kiri
 */
Tree* Left(Tree* a);

/**
 *succDroit(Tree*)
 *return adresse du successeur droit
 */
Tree* Right(Tree* a);

/**
 *feuil(Tree*)
 *vérifier si le noeud est une feuil
 *return 0 <=> pas une feuil
 */
int IsAvailableNode(Tree* a);

/**
 *CreateNode(Elm e)
 *return une feuil avec e
 */
Tree* CreateNode(Elm e);

/*Fonctions de transformation de l'expression arithmétique à une Tree binaire
	en utilisant la forme postfixée et une Stack des Trees*/
/**
 *définition de la structure de la Stack des Trees
 */
typedef struct elmStackTree
{
	Tree* info;
	struct elmStackTree* svt;
}StackATree;

void initStackA(StackATree** p);

int StackAEmpty(StackATree* p);

Tree* TopStackA(StackATree* p);

void PushStackrA(StackATree** p, Tree* a);

void PopStackrA(StackATree** p, Tree** a);


/**
 *constTree(Stack* p)
 *return la racine de l'Tree contenant l'expression arithmétique
 */
Tree* constTree(Elm* t, int n);


/**
 *evaluerTree(Tree* a)
 *return le résultat de l'évaluation de l'expression à partir de l'Tree
 */
double EvaluateTree(Tree* a);

/**
 *afficheTree(Tree* a)
 *afficher les noeuds de l'Tree un par un avec ses fils
 */
void PrintTree(Tree* a);

#endif // Tree_H_INCLUDED
