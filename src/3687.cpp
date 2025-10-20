#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    long long dp[MAX];
    fill(dp,dp+MAX,888888888888888);
    dp[2]=1,dp[3]=7,dp[4]=4,dp[5]=2,dp[6]=6,dp[7]=8;

    for(int i=8;i<MAX;i++) for(int j=2;j<8;j++)
    dp[i]=min(dp[i],dp[i-j]*10+(j==6?0:dp[j]));

    while(T--){
        int n; cin>>n;
        cout<<dp[n]<<" ";
        if(n%2) cout<<"7", n-=3;
        for(int i=0;i<n/2;i++) cout<<"1";
        cout<<"\n";
    }
}