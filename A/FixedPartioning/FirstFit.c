#include<stdio.h>
#include<stdlib.h>
int n;
int b;
int process[100];
int block[100];
int visited[100];//this is to store visited blocks
int internalfragmentation=0;
int externalfragmentation=0;
int unvisited[100];//this is for waiting processes
int sum(int num)
{
	int i;
	int sum=0;
	for(i=0;i<num;i++)
	{
		if(visited[i]==0)
		{
			sum+=block[i];
		}
	}
	return sum;
}
void firstFit(void){
	int i,j;
	int k=0;
	for(i=0;i<n;i++)
	{
		int flag=0;
		for(j=0;j<b;j++)
		{
			if(process[i]<=block[j] && visited[j]==0)
			{
				flag=1;
				printf("%d (p%d)->%d block\n",process[i],i+1,block[j]);
				block[j]=block[j]-process[i];
				internalfragmentation+=block[j];
				visited[j]=1;
				break;
			}
		}
		if(flag==0)
		{
			unvisited[k]=i;
			k++;
		}
	}
	int val=sum(b);
	for(i=0;i<k;i++)
	{
		if(process[unvisited[i]]<=val)
		{
			externalfragmentation=val;
			break;
		}
	}
}
int main(){
	printf("Enter Number of Processes: ");
	scanf("%d",&n);
	printf("Enter Number of Blocks: ");
	scanf("%d",&b);
	int i;
	printf("Enter Memory for each process\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&process[i]);
	}
	printf("Enter size of each Block\n");
	for(i=0;i<b;i++)
	{
		scanf("%d",&block[i]);
		visited[i]=0;
	}
	firstFit();
	printf("\nInternalFragmentation: %d",internalfragmentation);
	printf("\nExternalFragmentation: %d",externalfragmentation);
}
