#include<bits/stdc++.h>
using namespace std;
int txi[8]={1,1,1,0,0,-1,-1,-1};
int tyi[8]={1,0,-1,1,-1,1,0,-1};
string a="yizhong";
int ans=0; 
char ma[105][105]={'\0'};
int book[105][105]={0};
void dfs(int x,int y,int k){
    int tx=x; int ty=y;
        
        for (int i = 0; i < 7; i++)
        {
            if(ma[tx][ty]!=a[i]){
                return ;
            }
            tx+=txi[k];
            ty+=tyi[k];
        }
        for (int i = 0; i < 7; i++)
        {
            book[x][y]=1;
            x+=txi[k];
            y+=tyi[k];
        }  

}  
int main (){
    int n;
    scanf("%d",&n);
    for (int i = 0; i <n; i++)
    {
        scanf("%s",ma[i]);
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if(ma[i][j]=='y'){
                for (int k = 0; k < 8; k++)
                {
                    dfs(i,j,k);
                }
            }
        }
        
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if(book[i][j]==0)printf("*");
            else printf("%c",ma[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}