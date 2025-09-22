#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 100005
int N, dist[MAX],price[MAX];

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N-1; i++) scanf("%d",&dist[i]);
    for(int i=0; i<N; i++) scanf("%d", &price[i]);
    long long ans=0;
    int price_min=price[0];
    for(int i=0; i<N-1; i++) {
        price_min=min(price_min, price[i]);
        ans+=(long long)price_min*dist[i];
    }
    printf("%lld",ans);
}