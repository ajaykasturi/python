#include<stdio.h>
#include<limits.h>
int n;
int tq;
int ct[100]={0};
int pno[100];
int gs[1000]={0};
int p[1000]={0};
int temp[100]={0};
int q[1000]={0};
int front=-1,rear=-1;
int k=0; 
int ide=0;
void enq(int process)
{
	if(front==-1 && rear==-1)
	{
		front=0;
	}
	rear=rear+1;
	q[rear]=process;
}
int deq()
{
	int pro=q[front++];
	return pro;
}
void scanArray(int *at,int *bt,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		pno[i]=i+1;
		scanf("%d%d",&at[i],&bt[i]);
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
int ispossible(int prsr)
{
	int i;
	for(i=front;i<=rear;i++)
	{
		if(q[i]==prsr)
		{
			return 0;
		}
	}
	return 1;
}
void findCT(int at[],int bt[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		temp[i]=bt[i];
	}
	int prev=0;
	
	int qp=-1;
	while(isempty(temp,n))
	{
		if(qp==-1)
		{
			qp=0;
		}
		else
		{
			qp=q[front]-1;
		}
		if(qp==-1)
		{
			gs[k]=prev;
			p[k]=-1;
			prev=at[ide];
			k+=1;
			enq(ide+1);
			qp=ide+1;
		}
		else if(at[qp]<=prev)
		{
		if(temp[qp]>=tq && temp[qp]!=0)
		{
			if(temp[qp]==tq && ispossible(qp+1))
			{
				enq(qp+1);
				ide=qp+1;
			}
			gs[k]=prev;
			p[k]=pno[qp];
			temp[qp]=temp[qp]-tq;
			prev+=tq;
			k+=1;
		}
		else if(temp[qp]!=0)
		{
			gs[k]=prev;
			p[k]=pno[qp];
			prev+=temp[qp];
			temp[qp]=0;
			k+=1;
		}
		int j;
		for(j=0;j<n;j++)
		{
			if(at[j]<=prev && ispossible(j+1) &&temp[j]!=0)
			{
				enq(j+1);
			}
		}
		int pr=deq();
		if(temp[pr-1]!=0)
		{
			enq(pr);
		}
		else if(temp[pr-1]==0)
		{
			ct[pr-1]=prev;
		}
		
		}
		else
		{
			gs[k]=prev;
			p[k]=-1;
			prev=at[0];
			int j;
			enq(0+1);
			k+=1;
		}
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
	printf("\n");
	for(i=0;i<k;i++)
	{
		/*if(gs[i]==gs[i+1])
		{
			
		}*/
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
	printf("\nEnter Time Quantum: ");
	scanf("%d",&tq);
	int at[n],bt[n];
	printf("\nEnter Arrival and Brust Time\n");
	scanArray(at,bt,n);
	printf("\nP.NO\tAT\tBT\n");
	printArray(at,bt,ct,n);
	sort(at,bt,n);
    printf("\nP.NO\tAT\tBT\n");
	printArray(at,bt,ct,n);
	findCT(at,bt,n);
	printf("\nP.No\tAT\tBT\tCT\tTAT\tWT\n");
	printfArray(at,bt,ct,n);
	printGun();
}
/*
tq=3
7 3
4 7
6 5
2 4
5 6
3 8
*/
