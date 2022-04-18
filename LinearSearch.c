#include<stdio.h>
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
	scanf("%d",&n);
	int i,arr[n],k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	printf("%d",linearsearch(arr,n,k));
}