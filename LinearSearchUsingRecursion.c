#include<stdio.h>
int linearsearch(int *arr,int n,int k)
{
	int static i=0;//static because the new i value will be maintained throughout the program
	if(i==n)//if last position that means element is not found at all
	{
		return 0;
	}
	if(arr[i]==k)
	{
		return 1;
	}
	i++;
	return linearsearch(arr,n,k);
}
int main()
{
	int n;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int i,arr[n],k;
	printf("Enter the array elments:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element that you want to search in that array: ");
	scanf("%d",&k);
	if(linearsearch(arr,n,k))
	{
		printf("Element found");
	}
	else
	{
		printf("Element not found");
	}
}