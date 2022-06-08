#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int coef;
	int pow;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head1=NULL,*head2=NULL,*head3=NULL;
void insert(int c,int p,NODE **head)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->coef=c;
	NN->pow=p;
	NN->next=NULL;
	if(*head==NULL)
	{
		*head=NN;
	}
	else
	{
		temp=*head;
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=NN;
	}
}
void display(NODE **head)
{
	NODE *temp;
	temp=*head;
	if(*head==NULL)
	{
		printf("NO Nodes");
	}
	else
	{
		while(temp)
		{
			if(temp->coef>=0)
			{
				printf("+%dx^%d",temp->coef,temp->pow);	
			}
			else
			{
				printf("%dx^%d",temp->coef,temp->pow);
			}
			temp=temp->next;
		}
	}
}
void add(NODE **head1,NODE **head2)
{
	int c,p;
	NODE *temp1,*temp2;
	temp1=*head1;
	temp2=*head2;
	while(temp1 && temp2)
	{
		if(temp1->pow==temp2->pow)
		{
			c=temp1->coef+temp2->coef;
			p=temp1->pow;
			insert(c,p,&head3);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->pow>temp2->pow)
		{
			c=temp1->coef;
			p=temp1->pow;
			insert(c,p,&head3);
			temp1=temp1->next;
		}
		else
		{
			c=temp2->coef;
			p=temp2->pow;
			insert(c,p,&head3);
			temp2=temp2->next;
		}
	}
	while(temp1)
	{
		c=temp1->coef;
		p=temp1->pow;
		insert(c,p,&head3);
		temp1=temp1->next;
	}
	while(temp2)
	{
		c=temp2->coef;
		p=temp2->pow;
		insert(c,p,&head3);
		temp2=temp2->next;
	}
}
void main()
{
	int ch=1,c,p;
	printf("1st Polynomial\n");
	while(ch)
	{
		printf("Enter coefficient and power: ");
		scanf("%d%d",&c,&p);
		insert(c,p,&head1);
		printf("1)Yes 2)No: ");
		scanf("%d",&ch);
		if(ch!=1)
		{
			break;
		}
	}
	ch=1;
	printf("2nd Polynomial\n");
	while(ch)
	{
		printf("Enter coefficient and power: ");
		scanf("%d%d",&c,&p);
		insert(c,p,&head2);
		printf("1)Yes 2)No: ");
		scanf("%d",&ch);
		if(ch!=1)
		{
			break;
		}
	}
	printf("1st Polynomial: ");
	display(&head1);
	printf("\n2nd Polynomial: ");
	display(&head2);
	add(&head1,&head2);
	printf("\nAddition of two polynomials is:\n");
	display(&head3);
}
//turning two polynomials into linked lists and adding them