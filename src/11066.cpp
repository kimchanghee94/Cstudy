#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 505
#define INF 500000004
int sum[MAX],dp[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T; cin>>T;
    while(T--){
        int K; cin>>K;
        for(int i=1;i<=K; i++){
            cin>>sum[i];
            sum[i]+=sum[i-1];
        }
        for(int i=1;i<=K;i++){
            for(int j=1;j<=K-i;j++){
                dp[j][i+j]=INF;
                for(int k=j;k<i+j;k++) dp[j][i+j]=min(dp[j][i+j], dp[j][k]+dp[k+1][i+j]+sum[i+j]-sum[j-1]);
            }
        }
        cout<<dp[1][K]<<"\n";
    }
}