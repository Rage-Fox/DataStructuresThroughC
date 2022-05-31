#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert_at_end(int val)
{
	node *nn,*temp;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=head;
	if(head==NULL)
	{
		head=nn;
		nn->next=head;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
}
int delete_at_end()
{
	int val;
	node *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==head)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		while(temp->next->next!=head)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next=head;
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
		printf("%d %d %d\n",temp,temp->data,temp->next);
		temp=temp->next;
		while(temp!=head)
		{
			printf("%d %d %d\n",temp,temp->data,temp->next);
			temp=temp->next;
		}
	}
}
void insert_at_head(int val)
{
	node *nn,*temp=head;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
		nn->next=head;
	}
	else
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		nn->next=head;
		head=nn;
		temp->next=head;
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
	else if(head->next==head)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		val=head->data;
		head=head->next;
		temp->next=head;
		return val;
	}
}
void insert_at_pos(int val,int pos)
{
	node *temp,*nn;
	int c=1,i;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
		c++;
	}
	if(head==NULL)
	{
		head=nn;
	}
	else if(pos==1)
	{
		insert_at_head(val);
	}
	else if(c<pos)
	{
		insert_at_end(val);
	}
	else//c>pos
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}
int delete_at_pos(int pos)
{
	node *temp=head;
	int c=1,val,i;
	if(head==NULL)
	{
		return -1;
	}
	else if(pos==1)
	{
		return delete_at_head();
	}
	while(temp->next!=head)
	{
		temp=temp->next;
		c++;
	}
	if(c<=pos)
	{
		return delete_at_end();
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next=temp->next->next;
		return val;
	}
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
			//insert at postion
			scanf("%d%d",&val,&pos);
			insert_at_pos(val,pos);
		}
		else if(ch==7)
		{
			//delete at position
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
//circular linked list program