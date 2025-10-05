#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
char ov[10], oper[]={' ','+','-'};

void dfs(int cnt, int s, int d){
    if(cnt==N){
        if(!(s+d)){
            printf("1");
            for(int i=0;i<N-1;i++) printf("%c%d",ov[i],i+2);
            puts("");
        }
    }else{
        for(int i=0; i<3; i++){
            ov[cnt-1]=oper[i];
            if(i==0){
                if(d>0) dfs(cnt+1, s, d*10+cnt+1);
                else dfs(cnt+1, s, d*10-cnt-1);
            }else if(i==1) dfs(cnt+1, s+d, cnt+1);
            else dfs(cnt+1, s+d, -cnt-1);
        }
    }
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&N); dfs(1,0,1);
        puts("");
    }
}