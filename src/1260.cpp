#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> vec;
vector<int> flag;
int N,M,V;

void dfs(int strt){
    flag[strt]=1;
    cout<<strt<<" ";
    for(int i=0;i<vec[strt].size();i++){
        int next=vec[strt][i];
        if(flag[next]) continue;
        dfs(next);
    }
}

void bfs(){
    fill(flag.begin(), flag.end(), 0);
    queue<int> q;
    q.push(V);
    flag[V]=1;

    while(!q.empty()){
        int first=q.front();
        cout<<first<<" ";
        q.pop();

        for(int j=0; j<vec[first].size(); j++){
            int next=vec[first][j];
            if(flag[next]) continue;
            flag[next]=1;
            q.push(next);
        }
    }
}

int main(){
    cin>>N>>M>>V;
    vec.resize(N+1); flag.resize(N+1);
    for(int i=0;i<M;i++){
        int s,e;cin>>s>>e;
        vec[s].push_back(e); vec[e].push_back(s);
    }
    for(int i=1; i<=N; i++) sort(vec[i].begin(), vec[i].end());
    dfs(V); cout<<"\n";
    bfs();
}