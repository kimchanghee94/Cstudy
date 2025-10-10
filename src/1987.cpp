#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 21
int R,C,ans,flag[MAX][MAX];
int di[]={1,0,-1,0},dj[]={0,1,0,-1};
char graph[MAX][MAX];

void dfs(int si, int sj, int cnt, int bitmask){
    bitmask |= 1<<(graph[si][sj]-'A');
    if(flag[si][sj]==bitmask) return;
    
    ans=cnt>ans?cnt:ans;
    flag[si][sj]=bitmask;
    for(int d=0;d<4;d++){
        int ni=si+di[d],nj=sj+dj[d];
        if(ni<0||nj<0||ni>=R||nj>=C||bitmask&1<<(graph[ni][nj]-'A')) continue;
        dfs(ni,nj,cnt+1,bitmask);
    }
}

int main(){
    scanf("%d%d",&R,&C);
    for(int i=0; i<R; i++) scanf("%s",graph[i]);
    dfs(0,0,1,0);
    printf("%d",ans);
}