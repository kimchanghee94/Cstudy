#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    int ans=1, strt=1;
    while(strt<N) strt+=((ans++)*6);
    printf("%d", ans);
}