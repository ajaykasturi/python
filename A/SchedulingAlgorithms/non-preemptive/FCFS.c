#include<stdio.h>
int ct[100]={0};
int pno[100];

int gs[100]={0};
int k=1;
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
		}
	}
}
void findCT(int at[],int bt[],int n)
{
	ct[0]=0;
	int i;
	if(at[0]==0)
	{
		ct[0]=bt[0];
	}
	else
	{
		ct[0]=at[0];
	}
	for(i=0;i<n;i++)
	{
		if(at[i]<=ct[i-1])
		{
			ct[i]=ct[i-1]+bt[i];
		}
		else
		{
			gs[k++]=at[i];
			ct[i]=at[i]+bt[i];
		}
		gs[k++]=ct[i];
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
	for(i=0;i<k;i++)
	{
		printf("%d\t",gs[i]);
	}
	printf("\n");
}
int check(int dt)
{
	int i;
	for(i=0;i<k;i++)
	{
		if(ct[i]==dt)
		{
			return ct[i];
			break;
		}
	}
	return -1;
}
void printIdle()
{
	int i;
	int p=0;
	for(i=1;i<k;i++)
	{
		if(gs[i]!=check(gs[i]))
		{
			printf("\n%d->%d : idle",gs[i-1],gs[i]);
		}
		else
		{
			printf("\n%d->%d:P%d",gs[i-1],gs[i],pno[p++]);
		}
	}
}
int main()
{
	printf("Enter Size of array: ");
	int n;
	scanf("%d",&n);
	int at[n],bt[n];
	printf("\nEnter Arrival AND Brust Time\n");
	scanArray(at,bt,n);
	printf("\nP.NO\tAT\tBT\n");
	printArray(at,bt,ct,n);
	sort(at,bt,n);
    printf("\nP.NO\tAT\tBT\tCT\n");
	printArray(at,bt,ct,n);
	findCT(at,bt,n);
	printf("\nP.No\tAT\tBT\tCT\tTAT\tWT\n");
	printfArray(at,bt,ct,n);
	int i;
	printGun();
	printIdle();
	
}
