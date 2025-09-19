#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1005

int main(void){
    int N; scanf("%d", &N);
    int dp[MAX];
    dp[1]=0,dp[2]=1,dp[3]=0,dp[4]=1;
    for(int i=5; i<=N; i++) dp[i]=(dp[i-1] || dp[i-3]) ? 0:1;
    printf("%s", dp[N] ? "CY" : "SK");
}