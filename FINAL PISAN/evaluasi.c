#include "evaluasi.h"

int charValidation(char c)
{
	if ( ((c >= '0')&&(c <= '9')) ||
		 (c == '+') || (c == '-') ||
		 (c == '*') || (c == '/') || (c == '%') ||
		 (c == '(') || (c == ')') ||
		 (c == 'e') || (c == 'E') || (c == '.'))
			return 1;
	else
		return 0;
}

int verify(char* exp)
{
	int i;
	
	for(i = 0; (i < L_MAX)&&(exp[i] != '\0'); i++)
		if ( !charValidation(exp[i]) )
			return 0;
	return 1;
}

int isCharOperand(char c)
{
	if ((c >= '0')&&(c <= '9'))
		return 1;
	else
		return 0;
}

int isCharOperator(char c)
{
	if ((c == '+') || (c == '-') ||
		(c == '*') || (c == '/') || (c == '%'))
		return 1;
	else
		return 0;
}

int parenthesis(char* exp)
{
	int i;
	int nbParO = 0, nbParF = 0; 
	
	if (!isCharOperand(exp[0])&&(exp[0] != '-')&&(exp[0]!='('))
		return 0;

	if ((exp[0] == '-')&&(exp[1] == '-'))
		return 0;

	if (exp[0] == '(')
		nbParO++;

	for(i = 1; (i < L_MAX-1) && (exp[i] != '\0'); i++)
	{

		if((isCharOperator(exp[i]))&&(!isCharOperand(exp[i+1]))&&(exp[i+1] != '(')&&(exp[i+1] != '-'))
			return 0;

		if((exp[i] == '(')&&(!isCharOperand(exp[i+1]))&&(exp[i+1] != '(')&&(exp[i+1] != '-'))
			return 0;
	
		if ((exp[i] == ')')&&(exp[i+1] != ')')&&(exp[i+1] != '\0')&&(!isCharOperator(exp[i+1])))
			return 0;
	
		if((isCharOperand(exp[i]))&&(exp[i+1] == '('))
			return 0;
		
		if((exp[i-1] == '-')&&(exp[i] == '-')&&(exp[i+1] == '-'))
			return 0;
	
		if((exp[i] == '.')&&(!isCharOperand(exp[i+1])))
			return 0;
	
		if (exp[i] == '(')
			nbParO++;
		else if (exp[i] == ')')
			nbParF++;
	}
	
	if (nbParO != nbParF)
		return 0;

	return 1;
}

void StringtoFloat(char *ch, Infotype *t, int *n)
{
	int iCh, iT, iC;
    char c[L_MAX];
    for(iCh = 0, iT =0; (iCh < L_MAX)&&(ch[iCh] != '\0'); iT++)
	{
		if(ch[iCh] == '(')
		{ /*inisalisasi '(' menjadi 6 : 0 */
			t[iT].val = 6.0;
			t[iT].operand = 0;
			iCh++;
		}
		else if (ch[iCh] == ')')
		{/*inisalisasi ')' menjadi 7 : 0 */
			t[iT].val = 7.0;
			t[iT].operand = 0;
			iCh++;
		}
		else if (ch[iCh] == '*')
		{/*insialisasi '*' menjadi 1 : 0 */
			t[iT].val = 1.0;
			t[iT].operand = 0;
			iCh++;
		}
		else if (ch[iCh] == '/')
		{/*inisalisasi  '/' menjadi 2 : 0 */
			t[iT].val = 2.0;
			t[iT].operand = 0;
			iCh++;
		}
		else if (ch[iCh] == '%')
		{/*inisialisasi '%' menjadi 3 : 0 */
			t[iT].val = 3.0;
			t[iT].operand = 0;
			iCh++;
		}
		else if (ch[iCh] == '+')
		{/*inisialisasi '+' menjadi 4 : 0 */
			t[iT].val = 4.0;
			t[iT].operand = 0;
			iCh++;
		}
		else if ((ch[iCh] == '-')&&(iCh > 0)&&(!isCharOperator(ch[iCh-1]))&&(ch[iCh-1] != '('))
		{/*inisialisai '-' menjadi 5 : 0 */
			t[iT].val = 5.0;
			t[iT].operand = 0;
			iCh++;
		}
		else
		{ 
			for(iC = 0; (ch[iCh] != '\0'); iC++, iCh++)
			{
			
				if((isCharOperand(ch[iCh - 1]))&&((isCharOperator(ch[iCh]))||(ch[iCh] == ')')))
					break;
				c[iC] = ch[iCh];
			}
			
			c[iC] = '\0';

			t[iT].val = atof(c);
			t[iT].operand = 1;
		}
	}
	
	*n = iT;
}


int isOperator(Infotype e)
{

	if( (!e.operand)&&(e.val != 6.0)&&(e.val != 7.0))
		return 1;
	else
		return 0;
}

int isOperand(Infotype e)
{
	return e.operand;
}

int priority(Infotype e)
{
	/*
	 * 1=> '*'
	 * 2=> '/'
	 * 3=> '%'
	 */
	if ((e.val == 1.0)||(e.val == 2.0)||(e.val == 3.0))
		return 1;
	else
		return 2;
}

double operation(Infotype x1, Infotype op, Infotype x2)
{
	if(op.val == 1.0)
		return x1.val * x2.val;
	else if(op.val == 2.0)
		return x1.val / x2.val;
	else if(op.val == 3.0)
		return (double)((int)(x1.val) % (int)(x2.val));
	else if(op.val == 4.0)
		return x1.val + x2.val;
	else 
		return x1.val - x2.val;

}


void PrintInfotype(Infotype e)
{
	if(isOperand(e))
	{
		printf("[%.3f]", e.val);
	}
	else
	{
		printf("[%3.0f]", e.val);
	}
}
