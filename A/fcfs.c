#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
   int n;
   scanf("%d",&n);
    int pn[n];
   int at[n];
   int bt[n];
   int ct[n];
   int visited[n];
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
   int start=0;
   int final[100];
   
   for(int i=0;i<n;i++){
    int x=start;
        if(at[i]<=start){
          
           ct[i]=start+bt[i];
           start=start+bt[i];
           printf("process id%d (%d-%d)  ",pn[i],x,ct[i]);
        }
        else{
           ct[i]=start+(at[i]-start)+bt[i];
           int y=start+(at[i]-start);
           start=ct[i];
           printf("IDLE (%d %d)",x,y);
           printf("process id%d (%d-%d)  ",pn[i],y,ct[i]);
        }
   }
    printf("\n");
    printf("after sorting \n"); 
    int tat[n];
    int wt[n];
    printf("PN AT BT CT TAT WT \n");
    for(int i=0;i<n;i++){
       tat[i]=ct[i]-at[i];
       wt[i]=tat[i]-bt[i];
      printf("%d  %d  %d  %d  %d  %d \n",pn[i],at[i],bt[i],ct[i],tat[i],wt[i]);
   } 
  return 0;
}
