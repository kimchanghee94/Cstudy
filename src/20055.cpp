#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 202

int main(){
    int N,K,belt[MAX]={0},robot[MAX]={0}; scanf("%d%d",&N,&K);
    for(int i=0; i<2*N; i++) scanf("%d",&belt[i]);
    int s=0,e=N-1,cnt=0,ans=0;
    
    while(cnt<K){
        if(--s==-1) s=2*N-1;
        if(--e==-1) e=2*N-1;

        if(robot[e]) robot[e]=0;

        int de=e;
        for(int i=0;i<N-1;i++){
            int ne=de==0?2*N-1:de-1;
            if(robot[ne] && !robot[de] && belt[de]){
                belt[de]--;
                if(!belt[de]) cnt++;
                if(de!=e) robot[de]=1;
                robot[ne]=0;
            }
            if(--de==-1) de=2*N-1;
        }

        if(belt[s]>0) {
            if(!(--belt[s])) cnt++;
            robot[s]=1;
        }

        ans++;
    }
    printf("%d",ans);
}