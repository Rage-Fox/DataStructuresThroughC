#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[10000],ans[10000],stack[10000];
int top=-1;
int is_op(char ch)
{
	if(ch==42||ch==47||ch==37)
	{
		return 2;
	}
	if(ch==43||ch==45)
	{
		return 1;
	}
	if(ch=='(')
	{
		return -1;//to insert + or other operators into stack
	}
	
	return 0;
}
void infixtopostfix(char *s)
{
	int i,k=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(is_op(s[i]))
		{
			X:if(top==-1||str[i]=='(')
			{
				stack[++top]=s[i];
			}
			else
			{
				if(is_op(s[i])>is_op(stack[top]))
				{
					stack[++top]=s[i];
				}
				else
				{
					ans[k++]=stack[top--];
					goto X;
				}
			}
		}
		else
		{
			if(str[i]==')')
			{
				while(stack[top]!='(')
				{
					ans[k++]=stack[top--];
				}
				stack[top--];
			}
			else
			{
				ans[k++]=s[i];
			}
		}
	}
	for(i=top;i>=0;i--)
	{
		ans[k++]=stack[i];
	}
	ans[k]='\0';
}
int main()
{
	scanf("%[^\n]s",str);
	infixtopostfix(str);
	printf("%s",ans);
}
/*
infix-->	a+b*c-d*e/f		a-b+c*d*e/f*g-z		a+b+c-d*e-f*g/h
postfix-->	abc*+de*f/-		ab-cd*e*f/g*+z-		ab+c+de*-fg*h/-
--------------
with brackets:
--------------
infix-->	a+b*(c-d*e)-(f-g)	(a*b-c)-(d-e-f)+(g+h)
postfix-->	abcde*-*+fg--		ab*c-de-f--gh++
*/