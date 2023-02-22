#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a,b,c,d,j,k,m;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        m=a*b;
        for(j=a+1;j<=c;j++)
        {    int flag=0;
            for(k=b+1;k<=d;k++)
            {
                if((j*k)%m==0)
                {
                    printf("%d %d",j,k);
                    printf("\n");
                    flag=1;
                    break;
                }
            }
            if(flag!=1)
            {
            	  printf("%d %d",-1,-1);
            	  break;
			}
			
          
        }
    }
}
