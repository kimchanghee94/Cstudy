#include <iostream>
#include <vector>
using namespace std;
#define MAX 101
int arr[MAX],flag[MAX];
vector<int> v;

void dfs(int s, int e){
    if(flag[e]){
        if(s==e) v.push_back(s);
    }
    else{
        flag[e]=1;
        dfs(s,arr[e]);
        flag[e]=0;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];
    for(int i=1;i<=N;i++) dfs(i,i);
    cout<<v.size()<<"\n";
    for(auto &val:v) cout<<val<<"\n";
}