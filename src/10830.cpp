#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ll long long
#define MAX 6
#define DIV 1000

void multi(ll N, ll a[MAX][MAX], ll b[MAX][MAX]){
    ll tmp[MAX][MAX]={0};
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) for(int k=0;k<N;k++) tmp[i][j]+=a[i][k]*b[k][j];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) a[i][j]=tmp[i][j]%DIV;
}

int main(){
    ll N,B,a[MAX][MAX],ans[MAX][MAX]={0}; scanf("%lld %lld",&N,&B);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) scanf("%lld",&a[i][j]);
        ans[i][i]=1;
    }
    while(B){
        if(B%2) multi(N,ans,a);
        multi(N,a,a);
        B/=2;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) printf("%lld ",ans[i][j]);
        printf("\n");
    }
}