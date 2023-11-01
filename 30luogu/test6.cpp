#include<bits/stdc++.h>
using namespace std;
int f[1009][1009]={0};
int main (){
    string str1 ,str2;
    cin>>str1>>str2;
    if(str1[0]!=str2[0])
        f[0][0]=1;
    for (int i = 1; i < str2.size(); i++)
    {
        if(str1[i]==str2[i]){
            f[i][i]=f[i-1][i-1];
        }
        else f[i][i]=f[i-1][i-1]+1;
    }
    for (int i = 1; i < str1.size(); i++)
    {
        if(str1[i]==str2[i]){
            f[i][0]=0;
        }
        else f[i][0]=f[i-1][0];
    }
    for (int j = 1; j < str2.size(); j++)
    {
        for (int i = j+1; i < str1.size(); i++)
        {
            if(str1[i]==str2[j]){
                f[i][j]=f[i-1][j-1];
            }
            else{
                f[i][j]=max(f[i-1][j],f[i-1][j-1]+1);
            }
        }
        
    }
    printf("%d",f[str1.size()-1][str2.size()-1]);
    return 0;
}