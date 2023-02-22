#include<stdio.h>
#include<stdlib.h>
int pno[100]={0};
int alloc[100][100];
int max[100][100];
int need[100][100];
int avail[100];
int finish[100];
int find(int n,int m)
{
	int i,j,flag=-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(finish[i]!=0)
			{
				break;
			}
			else if(need[i][j]<=avail[j])
			{
				flag=i;
			}
			else
			{
				flag=-1;
				break;
			}
		}
		if(flag!=-1)
		{
			return flag;
		}
	}
	return -1;
}
void add(int index,int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(i==index)
		{
			for(j=0;j<m;j++)
			{
				avail[j]=avail[j]+alloc[index][j];
			}
			break;
		}
	}
}
void printArray(int arr[],int m)
{
	int i;
	printf("\n");
	for(i=0;i<m;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int isTrue(int n)
{
	int i,f=1;
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
		{
			f=0;
			return i;
		}
	}
	if(f==1)
	{
		return -1;
	}
	
}
void safetyAlgo(int n,int m)
{
	int i=0;
	while(isTrue(n)!=-1)
	{
		int k=find(n,m);
		if(k!=-1)
		{
			add(k,n,m);
			printf("\nProcess-%d\n",k);
			printArray(avail,m);
			finish[k]=1;
		}
		else if(k==-1)
		{
			printf("We get DeadLock");
			break;
		}
	}
}

void storeMatrix(int arr[][100],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}
void calcNeed(int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
}
void printMatrix(int arr[][100],int n,int m)
{
	int i,j;
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int n,m;
	printf("Enter Number of Processes: ");
	scanf("%d",&n);
	printf("Enter Number of Resources: ");
	scanf("%d",&m);
	//making pno array to store processes repective numbers
	int k;
	for(k=0;k<n;k++)
	{
		pno[k]=k;
		finish[k]=0;
	}
	//storing allocation & max values
	printf("\nEnter Allocation Matrix\n");
	storeMatrix(alloc,n,m);
	printf("\nEnter Maximum Matrix\n");
	storeMatrix(max,n,m);
	
	calcNeed(n,m);
	printf("\nNeed Matrix");
	printMatrix(need,n,m);
	
	int i;
	printf("\nEnter Available array\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	safetyAlgo(n,m);
}
/*
Enter Number of Processes: 5
Enter Number of Resources: 3

Enter Allocation Matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Need Matrix
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1


Enter Available array
3 3 2

question check safe or unsafe

available=[0,0,x,1,1]
Enter Allocation Matrix n=3,m=5
1 0 2 1 1
2 0 1 1 0
1 1 0 1 1
1 1 1 1 0
1 1 2 1 3
2 2 2 1 0
2 1 3 1 1
1 1 2 2 0
*/
