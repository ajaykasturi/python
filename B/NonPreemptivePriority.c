#include<stdio.h>
#include<stdlib.h>
int at[100];
int bt[100];
int tat[100];
int ct[100];
int ctt[100];
int visit[100];
int pno[100];
int wt[100];
int pt[100];
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int p,int q)
{
	int i,j;
	for(i=p;i<q-1;i++)
	{
		for(j=p;j<q-1-i;j++)
		{
			if(at[j]>at[j+1])
			{
				swap(&at[j],&at[j+1]);
				swap(&bt[j],&bt[j+1]);
				swap(&pt[j],&pt[j+1]);
				swap(&pno[j],&pno[j+1]);
			}
		}
	}
}
void sort1(int p,int q)
{
	int i,j;
	for(i=p;i<q-1;i++)
	{
		for(j=p;j<q-i;j++)
		{
			if(pt[j]>pt[j+1])
			{
				swap(&at[j],&at[j+1]);
				swap(&bt[j],&bt[j+1]);
				swap(&pt[j],&pt[j+1]);
				swap(&pno[j],&pno[j+1]);
			}
		}
	}
}
void sort2(int p,int q)
{
	int i,j;
	for(i=p;i<q-1;i++)
	{
		for(j=p;j<q-1-i;j++)
		{
			if(pt[j]>pt[j+1])
			{
				swap(&at[j],&at[j+1]);
				swap(&bt[j],&bt[j+1]);
				swap(&ctt[j],&ctt[j+1]);
				swap(&pno[j],&pno[j+1]);
			}
		}
	}
}
int findMin(int k,int l)
{
	int i,s;
	int min=INT_MAX;
	for(i=0;i<k;i++)
	{
		if(pt[i]<min && visit[i]!=1 && at[i]<=ct[l-1])
		{
			min=pt[i];
			s=i;
		}
	}
	return s;
}
int findMin1(int k)
{
	int i,s;
	int min=INT_MAX;
	for(i=0;i<k;i++)
	{
		if(at[i]<min && visit[i]!=1)
		{
			min=at[i];
			s=i;
		}
	}
	return s;
}
void findCt(int n)
{
	int i,s,d;
	if(ct[0]==at[0])
	{
		printf("\n%d : %d==>%d",pno[0],ct[0],bt[0]);
		ct[0]=ct[0]+bt[0];
		ctt[0]=ct[0];
		visit[0]=1;
	}
	else
	{
		printf("\nIDLE : %d==>%d",ct[0],at[0]);
		ct[0]=at[0];
		ct[0]=ct[0]+bt[0];
		ctt[0]=ct[0];
		printf("\n%d : %d==>%d",pno[0],at[0],ct[0]);
		visit[0]=1;
	}
	for(i=1;i<n;i++)
	{
		d=findMin1(n);
		if(at[d]<=ct[i-1])
		{
				s=findMin(n,i);
				ct[i]=ct[i-1]+bt[s];
				printf("\n%d : %d==>%d",pno[s],ct[i-1],ct[i]);
				ctt[s]=ct[i];
				visit[s]=1;
		}
		else
		{
			printf("\nIDLE : %d==>%d",ct[i-1],at[d]);
			ct[i]=at[d];
			ct[i]=ct[i]+bt[d];
			ctt[d]=ct[i];
			printf("\n%d : %d==>%d",pno[d],at[d],ct[i]);
			visit[d]=1;
		}
	}
}
void findTat(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=ctt[i]-at[i];
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
	int i,n;
	printf("Enter number of processes:");
	scanf("%d",&n);
	printf("Enter  priority & arrival & burst times:");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&pt[i],&at[i],&bt[i]);
		pno[i]=i+1;
	}
	sort(0,n);
	sort1(1,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d",pt[i],at[i],bt[i]);
		ct[i]=0;
		visit[i]=0;
		ctt[i]=0;
		printf("\n");
	}
	findCt(n);
	//sort2(0,n);
	findTat(n);
	findWt(n);
	for(i=0;i<n;i++)
	{
		printf("%d ",ct[i]);
	}
	printf("\n");
	printf("P.No\tPR\tAt\tBT\tCT\tTAT\tWT");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d",pno[i],pt[i],at[i],bt[i],ctt[i],tat[i],wt[i]);
		printf("\n");
	}
	printf("Average Turn Around Time = %f\n",findAvgT(n));
		printf("Average Waiting time = %f",findAvgW(n));
	
	
}
