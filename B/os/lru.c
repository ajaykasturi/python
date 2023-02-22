#include<stdio.h>
#include<string.h>
int pf=0;
int front=-1;
int ph=0;
int n;
int m;
void check(int val,int f[],int ar[],int index)
{
	int found=0,i,j;
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
		int temp[n];
		for( i=0;i<n;i++)
		{
			temp[i]=f[i];
		}
		int count=0;
		for(i=index-1;i>=0;i--)
		{
			for( j=0;j<n;j++)
			{
				if(temp[j]==ar[i])
				{
					temp[j]=-1;
					count++;
					break;
				//	if(count==n-1);
				//		break;
				}
			}
			if(count==n-1)
				break;
		}
		for(i=0;i<n;i++)
		{
			if(temp[i]!=-1)
			{
				f[i]=val;
				break;
			}
		}
		pf++;
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
		check(ar[i],f,ar,i);
	}
	printf("\n%d",pf);
}
