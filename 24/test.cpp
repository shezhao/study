#include<bits/stdc++.h>
using namespace std;
int sum[30]={0};
int book[30]={0};
int ans[30]={0};
int a=0;
int minx=1000000;int v;int g;
int check(int *vt){
    for (int i = 1; i <=v; i++)
    {
        if(sum[i]<vt[i]) return 0;
    }
    return 1;
}
void print(int *book){
    for (int i = 1; i <=g; i++)
    {
        if(book[i]==1) {printf("%d",i);a++;
        if(a<minx&&a>0) printf(" ");}
        
    }
}
void dfs(int deep,int *vt,int gt[][30]){
    if(check(vt)||deep>g){
        if(minx>deep-1){
            minx=deep-1; 
            // printf("%d ",minx);
            // print(book);
            for (int i = 1; i <=minx; i++)
            {
               ans[i]=book[i];
            }
        }
        return;
    }
    for (int i = 1; i <=g; i++)
    {
        if(book[i]==0){
            for (int j = 1; j <=v; j++)
            {
                sum[j]+=gt[i][j];
            }
                book[i]=1;
                dfs(deep+1,vt,gt);
                for (int j = 1; j <=v; j++)
            {
                sum[j]-=gt[i][j];
            }
                book[i]=0;
        }
    }
    return ;
}

int main (){
    
    scanf("%d",&v);
    int vt[v+1];
    for (int i = 1; i <= v; i++)
    {
        scanf("%d",&vt[i]);
    }
    
    scanf("%d",&g);
    int gt[g+1][30];
    for (int i = 1; i <= g; i++)
    {
            for (int j = 1; j <= v; j++)
        {
            scanf("%d",&gt[i][j]);
        }
    }
    dfs(1,vt,gt);
    printf("%d ",minx);
    print(ans);
    return 0;
}