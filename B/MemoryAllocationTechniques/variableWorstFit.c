#include<stdio.h>
#include<stdlib.h>
int tbm=0,exF=0,up[100],count=0;
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int b[],int nb,int bb[])
{
	int i,j;
	for(i=0;i<nb-1;i++)
	{
		for(j=0;j<nb-1-i;j++)
		{
			if(b[j]<b[j+1])
			{
				swap(&b[j],&b[j+1]);
				swap(&bb[j],&bb[j+1]);
			}
		}
	}
}
int findBestFit(int p,int b[],int nb)
{
	int i,res=-1;
	for(i=0;i<nb;i++)
	{
		if(p<=b[i])
		{
			res=i;
			break;
		}
	}
	return res;
}
void vBestFit(int p[],int b[],int np,int nb,int bb[])
{
	int i;
	for(i=0;i<np;i++)
	{
		int x=findBestFit(p[i],b,nb);
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
			sort(b,nb,bb);
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
	int p[np],b[nb],bb[nb];
	printf("Enter size of each process:");
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
	sort(b,nb,bb);
	vBestFit(p,b,np,nb,bb);
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
