#include<stdio.h>
int *insertsort(int *arr,int n)
{
	int i,temp,j;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	return arr;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i,*array;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	array=insertsort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
}