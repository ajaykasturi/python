#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int finish[100];
void findSafeSequence(int allocation[][100],int max[][100],int need[][100],int work[],int m,int n,int safe[])
{
	int i,j,k=0,l;
	for(i=0;i<m;i++)
	{
		int flag=0;
		if(finish[i]==0)
		{
			for(j=0;j<n;j++)
			{
				if(need[i][j]>work[j])	
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				finish[i]=1;
				safe[k++]=i;
				for(l=0;i<n;l++)
				{
					work[l]+=allocation[i][l];
				}
				i=-1;
			}
		}
	}
}
int main()
{
	int n,m,i,j;
	printf("Enter number of processes:");
	scanf("%d",&m);
	printf("Enter numnber of resources:");
	scanf("%d",&n);
	int available[n],work[n],allocation[m][n],max[m][n],need[m][n],safe[m];
	printf("Enter allocation matrix:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter max matrix:");
	for(i=0;i<m;i++)
	{
		finish[i]=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter available matrix:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&available[i]);
		work[i]=available[i];
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			need[i][j]=(max[i][j]-allocation[i][j]);
		}
	}
	printf("Need matrix:\n");
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	findSafeSequence(allocation,max,need,work,m,n,safe);
	int flag=0,count=0;
	for(i=0;i<m;i++)
	{
//		if(finish[i]==0)
//		{
//			printf("The system is in deadlock!!!");
//			flag=1;
//			break;
//		}
		printf("%d",finish[i]);
	}
	if(flag==0)
	{
		printf("System is in safe state!!!.\nSafe sequence is:");
		for(i=0;i<m;i++)
		{
			printf("P%d ",safe[i]);
		}
	}
}
