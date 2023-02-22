#include<stdio.h>
#include<math.h>
int main()
{
	int n,a[100],i,j,head,thm=0,c=0;
	printf("Enter number of requests:");
	scanf("%d",&n);
	printf("Enter request sequence:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter initial head position:");
	scanf("%d",&head);
	int min,d,index;
	while(c!=n)
	{
		min=100000;
		for(j=0;j<n;j++)
		{
			d=fabs(a[j]-head);
			if(d<min)
			{
				min=d;
				index=j;
			}
		}
		thm=thm+min;
		head=a[index];
		a[index]=10000;
		c++;
	}
	printf("Total head movements:%d",thm);
}
//98 183 41 122 14 124 67 67 ->323
