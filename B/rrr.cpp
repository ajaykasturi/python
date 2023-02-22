#include<stdio.h>
#include<stdlib.h>
#define max 100
int queue[max];
int front=-1;
int rear= -1;
void enqueue(int data){
	if(rear== max-1){
		printf("Queue overflow");
		exit(1);
	}
	else if(front==-1 && rear==-1){
		front =rear=0;
		queue[rear]=data;
	}
	else{
		rear++;
		queue[rear]=data;
	}
}
int dequeue(){
	int val;
	if(front==-1 && rear==-1){
	       return -1;
	}
	else if(front==rear){
		int e=queue[front];
		front=rear=-1;//if we want value v can store it and can return easily
		return e;
	}
	else{
		return queue[front++];
	}
}
void display(){
	int i;
	if(front == -1&& rear==-1){printf("queue empty");
	}
	else{
		for(i=front;i<rear+1;i++){
			printf("%d ",queue[i]);
		}
	}
	printf("\n");
}
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int pno[],int at[],int bt[],int btt[],int n)
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
				swap(&pno[j],&pno[j+1]);
				swap(&btt[j],&btt[j+1]);
			}
		}
	}
}
void readyq(int at[],int bt[],int l,int n,int visit[]){
	int i;
	for(i=0;i<n;i++){
		if(at[i]<=l && bt[i]!=0 && visit[i]==0){
			enqueue(i);
			visit[i]=1;
		}
	}
}
int main()
{
	int n,tq,i;
	printf("Enter number of processes:");
	scanf("%d",&n);
	int pno[n],bt[n],btt[n],ct[n],tat[n],wt[n],at[n],v[n];
	printf("Enter time quantum:");
	scanf("%d",&tq);
	printf("Enter arrival & burst times:");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&at[i],&bt[i]);
		btt[i]=bt[i];
		pno[i]=i+1;
		v[i]=0;
	}
	sort(pno,at,bt,btt,n);
	int c=0,l=0;
	i=-1;
	enqueue(0);
	v[0]=1;
	while(c<n)
	{
		int k=i;
		i=dequeue();
		if(i==-1)
		{
			i=k+1;
			v[i]=1;
		}
		if(at[i]<=l)
		{
			if(bt[i]>=tq)
			{
				printf("%d--%d p%d\n",l,l+tq,pno[i]);
				bt[i]=bt[i]-tq;
				l=l+tq;
				readyq(at,bt,l,n,v);
				if(bt[i]==0)
				{
					ct[i]=l;
					c++;
				}
				else
				{
					enqueue(i);
				}
			}
			else
			{
				printf("%d--%d p%d\n",l,l+bt[i],pno[i]);
				l=l+bt[i];
				bt[i]=0;
				ct[i]=l;
				c++;
			}
		}
		else
		{
			printf("%d--%d  IDLE\n",l,at[i]);
			l=at[i];
			if(bt[i]>=tq)
			{
				printf("%d--%d p%d\n",l,l+tq,pno[i]);
				bt[i]=bt[i]-tq;
				l=l+tq;
				readyq(at,bt,l,n,v);
				if(bt[i]==0)
				{
					ct[i]=l;
					c++;
				}
				else
				{
					enqueue(i);
				}
			}
			else
			{
				printf("%d--%d p%d\n",l,l+bt[i],pno[i]);
				l=l+bt[i];
				bt[i]=0;
				ct[i]=l;
				c++;
			}
		}
	}
	float awt=0,atat=0;
	for(i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		atat=atat+tat[i];
		wt[i]=tat[i]-btt[i];
		awt=awt+wt[i];
	}
	printf("pno\tat\tbt\tct\ttat\twt\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],at[i],btt[i],ct[i],tat[i],wt[i]);
	}
	printf("===================================================\n");
	printf("AVERAGE WAITING TIME:%f\n",awt/n);
	printf("AVERAGE TURN AROUND TIME:%f",atat/n);
}
