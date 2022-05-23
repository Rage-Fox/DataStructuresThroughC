#include<stdio.h>
#include<stdlib.h>
int f=-1,r=-1,n,*queue;
void rear_enqueue(int val)
{
	if((f==0&&r==n-1)||f==r+1)
	{
		printf("Queue Overflow\n");
	}
	else if(f==-1&&r==-1)
	{
		f=0;
		r=0;
		queue[r]=val;
	}
	else
	{
		r=(r+1)%n;
		queue[r]=val;
	}
}
void front_enqueue(int val)
{
	if((f==0&&r==n-1)||f==r+1)
	{
		printf("Queue Overflow\n");
	}
	else if(f==-1&&r==-1)
	{
		f=0;
		r=0;
		queue[f]=val;
	}
	else
	{
		if(f==0)
		{
			f=n-1;//circular queue way
		}
		else
		{
			f--;
		}
		queue[f]=val;
	}
}
int rear_dequeue()
{
	int val;
	if(f==-1&&r==-1)
	{
		return -1;
	}
	if(f==r)//single element
	{
		val=queue[r];
		f=-1;
		r=-1;
		return val;
	}
	val=queue[r];
	if(r==0)
	{
		r=n-1;
	}
	else
	{
		r--;
	}
	return val;
}
int front_dequeue()
{
	int val;
	if(f==-1&&r==-1)
	{
		return -1;
	}
	if(f==r)//single element
	{
		val=queue[f];
		f=-1;
		r=-1;
		return val;
	}
	val=queue[f];
	f=(f+1)%n;
	return val;
}
void display()
{
	int i;
	if(f==-1&&r==-1)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		for(i=f;i!=r;i=(i+1)%n)
		{
			printf("%d %d\n",i,queue[i]);
		}
		printf("%d %d\n",i,queue[i]);
	}
}
int main()
{
	int i,ch,val;
	scanf("%d",&n);
	queue=(int *)calloc(n,sizeof(int));
	while(1)
	{
		printf("1.Enqueue at Rear\t2.Dequeue at Rear\t3.Enqueue at Front\t4.Dequeue at Front\t5.Display\t6.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//enqueue at rear
			scanf("%d",&val);
			rear_enqueue(val);
		}
		else if(ch==2)
		{
			val=rear_dequeue();
			if(val==-1)
			{
				printf("Queue Underflow\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			//enqueue at front
			scanf("%d",&val);
			front_enqueue(val);
		}
		else if(ch==4)
		{
			val=front_dequeue();
			if(val==-1)
			{
				printf("Queue Underflow\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==5)
		{
			display();
		}
		else
		{
			break;
		}
	}
}
/*
properties are similar to circular queue
we can do both enque and deque at both front and rear
4 operations are there
1) enque at rear--> rear++
2) deque at rear--> rear--
3) enque at front--> front--
4) deque at front--> front++
*/