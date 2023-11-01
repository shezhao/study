#include<bits/stdc++.h>
using namespace std;
int dp[100000][1000000];
int t,p;
int dfs(int x,int y){
    if(dp[x][y]==-1) return 3;
    if(dp[x][y]!=0)  return dp[x][y];
    dp[x][y]=-1;
    if(x==0) return dp[x][y]=1;
    if(y==0)  return dp[x][y]=2;
    int tx=(x+y)%p;
    int ty=(tx+y)%p;
    return dp[x][y]=dfs(tx,ty);

}
int main (){
    
    int x,y;
    scanf("%d %d",&t,&p);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d",&x,&y);
        int ans=dfs(x,y); 
        if(ans==3) printf("error\n");
        else printf("%d\n",ans);
    }

    return 0;
}