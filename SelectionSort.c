#include<stdio.h>
int max(int *arr,int i)
{
	int j,maxx=0,k;
	for(j=i;j>=0;j--)
	{
		if(arr[j]>maxx)
		{
			maxx=arr[j];
			k=j;
		}
	}
	return k;
}
void selection_sort(int *arr,int n)
{
	int i,l,k;
	for(i=n-1;i>=0;i--)
	{
		l=max(arr,i);
		k=arr[l];
		arr[l]=arr[i];
		arr[i]=k;
	}
}
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
/*
10
85 20 66 33 54 35 22 11 9 67
*/