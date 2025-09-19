#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int H,W,N,M;
    scanf("%d %d %d %d",&H,&W,&N,&M);
    int ans=0;
    for(int i=0; i<H; i+=(N+1)) for(int j=0; j<W; j+=(M+1)) ans++;
    printf("%d", ans);
}