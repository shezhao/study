// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// int main(){
//     float a;
//     float *p=NULL;
//     scanf("%f",&a);
//     p=&a;
//     printf("%f\n",*p);
//     return 0;
// }
 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *getMemory(char *p,int num){
    p=(char*)malloc(sizeof(char)*num);
    return p;
}
int main(){
   char *str=NULL;
   str=getMemory(str,20);
   //str=(char*)malloc(sizeof(char)*20);
   strcpy(str,"Hello World");
   printf("%s",str);
  
   free(str);
   str=NULL;
    return 0;
}