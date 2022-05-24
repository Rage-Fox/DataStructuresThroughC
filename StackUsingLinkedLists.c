#include<stdio.h>
#include<stdlib.h>
//creation of node
struct node
{
	int data;
	struct node *next;//self-referential structure
};
typedef struct node node;//user defined datatype
//head contains address of first node
//head value is always at NULL initially i.e; list has no nodes
//last node address value is always NULL
//collection of nodes is called linked lists
node *head=NULL;
//write functions after creating structure and head
void insert(int val)
{
	node *nn,*temp;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;//giving first node address to head
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
}
int deletee()
{
	int val;
	node *temp;
	if(head==NULL)//no nodes at all
	{
		return -1;
	}
	else if(head->next==NULL)//only single element is there
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		while(temp->next->next!=NULL)//last-1 is temp->next and next to that is null or not
		{
			temp=temp->next;
		}
		val=temp->next->data;//copy the deleting data
		temp->next=NULL;//make null after copying the value which you're about to delete
		return val;
	}
		
}
void display()
{
	node *temp;
	if(head==NULL)
	{
		printf("NO NODES\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d %d %d\n",temp,temp->data,temp->next);
			temp=temp->next;
		}
	}
}
int main()
{
	/*node *nn=(node *)malloc(sizeof(node));
	nn->data=10;//indirection operator -> which catches address
	nn->next=NULL;
	printf("%d %d %d\n",nn,nn->data,nn->next);*/
	int ch,val;
	while(1)
	{
		printf("1)Insert\t2)Delete\t3)Display\t4)Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			insert(val);
		}
		else if(ch==2)
		{
			val=deletee();
			if(val==-1)
			{
				printf("NO NODES TO DELETE\n");
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
//linked list is a "linear data structure" in a continuous process and also it is a collection of nodes
//node: data|addressofnextnode
/*
insert(100)
create a nn(new node)
assign value and null to it
temp=head
if(temp==NULL):
	temp=nn
else:
	temp->next
	temp=temp->next
*/
/*
DISPLAYING DATA
temp=head
if(temp!=NULL):
	print temp->data
	temp=temp->next
else:
	stop displaying data
*/