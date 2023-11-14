#include<stdio.h>
long long a,b,p;
typedef long long LL;
LL Mul(LL b){
    LL base=a;
    LL ans=1;
    while(b>0){
        if(b&1){
            
            ans*=base;
            ans%=p;
        }
        ans*=(b%p);
        base*=base;
        base%=p;
        b>>1;
    }
}


int main(){
    
    scanf("%lld %lld %lld",&a,&b,&p);
    LL ans;
    ans=Mul(b);
    printf("%lld^%lld mod %lld=%lld",a,b,p,ans);




    return 0;
}