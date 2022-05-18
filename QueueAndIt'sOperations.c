#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f=-1,r=-1,n,*queue;
void enqueue(int val)
{
	if(r==n-1)
	{
		printf("Overflow\n");
	}
	else if(f==-1&&r==-1)
	{
		queue[++r]=val;
		f=0;//if queue is empty making both front and rear to index "0"
	}
	else
	{
		queue[++r]=val;
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
		f++;
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
		for(i=f;i<=r;i++)
		{
			printf("%d ",queue[i]);
		}
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
/*
fifo and lilo--> first in first out and last in last out
deletion and insertion--> dequeue and enqueue
2 way open
rear(insertion) and front(deletion)--> -1 and -1(initially)
underflow and overflow--> isempty and isfull
===============
f			 r
10|20|30|40|50
===============
queue will be full when (f==0&&r==size-1)||(f==r+1)
both f and r at same position, it indicates single element in the queue. if we apply deque(), then we have to make f and r at -1
Drawback: whenever we delete the element using deque(), then size decreases
this will be overcome using various types of queues like circular queue, etc....
*/