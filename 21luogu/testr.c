#include<stdio.h>
int mine[105][105]={0};
int GetMineCount(int x ,int y )
{
    return (mine[x-1][y]
    +mine[x-1][y-1] 
    +mine[x-1][y+1] 
    +mine[x][y+1]
    +mine[x][y-1]
    +mine[x+1][y+1]
    +mine[x+1][y]
    +mine[x+1][y-1]);
}
int main (){
    int n,m;
    char str[101][101];
    char str2[101][101];
    scanf("%d %d",&n,&m);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s",str[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(str[i][j]=='*') mine[i+1][j+1]=1;
        }
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
          if(mine[i][j]==1){
            str2[i][j]='*';
          }
          else{
            str2[i][j]=GetMineCount(i,j)+'0';
          }
        }
        
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
          
          printf("%c",str2[i][j]);
        }
        printf("\n");
    }
    return 0;
}