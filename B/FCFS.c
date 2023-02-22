#include<stdio.h>
int p[100];
int tat[100];
int ct[100];
int at[100];
int bt[100];
int wt[100];
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(at[j+1]<at[j])
			{
				swap(&at[j],&at[j+1]);
				swap(&bt[j],&bt[j+1]);
				swap(&p[j],&p[j+1]);
			}
		}
	}
}
void findCt(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(ct[i]==at[i])
		{
			printf("\n%d : %d==>%d",p[i]+1,ct[0],bt[i]);
			ct[i]=ct[i]+bt[i];
		}
	/*	if(ct[i]!=at[i])
		{
			ct[i]=at[i];
			ct[i]=ct[i]+bt[i];
		}*/
		else
		{
			if(at[i]<=ct[i-1])
			{
				ct[i]=ct[i-1]+bt[i];
				printf("\n%d : %d==>%d",p[i]+1,ct[i-1],ct[i]);
			}
			else
			{
				printf("\nIDLE: %d==>%d",ct[i-1],at[i]);
				ct[i]=at[i];
			    ct[i]=ct[i]+bt[i];
			    printf("\n%d : %d==>%d",p[i]+1,at[i],ct[i]);
			}
		}
	}
}
void findTat(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
}
void findWt(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
}
float findAvgT(int n)
{
	float sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		sum=sum+tat[i];
	}
	return sum/n;
}
float findAvgW(int n)
{
	float sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		sum=sum+wt[i];
	}
	return sum/n;
}
int main()
{
	int n,i;
	float avgT,avgW;
	printf("Enter number of processes:");
	scanf("%d",&n);
	printf("Enter arrival & burst times:");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&at[i],&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",at[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",bt[i]);
		ct[i]=0;
	}
	printf("\n");
	sort(n);
	/*for(i=0;i<n;i++)
	{
		printf("%d ",at[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",bt[i]);
		
	}
	printf("\n");
	ct[0]=0;*/
	findCt(n);
	printf("\n");
	findTat(n);
	findWt(n);
	avgT=findAvgT(n);
	avgW=findAvgW(n);
	printf("P.No\tAT\tBT\tCT\tTAT\tWT");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
		
	}
	printf("Average Turn Around Time = %f\n",avgT);
	printf("Average Waiting time = %f",avgW);
	
	
	
	
}
