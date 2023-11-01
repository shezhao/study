#include<stdio.h>
int numx[]={1,2,-1,-2,1,2,-1,-2};
int numy[]={2,1,2,1,-2,-1,-2,-1};
int map[50][50]={0};
long long dp[50][50]={0};
int main (){
    int tx,ty,hx,hy;
    scanf("%d %d %d %d",&tx,&ty,&hx,&hy);
    map[hx][hy]=1;
    for (int i = 0; i < 8; i++)
    {
        if(hx+numx[i]>=0&&hy+numy[i]>=0)
         map[hx+numx[i]][hy+numy[i]]=1;

    }
    for (int i = 0; i <=tx; i++)
    {
        dp[i][0]=1;
    }
    for (int i = 0; i <=ty; i++)
    {
        dp[0][i]=1;
    }
    if(hx+numx[7]==0){
            for (int i = hx+numx[7]; i <=tx; i++)
        {
            dp[0][i]=0;
        }
    }
    if(hy+numy[7]==0){
            for (int i = hy+numy[7]; i <=ty; i++)
        {
            dp[i][0]=0;
        }
    }
    
    for (int i = 0; i <=tx; i++)
    {
        for (int j = 0; j <=ty; j++)
        {
           if(map[i][j-1]==1&&j>=1){
               dp[i][j]=dp[i-1][j];
           }
           else if(map[i-1][j]==1&&i>=1){
               dp[i][j]=dp[i][j-1];
           }
           else if((map[i-1][j]==1&&map[i][j-1]==1&&i>=1&&j>=1)||map[i][j]==1){
               dp[i][j]=0;
           }
           else if(i>=1&&j>=1){
             dp[i][j]=dp[i-1][j]+dp[i][j-1];
           }

        }
        
    }
    printf("%lld",dp[tx][ty]);
    
    


    return 0;
}