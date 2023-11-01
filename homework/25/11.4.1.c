#include <stdio.h>
#include <stdlib.h>
void Transpose(int *num,int *numT,int m,int n){
    for (int i = 1; i <=m; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            numT[j*m+i]=num[i*n+j];
        }
    }
}
void print(int *num,int m,int n){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            printf("%d ",num[i*m+j]);
        }
        printf("\n");
    }
    
}
void Input(int *num,int m,int n);
int main()
{
    printf("Hello world!\n");
    int n;
    int m;
    int num[20][20]={0};
    int numT[20][20]={0};
    printf("please input the matrix's order\n");
    scanf("%d %d",&m,&n);
    printf("please input the matrix\n");
    Input(*num,m,n);
    Transpose(*num,*numT,m,n);
    printf("the transpose matrix:\n");
    print(*numT,m,n);
    return 0;
}
void Input(int *num,int m,int n){
    for (int i = 1; i <=m; i++)
    {
        for (int j = 1; j <=n; j++)
            {
                scanf("%d",&num[i*n+j]);
            }
    }
}