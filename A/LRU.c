#include<stdio.h>
int frames[100];
int string[100];

int pagefaults=0,pagehits=0;

void printArray(int n)
{
	printf("\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",frames[i]);
	}
	printf("\n");
}
int find(int f,int index)
{
	int dup[10];
	int i;
	for(i=0;i<f;i++)
	{
		dup[i]=frames[i];
	}
	int count=0,flag=0;
	for(i=index-1;i>=0;i--)
	{
		int j;
		for(j=0;j<f;j++)
		{
			if(string[i]==dup[j])
			{
				if(count==(f-1))
				{
					flag=1;
					break;
				}
				else
				{
					dup[j]=-1;count+=1;
				}
			}
		}
		if(count==(f-1))
			break;
	}
	for(i=0;i<f;i++)
	{
		if(dup[i]!=-1)
		{
			return i;
		}
	}
}
void enq(int val,int f,int n,int index)
{
	int i=find(f,index);
	frames[i]=val;
	printArray(f);
	pagefaults+=1;
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
	for(i=0;i<f;i++){
		frames[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		if(pagehit(string[i],f,n)==-1)
		{
			if(i<f)
			{
				frames[i]=string[i];
				printArray(f);
				pagefaults+=1;
			}
			else
			{
				enq(string[i],f,n,i);
			}
		}
	}
	printf("No. of PageFaults: %d\n",pagefaults);
	printf("No. of PageHits: %d\n",pagehits);
	printf("Page Fault Ratio : %f\n",(float)pagefaults/(float)n);
}
