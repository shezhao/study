// #include<stdio.h>
// #include<stdlib.h>
// typedef long long LL;
// LL n,p;
// int main() {
//     FILE *fp=NULL;
//     if((fp=fopen("number.txt","w"))==NULL){
//         printf("no open");
//         exit(0);
//     }
//     int ans=0;
//     scanf("%lld %lld",&n,&p);
//     for (LL i = 1; i <=n; i++)
//     {
//         for (LL j = 1; j <p; j++)
//         {
//             if(((i%p)*(j%p))%p==1){
//                 fprintf(fp,"%8lld",j);
//                 if(ans>100){
//                      printf("\n");
//                      ans=0;
//                 }
//                 ans++;
//                 break;
//             }
           
//         }
//     }
//     fclose(fp);
//     return 0;
// }
// #include<iostream>
// typedef long long ll;
// void Exgcd(ll a, ll b, ll *x, ll *y) {
//     if (!b) *x = 1, *y = 0;
//     else {
//         Exgcd(b, a % b, y, x);
//         *y -= a / b * *x;
//         }
// }
// int main() {
//     ll x, y;
//     ll p,a;
//     std::cin>>a>>p;
//     for (int i = 1; i <=a; i++)
//     {
//         Exgcd (i, p, &x, &y);
//         x = (x % p + p) % p;
//         printf ("%d\n", x); //x是a在mod p下的逆元
//     }
    
    
// }
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
    

   