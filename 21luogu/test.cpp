#include<bits/stdc++.h>
using namespace std;
int main (){
    int k;
    int ans=0;
    scanf("%d",&k);
    for (int m=k+1; ans==0 ; m++)
    {
       int out=0,sum=2*k,dis;
       while(sum>k){
        dis=m%sum-1;
        out=(out+dis+sum)%sum;
        if(out>=k&&out<2*k){
            sum--;
        }
        else break;
        if(sum==k){
            ans=m;
        }
       }
    }
    
    
    printf("%d",ans);

    return 0;
}