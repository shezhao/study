#include<stdio.h>
int main(){
    char str;
    scanf("%c",&str);
    if(str>='a'&&str<='z'){ 
        str='a'+(str+5-'a')%26;;
        printf("%c",str);
      }
      else{
        str='A'+(str+5-'A')%26;;
        printf("%c",str);
      }
        

    return 0;
}