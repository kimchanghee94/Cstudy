#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX 501

int arr[MAX][2],dp[MAX][MAX];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i][0]>>arr[i][1];
    for(int i=1;i<N;i++){
        for(int j=1;j<=N-i;j++){
            dp[j][j+i]=INT_MAX;
            for(int k=j;k<i+j;k++){
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][i+j]+arr[j][0]*arr[k][1]*arr[i+j][1]);
            }
        }
    }
    cout<<dp[1][N];
}