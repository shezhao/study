
#include<bits/stdc++.h>

using namespace std;
 
 
int dp[8];
int n;
 
char str[10];
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i < 8; i++) {
		dp[i] = 1e9;
	}
	while(n--) {
		int s;
		scanf("%d %s", &s, str);
		int m = 0;
		for(int i = 0; i < strlen(str); i++) {
			m |= 1 << (str[i] - 'A');
		}
		for(int i = 0; i < 8; i++) {
			dp[i|m] = min(dp[i|m], dp[i] + s);
		}
	}
	if(dp[7] == 1e9) dp[7] = -1;
	printf("%d\n", dp[7]);
    return 0;
}
