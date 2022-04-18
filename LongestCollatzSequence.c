#include<stdio.h>
int main()
{
	long long int n,num,i,c,max=0;
	printf("Longest Collatz Sequence Number is ");
	for(i=2;i<=1000000;i++)
	{
		n=i;
		c=0;
		while(n>1)
		{
			if(n%2==0)
			{
				n=n/2;
				c++;
			}
			else if(!(n%2==0))
			{
				n=3*n+1;
				c++;
			}
		} //while loop ends
		if(c>max)
		{
			max=c;
			num=i;
		}
	}
	printf("%lld with %lld steps",num,max);
}
