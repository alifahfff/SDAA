#include "stack.h"

void initStack(Stack **p)
{
	(*p) = NULL;
}

int EmptyStack(Stack* p)
{
	if ( p == NULL)
		return 1;
	else
		return 0;
}

Elm top(Stack* p)
{
	if (!EmptyStack(p))
		return p->info;
	else
		printf("Eror: Stack Kosong! ");
}

void push(Stack** p, Elm e)
{
	Stack* q;
	q = (Stack*)malloc(sizeof(Stack));
	q->info = e;
	q->svt = (*p);
	(*p) = q;
}

void pop(Stack** p, Elm* e)
{
	Stack *top;
	top = (*p);
	(*p) = top->svt;
	*e = top->info;
	free(top);
}

Stack* infixtoPostfix(Elm* t, int n)
{
	Stack *p, *r;
	Elm x;
	int i;
	initStack(&p);
	initStack(&r);
	for(i = 0; i < n; i++)
	{
		if(operande(t[i]))
			push(&r, t[i]);
		else if(operateur(t[i]))
		{
			while((!EmptyStack(p))&&(operateur(top(p)))&&(priorite(t[i]) >= priorite(top(p))))
			{
				pop(&p, &x);
				push(&r, x);
			}
			push(&p, t[i]);
		}
		else if(t[i].val == 6.0)
			push(&p, t[i]);
		else
		{
			while((!EmptyStack(p)) && !((top(p).val == 6.0)&&(!top(p).operand)))
			{
				pop(&p, &x);
				push(&r, x);
			}
			pop(&p, &x);
		}
	}
	while(!EmptyStack(r))
	{
		pop(&r, &x);
		push(&p, x);
	}
	return p;
}


void PrintStack(Stack* p, Stack* r)
{
	printf("\t[  p  ]\t\t[  r  ]\n");
	/*on va traiter les piles comme des liste chaines simples pour ne pas perdre les élément*/
	Stack* pTmp;
	Stack* rTmp;
	for( pTmp = p, rTmp = r; (pTmp)&&(rTmp); pTmp = pTmp->svt, rTmp = rTmp->svt)
	{
		printf("\t");
		afficheElm(pTmp->info);
		printf("\t\t");
		afficheElm(rTmp->info);
		printf("\n");
	}
	for( ;(pTmp); pTmp = pTmp->svt)
	{
		printf("\t");
		afficheElm(pTmp->info);
		printf("\n");
	}
	for( ;(rTmp); rTmp = rTmp->svt)
	{
		printf("\t\t\t");
		afficheElm(rTmp->info);
		printf("\n");
	}
}



double Evaluate(Stack** p)
{
	Elm resultat, x, x1, x2;
	resultat.operand = 1;
	Stack *r;
	initStack(&r);
	while(!EmptyStack((*p)))
	{
		PrintStack( *p, r);
		pop(p, &x);
		if (operande(x))
			push(&r, x);
		else
		{
			pop(&r, &x2);
			pop(&r, &x1);
			resultat.val = operation(x1, x, x2);
			push(&r, resultat);
		}
		//printf("----------------------------------\n");
	}
	return top(r).val;
}
