#include<stdio.h>
int max(int x,int y){
    if(x>y) return x;
    return y;

}
int t,m;int dp[40000]={0};
int main (){
    int ti[1005]={0};
    scanf("%d %d",&t,&m);
    for (int i = 1; i <=m; i++)
    {
        scanf("%d",&ti[i]);
    }
    for (int i = 1; i <=m; i++)
    {
        for (int j = t; j >=ti[i]; j--){
            if(j>=ti[i])
            dp[j]=max(dp[j],dp[j-ti[i]]+ti[i]);
        }
        
    }
    printf("%d",t-dp[t]);
    return 0;
}