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
void insert_at_pos(int pos,int val)
{
	node *temp,*nn,*temp1;
	int nc=1,i;//to count number of nodes
	//as temp is at head position, the default count is 1
	nn=(node *)malloc(sizeof(node));
	nn->prev=NULL;
	nn->data=val;
	nn->next=NULL;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		nc++;
	}
	if(head==NULL)
	{
		head=nn;
	}
	else if(pos==1)
	{
		insert_at_head(val);
	}
	else if(nc<=pos)
	{
		insert_at_end(val);
	}
	else//nc>pos
	{
		temp=head;
		for(i=1;i<pos-1;i++)//stop at position-1
		{
			temp=temp->next;
		}
		temp1=temp->next;//moving temp1 to position's node
		temp->next=nn;
		nn->prev=temp;
		temp1->prev=nn;
		nn->next=temp1;
	}
}
int delete_at_pos(int pos)
{
	int val,nc=0,i;
	node *temp,*temp1;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		nc++;
	}
	if(head==NULL||pos>nc)
	{
		return -1;
	}	
	if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	if(pos==1)
	{
		return delete_at_head();
	}
	if(pos==nc)
	{
		return delete_at_end();
	}
  //pos<nc
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=temp1->next;
	temp->next->prev=temp;
	temp1->next=NULL;
	temp1->prev=NULL;
	return temp1->data;
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit\n");
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
		else if(ch==6)
		{
			scanf("%d%d",&pos,&val);
			insert_at_pos(pos,val);
		}
		else if(ch==7)
		{
			scanf("%d",&pos);
			val=delete_at_pos(pos);
			if(val==-1)
			{
				printf("NO NODES TO DELETE AT THAT POSITION\n");
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
