#include<stdio.h>
#include<string.h>
int pf=0;
int front=-1;
int ph=0;
int n;
int m;
void check(int val,int f[])
{
	int found=0;
	int i;
	for( i=0;i<n;i++)
	{
		if(f[i]==-1)
		{
			pf++;
			found=1;
			f[i]=val;
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
		pf++;
		f[front]=val;
		if(front==n-1)
		{
			front=-1;
		}
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	scanf("%d",&m);
	int ar[m];
	for(i=0;i<m;i++)
	{
		scanf("%d",&ar[i]);
	}
	int f[n];
	for(i=0;i<n;i++)
	{
		f[i]=-1;
	}
	for( i=0;i<m;i++)
	{
		check(ar[i],f);
	}
	printf("\n%d",pf);
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 ->20
