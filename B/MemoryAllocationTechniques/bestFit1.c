#include<stdio.h>
int up[100],count=0;
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int b[],int nb)
{
	int i,j;
	for(i=0;i<nb-1;i++)
	{
		for(j=0;j<nb-i-1;j++)
		{
			if(b[j]>b[j+1])
			{
				swap(&b[j],&b[j+1]);
			}
		}
	}
}
int findBestFit(int p,int b[],int nb,int vb[])
{
	int i,x;
	for(i=0;i<nb;i++)
	{
		if(p<=b[i] && vb[i]==0)
		{
			vb[i]=1;
			x=i;
			break;
		}
	}
	return x;
}
void bestFit(int p[],int b[],int vb[],int np,int nb)
{
	int i,x;
	for(i=0;i<np;i++)
	{
		x=findBestFit(p[i],b,nb,vb);
		if(x==0)
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
	int np,nb,i;
	printf("Enter number of processes:");
	scanf("%d",&np);
	printf("Enter number of blocks:");
	scanf("%d",&nb);
	int p[np],b[nb],vb[nb];
	printf("Enter memory required for each process:");
	for(i=0;i<np;i++);
	{
		scanf("%d",&p[i]);
	}
	printf("Enter size of each block:");
	for(i=0;i<nb;i++)
	{
		scanf("%d",&b[i]);
		vb[i]=0;
	}
	sort(b,nb);
	bestFit(p,b,vb,np,nb);
}
