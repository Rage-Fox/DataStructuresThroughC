#include<stdio.h>
void countsort(int *arr,int n,int pos)
{
	int count[10]={0},b[n],i;
	for(i=0;i<n;i++)
	{
		++count[(arr[i]/pos)%10];
	}
	for(i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		b[--count[(arr[i]/pos)%10]]=arr[i];
	}
	for(i=0;i<n;i++)
	{
		arr[i]=b[i];
	}
}
void radixsort(int *arr,int n)
{
	int max=-100,pos;
	for(pos=0;pos<n;pos++)
	{
		if(max<arr[pos])
		{
			max=arr[pos];
		}
	}
	for(pos=1;(max/pos)>0;pos*=10)
	{
		countsort(arr,n,pos);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	radixsort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}