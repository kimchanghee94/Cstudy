#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 1001
int main(){
    int N,M; scanf("%d%d",&N,&M);
    int g[MAX][MAX]; int dp[2][MAX];
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d",&g[i][j]);
    dp[0][0]=dp[1][0]=g[0][0];
    for(int i=1;i<M;i++) dp[0][i]=dp[0][i-1]+g[0][i], dp[1][i]=dp[1][i-1]+g[0][i];
    for(int i=1;i<N;i++){
        dp[0][0]+=g[i][0];
        dp[1][M-1]+=g[i][M-1];
        for(int j=1;j<M;j++){
            dp[0][j]=max(dp[0][j],dp[0][j-1])+g[i][j];
            dp[1][M-j-1]=max(dp[1][M-j-1],dp[1][M-j])+g[i][M-j-1];
        }
        for(int j=0;j<M;j++) dp[0][j]=dp[1][j]=max(dp[1][j],dp[0][j]);
    }
    printf("%d",dp[1][M-1]);
}