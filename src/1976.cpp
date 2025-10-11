#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 201
int p[MAX];
int find(int s){return p[s]==s ? s : p[s]=find(p[s]);}
void unite(int s, int e){p[find(s)]=find(e);}
int main(){
    int N,M; scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) p[i]=i;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
        int val; scanf("%d",&val);
        if(val) unite(i,j);
    }
    int s; scanf("%d",&s);
    for(int i=1;i<M;i++){
        int e; scanf("%d",&e);
        if(find(s)!=find(e)){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}