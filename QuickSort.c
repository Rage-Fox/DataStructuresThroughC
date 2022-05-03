#include<stdio.h>
int fun(int *a,int lb,int ub)
{
	int pivot=a[lb],start=lb,end=ub,temp;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
	temp=a[lb];
	a[lb]=a[end];
	a[end]=temp;
	return end;
}
void quicksort(int *arr,int lb,int ub)
{
	int loc;
	if(lb<ub)
	{
		loc=fun(arr,lb,ub);
		quicksort(arr,lb,loc-1);
		quicksort(arr,loc+1,ub);
	}
}
int main()
{
	int i,n,arr[10000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}