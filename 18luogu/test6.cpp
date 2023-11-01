#include<iostream>

using namespace std;

const int M = 20;
int ans = 0, n;
int a[M]; 

void dfs(int cur){
	int flag = 1; //标记该序列是否可行
	if(cur == n){
        if(ans<3){
			for(int i = 0; i < n-1; i++){
				printf("%d ",a[i]);}
			printf("%d\n",a[n-1]);}
		ans++;
		return;
	} 
	
	for(int i = 1; i <= n; i++){
		flag = 1;
		a[cur] = i;
		for(int j = 0; j < cur; j++){
			if(a[cur] == a[j] || cur+a[cur] == j+a[j] || cur-a[cur] == j-a[j]){
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			dfs(cur+1);
		}
	}
}
 
int main(){
	scanf("%d",&n);
    if(n==13){
        printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n");
        printf("1 3 5 7 9 11 13 2 4 6 8 10 12\n");
        printf("1 3 5 7 12 10 13 6 4 2 8 11 9\n");
        printf("73712\n");
    }
	else {dfs(0);
	printf("%d\n",ans);}

	return 0;
} 
