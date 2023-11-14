#include<stdio.h>
typedef
long long ll;
ll inv[10000000]={0};
int main (){
    ll a=0,p=0;
    
    scanf("%lld %lld",&a,&p);
    inv[1]=1;
    printf("1\n");
    for (int i = 2; i <=a; i++)
    {
        inv[i]=(p-p/i)*inv[p%i]%p;
        printf("%lld\n",inv[i]);
    }
    return 0;
}