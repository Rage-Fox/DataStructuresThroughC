#include<stdio.h>
#include<stdlib.h>
int Top=-1;//globally declaring Top variable
int n;//declaring size also as globally
int *stack;//declaring stack as a global variable too..
//we are declaring globally because we need to print them without passing into functions
void push(int val)
{
	if(Top==n-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		stack[++Top]=val;
	}
}
int pop()
{
	int val;
	if(Top==-1)
	{
		return -1;//because stack is empty
	}
	else
	{
		val=stack[Top];//selecting size-1 element
		stack[Top--]=0;//removing it and decreasing top
		return val;//returning size-1 value
	}
}
void display()
{
	int i;
	if(Top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		for(i=Top;i>=0;i--)
		{
			printf("%d ",stack[i]);
		}
		printf("\n");
	}
}
int main()
{
	int i,ch,val;
	scanf("%d",&n);//size of the stack
	stack=(int *)calloc(n,sizeof(int));//allocating the memory of stack
	while(1)//infinite loop
	{
		printf("1.Push\t2.Pop\t3.Display\t4.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//push
			scanf("%d",&val);
			push(val);//calling push function
		}
		else if(ch==2)
		{
			//pop
			val=pop();//it works with return value
			if(val==-1)
			{
				printf("Stack is empty\n");
			}
			else
			{
				printf("%d\n",val);//displaying what element is deleted from stack
			}
		}
		else if(ch==3)
		{
			//display
			display();
		}
		else
		{
			//exit
			break;
		}
	}
}
/*
5
1.Push  2.Pop   3.Display       4.Exit
2
Stack is empty
1.Push  2.Pop   3.Display       4.Exit
3
Stack is empty
1.Push  2.Pop   3.Display       4.Exit
1
10
1.Push  2.Pop   3.Display       4.Exit
3
10
1.Push  2.Pop   3.Display       4.Exit
1
20
1.Push  2.Pop   3.Display       4.Exit
3
20 10
1.Push  2.Pop   3.Display       4.Exit
1
30
1.Push  2.Pop   3.Display       4.Exit
1
40
1.Push  2.Pop   3.Display       4.Exit
1
50
1.Push  2.Pop   3.Display       4.Exit
3
50 40 30 20 10
1.Push  2.Pop   3.Display       4.Exit
1
60
Stack is full
1.Push  2.Pop   3.Display       4.Exit
1
70
Stack is full
1.Push  2.Pop   3.Display       4.Exit
3
50 40 30 20 10
1.Push  2.Pop   3.Display       4.Exit
2
50
1.Push  2.Pop   3.Display       4.Exit
3
40 30 20 10
1.Push  2.Pop   3.Display       4.Exit
1
100
1.Push  2.Pop   3.Display       4.Exit
3
100 40 30 20 10
1.Push  2.Pop   3.Display       4.Exit
4

--------------------------------
*/