#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1002

int main(void){
    int N,K,C,arr[MAX][3],ans=1;
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &C);
        scanf("%d%d%d",&arr[C][0],&arr[C][1],&arr[C][2]);
    }
    for(int i=1; i<=N; i++) {
        if(i==K) continue;
        if(arr[i][0] > arr[K][0]) ans++;
        else if(arr[i][0]==arr[K][0]){
            if(arr[i][1]>arr[K][1]) ans++;
            else if(arr[i][1]==arr[K][1] && arr[i][2]>arr[K][2]) ans++;
        }
    }
    printf("%d", ans);
}