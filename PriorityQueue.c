#include<stdio.h>
#include<stdlib.h>
int f=-1,r=-1,n,*queue,*priority;
void enqueue(int val,int p)
{
	int i,j;
	if(r==n-1)
	{
		printf("Queue Overflow\n");
	}
	else if(f==-1&&r==-1)
	{
		f=0;
		r=0;
		queue[r]=val;
		priority[r]=p;
	}
	else
	{
		j=r;
		while(p<priority[j] && j>=0)
		{
			priority[j+1]=priority[j];
			queue[j+1]=queue[j];
			j--;
		}
		priority[j+1]=p;
		queue[j+1]=val;
		r++;
	}
}
int dequeue()
{
	int val;
	if(f==-1&&r==-1)
	{
		return -1;
	}
	else if(f==r)
	{
		val=queue[f];
		queue[f]=0;
		priority[f]=0;
		f=-1;
		r=-1;
		return val;
	}
	else
	{
		val=queue[f];
		queue[f]=0;
		priority[f]=0;
		f++;
		return val;
	}
}
void display()
{
	int i;
	if(f==-1&&r==-1)
	{
		printf("Queue is Underflow\n");
	}
	else
	{
		for(i=f;i<=r;i++)
		{
			printf("%d %d\n",queue[i],priority[i]);
		}
	}
}
int main()
{
	int i,ch,val,p;
	scanf("%d",&n);
	queue=(int *)calloc(n,sizeof(int));
	priority=(int *)calloc(n,sizeof(int));
	while(1)
	{
		printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			scanf("%d",&p);
			enqueue(val,p);
		}
		else if(ch==2)
		{
			val=dequeue();
			if(val==-1)
			{
				printf("Queue is Underflow\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else
		{
			break;
		}
	}
}
//queueing based on priority
/*
10 50 20 30 40
1  1  2  2  3
*/