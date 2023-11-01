#include<bits/stdc++.h>
using namespace std;
int num[10000]={0};
int t[10000]={0};
int main (){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }
    int max=0,ans=0;
    int m1,m2;
    for (int i = 0; i < n-1; i++)
    {
        if(num[i+1]<=num[i]) {ans++;t[ans]=i+1;} 
    }
    for (int i = 1; i <=ans; i++)
    {
        m1=num[t[i]-1]-num[t[i-1]];
        max=m1>max?m1:max;
    }
    m2=num[n-1]-num[t[ans]];
     max=m2>max?m2:max;
    printf("%d\n",max);
    return 0;
}