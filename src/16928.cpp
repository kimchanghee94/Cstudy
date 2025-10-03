#include <iostream>
#include <queue>
using namespace std;
#define MAX 100

queue<int> q;
int N,M,board[MAX],flag[MAX];

int bfs(){
    q.push(0);
    flag[0]=1;
    while(!q.empty()){
        int fi=q.front();
        q.pop();
        if(fi==MAX-1) break;

        for(int i=1;i<=6;i++){
            int ni=fi+i;
            if(ni>=MAX || flag[ni]) continue;
            flag[ni]=flag[fi]+1;
            if(!board[ni]) q.push(ni);
            else if(!flag[board[ni]]){
                flag[board[ni]]=flag[ni];
                q.push(board[ni]);
            }
        }
    }
    return flag[MAX-1]-1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    while(N--){
        int x,y; cin>>x>>y;
        board[x-1]=y-1;
    }
    while(M--){
        int u,v; cin>>u>>v;
        board[u-1]=v-1;
    }
    cout<<bfs();
}