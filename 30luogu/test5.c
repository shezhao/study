#include<stdio.h>
typedef long long LL;
#define N 105
LL v[N]={0};
LL f[N]={0};
LL b[N]={0};
LL n,k,d;
LL max=0;
LL MAX(int a,int b){
    if(a>b)return a;
    return b;
}
void dfs(int deep,int index,LL sum){
    if(deep>k){
        if(sum%d==0){
            max=MAX(max,sum);
        }
        return ;
    }
    for (int i = 1; i <=n; i++)
    {
        if(f[i]==0){
            f[i]=1;
            sum+=v[i];
            dfs(deep+1,i+1,sum);
            sum-=v[i];
            f[i]=0;
        } 
    }
    return ;
}
LL ans=0;
void Sum(){
    for (int i = 1; i <=n; i++)
    {
       if(f[i]){
        ans+=b[i];
       }
    }
    
    
}
int main (){
    
    LL cnt=1;
    scanf("%lld %lld %lld",&n,&k,&d);
    LL a;
    for (int i = 1; i <=n; i++)
    {
        scanf("%lld",&a);
        b[i]=a; 
        v[i]=a%d;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = k*d ; j >=v[i]; j--)
    //     {
    //          f[j]=MAX(f[j],f[j-v[i]]+v[i]);
    //     }
    // }
    // if(f[m]==m) printf("Yes\n");
    // else printf("No\n");
    dfs(0,1,0);
    Sum();
    printf("%lld",ans);
    return 0;
}