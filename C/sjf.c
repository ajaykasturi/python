#include<stdio.h>
#include<string.h>
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int findminburst(int at[],int bt[],int arrival,int n,int v[]){
   int z=-1;
   int min=9999;
   for(int i=0;i<n;i++){
      if(at[i]<=arrival&&v[i]==0&&bt[i]<min){
         min=bt[i];
         z=i;
      }
   }
   return z;
}
int findnext(int at[],int arrival,int n){
     for(int i=0;i<n;i++){
        if(at[i]>arrival){
          return i;
        }
     }
}
int main(){
    int n;
   scanf("%d",&n);
    int pn[n];
   int at[n];
   int bt[n];
   int ct[n];
   int v[n];
   memset(v,0,sizeof(v));
    memset(ct,0,sizeof(ct));
   for(int i=0;i<n;i++){
      scanf("%d",&pn[i]);
      scanf("%d",&at[i]);
      scanf("%d",&bt[i]);
   } 
   printf("before sorting\n");  
    for(int i=0;i<n;i++){
      printf("%d %d %d\n",pn[i],at[i],bt[i]);
   }   
   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-i-1;j++){
           if(at[j]>at[j+1]){
                  swap(&at[j+1],&at[j]);
                  swap(&bt[j+1],&bt[j]);
                  swap(&pn[j+1],&pn[j]);
           }
      }
   }
   int count=n;
   int arrival=0;
   while(count!=0){
     int z=findminburst(at,bt,arrival,n,v);
      if(z!=-1){
         count--;
         int k=arrival;
         ct[z]=arrival+bt[z];
         arrival=ct[z];
         v[z]=1;
         printf("p%d(%d-%d)->",pn[z],k,arrival);
      }  
      else{
          int c=findnext(at,n,arrival);
          printf("IDLE(%d %d)",arrival,arrival+at[c]-arrival);
          arrival=arrival+at[c]-arrival;
      }
   }
return 0;
}
