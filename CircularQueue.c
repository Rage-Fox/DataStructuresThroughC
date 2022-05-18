#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f=-1,r=-1,n,*queue;
void enqueue(int val)
{
	if((f==0&&r==n-1)||f==r+1)
	{
		printf("Overflow\n");
	}
	else
	{
		if(f==-1)
		{
			f=0;
		}
		r=(r+1)%n;
    	queue[r] =val;
	}
}
int dequeue()
{
	int val;
	if(f==-1&&r==-1)
	{
		return -1;//return front;
	}
	else if(f==r)
	{
		val=queue[f];
		f=-1;
		r=-1;
		return val;
	}
	else
	{
		val=queue[f];
		f=(f+1)%n;
		return val;
	}
}
void display()
{
	int i;
	if(f==-1&&r==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=f;i!=r;i=(i+1)%n)
		{
			printf("%d ",queue[i]);
		}
		printf("%d",queue[i]);
		printf("\n");
	}
}
int main()
{
	int i,ch,val;
	scanf("%d",&n);
	queue=(int *)calloc(n,sizeof(int));//allocating the memory of queue
	while(1)//infinite loop
	{
		printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//enqueue
			scanf("%d",&val);
			enqueue(val);
		}
		else if(ch==2)
		{
			//dequeue
			val=dequeue();//it works with return value
			if(val==-1)
			{
				printf("Underflow\n");
			}
			else
			{
				printf("%d\n",val);//displaying what element is deleted from queue
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