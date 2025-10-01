#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10
int main(){
    int N,arr[MAX]={0}; scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        int val; scanf("%d",&val);
        for(int j=0;j<N;j++) {
            if(!arr[j] && !(val--)) {
                arr[j]=i;
                break;
            }
        }
    }
    for(int i=0; i<N; i++) printf("%d ",arr[i]);
}