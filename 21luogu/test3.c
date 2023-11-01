#include<stdio.h>
int ma[105][105]={0};
int tx[]={1,-1,0,0};
int ty[]={0,0,1,-1};
int n;int m;
int check(int i,int j){
    if(i>=0&&i<n&&j>=0&&j<m&&ma[i][j]==1) return 1;
    return 0;
}
int dfs(int x,int y){
    if(check(x,y)){
        ma[x][y]=0;
        for (int i = 0; i < 4; i++)
        {   
            int ix=x+tx[i];
            int iy=y+ty[i];
            dfs(ix,iy);
        }
        return 1;
    }
    return 0;
}
int main (){
    
    int ans=0;
    char str[105][105];
    scanf("%d %d",&n,&m);
    getchar();
    for (int i = 0; i <n; i++)
    {
        scanf("%s",str[i]);
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <m; i++)
        {
            if(str[j][i]=='0') ma[j][i]=0;
            else ma[j][i]=1;
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <m; i++)
        {
            if(dfs(j,i))
            {ans++;}
        }
    }
    printf("%d",ans);
    return 0;
}