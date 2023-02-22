#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int headmovements=0;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort1(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}
void sort2(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]<arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}
int findindex(int arr[],int n,int head)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(head==arr[i])
		{
			return i;
		}
	}
	return -1;
}
void scanDisk(int arr[],int n,int head)
{
	int index=findindex(arr,n,head);
	int inithead=head;
	int curr_track,distance;
	int i;
	for(i=index;i<n;i++)
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
	for(i=index-1;i>=0;i--)
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
void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int size;
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	int arr[size+2];
	printf("\nEnter request tracks\n");
	int i;
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter Head is at:  ");
	int head;
	scanf("%d",&head);
	arr[size]=head;
	int tracks;
	printf("Enter number of tracks: ");
	scanf("%d",&tracks);
	printf("Enter direction(l or r): ");
	char dir;
	scanf("%c",&dir);
	scanf("%c",&dir);
	if(dir=='l')
	{
		arr[size+1]=0;
		sort2(arr,size+2);
		printArray(arr,size+2);
	}
	else if (dir=='r')
	{
		arr[size+1]=tracks-1;
		sort1(arr,size+2);
		printArray(arr,size+2);
	}
	else
	{
		printf("\nTry Again");
	}
	scanDisk(arr,size+2,head);
}
/*
98
183
41
122
14
124
65
67
head is at 53
scan in forward(r) no.of headmovements=331
scan in backward(l) no.of headmovements=236

176
79
34
60
92
11
41
114
Enter Head is at:  50
Enter number of tracks: 200
Enter direction(l or r): l
176 114 92 79 60 50 41 34 11 0
50->41->34->11->0->60->79->92->114->176
Head Movements: 226
*/
