#include<stdio.h>
int max(int x,int y){
    if(x>y) return x;
    return y;

}
int t,m;
int main (){
    int ti[1005]={0};
    int value[1005]={0};
   
    int dp[1005]={0};
    scanf("%d %d",&t,&m);
    for (int i = 1; i <=m; i++)
    {
        scanf("%d %d",&ti[i],&value[i]);
    }
    for (int i = 1; i <=m; i++)
    {
        for (int j = t; j >=ti[i]; j--){
            dp[j]=max(dp[j],dp[j-ti[i]]+value[i]);
        }
        
    }
    printf("%d",dp[t]);
    return 0;
}