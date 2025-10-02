#include <iostream>
#include <queue>
using namespace std;
#define MAX 100005
int di[]={1,-1,0}, dj[]={1,1,2};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K; cin>>N>>K;
    int graph[MAX]={0};
    graph[N]=1;
    queue<int> q; q.push(N);
    while(!q.empty()){
        int fi=q.front();
        if(fi==K) break;
        q.pop();

        for(int d=0; d<3; d++){
            int ni=fi*dj[d]+di[d];
            if(ni<0 || ni>=MAX || graph[ni]) continue;
            graph[ni]=graph[fi]+1;
            q.push(ni);
        }
    }
    cout<<graph[K]-1;
}