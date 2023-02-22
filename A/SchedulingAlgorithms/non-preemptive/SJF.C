#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int n;
int ct[100]={0};
int pno[100];
int visited[100]={0};
int gs[100]={0};
int g=1;
void scanArray(int *at,int *bt,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		pno[i]=i+1;
		scanf("%d %d",&at[i],&bt[i]);
	}
}

int printArray(int at[],int bt[],int ct[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",pno[i],at[i],bt[i],ct[i]);
	}
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int at[],int bt[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(at[j]>at[j+1])
			{
				swap(&at[j],&at[j+1]);	
				swap(&bt[j],&bt[j+1]);
				swap(&pno[j],&pno[j+1]);
			}
			else if(at[j]==at[j+1])
			{
				if(bt[j]>bt[j+1])
				{
					swap(&at[j],&at[j+1]);	
					swap(&bt[j],&bt[j+1]);
					swap(&pno[j],&pno[j+1]);
				}
			}
		}
	}
}
int findminbt(int at[],int bt[],int n,int temp)
{
	int i;
	int min=INT_MAX;
	int index=0;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(at[i]<=temp && visited[i]==0)
		{
			if(min>bt[i])
			{
				min=bt[i];
				index=i;
				flag=1;
			}
		}
	}
	if(flag==1)
	{
		return index;
	}
}
void findCT(int at[],int bt[],int n)
{
	ct[0]=0;
	int i;
	ct[0]=at[0];
	if(ct[0]!=0)
	{
		gs[g++]=ct[0];
	}
	int temp=ct[0];
	int k;
	for(i=0;i<n;i++)
	{
		if(at[i]<=temp)
		{
			k=findminbt(at,bt,n,temp);
			visited[k]=1;
			ct[k]=temp+bt[k];
			temp=ct[k];
			gs[g++]=temp;
		}
		else
		{
			temp=at[i];
			gs[g++]=temp;
			i=i-1;
		}
	}
}
void printfArray(int at[],int bt[],int ct[],int n)
{
	int i;
	int sumtat=0;
	int sumwt=0;
	for(i=0;i<n;i++)
	{
		int tat=ct[i]-at[i];
		sumtat+=tat;
		sumwt+=tat-bt[i];
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],at[i],bt[i],ct[i],tat,tat-bt[i]);
	}
	printf("\n");
	printf("\nAverage Turn Around Time: %.3f",(float)sumtat/(float)n);
	printf("\nAverage Wait Time : %.3f",(float)sumwt/(float)n);
	
}
void printGun()
{
	printf("\n");
	int i;
	for(i=0;i<g;i++)
	{
		printf("%d\t",gs[i]);
	}
	printf("\n");
}
int check(int dt)
{
	int i;
	for(i=0;i<g;i++)
	{
		if(ct[i]==dt)
		{
			return ct[i];
			break;
		}
	}
	return -1;
}
int processor(int val)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(val==ct[i])
		{
			return pno[i];
			break;
		}
	}
	return -1;
}
void printIdle()
{
	int i;
	int p=0;
	for(i=1;i<g;i++)
	{
		if(gs[i]!=check(gs[i]))
		{
			printf("\n%d->%d : idle",gs[i-1],gs[i]);
		}
		else
		{
			printf("\n%d->%d:P%d",gs[i-1],gs[i],processor(gs[i]));
		}
	}
}
int main()
{
	printf("Enter Size of array: ");
	scanf("%d",&n);
	int at[n],bt[n];
	printf("\nEnter Arrival AND Brust Time\n");
	scanArray(at,bt,n);
	printf("\nP.NO\tAT\tBT\n");
	printArray(at,bt,ct,n);
	sort(at,bt,n);
    printf("\nP.NO\tAT\tBT\n");
	printArray(at,bt,ct,n);
	findCT(at,bt,n);
	printf("\nP.No\tAT\tBT\tCT\tTAT\tWT\n");
	printfArray(at,bt,ct,n);
	int i;
	printGun();
	printIdle();
	
}
/*
4 2
10 1
15 2
20 3
28 8
4 3
*/
