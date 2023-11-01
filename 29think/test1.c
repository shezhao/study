// #include<stdio.h>
// #define MAX 100
// int main(){
//     int num[MAX]={0};
//     num[3]=1;
//     int n=0;
//     scanf("%d",&n);
//     for (int i = 4; i <=n; i++)
//     {
//         num[i]=num[i-1]+num[i-2]+num[i-3];
//     }
//     long long sum=0;
//     for (int i = 1; i <=n; i++)
//     {
//         sum+=num[i];
//     }
//     printf("%lld\n",sum);
//     return 0;
// }
#include <stdio.h>
int main (){
    int a=0,b=0,c=1;
    int sum=1;
    int d=0;
    int n=0;
    scanf("%d",&n);
    if(n<=2){
        sum=0;
    }
    else{
        for (int i = 1; i <=n-3; i++)
        {
            d=a+b+c;
            sum+=d;
            a=b;
            b=c;
            c=d;
        }
    }
    printf("%d",sum);
    return 0;
}