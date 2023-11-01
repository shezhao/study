/*10.1改为
while(*srcStr!='\0){
    *dstStr=*srcStr;
    dstStr++;
    srcStr++;
}*/
//10.2
#include<stdio.h>
main(){char*a="main(){char*a=%c%s%c;printf(a,34,a,34);})";printf(a,34,a,34);}
/*
char *a="main(){char*a=;printf(a,34,a,34);})
%c=34转成字符'"'
*/

/*10.3
(1) 1.'\0' 2.++ 3.len
(2) 1.'\0' 2.p-s
(3) 1.0    2.*p1-*p2
(4) 1'\0'  2.s[i]-t[i]
(5) 1.strcmp(userInput,password) == 0 2.strcmp(userInput,password)<0
*/
