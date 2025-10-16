#include <iostream>
#include <stack>
using namespace std;
#define MAX 100001

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin>>N;
    int arr[MAX],dp[2][MAX]={0};
    stack<int> s;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        while(!s.empty() && arr[s.top()]<=arr[i]) s.pop();
        dp[0][i]=s.size();
        if(!s.empty()) dp[1][i]=s.top()+1;
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=N-1; i>=0; i--){
        while(!s.empty() && arr[s.top()]<=arr[i]) s.pop();
        dp[0][i]+=s.size();
        if(!s.empty()) if(!dp[1][i] || i+1-dp[1][i]>s.top()-i) dp[1][i]=s.top()+1;
        s.push(i);
    }
    for(int i=0; i<N; i++){
        if(dp[0][i]) cout<<dp[0][i]<<" "<<dp[1][i]<<"\n";
        else cout<<"0"<<"\n";
    }
}