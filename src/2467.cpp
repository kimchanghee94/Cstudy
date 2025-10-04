#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100005

int main(){
    int N,arr[MAX]; scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&arr[i]);
    int l=0,r=N-1,ansl,ansr,ans=INT_MAX;
    while(l<r){
        int val=arr[l]+arr[r];
        if(ans>abs(val)){
            ans=abs(val);
            ansl=arr[l],ansr=arr[r];
        }
        if(val<0) l++;
        else r--;
    }
    printf("%d %d",ansl,ansr);
}