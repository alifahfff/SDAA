#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "expression.h"
#include "Stack.h"


/** Primitives des bTrees binaire **/

/**
 *Définition de la structure
 */
 
typedef struct elmbTree
{
	Elm info;
	struct elmbTree* Left;
	struct elmbTree* Right;
}bTree;

/**
 *bTreeEmpty(bTree*)
 *Vérifier si l'bTree est Empty
 *return 0 <=> bTree non Empty
 */
int MakeEmptybTree(bTree* T);

/**
 *succKiri(bTree*)
 *return adresse du successeur Kiri
 */
bTree* Left(bTree* T);

/**
 *succDroit(bTree*)
 *return adresse du successeur droit
 */
bTree* Right(bTree* T);

/**
 *feuil(bTree*)
 *vérifier si le noeud est une feuil
 *return 0 <=> pas une feuil
 */
int IsAvailableNode(bTree* T);

/**
 *CreateNode(Elm e)
 *return une feuil avec e
 */
bTree* CreateNode(Elm X);

/*Fonctions de transformation de l'expression arithmétique à une bTree binaire
	en utilisant la forme postfixée et une Stack des bTrees*/
/**
 *définition de la structure de la Stack des bTrees
 */
typedef struct elmStackbTree
{
	bTree* info;
	struct elmStackbTree* svt;
}StackAbTree;

void initStackA(StackAbTree** p);

int StackAEmpty(StackAbTree* p);

bTree* TopStackA(StackAbTree* p);

void PushStackrA(StackAbTree** p, bTree* T);

void PopStackrA(StackAbTree** p, bTree** a);


/**
 *constbTree(Stack* p)
 *return la racine de l'bTree contenant l'expression arithmétique
 */
bTree* constbTree(Elm* X, int n);


/**
 *evaluerbTree(bTree* T)
 *return le résultat de l'évaluation de l'expression à partir de l'bTree
 */
double EvaluatebTree(bTree* T);

/**
 *affichebTree(bTree* T)
 *afficher les noeuds de l'bTree un par un avec ses fils
 */
void PrintbTree(bTree* T);

#endif // bTree_H_INCLUDED
