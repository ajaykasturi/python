#include<stdio.h>
#include<string.h>

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int arr[1000];
int rear=-1;
int front=-1;
void enqueue(int element){
   rear++;
   arr[rear]=element;
}
int dequeue(){
   front++;
   return arr[front];
}
int check(int n){
   for(int i=front+1;i<=rear;i++){
      if(arr[i]==n){
         return 0;
      }
   }
   return 1;
}
int isempty(){
   if(front==rear){
       return 1;
   }
   else{
       return 0;
   }
}
int main(){
    int n;
    scanf("%d",&n);
    int p[n];
    int bt[n];
    int at[n];
    int count=n;
    for(int i=0;i<n;i++){
            scanf("%d %d %d",&p[i],&at[i],&bt[i]);
            //count+=bt[i];

    }
    for(int i=0;i<n-1;i++){
           for(int j=0;j<n-i-1;j++){
               if(at[j]>at[j+1]){
                  swap(&at[j],&at[j+1]);
                  swap(&p[j],&p[j+1]);
                  swap(&bt[j],&bt[j+1]);
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
    enqueue(0);
    if(at[0]>arrival){
       int x=arrival;
       arrival+=at[0];
       printf("IDLE (%d %d)",x,arrival);
    }
    int qt=2;
    while(count!=0){
       int  index=dequeue();
       if(at[index]<=arrival){
          if(bt[index]>=qt){
             int x=arrival;
             ct[index]=arrival+qt;   
             arrival+=qt;
             bt[index]-=qt;
             printf("p%d(%d %d)->",p[index],x,arrival);
             if(bt[index]==0){
                count--;
             }
             if(count==0){
               break;
             }
          }
          else{
             int x=arrival;
             ct[index]=arrival+bt[index];   
             arrival+=bt[index];
             bt[index]=0;
             printf("p%d(%d %d)->",p[index],x,arrival);
             if(bt[index]==0){
                count--;
             }
             if(count==0){
               break;
             }
          }    
          for(int i=0;i<n;i++){
              if(at[i]<=arrival&&i!=index&&bt[i]!=0&&check(i)){
                  enqueue(i);
              }
          }
          if(isempty()){
             int y;
             for(int i=0;i<n;i++){
                if(bt[i]!=0){
                   y=i;
                   break;
                }
             }  
             if(index!=y){
                    int x=arrival;
                     arrival=arrival+at[y]-arrival;
                   printf("IDLE (%d %d)->",x,arrival);
             }
             enqueue(y);
          }
          else{
             if(bt[index]!=0){
                enqueue(index);
             }
          }
                 
       }//if end
    }
    printf("\nTABLE\n");
    int tat[n];
    int wt[n];
    int tsum=0;
    int wsum=0;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt1[i];
        tsum+=tat[i];
        wsum+=wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt1[i],ct[i],tat[i],wt[i]);
    }
    printf("average tat%f average wat%f",(float)tsum/(float)n,(float)wsum/(float)n);
return 0;
}
