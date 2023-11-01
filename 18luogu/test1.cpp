#include <stdio.h>
int a[12][12]={0};//地图 
int book[12][12]={0};//标记 
int txi[25],tyi[25];
int next[4][2]={{0,1},//向右 
				{1,0},//向下 
				{0,-1},//向左 
				{-1,0}};//向上
int n,m,p,q,ans=0;//m,n为地图大小，p,q为终点
void  dfs(int x,int y)//当前状态
{
	
	int tx,ty;
	if(x==p&&y==q){//走到了终点 
		ans++;
		return;//返回上一步
	}
	for(int i=0;i<4;i++){
		tx=x+next[i][0];
		ty=y+next[i][1];
		if(tx<1||ty<1||tx>n||ty>m){
			continue; 
		}
		if(book[tx][ty]==0&&a[tx][ty]==0){//是否是障碍物或已在路径中,0代表通畅，1代表障碍 
			book[tx][ty]=1;//标记 
			dfs(tx,ty);
			book[tx][ty]=0;//消除标记 
		} 
		
	}
	return;
}
int main(){
	int sx,sy,T;
	scanf("%d %d %d",&n,&m,&T);
    scanf("%d %d %d %d",&sx,&sy,&p,&q); 
	for(int i=1;i<=T;i++){
		scanf("%d %d",&txi[i],&tyi[i]);
        a[txi[i]][tyi[i]]=1;
	}
	book[sx][sy]=1; 
	dfs(sx,sy);
	printf("%d",ans); 
	return 0 ;
}