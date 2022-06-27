#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
};
typedef struct Node node;
node *root=NULL,*adrs[100];
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
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void create_tree(int *arr,int n)
{
	int i,val=arr[0];
	node *nn=(node *)malloc(sizeof(node));
	node *nn1,*nn2;
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	adrs[0]=nn;
	root=nn;
	for(i=0;2*i+1<n;i++)
	{
		nn1=(node *)malloc(sizeof(node));//creating left node
		nn1->data=arr[2*i+1];//left child
		nn1->left=NULL;
		nn1->right=NULL;
		nn2=(node *)malloc(sizeof(node));//creating right node
		nn2->data=arr[2*i+2];//right child
		nn2->left=NULL;
		nn2->right=NULL;
		adrs[2*i+1]=nn1;//placing address in adrs array
		adrs[2*i+2]=nn2;
		adrs[i]->left=nn1;//connecting child to parent node
		adrs[i]->right=nn2;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	create_tree(arr,n);
	printf("Inorder Travesal: ");
	inorder(root);
	printf("\nPostorder Traversal: ");
	postorder(root);
	printf("\nPreorder Traversal: ");
	preorder(root);
}
/*
	level 1				(1000) 10 (2000)
				  (1000) 				  (2000)
	level 2			20  					30
	level 3		40		50  			60  	70
Binary Tree contains two child nodes and is a non-linear and non-sequential data structure
each node has left child address, data, right child address
Leaf node is a node which doesn't have any child
Any operations to the binary tree can be done from the Root Node itself
for a parent node i, 2*i+1 and 2*i+2 are two child nodes
Travelsal Techniques to view data of a binary tree:
1) Inorder Traversal-> left,parent,right-> 40 20 50 10 60 30 70
2) Postorder Traversal-> left,right,parent-> 40 50 20 60 70 30 10
3) Preorder Traversal-> parent,left,right-> 10 20 40 50 30 60 70
4) Levelorder Traversal-> 10 20 30 40 50 60 70
*/