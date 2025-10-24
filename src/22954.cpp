#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001

int N,M;
int tree,flag[MAX],leaf[MAX];
vector<int> tnode[MAX], tedge[MAX];
vector<pair<int,int>> edge[MAX];

void dfs(int s, int ti){
    flag[s]=1;
    tnode[ti].push_back(s);
    int is_leaf=0;
    for(int i=0; i<edge[s].size(); i++){
        int e=edge[s][i].first;
        int tmp_edge=edge[s][i].second;
        if(!flag[e]){
            is_leaf=1;
            tedge[ti].push_back(tmp_edge);
            dfs(e,ti);
        }
    }
    if(!is_leaf) leaf[s]=1;
}
void print(vector<int> &v){
    sort(v.begin(), v.end());
    for(int num : v) cout<<num<<" ";
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        int u,v; cin>>u>>v;
        edge[u].push_back({v,i});
        edge[v].push_back({u,i});
    }
    for(int i=1;i<=N;i++) if(!flag[i]) dfs(i,tree++);
    if(tree==1){
        int s=0,l=0;
        for(int i=1;i<=N;i++){
            if(leaf[i]) l=i;
            else s=i;
        }
        tnode[0].clear(); tedge[0].clear();
        fill(flag, flag+N+1, 0);
        flag[l]=1; tnode[1].push_back(l);
        dfs(s,0);
    }
    if(tnode[0].size()==tnode[1].size() || tree>2) cout<<"-1";
    else{
        cout<<tnode[0].size()<<" "<<tnode[1].size()<<"\n";
        print(tnode[0]);print(tedge[0]);
        print(tnode[1]);print(tedge[1]);
    }
}