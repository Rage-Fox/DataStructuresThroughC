#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char pe[10000];//postfix expression
int stack[10000],top=-1;
int is_op(char ch)
{
	char op[5]={'+','-','*','/','%'};//ascii values are 43,45,47,42,37
	if(ch==42||ch==43||ch==45||ch==47||ch==37)
	{
		return 1;
	}
	return 0;
}
void postevaluation(char *s)//23 34 +
{
	int i,k=0,val=0,op1,op2;
	char temp[100];
	for(i=0;s[i]!='\0';i++)
	{
		if(is_op(s[i]))
		{
			//pop two elements and perform operation and insert the result into the stack
			op1=stack[top--];
			op2=stack[top--];
			if(s[i]=='+')
			{
				stack[++top]=op2+op1;
			}
			else if(s[i]=='-')
			{
				stack[++top]=op2-op1;
			}
			else if(s[i]=='*')
			{
				stack[++top]=op2*op1;
			}
			else if(s[i]=='/')
			{
				stack[++top]=op2/op1;
			}
			else
			{
				stack[++top]=op2%op1;
			}
		}
		else
		{
			if(s[i]!=' ')
			{
				temp[k++]=s[i];
			}
			else if(s[i]==' ' && !is_op(s[i-1]))//k!=0
			{
				temp[k]='\0';//closing the string temp to avoid garbage values
				stack[++top]=atoi(temp);
				k=0;
			}
			//atoi();//string into integer in-built function
		}
	}
}
int main()
{
	scanf("%[^\n]s",pe);
	postevaluation(pe);//final value is an integer
	printf("%d",stack[0]);
}
/*
1. If it is an operand, push into the stack
2. If it is an operator, pop two elements from the stack, perform operation and push result into the stack
2 3 2 * + 1 2 / 3 * +
*/