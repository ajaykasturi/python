#include<stdio.h>
#include<string.h>
int arr[10000];
int front=-1;
int rear=-1;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void enqueue(int element){
     if(rear==9999){
        printf("queue full");
     }
     else{
        rear++;
        arr[rear]=element;
     }
}
int dequeue(){
    front++;
    int element=arr[front];
    return element;
}
int isempty(){
      if(front==rear){
         return 1;
      }
      else{
         return 0;
      }
}
int check(int n){
 int found=1;
  for(int i=front+1;i<=rear;i++){
     if(arr[i]==n){
        found=0;
        break;
     }
  }
  return found;
}
int main(){
      
          int n;
   scanf("%d",&n);
    int pn[n];
   int at[n];
   int bt[n];
   int ct[n];
   int visited[n];
   int count=0;
   memset(visited,0,sizeof(visited));
    memset(ct,0,sizeof(ct));
   for(int i=0;i<n;i++){
      scanf("%d",&pn[i]);
      scanf("%d",&at[i]);
      scanf("%d",&bt[i]);
      count+=bt[i];
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
      int bt1[n];
   for(int i=0;i<n;i++){
      bt1[i]=bt[i];
   }
   int arrival=0;
  // printf("%d\n",count);
   int qt=2;
   printf("\n");
   printf("after sorting \n"); 
    for(int i=0;i<n;i++){
      printf("%d %d %d\n",pn[i],at[i],bt[i]);
   }
   printf("\n");
   int c=n;
   
   enqueue(0);
   int index;
   int flag=0;
   int prev;
    if(at[0]>arrival&&flag==0){
                 prev=arrival;
                  arrival=arrival+at[index];
                     printf("IDLE(%d %d)",prev,arrival);
                  flag=1;
    }
 while(c!=0){
         index=dequeue();
         // printf("index =%d\t",index);
         if(at[index]<=arrival){
           
             if(bt[index]>=qt){
                 //ct[index]=ct[index]+qt;
                  ct[index]=arrival+qt;
                  bt[index]-=qt;
                  prev=arrival;
                  arrival+=qt;
                // printf("arrival%d\t",arrival);
                  printf("p%d (%d-%d)\t",pn[index],prev,arrival);
                  if(bt[index]==0){
                     c--;
                  }
                    if(c==0){
                     break;
                 }
             }
             else{
                 ct[index]=arrival+bt[index];
                 c--;
                   prev=arrival;
                  arrival+=bt[index];
                    printf("p%d (%d-%d)\t",pn[index],prev,arrival);
                 bt[index]=0;
                 if(c==0){
                     break;
                 }
                
                 
             }
             for(int i=0;i<n;i++){
                 if(i!=index&&at[i]<=arrival&&bt[i]!=0&&check(i)){
                     enqueue(i);
                    // printf("yes");            
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
             if(y!=index){
               printf("IDLE");
               arrival=arrival+(at[y]-arrival);
             }
             enqueue(y);
            
            }
             else {
                 if(bt[index]!=0){
                  enqueue(index);
                 }
             }
       }   
      /*  else{
             printf("IDLE\t");
             for(int i=0;i<n;i++){
                   if(at[i]<=arrival&&bt[i]!=0){
                       arrival=arrival+at[i];
                       index=i;
                       break;
                   }
             }
             enqueue(index);
         }  */ 
   }
       
      
        /**/
 //}
  
  
    int tat[n];
    int wt[n];
      int avgtat=0;
    int avgwt=0;
    printf("\n");
    printf("PN\tAT\tBT\tCT\tTAT\tWT \n");
    for(int i=0;i<n;i++){
       tat[i]=ct[i]-at[i];
       wt[i]=tat[i]-bt1[i];
        avgtat+=tat[i];
       avgwt+=wt[i];
      printf("%d	%d	%d	%d	%d	%d \n",pn[i],at[i],bt1[i],ct[i],tat[i],wt[i]);
   } 
        //printf("queue:");
        //display(&q);
  // }*//
return  0;
}
