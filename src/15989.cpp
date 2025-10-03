#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10005
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int val;scanf("%d",&val);
        int dp[MAX][3]={0};
        dp[1][0]=1,dp[2][0]=1,dp[2][1]=1,dp[3][0]=1,dp[3][1]=1,dp[3][2]=1;
        for(int i=4;i<=val;i++) {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-2][0]+dp[i-2][1];
            dp[i][2]=dp[i-3][0]+dp[i-3][1]+dp[i-3][2];
        }
        printf("%d\n",dp[val][0]+dp[val][1]+dp[val][2]);
    }
}