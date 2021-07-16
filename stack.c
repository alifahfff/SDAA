#include "stack.h"

int isEmpty_stack(Stack *stack)
{
	if(!stack) {
		puts("the stack doesn't exist.");
		return TRUE;
	}
	return stack->topNode == NULL;
}

StackNode* make_stack_node()
{
	StackNode *tmp = (StackNode*)calloc(sizeof(StackNode), 1);
	if(!tmp){
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

Stack* make_stack()
{
	Stack *tmp = (Stack*)calloc(sizeof(Stack), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

void print_stack_node(StackNode *tNode)
{
	if(!tNode)	return;
	if(tNode->isChar){
		printf("%c", tNode->data.opr);
	}
	else{
		printf("%g", tNode->data.num);
	}
}

void push(Stack *stack, Data datum, int isChar)
{
	StackNode *tmp = make_stack_node();
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	tmp->data = datum;
	tmp->isChar = isChar;
	tmp->pNode = stack->topNode;
	stack->topNode = tmp;
}	

StackNode pop(Stack *stack)
{
	StackNode res;
	res.data = dummy_data;
	res.isChar = FALSE;
	if(!stack || isEmpty_stack(stack))	return res;
	res = *(stack->topNode);
	StackNode *tmp = stack->topNode;
	stack->topNode = tmp->pNode;
	free(tmp);
	return res;
}

void remove_stack(Stack *stack)
{
	StackNode sn;
	while(!isEmpty_stack(stack)) {
		sn = pop(stack);
		print_stack_node(&sn);
	}
}


//-----------------NGECEK OPERATOR-----------------------//
int is_operand(char ch)
{
	if(ch>='a'&&ch<='z' || ch>='A'&&ch<='Z')
	return 1;
	else
	return 0;
}
//-----------------EVALUATE POSTFIX----------------------//
int evaluatepostfix(char* ch)
{
    // Create a stack of capacity equal to expression size
    struct Stack* stack = make_stack();
    int i=0,op1,op2,result,nilai;
    char nampung;
    
    while(ch[i]!='\0')
		{
			nampung=ch[i];
				if(is_operand(nampung)==1)
				{
					printf("masukan angka %c : ", nampung);
					scanf("%d", &nilai);
					push(nilai);
				}
				else
				{
					op2=pop();
					op1=pop();
					switch(nampung)
					{
						case '+': result=op1+op2;
								  push(result);
								  break;
						case '-': result=op1-op2;
								  push(result);
								  break;
						case '*': result=op1*op2;
								  push(result);
								  break;
						case '/': result=op1/op2;
								  push(result);
								  break;
					}
				}
			i++;
		}
	result= pop();
	printf("hasilnya adalah ini bgst : %d", result);
	
	getch();
	return 0;
}
//  
//    // See if stack was created successfully
//    if (!stack) return -1;
//  
//    // Scan all characters one by one
//    for (i = 0; exp[i]; ++i)
//    {
//        //if the character is blank space then continue
//        if(exp[i]==' ')continue;
//          
//        // If the scanned character is an 
//        // operand (number here),extract the full number
//        // Push it to the stack.
//        else if (isdigit(exp[i]))
//        {
//            int num=0;
//              
//            //extract full number
//            while(isdigit(exp[i])) 
//            {
//            num=num*10 + (int)(exp[i]-'0');
//                i++;
//            }
//            i--;
//              
//            //push the element in the stack
//            push(stack,num);
//        }
//          
//        // If the scanned character is an operator, pop two
//        // elements from stack apply the operator
//        else
//        {
//            int val1 = pop(stack);
//            int val2 = pop(stack);
//              
//            switch (exp[i])
//            {
//            case '+': push(stack, val2 + val1); break;
//            case '-': push(stack, val2 - val1); break;
//            case '*': push(stack, val2 * val1); break;
//            case '/': push(stack, val2/val1); break;
//              
//            }
//        }
//    }
//    return pop(stack);
//}

