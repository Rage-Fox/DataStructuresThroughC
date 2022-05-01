#include<stdio.h>
#include<stdlib.h>
void bubblesort(int *arr,int n)
{
	int i,j,temp,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}
int *merge_sort(int *arr1,int *arr2,int n1,int n2)
{
	int i=0,j=0,k=0;
	static int *newarr;
	newarr=(int *)calloc((n1+n2),sizeof(int));
	while(i<n1&&j<n2)
	{
        if(arr1[i]<=arr2[j])
		{
            newarr[k]=arr1[i];
            i++;
        }
		else
		{
            newarr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
	{
        newarr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2)
	{
        newarr[k]=arr2[j];
        j++;
        k++;
    }
    return newarr;
}
int main()
{
	int n1,n2,*array;
	scanf("%d",&n1);
	int i,arr1[n1];
	for(i=0;i<n1;i++)
	{
		scanf("%d",&arr1[i]);
	}
	bubblesort(arr1,n1);//merge sort requires a sorted array so first we have to sort the input array
	scanf("%d",&n2);
	int arr2[n2];
	for(i=0;i<n2;i++)
	{
		scanf("%d",&arr2[i]);
	}
	bubblesort(arr2,n2);
	array=merge_sort(arr1,arr2,n1,n2);
	printf("Merged and sorted array elements are:\n");
	for(i=0;i<n1+n2;i++)
	{
		printf("%d ",array[i]);
	}
}
/*
5
5 7 11 15 25
7
1 2 6 8 10 110 200
*/