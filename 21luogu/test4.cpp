#include<bits/stdc++.h>
using namespace std;
int f[1000][10005]={0};
int main (){
    int n,m;
    int ans=0;
    scanf("%d %d",&n,&m);
    int num[1000]={0};
    for (int i = 1; i <=n; i++)
    {
        scanf("%d",&num[i]);
    }
    
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {if(j==num[i]){
                    f[i][j]=1+f[i-1][j];
                }
            if(j<num[i]){
                f[i][j]=f[i-1][j];
            }
            
            if(j>num[i])f[i][j]=f[i-1][j]+f[i-1][j-num[i]];
            
        }
        
    }
    printf("%d",f[n][m]);
    return 0;
}