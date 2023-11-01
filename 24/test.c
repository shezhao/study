#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
char a[105][105];
int n,m,result;
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
 
int check(int x,int y)//检查是否有油田
{
    if(x>=0&&x<m&&y>=0&&y<n&&a[x][y]=='@')
        return 1;
    return 0;
}
 
int dfs(int x, int y)
{
    int i,xx,yy;
    if(check(x,y))
    {
        a[x][y]='.'; 
        for(i=0;i<8;i++)
        {
            xx=x+dir[i][0];
            yy=y+dir[i][1];
            dfs(xx,yy);//依次检查8个方向
        }
        return 1;
    }
    return 0;
}
 
int main(void)
{
    int i,j;
    while(scanf("%d %d",&m,&n)==2)
    {
        if(m==0&&n==0)
            break;
        result = 0;
        memset(a,0,sizeof(a));
        for(i=0;i<m;i++)
            scanf("%s",a[i]);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dfs(i,j))
                    result++;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}