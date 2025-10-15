#include <iostream>
#include <deque>
using namespace std;

#define MAX 1001

int R,C;
int di[]={1,0,-1,0}, dj[]={0,1,0,-1};
char graph[MAX][MAX];
deque<pair<int,int>> q;


void bfs(){
    int ans=1;
    while(!q.empty()){
        int q_size=q.size();
        for(int i=0; i<q_size; i++){
            auto [fi,fj]=q.front();
            q.pop_front();

            for(int d=0;d<4;d++){
                int ni=fi+di[d];
                int nj=fj+dj[d];
                if(ni<0 || ni>=R || nj<0 || nj>=C){
                    if(graph[fi][fj]=='J'){
                        cout<<ans;
                        return;
                    }else continue;
                }
                if(graph[ni][nj]!='.') continue;
                graph[ni][nj]=graph[fi][fj];
                q.push_back({ni,nj});
            }
        }
        ans++;
    }
    cout<<"IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>R>>C;
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
        cin>>graph[i][j];
        if(graph[i][j]=='J') q.push_back({i,j});
        else if(graph[i][j]=='F') q.push_front({i,j});
    }
    bfs();
}