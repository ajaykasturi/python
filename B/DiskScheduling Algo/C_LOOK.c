#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,a[100],i,j,head,thm=0,size,index,move;
	printf("Enter number of requests:");
	scanf("%d",&n);
	printf("Enter request sequence:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter initial head position:");
	scanf("%d",&head);
	printf("Enter size of disk:");
	scanf("%d",&size);
	printf("Enter movement of the head.(1-Larger value|0-Lower value):");
	scanf("%d",&move);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(head<a[i])
		{
			index=i;
			break;
		}
	}
	if(move==1)
	{
		for(i=index;i<n;i++)
		{
			thm=thm+fabs(a[i]-head);
			head=a[i];
		}
		//thm=thm+fabs(size-a[i-1]-1);
		//thm=thm+(size-1-0);
		//head=0;
		for(i=0;i<index;i++)
		{
			thm=thm+fabs(a[i]-head);
			head=a[i];
		}
	}
	else
	{
		for(i=index-1;i>=0;i--)
		{
			thm=thm+fabs(a[i]-head);
			head=a[i];
		}
		//thm=thm+fabs(0-a[i+1]);
	//	thm=thm+fabs(size-1-0);
	//	head=size-1;
		for(i=n-1;i>=index;i--)
		{
			thm=thm+fabs(a[i]-head);
			head=a[i];
		}
	}
	printf("Total head movements :%d",thm);
}
//9->Number of requests
//55 58 39 18 90 160 150 38 184 ->Request sequence
//100 ->Initial head position
//185 ->Disk Size
//1 ->Direction higher value:250
//0->Lower value:284
