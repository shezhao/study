#include<bits/stdc++.h>
using namespace std;
int num[3][200]={0};
char str[3][200]={'\0'};
int book[3][200]={0};
int nextx[8]={1,1,1,0,0,-1,-1,-1};
int nexty[8]={-1,0,1,-1,1,1,0,-1};
int flag=0;
void dfs(int x,int y,int m){ 
    if(x==2&&y==m){
        flag=1;
        return ;
    }
    int tx,ty;
    for(int i=0;i<8;i++){
		tx=x+nextx[i];
		ty=y+nexty[i];
		if(tx<1||ty<1||tx>2||ty>m){
			continue; 
		}
		if(book[tx][ty]==0&&num[tx][ty]==0){
			book[tx][ty]=1;
			dfs(tx,ty,m);
			book[tx][ty]=0;
		} 
		
	}
	return;
}
int main (){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d",&m);
        getchar(); 
        gets(str[1]); 
        gets(str[2]);
        for (int j = 1; j<=m ; j++)
        {
           num[1][j]=str[1][j-1]-'0';
           num[2][j]=str[2][j-1]-'0';
        } 
       
        dfs(1,1,m);
        if(flag==1) printf("YES\n");
        else printf("NO\n");
        flag=0;
    }
    return 0;
}