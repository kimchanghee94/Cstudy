#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 101
char graph[MAX][MAX];
int R,C,N,flag[MAX][MAX];
int di[]={1,0,-1,0},dj[]={0,1,0,-1};

void dfs(int si, int sj){
    for(int d=0;d<4;d++){
        int ni=si+di[d], nj=sj+dj[d];
        if(ni<0||ni>=R||nj<0||nj>=C||flag[ni][nj]||graph[ni][nj]=='.') continue;
        flag[ni][nj]=1;
        dfs(ni,nj);
    }
}

void thr(int H, int dir){
    if(dir%2==0) {
        for(int i=0;i<C;i++) {
            if(graph[R-H][i]=='x'){
                graph[R-H][i]='.';
                break;
            }
        }
    }
    else{
        for(int i=C-1;i>=0;i--){
            if(graph[R-H][i]=='x'){
                graph[R-H][i]='.';
                break;
            }
        }
    }
}

int main(){
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++) scanf("%s",graph[i]);
    scanf("%d",&N);
    for(int d=0;d<N;d++){
        int H; scanf("%d",&H);
        thr(H,d);
        for(int i=0;i<R;i++) memset(flag[i],0,sizeof(flag[i]));
        for(int i=0;i<C;i++) if(!flag[R-1][i] && graph[R-1][i]=='x') flag[R-1][i]=1, dfs(R-1,i);
        int mh=MAX;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(!flag[i][j] && graph[i][j]=='x'){
                    for(int k=i+1;k<R;k++){
                        if(flag[k][j] && graph[k][j]=='x'){
                            mh=mh<k-i-1?mh:k-i-1;
                            break;
                        }else if(k==R-1 && graph[k][j]=='.'){
                            mh=mh<k-i?mh:k-i;
                            break;
                        }
                        else if(!flag[k][j] && graph[k][j]=='x') break;
                    }
                }
            }
        }
        if(mh!=MAX){
            for(int i=R-1;i>=0;i--){
                for(int j=0;j<C;j++){
                    if(!flag[i][j] && graph[i][j]=='x'){
                        graph[i+mh][j]='x';
                        graph[i][j]='.';
                    }
                }
            }
        }
    }
    for(int i=0;i<R;i++){
        printf("%s\n",graph[i]);
    }
}