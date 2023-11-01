#include <stdio.h>
#include <stdlib.h>
void Transpose(int *num,int *numT,int n){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            numT[j*n+i]=num[i*n+j];
        }
    }
}
void print(int *num,int n){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            printf("%d ",num[i*n+j]);
        }
        printf("\n");
    }
    
}
void Input(int *num,int n);
int main()
{
    printf("Hello world!\n");
    int n;
    int num[20][20]={0};
    int numT[20][20]={0};
    printf("please input the matrix's order\n");
    scanf("%d",&n);
    printf("please input the matrix\n");
    Input(*num,n);
    Transpose(*num,*numT,n);
    printf("the transpose matrix:\n");
    print(*numT,n);
    return 0;
}
void Input(int *num,int n){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
            {
                scanf("%d",&num[i*n+j]);
            }
    }
}
