#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 1002
#define MAX_T 202
int T,N,arr[MAX];

int main(void){
    scanf("%d",&T);
    while(T-->0){
        int team[2][MAX_T],score[MAX_T][2];
        for(int i=0; i<2; i++) memset(team[i], 0, sizeof(team[i])); 
        for(int i=0; i<MAX_T; i++) memset(score[i],0,sizeof(score[i]));
        scanf("%d",&N);
        for(int i=0; i<N; i++) {
            scanf("%d",&arr[i]);
            team[0][arr[i]]++;
        }

        int rank=0;
        for(int i=0; i<N; i++){
            if(team[0][arr[i]]!=6) continue;
            rank++;
            if(team[1][arr[i]]<4) score[arr[i]][0]+=rank;
            else if(team[1][arr[i]]==4) score[arr[i]][1]=score[arr[i]][0]+rank;
            team[1][arr[i]]++;
        }

        int tot_min=6000, ans;
        for(int i=0; i<N; i++){
            if(team[0][arr[i]]!=6) continue;
            if(score[arr[i]][0]<tot_min){
                tot_min=score[arr[i]][0];
                ans=arr[i];
            }
        }

        int same=0;
        for(int i=0; i<N; i++) {
            if(score[arr[i]][0]==tot_min) same++;
            else team[0][arr[i]]=0;
        }
        if(same>1) {
            tot_min=6000;
            for(int i=0; i<N; i++){
                if(team[0][arr[i]]!=6) continue;
                if(score[arr[i]][1]<tot_min){
                    tot_min=score[arr[i]][1];
                    ans=arr[i];
                }
            }
        }
        
        printf("%d\n", ans);
    }
}