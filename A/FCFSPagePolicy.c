#include<stdio.h>
int frames[100];
int string[100];
int front=-1,rear=-1;
int pagefaults=0,pagehits=0;
int printArray(int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",frames[i]);
	}
	printf("\n");
}
void enq(int val,int f,int n)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
	}
	else
	{
		rear=(rear+1)%f;
	}
	frames[rear]=val;
	pagefaults+=1;
	printArray(f);
}
int pagehit(int val,int f,int n)
{
	int i;
	for(i=0;i<f;i++)
	{
		if(val==frames[i])
		{
			pagehits+=1;
			return 1;
		}
	}
	return -1;
}
int main()
{
	int n,f;
	printf("Enter Number of Frames: ");
	scanf("%d",&f);
	printf("Enter Length of Page Reference String: ");
	scanf("%d",&n);
	int i;
	printf("Enter Page Reference String: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&string[i]);
	}
	for(i=0;i<f;i++)
	{
		frames[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		if(pagehit(string[i],f,n)==-1)
		{
			enq(string[i],f,n);
		}
	}
	printf("No. of PageFaults: %d\n",pagefaults);
	printf("No. of PageHits: %d\n",pagehits);
	printf("Page Fault Ratio : %f\n",(float)pagefaults/(float)n);
}
