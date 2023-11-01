#include<stdio.h>
int tx[]={1,2,-1,-2,1,2,-1,-2};
int ty[]={2,1,2,1,-2,-1,-2,-1};
int n,m;
int sx,sy;
int num[1000][1000]={0};
int map[1000][1000]={0};
int min=10000000;
int check(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<m&&map[x][y]==0){
        return 1;
    }
  return 0;
}
void dfs(int deep,int x,int y,int px,int py){
    if(x==px&&y==py){
        min=deep<min?deep:min;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int dx=x+tx[i];
        int dy=y+ty[i];
        if(check(dx,dy)){
            map[dx][dy]=1;
            dfs(deep+1,dx,dy,px,py);
            map[dx][dy]=0;
        }
    }
    return ;  
}
int main (){
    
    scanf("%d %d",&n,&m);
    scanf("%d %d",&sx,&sy);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
             dfs(0,sx-1,sy-1,i,j);
             num[i][j]=min;
             min=10000000;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(num[i][j]==10000000){num[i][j]=-1;}
            printf("%-5d",num[i][j]);

        }
        printf("\n");
        
    }
    return 0;
}