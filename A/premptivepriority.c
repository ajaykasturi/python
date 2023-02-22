#include<stdio.h>
#include<string.h>

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int findminburst(int at[],int pt[],int bt[],int n,int arrival){
  int k=-1;
  int min=9999;
  int minprior=100;
  for(int i=0;i<n;i++){
    if(at[i]<=arrival&&bt[i]!=0&&pt[i]<minprior){
       // min=bt[i];
        k=i;
        minprior=pt[i];
    }
  }
  return k;

}
int findnextarrival(int at[],int n,int arrival){
      //int index;
      for(int i=0;i<n;i++){
         if(at[i]>arrival){
            return i;
         }
      }
}
int main(){
    int n;
    scanf("%d",&n);
    int p[n];
    int pt[n];
    int bt[n];
    int at[n];
    int count=0;
    for(int i=0;i<n;i++){
            scanf("%d %d %d %d",&p[i],&pt[i],&at[i],&bt[i]);
            count+=bt[i];

    }
    for(int i=0;i<n-1;i++){
           for(int j=0;j<n-i-1;j++){
               if(at[j]>at[j+1]){
                  swap(&at[j],&at[j+1]);
                  swap(&pt[j],&pt[j+1]);
                  swap(&p[j],&p[j+1]);
                  swap(&bt[j],&bt[j+1]);
               }
           }
    }
    for(int i=0;i<n-1;i++){
           for(int j=0;j<n-i-1;j++){
               if(at[j]==at[j+1]){
                 if(bt[j]>bt[j+1]){
                  swap(&at[j],&at[j+1]);
                  swap(&pt[j],&pt[j+1]);
                  swap(&p[j],&p[j+1]);
                  swap(&bt[j],&bt[j+1]);
                  }
               }
           }
    }
    int bt1[n];
      for(int i=0;i<n;i++){
          bt1[i]=bt[i];
    }
    int arrival=0;
    int ct[n];
    memset(ct,0,sizeof(ct));
    printf("\n");
    while(count!=0){
       int z=findminburst(at,pt,bt,n,arrival);
       if(z!=-1){
       
           bt[z]=bt[z]-1;
           int y=arrival;
           arrival+=1;
           ct[z]=arrival;
           printf("p%d(%d %d)--",p[z],y,arrival);
           count--;
       }
       else{
          int l=findnextarrival(at,n,arrival);
          int x=arrival;
          arrival= arrival+at[l]-arrival;
          printf("idle (%d %d)--",x,arrival);
       }
    }
   
return 0;
}
