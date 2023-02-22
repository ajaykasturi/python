	#include<stdio.h>
int main()
{
	int n,m,i,j,k,l;
	printf("Enter number of processes:");
	scanf("%d",&m);
	printf("Enter number of resources:");
	scanf("%d",&n);
	int alloc[m][n],max[m][n],need[m][n],avail[n],visit[m];
	printf("Enter allocation matrix:");
	for(i=0;i<m;i++)
	{
		visit[i]=-1;
		for(j=0;j<n;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter Max matrix:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter Available matrix:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&avail[i]);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
			//printf("%d %d %d",need[i][j],alloc[i][j],max[i][j]);
		}
	}
	printf("Need Matrix:");
	printf("\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		int s;
		for(s=0;s<m;s++)
		{
			int index=-1;
			for(k=0;k<n;k++)
			{
				if(need[s][k]>avail[k])
				{
					index=k;
					break;
				}
			}
			//printf("%d",index);
			if(index==-1 && visit[s]==-1)
		    {
			    printf("P%d ",s);
			    for(l=0;l<n;l++)
			    {
				    avail[l]+=alloc[s][l];
			    }
			    visit[s]=1;
	      	}
		
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",avail[i]);
	}
}
/*
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/
