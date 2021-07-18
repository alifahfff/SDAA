#include "common.h"

char readinfix(){
	char p[100];
	printf("\n\t\tMasukan perhitungan :")
	scanf("%s",p);
	return p;
}

int isdigits(char ch)
{
	if(ch >= '0' && ch <='9')
        return TRUE;
	else
		return FALSE;    
}

int isAlphabet(char temp) {
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
}

int priorityOp(const char op) {
	if (op == '^'){
		return 4;
	}

	if (op == '*' || op == '/'){
		return 3;
	}

	if (op == '+' || op == '-'){
		return 2;
	}

	return 1;
}

/*
int compare_op_priority(const char first, const char second) {
	if (first == '(' || second == '(' || second == ')'){
		return 0;
	}

	if (first == second && second == '^'){
		return 0;
	}

	return get_op_priority(first) >= get_op_priority(second);
}
*/
