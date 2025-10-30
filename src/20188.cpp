#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define MAX 300001
ll N,dp[MAX],ans;
vector<int> v[MAX];

ll dfs(int s){
    dp[s]=1;
    for(int e : v[s]) if(!dp[e]) dp[s]+=dfs(e);
    ans+=((N*(N-1)/2)-((N-dp[s])*(N-dp[s]-1)/2));
    return dp[s];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0;i<N-1;i++){
        int s,e; cin>>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    dfs(1);
    cout<<ans-(N*(N-1)/2);
}