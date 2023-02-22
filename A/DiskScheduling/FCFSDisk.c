#include<stdio.h>
#include<math.h>

int headmovements=0;

void fcfsDisk(int arr[],int n,int head)
{
	int curr_track,distance;
	int inithead=head;
	int i;
	for(i=0;i<n;i++)
	{
		if(inithead!=arr[i])
		{
			printf("%d->",head);
			curr_track=arr[i];
			distance=fabs(head-curr_track);
			headmovements+=distance;
			head=curr_track;
		}
	}
	printf("%d",head);
	printf("\nHead Movements: %d\n",headmovements);
}
int main()
{
	int size;
	printf("Enter size of array: ");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter request tracks\n");
	int i;
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter Head is at:  ");
	int head;
	scanf("%d",&head);
	fcfsDisk(arr,size,head);
}
