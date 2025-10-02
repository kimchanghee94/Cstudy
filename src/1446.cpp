#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10001
int graph[MAX],N,D;
vector<pair<int,int>> v[MAX];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>D;
    for(int i=0; i<N; i++){
        int s,e,d; cin>>s>>e>>d;
        v[s].push_back({e,d});
        if(s==0) if(!graph[e] || graph[e]>d) graph[e]=d;
    }
    for(int i=1; i<=D; i++){
        if(!graph[i]) graph[i]=graph[i-1]+1;
        else graph[i]=min(graph[i-1]+1,graph[i]);

        for(int j=0; j<v[i].size(); j++){
            int ni=v[i][j].first;
            int dist=v[i][j].second;
            if(!graph[ni] || graph[ni]>dist+graph[i]) graph[ni]=dist+graph[i];
        }
    }
    cout<<graph[D];
}