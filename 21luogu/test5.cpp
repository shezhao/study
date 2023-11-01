#include<bits/stdc++.h>
using namespace std;
int n,m;
    int ans=0;
    
    int num[1000]={0};
    int book[1000]={0};
int max(int x,int y){
    if(x>y) return x;
    return y;
}
int sum=0;
void dfs(int deep,int st){
    if(sum==m&&deep<=n){
        ans++;
        return ;
    }
    for (int i = deep; i < n; i++)
    {
        if(book[i]==0){
        book[i]=1;
        sum+=num[i];
        dfs(deep+1,i+1);
        book[i]=0;
        sum-=num[i];}
    }
    return;
    
}
int main (){
    
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }
    dfs(0,0);
    printf("%d",ans);
    return 0;
}