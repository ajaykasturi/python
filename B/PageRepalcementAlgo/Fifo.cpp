#include<stdio.h>
int pf=0,ph=0,front=-1,n,m;
void check(int f[],int val)
{
	int found=0,i;
	for(i=0;i<n;i++)
	{
		if(f[i]==-1)
		{
			pf++;
			f[i]=val;
			found=1;
			break;
		}
		else
		{
			if(f[i]==val)
			{
				ph++;
				found=1;
				break;
			}
		}
	}
	if(found==0)
	{
		front++;
		f[front]=val;
		pf++;
		if(front==n-1)
		{
			front=-1;
		}
	}
}
int main()
{
	int i,j;
	printf("Enter number of frames:");
	scanf("%d",&n);
	printf("Enter number of references:");
	scanf("%d",&m);
	int r[m],f[n];
	printf("Enter reference string:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&r[i]);
	}
	for(i=0;i<n;i++)
	{
		f[i]=-1;
	}
	for(i=0;i<m;i++)
	{
		check(f,r[i]);
	}
	printf("Total page faults:%d",pf);
}
