#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 52

int main(void){
    int N, arr[MAX][2];
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d%d",&arr[i][0],&arr[i][1]);
    for(int i=0; i<N; i++){
        int ans=1;
        for(int j=0; j<N; j++){
            if(i==j) continue;
            if(arr[i][0]<arr[j][0] && arr[i][1]<arr[j][1]) ans++;
        }
        printf("%d ", ans);
    }
}