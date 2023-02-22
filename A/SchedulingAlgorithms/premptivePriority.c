#include<stdio.h>
#include<limits.h>
int n;
int ct[100]={0};
int pno[100];
int gs[1000]={0};
int p[1000]={0};
int temp[100]={0};
int prior[100]={0};
int k=0; 
void scanArray(int *at,int *bt,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		pno[i]=i+1;
		scanf("%d%d%d",&prior[i],&at[i],&bt[i]);
	}
}
int printArray(int at[],int bt[],int ct[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",prior[i],pno[i],at[i],bt[i],ct[i]);
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
				swap(&prior[j],&prior[j+1]);
			}
		}
	}
}
int isempty(int temp[],int n)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(temp[i]!=0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void findCT(int at[],int bt[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		temp[i]=bt[i];
	}
	
	int prev=0;
	while(isempty(temp,n))
	{
		int j,min=INT_MAX,m,flag=0,r;
		int priority=INT_MAX;
		for(j=0;j<n;j++)
		{
			
			if(at[j]<=prev)
			{
				if(prior[j]<priority && temp[j]!=0) 
				{
					priority=prior[j];
					m=j;
					flag=1;
				}
			}
		}
		gs[k]=prev;
		if(flag==0)
		{
			p[k]=-1;
			prev=prev+1;
		}
		else
		{
			p[k]=pno[m];
			temp[m]=temp[m]-1;
			prev=prev+1;
			if(temp[m]==0)
			{
				ct[m]=prev;
			}
		}
		k+=1;
	}
	gs[k]=prev;
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
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],prior[i],at[i],bt[i],ct[i],tat,tat-bt[i]);
	}
	printf("\n");
	printf("\nAverage Turn Around Time: %.3f",(float)sumtat/(float)n);
	printf("\nAverage Wait Time : %.3f",(float)sumwt/(float)n);
	
}
void printGun()
{
	printf("\n");
	int i;
	printf("\n");
	for(i=0;i<k;i++)
	{
		if(p[i]!=-1)
		{
			printf("%d->%d:P%d\n",gs[i],gs[i+1],p[i]);
		}
		else
		{
			printf("%d->%d:IDLE\n",gs[i],gs[i+1]);
		}
	}
}

int main()
{
	printf("Enter Size of array: ");
	scanf("%d",&n);
	int at[n],bt[n];
	printf("\nEnter Priority and Arrival and Brust Time\n");
	scanArray(at,bt,n);
	printf("\nP.NO\tP\tAT\tBT\n");
	printArray(at,bt,ct,n);
	sort(at,bt,n);
    printf("\nP.NO\tP\tAT\tBT\n");
	printArray(at,bt,ct,n);
	findCT(at,bt,n);
	printf("\nP.No\tP\tAT\tBT\tCT\tTAT\tWT\n");
	printfArray(at,bt,ct,n);
	printGun();
}
/*
2 0 4
4 1 2
6 2 3
1 3 5
8 4 1
3 5 4
2 11 6
*/
