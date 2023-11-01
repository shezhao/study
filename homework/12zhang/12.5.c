#include<stdio.h>
#include<stdlib.h>
typedef struct card{
    char*Color;
    char*face;

  }card;
int main(){
     card num[52];
 
     char*hua[]={"redTao","balTao","fanPia","meiHua"};
     char*fac[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    printf("初始牌堆\n");
     for(int i=0;i<52;i++){
        num[i].Color=hua[i/13];
        num[i].face=fac[i%13];
        
        printf("%s\t%s\n",num[i].Color,num[i].face);
     }
     card temp;
     
     for(int i=0;i<52;i++){
        int  j=rand()%52;
        temp=num[i];
        num[i]=num[j];
        num[j]=temp;
     }
     printf("洗牌后>>\n");
     for(int i=0;i<52;i++){
        printf("%s\t%s\n",num[i].Color,num[i].face);
     }
     return 0;
 }