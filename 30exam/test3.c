#include<stdio.h>
#include<string.h>

int main(){
    char str1[100];
    char str2[100];
    int ans=0;
    int flag=0;
    gets(str1);
    gets(str2);
    for (int i = 0; i < strlen(str1); i++)
    {
        if(str1[i]==str2[0]){
            for (int j = 0; j < strlen(str2); j++)
            {
                if(str1[i+j]==str2[j]) ans++;
            }
            if(ans==strlen(str2)){
                printf("Yes\n");
                flag=1;
                break;
            }
            else{
                continue;
            }
        }
    }
    if(!flag){
        printf("No\n");
    }
    return 0;
}