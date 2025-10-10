#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100001
int main(){
    int N; scanf("%d",&N);
    int arr[MAX],flag[MAX]={0};
    int l=0;
    long ans=0;
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
        flag[arr[i]]++;

        while(flag[arr[i]]==2) {
            ans+=i-l;
            flag[arr[l++]]--;
        }

        if(i==N-1){
            long val=i-l+1;
            ans+=(val*(val+1))/2;
        }
    }
    printf("%lld",ans);
}