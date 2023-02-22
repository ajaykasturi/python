#include<stdio.h>
#include<stdlib.h>
//variable partitioning WorstFit()
int n;
int b;
int process[100];
int block[100];
int newblock[100];
int unvisited[100];
int internalfragmentation=0;
int externalfragmentation=0;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort()
{
	int i,j;
	for(i=0;i<b;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(block[j]<block[j+1])
			{
				swap(&block[j],&block[j+1]);
				swap(&newblock[j],&newblock[j+1]);
			}
		}
	}
}
void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void bestFit(){
	int i,j;
	int flag;
	int k=0;
	for(i=0;i<n;i++)
	{
		flag=0;
		sort();
		for(j=0;j<b;j++)
		{
			if(process[i]<=block[j])
			{
				flag=1;
				printf("%d (p%d)->%d block(remaining->%d)\n",process[i],i+1,newblock[j],block[j]-process[i]);
				block[j]=block[j]-process[i];
				break;
			}
		}
		if(flag==0)
		{
			unvisited[k]=i;
			k++;
		}
	}
	int value=0;
	for(i=0;i<b;i++)
	{
		if(block[i]!=newblock[i])
		{
			internalfragmentation+=block[i];
		}
		if(block[i]==newblock[i])
		{
			value+=block[i];
		}
	}
	for(i=0;i<k;i++)
	{
		if(process[unvisited[i]]<=value)
		{
			externalfragmentation=value;
		}
	}
}
int main()
{
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter number of blocks: ");
	scanf("%d",&b);
	printf("\nEnter Memory for each process\n");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&process[i]);
		unvisited[i]=0;
	}
	printf("\nEnter size of each block\n");
	for(i=0;i<b;i++)
	{
		scanf("%d",&block[i]);
		newblock[i]=block[i];
	}
	sort();
	//printArray(newblock,b);
	//printArray(block,b);
	bestFit();
	printf("\nInternalFragmentation: %d",internalfragmentation);
	printf("\nExternalFragmentation: %d",externalfragmentation);
}
/*
212
417
112
426

100
500
200
300
600
*/
