#include<stdio.h>
int main (){
    int n;
    scanf("%d",&n);
    for (int i =n; i <=919; i++)
    {
        if((i/100)*((i-(i/100)*100)/10)==i%10){
            printf("%d",i);
            break;
        }
    }
    



    return 0;
}