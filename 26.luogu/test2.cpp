#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int num[2][MAX]={0};
int main (){
    int n;
    scanf("%d",&n);
    while(n--){
        for (int i = 0; i < 100; i++)
        {
            num[0][i]=100;
            num[1][i]=0;
        }
        int m;
        scanf("%d",&m);
        for (int i = 0; i <MAX; i++)
        {
            scanf("%d",&num[0][i]);
        }
        for (int i = 0; i <m; i++)
        {
            scanf("%d",&num[1][i]);
        }
        sort(num[0],num[0]+m,greater<int>());
        sort(num[1],num[1]+m,greater<int>());
        int k=m;
        int ans=0;
        int j=0;
        do{
        long long sum1=0,sum2=0;
        for (int i = 0; i <k-(k/4); i++)
        {
            sum1+=num[0][i];
            sum2+=num[1][i];
            
        } 
        if(sum1>=sum2){
            ans=k-m;
            break;
        }      
        k++;
        j++;
        sort(num[0],num[0]+m+j,greater<int>());
        sort(num[1],num[1]+m+j,greater<int>());
        }while(1);
        printf("%d\n",ans);
    }
    return 0;
}