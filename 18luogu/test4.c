#include<stdio.h>
int ma[100][100]={0};
int b[100][100]={0};
int tx[]={1,-1,0,0};
int ty[]={0,0,1,-1};
int n;
int check(int i,int j){
    if(i<0||i>n+1||j<0||j>n+1||ma[i][j]!=0) return 0;
    else return 1;
}
void dfs(int x,int y){
    if(check(x,y)){
        ma[x][y]=3;
            for (int i = 0; i < 4; i++)
        {   
            int ix=x+tx[i];
            int iy=y+ty[i];
            dfs(ix,iy);
        }
        
    }
    return ;
}
int main (){
    
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            scanf("%d",&ma[i][j]);
            b[i][j]=ma[i][j];
        }
    }
    dfs(0,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
           if(ma[i][j]==3||ma[i][j]==1)printf("%d ",b[i][j]);
           else printf ("2 ");
        }
        printf("\n");
    }
    return 0;
}