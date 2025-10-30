#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K; cin>>N>>K;
    int dp[MAX]={0};
    for(int i=0;i<N;i++){
        int W,V; cin>>W>>V;
        for(int j=K;j>=W;j--) dp[j]=max(dp[j],dp[j-W]+V);
    }
    cout<<dp[K];
}