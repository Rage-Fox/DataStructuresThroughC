#include<stdio.h>
#include<stdlib.h>
struct node
{
	int row;
	int col;
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int r,int c,int val)
{
	node *nn,*temp;
	nn=(node *)malloc(sizeof(node));
	nn->row=r;
	nn->col=c;
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
	}
}
void display()
{
	node *temp=head;
	if(head==NULL)
	{
		printf("No nodes to display\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d %d %d %d %d\n",temp,temp->row,temp->col,temp->data,temp->next);
			temp=temp->next;
		}
	}
}
int main()
{
	int r,c,arr[100][100],i,j;
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j]!=0)
			{
				insert(i,j,arr[i][j]);
			}
		}
	}
	display();
}