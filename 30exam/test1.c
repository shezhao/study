#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Push(int *mul){
    for (int k  = 0; k <51; k++)
        {
            if(mul[k]>=10){
                mul[k+1]=mul[k+1]+mul[k]/10;
                mul[k]=mul[k]%10;
            }
        }
}
int main (){
char num1[51],num2[51];
int number1[51]={0},number2[51]={0};
int index=0;
scanf("%s",num1);
scanf("%s",num2);

for(int i=0;i<strlen(num1);i++)
    number1[strlen(num1)-i-1]=num1[i]-'0';
for(int i=0;i<strlen(num2);i++)
    number2[strlen(num2)-i-1]=num2[i]-'0';
for(int i=0;i<51;i++)
     number1[i]+=number2[i];
Push(number1);
for(int i=50;i>=0;i--)
    if(number1[i]!=0) {index=i;break;}
for(int i=index;i>=0;i--)
    printf("%d",number1[i]);

     
return 0;}
