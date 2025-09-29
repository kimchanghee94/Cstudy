#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20005

int main(void){
    char arr[MAX];
    int N,K,ans=0; scanf("%d%d%s",&N,&K,arr);
    for(int i=0; i<N; i++){
        if(arr[i]=='H'){
            for(int j=i-K; j<=i+K; j++){
                if(j<0||j>=N) continue;
                if(arr[j]=='P'){
                    arr[j]='X';
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d", ans);
}