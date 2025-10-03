#include <iostream>
#include <queue>
using namespace std;

#define MAX 100005
int graph[MAX],N,K;
queue<int> q;
int di[]={1,-1,0},dj[]={1,1,2};

int bfs(){
    q.push(N);
    graph[N]=1;

    while(!q.empty()){
        int fi=q.front();
        q.pop();
        if(fi==K) break;
        for(int d=0;d<3;d++){
            int ni=fi*dj[d]+di[d];
            if(ni<0 || ni>=MAX || (graph[ni] && graph[ni]<=graph[fi])) continue;
            if(d==2) graph[ni]=graph[fi];
            else graph[ni]=graph[fi]+1;
            q.push(ni);
        }
    }
    return graph[K]-1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    cout<<bfs();
}