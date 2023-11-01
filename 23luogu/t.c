#include<stdio.h>
int main (){
    int x=2;
    int y=3;
    int a,b;
    scanf("%d %d",&x,&y);
    a=x;b=y;
    if(x>y)
    {x=y;y=x;}
    else
    {x++;y++;}
    if(a>b)
    {a=b,b=a;}
    else
    {a++,b++;}
    printf("%d %d\n",x,y);
    printf("%d %d",a,b);
    return 0;
}
