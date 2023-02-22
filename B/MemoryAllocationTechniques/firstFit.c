#include<stdio.h>
int intF=0,exF=0,tbm=0,up[100],count=0;
int  findFirstFit(int p,int b[],int vb[],int nb)
{
	int i,x=-1;
	for(i=0;i<nb;i++)
	{
		if(p<=b[i] && vb[i]==0)
		{
			vb[i]=1;
			exF=exF+b[i];
			intF=intF+b[i]-p;
			x=i;
			break;
		}
	}
	return x;
}
void firstFit(int p[],int b[],int vb[],int np,int nb)
{
	int i,x;
	for(i=0;i<np;i++)
	{
		x=findFirstFit(p[i],b,vb,nb);
		if(x==-1)
		{
			up[count++]=p[i];
			printf("Process %d must wait\n",i+1);
		}
		else
		{
			printf("Process %d is allocated with %d block memory\n",i+1,b[x]);
		}
	}
}
int main()
{
	int np,nb;
	printf("Enter number of processes:");
	scanf("%d",&np);
	printf("Enter number of blocks:");
	scanf("%d",&nb);
	int p[np],b[nb],vb[nb];
	printf("Enter memory required for each process:");
	int i,j;
	for(i=0;i<np;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("Enter size of each block:");
	for(j=0;j<nb;j++)
	{
		scanf("%d",&b[j]);
		tbm=tbm+b[j];
		vb[j]=0;
	}
	firstFit(p,b,vb,np,nb);
	printf("Total internal fragmentation id %d\n",intF);
	int y=0;
	for(i=0;i<count;i++)
	{
		//printf("%d",up[i]);
		if(up[i]<=(tbm-exF))
		{
			printf("External fragmentation is %d\n",(tbm-exF));
			y=1;
			break;
		}
	}
	if(y==0)
	{
		printf("No external fragmentation");
	}
}
