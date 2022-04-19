#include<stdio.h>
int binarysearch(int *arr,int e,int l,int r)
{
	int m;
	while(l<=r)
	{
		m=(l+r)/2;
		if(arr[m]==e)
		{
			return 1;
		}
		if(arr[m]<e)
		{
			l=m+1;
		}
		if(arr[m]>e)
		{
			r=m-1;
		}
	}
	return 0;
}
int main()
{
	int n,e,i,j,k,t;
	scanf("%d",&n);
	int l=0,r=n-1,arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	scanf("%d",&e);
	if(binarysearch(arr,e,l,r))
	{
		printf("Element found");
	}
	else
	{
		printf("Element not found");
	}
}