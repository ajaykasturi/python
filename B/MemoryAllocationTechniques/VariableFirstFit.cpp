#include<stdio.h>
#include<stdlib.h>
int tbm=0,count=0,up[100],exF=0;
int findFirstFit(int p,int b[],int nb)
{
	int x=-1,i;
	for(i=0;i<nb;i++)
	{
		if(p<=b[i])
		{
			x=i;
			break;
		}
	}
	return x;
}
void vFirstFit(int p[],int b[],int np,int nb,int bb[])
{
	int i;
	for(i=0;i<np;i++)
	{
		int x=findFirstFit(p[i],b,nb);
		if(x==-1)
		{
			up[count++]=p[i];
			printf("Process %d must wait\n",i+1);
		}
		else
		{
			printf("Process %d is allocated with %d block memory\n",i+1,bb[x]);
			exF=exF+p[i];
			b[x]=b[x]-p[i];
		}
	}
}
int main()
{
	int np,nb,i;
	printf("Enter number of processes:");
	scanf("%d",&np);
	printf("Enter number of blocks:");
	scanf("%d",&nb);
	printf("Enter size of each process:");
	int p[np],b[nb],bb[nb];
	for(i=0;i<np;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("Enter size of each block:");
	for(i=0;i<nb;i++)
	{
		scanf("%d",&b[i]);
		tbm=tbm+b[i];
		bb[i]=b[i];
	}
	vFirstFit(p,b,np,nb,bb);
	int y=0;
	for(i=0;i<count;i++)
	{
		if(up[i]<=(tbm-exF))
		{
			y=1; 
			printf("Total External Fragmentation : %d",(tbm-exF));
			break;
		}
	}
	if(y==0)
	{
		printf("No External Fragmentation");
	}
}
