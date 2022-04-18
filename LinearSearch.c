#include<stdio.h>
int elementsearch(int n,int k)
{
	if(n==k)
	{
		return 1;
	}
	return 0;
}
int linearsearch(int *arr,int n,int k)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==k)
		{
			c++;
		}
	}
	return c;
}
int main()
{
	int n;
	printf("Enter: ");
	scanf("%d",&n);
	int i,arr[n],k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	if(linearsearch(arr,n,k))
	{
		printf("Element found\n");
		printf("Element found %d times\nElements found at index:\n",linearsearch(arr,n,k));
		for(i=0;i<n;i++)
		{
			if(elementsearch(arr[i],k))
			{
				printf("%d ",i);
			}
		}
	}
	else
	{
		printf("Element not found");
	}
}