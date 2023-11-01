#include<bits/stdc++.h>
using namespace std;
int num[1100][1100]={0};
void f(int n,int x,int y){
    if(n==2){
        num[x][y]=0;
        return ;
    }
    for (int i = x; i <=x+n/2-1; i++)
    {
        for (int j = y; j <=y+n/2-1; j++)
        {
            num[i][j]=0;
        }
        
    }
    f(n/2,x+n/2,y);
    f(n/2,x+n/2,y+n/2);
    f(n/2,x,y+n/2);


}
int main (){
    int n;
    scanf("%d",&n);
    int s=(int)pow(2.0,n*1.0);
    
    for (int i = 1; i <=s; i++)
    {
        for (int j = 1; j <=s; j++)
        {
             num[i][j]=1;
        }
    }
    f(s,1,1);
    for (int i = 1; i <=s; i++)
    {
        for (int j = 1; j <=s; j++)
        {
             printf("%d",num[i][j]);
             if(j!=s) printf(" ");
        }
        printf("\n");
    }
    

    
    return 0;
}