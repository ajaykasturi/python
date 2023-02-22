#include<stdio.h>
#include<math.h>
int main()
{
	int n,a[100],i,head,thm=0;
	printf("Enter number of requests:");
	scanf("%d",&n);
	printf("Enter request sequence:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter initial head position:");
	scanf("%d",&head);
	for(i=0;i<n;i++)
	{
		printf("%d-->%d\n",head,a[i]);
		thm=thm+fabs(head-a[i]);
		head=a[i];
	}
	printf("\nTotal number of head moments: %d",thm);
}
