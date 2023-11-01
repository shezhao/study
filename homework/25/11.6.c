#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,m;
    printf("please input the number of classes and students\n");
    scanf("%d %d",&m,&n);
    int *num;
    int max=0;
    num=(int*)malloc(m*n*sizeof(int));
    printf("please input the score\n");
    for (int i = 0; i <m ; i++)
    {
       for (int j = 0; j < n; j++)
       {
           printf("%d class%d students>>",i+1,j+1);
           scanf("%d",&num[i*n+j]);
           max=num[i*n+j]>max?num[i*n+j]:max;
       }
       
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(num[i*n+j]==max){
                printf("maxScore=%d\tclass:%d\tid=%d\n",max,i+1,j+1);
            }
        }
        
    }
    

    


    return 0;
}