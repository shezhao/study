
#include<bits/stdc++.h>
using namespace std;
long long num[300]={0};
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for (int i = 1; i <=n; i++)
    {
        scanf("%lld",&num[i]);
    }
    long long ans=0;
    long long max=0;
    sort(num+1,num+1+n);
    for (int i = 1; i <=n; i++)
    {
        if(num[i]==num[i-1]){continue;}
        for (int j = i; j <=n; j++)
        {
            if(num[j]>=num[i]+m){
                break;
            }
            ans++;
        }
        max=ans>max?ans:max;
        ans=0;
    }
    printf("%lld",max);
    return 0;
}