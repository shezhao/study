
#include<bits/stdc++.h>
using namespace std;
int n;
int num[10]={0};
int sum=0;
void dfs(int deep,int start){
        if(deep>n){return;}
        if(sum==n){
            for (int i = 0; i <deep; i++)
            {
                printf("%d",num[i]);
                if(i<deep-1)printf("+");
            }
            printf("\n");return; 
        }
        
    for (int i = start; i< n; i++)
    {
        num[deep]=i;
        sum+=num[deep];
        dfs(deep+1,i);
        sum-=num[deep];
    }
    return;
}
int main (){
    scanf("%d",&n);
    dfs(0,1);
    return 0;
}