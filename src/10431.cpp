#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 20

int main(void){
    int P; scanf("%d", &P);

    while(P-->0){
        int ans=0;
        int arr[MAX];
        int cur;
        scanf("%d", &cur);
        for(int i=0; i<MAX; i++) scanf("%d", &arr[i]);
        for(int i=0; i<MAX; i++)for(int j=0; j<i; j++) if(arr[j]>arr[i]) ans++;
        printf("%d %d\n", cur, ans);
    }
}