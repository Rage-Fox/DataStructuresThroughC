//two way partitioning method
#include<stdio.h>
void merge(int *arr,int l,int m,int h)
{
	int i,a[100],b[100],n1=m-l+1,n2=h-m,k=l,newarr[1000],j;
	for(i=0;i<n1;i++)
	{
		a[i]=arr[k++];
	}
	k=m+1;
	for(i=0;i<n2;i++)
	{
		b[i]=arr[k++];
	}
	i=j=k=0;
	while(i<n1&&j<n2)
	{
        if(a[i]<=b[j])
		{
            newarr[k]=a[i++];
        }
		else
		{
            newarr[k]=b[j++];
        }
        k++;
    }
    while(i<n1)
	{
        newarr[k++]=a[i++];
    }
    while(j<n2)
	{
        newarr[k++]=b[j++];
    }
    k=l;
    for(i=0;i<n1+n2;i++)
    {
    	arr[k++]=newarr[i];
	}
}
void mergesort(int *arr,int n)
{
	int l,h,m,p,i;//l=0,h=n-1,m=(l+h)/2
	for(p=2;p<=n;p=p*2)//part by part sorting
	{
		for(i=0;i<=n-p;i=i+p)
		{
			l=i;
			h=l+p-1;
			m=(l+h)/2;
			merge(arr,l,m,h);
		}
	}
	if((p/2)<n)
	{
		if(n%2)//for odd
		{
			merge(arr,0,(p/2)-1,n-2);
			merge(arr,0,n-2,n-1);
		}
		else
		{
			merge(arr,0,(p/2)-1,n-1);
		}
	}
}
/*//recursion method
void merge_sort(int *arr,int l,int h)
{
	int m;
	if (l<h)
	{
		m=(l+h)/2;
		merge_sort(arr,l,m);
		merge_sort(arr,m+1,h);
		merge(arr,l,m,h);	
	}
}
*/
int main()
{
	int n;
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
//5 7 10 15 2 6 8 100
//67 85 2 1 4 3 7 8