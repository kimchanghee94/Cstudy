#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1001

int main(){
    int N, graph[MAX]={0};scanf("%d",&N);
    for(int i=0; i<N; i++) {
        int idx,height; scanf("%d%d",&idx,&height);
        graph[idx]=height;
    }
    int l=0,r=MAX-1,ans=0;
    while(!graph[l]) l++; while(!graph[r]) r--;
    int lH=graph[l],rH=graph[r];
    while(l<r){
        if(lH<rH) {
            ans+=lH;
            lH=max(lH,graph[++l]);
        }
        else {
            ans+=rH;
            rH=max(rH,graph[--r]);
        }
    }
    printf("%d", ans+lH);
}