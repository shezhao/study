#include<stdio.h>
typedef long long LL;
#define N 1000010
LL v[N]={0};
LL f[N]={0};
LL MAX(int a,int b){
    if(a>b)return a;
    return b;
}
int main (){
    LL n,m;
    LL cnt=1;
    scanf("%lld %lld",&n,&m);
    LL a,b;
    for (int i = 1; i <=n; i++)
    {
        scanf("%lld %lld",&a,&b);
        for (int j = 1; j <= b; j++)
        {
            v[cnt]=a;
            cnt++;
        }
        
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = m; j >=v[i]; j--)
        {
             f[j]=MAX(f[j],f[j-v[i]]+v[i]);
        }
    }
    if(f[m]==m) printf("Yes\n");
    else printf("No\n");
    


    return 0;
}