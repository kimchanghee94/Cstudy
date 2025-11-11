#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ll long long
#define DIV 1000000

void mul(ll a[2][2], ll b[2][2]){
    ll tmp[2][2]={0};
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) tmp[i][j]+=a[i][k]*b[k][j];
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]=tmp[i][j]%DIV;
}

int main(){
    ll n; scanf("%lld",&n);
    ll ans[2][2]={{1,0},{0,1}}, a[2][2]={{1,1},{1,0}};
    while(n){
        if(n%2) mul(ans,a);
        mul(a,a);
        n/=2;
    }
    printf("%lld",ans[0][1]);
}