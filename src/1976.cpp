#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 201
vector<int> v[MAX];
int flag[MAX];

bool dfs(int s, int e){
    if(flag[s]==1) return false;
    if(s==e) return true;
    flag[s]=1;
    for(int i=0; i<v[s].size(); i++){
        int n=v[s][i];
        if(dfs(n,e)) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M; cin>>N>>M;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
        int val; cin>>val;
        if(val) v[i].push_back(j);
    }

    int s; cin>>s;
    for(int i=1; i<M; i++){
        int e; cin>>e;
        fill(flag, flag+MAX, 0);
        if(!dfs(s,e)) {
            cout<<"NO";
            return 0;
        }
        s=e;
    }
    cout<<"YES";
}