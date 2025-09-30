#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 6
int graph[MAX][MAX], N, M;
int ans=600;

void dfs(int val, int i, int j,int bd){
    if(i==N-1) ans=val+graph[i][j]<ans?val+graph[i][j]:ans;
    else{
        for(int d=-1;d<2;d++){
            if(d==bd || j+d<0 || j+d>=M) continue;
            dfs(val+graph[i][j], i+1, j+d, d);
        }
    }
}

int main(void){
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d",&graph[i][j]);
    for(int i=0; i<M; i++) dfs(0, 0, i, -2);
    printf("%d",ans);
}