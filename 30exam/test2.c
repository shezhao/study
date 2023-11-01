#include<stdio.h>
void ZH(int *ans){
    int m=4;
    while(m){
    for (int i = 1; i < 4; i++)
    {
        if(ans[i]<0){
            ans[i-1]=ans[i-1]-1;
            ans[i]=ans[i]+10;
        }
    }
    m--;
    }
}
int  Sum(int *num){
    int sum=0;
    sum=num[0]*1000+num[1]*100+num[2]*10+num[3];
    return sum;
}
int  Num(int n,int *num){
    num[0]=n/1000;
    num[1]=(n-(n/1000)*1000)/100;
    num[2]=(n%100-n%10)/10;
    num[3]=n%10;
}
void Greater(int *num){
    int temp=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(num[j]>num[j+1]){
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }  
    }
}
void Lower(int *num){
    int temp=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(num[j]<num[j+1]){
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }  
    }
}
void Push(int *num,int *num2,int *ans){
    for (int i = 0; i < 4; i++)
    {
        ans[i]=num[i]-num2[i];
    }
    ZH(ans);
    ZH(num);
    ZH(num2);
    
}
int main (){
    char str[6];
    int num[4]={0};
    int num2[4]={0};
    int ans[4]={0};
    scanf("%s",str);
    for (int i = 0; i <4; i++)
    {
        ans[i]=str[i]-'0';
        num[i]=num2[i]=ans[i];
    }
    int tot=0;
    while(Sum(ans)!=6174){
        tot++;
        Lower(num);
        Greater(num2);
        Push(num,num2,ans);
        printf("[%d]:%d-%d=%d\n",tot,Sum(num),Sum(num2),Sum(ans));
        for (int i = 0; i <4; i++)
        {
            num[i]=ans[i];
            num2[i]=ans[i];
        }
    }
    return 0;
}