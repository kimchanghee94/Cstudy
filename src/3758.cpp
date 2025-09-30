#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101
int main(void){
    int T; scanf("%d", &T);
    while(T-->0){
        int n,k,t,m; scanf("%d%d%d%d",&n,&k,&t,&m);
        int score[MAX]={0}, flag[MAX][MAX]={0}, cnt[MAX]={0}, time[MAX]={0};
        while(m-->0){
            int i,j,s; scanf("%d%d%d",&i,&j,&s);
            if(flag[i][j]<s){
                if(flag[i][j]) score[i]-=flag[i][j];
                score[i]+=s;
                flag[i][j]=s;
            }
            cnt[i]++;
            time[i]=m;
        }
        int rank=1;
        for(int i=1; i<=n; i++){
            if(i==t) continue;
            if(score[i]>score[t]) rank++;
            else if(score[i]==score[t]){
                if(cnt[i]<cnt[t]) rank++;
                else if(cnt[i]==cnt[t] && time[i]>time[t]) rank++;
            }
        }
        printf("%d\n", rank);
    }
}