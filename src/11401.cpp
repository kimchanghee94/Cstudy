#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long
#define DIV 1000000007
ll N,K,C,A=1,B=1;
ll pow(int m){
    if(!m) return 1;
    C=pow(m/2)%DIV;
    if(m%2==1) return C*C%DIV*B%DIV;
    else return C*C%DIV;
}

int main(){
    scanf("%lld %lld", &N,&K);
    for(int i=N;i>N-K;i--) A=A*i%DIV;
    for(int i=1;i<=K;i++) B=B*i%DIV;
    printf("%lld",A*pow(DIV-2)%DIV);
}