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

Infotype top(Stack* p)
{
	if (!EmptyStack(p))
		return p->info;
	else
		printf("Eror: Stack Kosong! ");
}

void push(Stack** p, Infotype e)
{
	Stack* q;
	q = (Stack*)malloc(sizeof(Stack));
	q->info = e;
	q->next = (*p);
	(*p) = q;
}

void pop(Stack** p, Infotype* e)
{
	Stack *top;
	top = (*p);
	(*p) = top->next;
	*e = top->info;
	free(top);
}

Stack* infixtoPostfix(Infotype* t, int n)
{
	Stack *p, *r;
	Infotype x;
	int i;
	initStack(&p);
	initStack(&r);
	for(i = 0; i < n; i++)
	{
		if(isOperand(t[i]))
			push(&r, t[i]);
		else if(isOperator(t[i]))
		{
			while((!EmptyStack(p))&&(isOperator(top(p)))&&(priority(t[i]) >= priority(top(p))))
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
	
	Stack* pTmp;
	Stack* rTmp;
	for( pTmp = p, rTmp = r; (pTmp)&&(rTmp); pTmp = pTmp->next, rTmp = rTmp->next)
	{
		printf("\t");
		PrintInfotype(pTmp->info);
		printf("\t\t");
		PrintInfotype(rTmp->info);
		printf("\n");
	}
	for( ;(pTmp); pTmp = pTmp->next)
	{
		printf("\t");
		PrintInfotype(pTmp->info);
		printf("\n");
	}
	for( ;(rTmp); rTmp = rTmp->next)
	{
		printf("\t\t\t");
		PrintInfotype(rTmp->info);
		printf("\n");
	}
}



double Evaluate(Stack** p)
{
	Infotype resultat, x, x1, x2;
	resultat.operand = 1;
	Stack *r;
	initStack(&r);
	while(!EmptyStack((*p)))
	{
		PrintStack( *p, r);
		pop(p, &x);
		if (isOperand(x))
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

void aturan()
{
	char buff[1000];
  	FILE *fptr;

  	// membuka file
 	if ((fptr = fopen("aturan.txt","r")) == NULL){
      printf("Error: File tidak ada!");
      // Tutup program karena file gak ada.
      exit(1);
  }

  	while(!feof(fptr)){
  		fgets(buff,1000,fptr);
  		printf("%s",buff);
	  }

  	// tutup file
  	fclose(fptr);
}
