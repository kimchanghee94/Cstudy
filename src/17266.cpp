#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int N,M,pos;

int main(void){
    int ans=0;
    scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++) {
        int tmp=pos;
        scanf("%d", &pos);
        if(i==0) ans=pos-tmp;
        else ans=max(ans, (pos-tmp)/2 + (pos-tmp)%2);
    }
    ans=max(ans,N-pos);
    printf("%d",ans);
}