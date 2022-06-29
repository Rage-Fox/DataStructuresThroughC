#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
};
typedef struct Node node;
node *root=NULL;
int search(int key)
{
	if(root==NULL)
	{
		return 0;
	}
	node *temp=root;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			return 1;
		}
		else if(temp->data>key)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	return 0;
}
void insert(int val)
{
	node *nn=(node *)malloc(sizeof(node)),*temp=root,*temp1;
	//taking temp1 because temp becomes null at end of while loop and we're not trying to place node at NULL temp variable
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL)
	{
		root=nn;
	}
	else
	{
		while(temp!=NULL)
		{
			temp1=temp;
			if(temp->data==val)
			{
				return;//no need to insert as it is already there
			}
			else if(temp->data>val)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
		if(temp1->data>val)
		{
			temp1->left=nn;
		}
		else
		{
			temp1->right=nn;
		}
	}
}
void delete_case1(node *temp,node *temp1,int key)
{
	if(temp==root)//single root with no children condition
	{
		root=NULL;
		return;
	}
	if(temp1->left!=NULL && temp1->left->data==key)
	{
		temp1->left=NULL;
	}
	else
	{
		temp1->right=NULL;
	}
}
void delete_case2(node *temp,node *temp1,int key)
{
	if(temp1==NULL)//root node condition
	{
		if(temp->left!=NULL)
		{
			temp=temp->left;
			root=temp;
		}
		else
		{
			temp=temp->right;
			root=temp;
		}
		return;
	}
	if(temp->right!=NULL)
	{
		if(temp1->right->data==key)
		{
			temp1->right=temp->right;
		}
		else if(temp1->left->data==key)
		{
			temp1->left=temp->right;
		}
	}
	else
	{
		if(temp1->right!=NULL && temp1->right->data==key)
		{
			temp1->right=temp->left;
		}
		else if(temp1->left->data==key)
		{
			temp1->left=temp->left;
		}
	}
}
int deletee(int key)
{
	if(root==NULL)
	{
		return 0;
	}
	node *temp=root,*temp1=NULL,*t1,*t2=NULL;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			if(temp->left==NULL && temp->right==NULL)//case1->no child
			{
				delete_case1(temp,temp1,key);
			}
			else if(temp->left==NULL || temp->right==NULL)//case2->single child
			{
				delete_case2(temp,temp1,key);
			}
			else//case3->two children(swapping parent node with bottom leaf node and then making case 1or2 by removing leaf node)
			{
				t1=temp->right;//inorder successor will always be on right child of parent node
				while(t1->left!=NULL)//always move left to find inorder successor of parent node
				{
					t2=t1;
					t1=t1->left;
				}
				int val=t1->data;
				t1->data=temp->data;
				temp->data=val;
				if(t2==NULL)
				{
					t2=temp;
				}
				if(t1->left==NULL && t1->right==NULL)
				{
					delete_case1(t1,t2,key);
				}
				else
				{
					delete_case2(t1,t2,key);
				}
			}
			return 1;
		}
		else if(temp->data>key)
		{
			temp1=temp;
			temp=temp->left;
		}
		else
		{
			temp1=temp;
			temp=temp->right;
		}
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int main()
{
	int val,ch,key;
	while(1)
	{
		printf("1)Search\t2)Insert\t3)Delete\t4)Inorder\t5)Preorder\t6)Postorder\t7)Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&key);
			if(search(key))
			{
				printf("Element found\n");
			}
			else
			{
				printf("Element not found\n");
			}
		}
		else if(ch==2)
		{
			scanf("%d",&val);
			insert(val);
		}
		else if(ch==3)
		{
			scanf("%d",&key);
			if(deletee(key))
			{
				printf("%d is deleted\n",key);
			}
			else
			{
				printf("Element not found\n");
			}
		}
		else if(ch==4)
		{
			inorder(root);
			printf("\n");
		}
		else if(ch==5)
		{
			preorder(root);
			printf("\n");
		}
		else if(ch==6)
		{
			postorder(root);
			printf("\n");
		}
		else
		{
			break;
		}
	}
}
/*
Types of trees: Complete,Full,Perfect,Avial
Binary Search Tree has left child nodes less than root node value and rigt child nodes greater than root node value
50 40 80 30 45 70 90 35 48 75
*/