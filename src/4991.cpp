#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 21
#define DMAX 11

int h,w;
int di[]={1,0,-1,0}, dj[]={0,1,0,-1};
int flag[MAX][MAX],pos[DMAX][2],dest[DMAX],dist[DMAX][DMAX];
char graph[MAX][MAX];
queue<pair<int,int>> q;

void bfs(int s){
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) flag[i][j]=0;
    flag[pos[s][0]][pos[s][1]]=1;
    q.push({pos[s][0],pos[s][1]});
    while(!q.empty()){
        auto [fi,fj]=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            int ni=fi+di[d],nj=fj+dj[d];
            if(ni<0||ni>=h||nj<0||nj>=w||graph[ni][nj]=='x'||flag[ni][nj]) continue;
            flag[ni][nj]=flag[fi][fj]+1;
            q.push({ni,nj});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(1){
        cin>>w>>h;
        int dcnt=0,ans=MAX*MAX*DMAX;
        if(!w&&!h) break;
        for(int i=0;i<h;i++) for(int j=0;j<w;j++){
            cin>>graph[i][j];
            if(graph[i][j]=='o') pos[0][0]=i,pos[0][1]=j;
            else if(graph[i][j]=='*') pos[++dcnt][0]=i,pos[dcnt][1]=j;
        }
        for(int i=0;i<dcnt;i++){
            bfs(i);
            for(int d=i+1;d<=dcnt;d++){
                dist[i][d]=flag[pos[d][0]][pos[d][1]]-1;
                dist[d][i]=flag[pos[d][0]][pos[d][1]]-1;
            }
        }
        for(int i=0;i<dcnt;i++) dest[i]=i+1;
        int chk=0;
        do{
            int tmp_ans=0,s=0;
            for(int i=0;i<dcnt && !chk;i++){
                if(dist[s][dest[i]]==-1) chk=1;
                tmp_ans+=dist[s][dest[i]];
                s=dest[i];
            }
            ans=min(ans,tmp_ans);
        }while(next_permutation(dest,dest+dcnt) && !chk);
        if(!chk) cout<<ans<<"\n";
        else cout<<"-1\n";
    }
}