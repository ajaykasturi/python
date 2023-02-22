#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int at[],int bt[],int pn[],int n,int btt[],int p[])
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				swap(&at[j],&at[j+1]);
				swap(&bt[j],&bt[j+1]); 
				swap(&pn[j],&pn[j+1]);
				swap(&btt[j],&btt[j+1]);
				swap(&p[j],&p[j+1]);
			}
		}
	}
}
int findMinJob(int at[],int bt[],int n,int count,int p[])
{
	int i,res=-1,min=INT_MAX;
	for(i=0;i<n;i++)
	{
		if(at[i]<=count && bt[i]>0 && p[i]<min)
		{
			min=p[i];
			res=i;
		}
	}
	return res;
}
void findCt(int at[],int bt[],int ct[],int n,int ctt[],int c,int pn[],int p[])
{
	int i,count=0;
	/*if(count==at[0])
	{
		printf("\nP%d==> %d-%d",pn[0],count,count+1);
		bt[0]=bt[0]-1;
		c--;
		count++;
		if(bt[0]==0)
		{
			ctt[0]=count;
		}
	}
	else
	{
		//printf("\nIdle==> %d-%d",count,count+1);
		count=at[0]+1;
		printf("\nP%d==> %d-%d",pn[0],count,count+1);
		bt[0]=bt[0]-1;
		c--;
		count++;
		if(bt[0]==0)
		{
			ctt[0]=count;
		}
	}*/
	while(c!=0)
	{
		int min=findMinJob(at,bt,n,count,p);
		if(min!=-1)
		{
			printf("\nP%d==> %d-%d",pn[min],count,count+1);
			bt[min]=bt[min]-1;
			c--;
			count++;
			if(bt[min]==0)
			{
				ctt[min]=count;
			}
		}
		else
		{
				printf("\nIdle==> %d-%d",count,count+1);
				count++;
		}
	}
}
void findTat(int ctt[],int at[],int tat[],int n,float* avgTat)
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=ctt[i]-at[i];
		*avgTat=*avgTat+tat[i];
	}
}
void findWt(int tat[],int btt[],int wt[],int n,float* avgWt)
{
	int i;
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-btt[i];
		*avgWt=*avgWt+wt[i];
	}
}
int main()
{
	int n,i,c=0;
	printf("Enter number of processes:");
	scanf("%d",&n);
	int at[n],bt[n],p[n],pn[n],ct[n],ctt[n],tat[n],wt[n],btt[n];
	float avgTat=0,avgWt=0,t,w;
	printf("Enter priority,arrival & burst times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		btt[i]=bt[i];
		c=c+bt[i];
		pn[i]=i+1;
	}
	sort(at,bt,pn,n,btt,p);
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",pn[i],p[i],at[i],bt[i]);
	}
	findCt(at,bt,ct,n,ctt,c,pn,p);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",ctt[i]);
	}
	findTat(ctt,at,tat,n,&avgTat);
	findWt(tat,btt,wt,n,&avgWt);
	printf("\nPNO\tP\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pn[i],p[i],at[i],btt[i],ctt[i],tat[i],wt[i]);
	}
	printf("\nAverage Turn Around Time : %f",avgTat/n);
	printf("\nAverage Waiting Time : %f",	avgWt/n);
}
