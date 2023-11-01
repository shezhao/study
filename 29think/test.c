#include<stdio.h>
#define MAX 1000
typedef long long LL;
int Index(LL *mul);
void Display(int n,LL *num);
void Push(LL *mul);//核心进位制
void MulSum(int n,LL *mul,LL *num);
int main (){
    LL num[MAX]={0};
    LL mul[MAX]={0};
    mul[1]=1;//注意！！！
    printf("please input>>");
    int n=0;
    scanf("%d",&n);

    MulSum(n,mul,num);

    int index=Index(mul);//位数
    int indexNum=Index(num);

    printf("MulMax=");Display(index,mul);//打印
    
    printf("\nMulSum=");Display(indexNum,num);
    
    return 0;
}
int Index(LL *mul){
    for (int i = MAX-1; i >=1; i--)//注意MAX-1
    {
        if(mul[i]!=0)
           return i;
    } 
}
void Display(int n,LL *num){
    for (int i = n; i >=1; i--)
    {
        printf("%d",num[i]);
    }
}
void Push(LL *mul){
    for (int k  = 1; k <MAX; k++)
        {
            if(mul[k]>=10){
                mul[k+1]=mul[k+1]+mul[k]/10;
                mul[k]=mul[k]%10;
            }
        }
}
void MulSum(int n,LL *mul,LL *num){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=MAX; j++)
        {
            mul[j]*=i;
            num[j]+=mul[j];
            //Push(mul)在里面会咋样
        }
        Push(mul);//进位                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    }
    Push(num);//想想
}