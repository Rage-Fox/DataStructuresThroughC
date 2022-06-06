#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert_at_end(int val)
{
	node *nn,*temp;
	nn=(node *)malloc(sizeof(node));
	nn->prev=NULL;
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
		nn->prev=temp;
	}
}
int delete_at_end()
{
	int val;
	node *temp,*temp1;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=temp->next;//taking temp1 to last node
		temp->next=NULL;
		temp1->prev=NULL;
		return temp1->data;
	}
}
void display()
{
	node *temp=head;
	if(temp==NULL)
	{
		printf("NO NODES\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("(%d) %d %d %d\n",temp,temp->prev,temp->data,temp->next);//temp is present node's address
			temp=temp->next;
		}
	}
}
void insert_at_head(int val)
{
	node *nn;
	nn=(node *)malloc(sizeof(node));
	nn->prev=NULL;
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		nn->next=head;
		head->prev=nn;
		head=nn;
	}
}
int delete_at_head()
{
	int val;
	node *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head->next;
		val=head->data;
		temp->prev=NULL;
		head->next=NULL;
		head=temp;
		return val;
	}
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			insert_at_end(val);
		}
		else if(ch==2)
		{
			val=delete_at_end();
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
		else if(ch==4)
		{
			scanf("%d",&val);
			insert_at_head(val);
		}
		else if(ch==5)
		{
			val=delete_at_head();
			if(val==-1)
			{
				printf("NO NODES TO DELETE\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else
		{
			break;
		}
	}
}
/*
----------------------------------------------
|previous node address|data|next node address|
----------------------------------------------
insert and delete at head/end/position
*/
