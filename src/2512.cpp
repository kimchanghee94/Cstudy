#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 10005
int N,M,arr[MAX],ans;
int low,high;

bool check(int mid){
    int sum=0;
    for(int i=0; i<N; i++) sum+=min(arr[i],mid);
    return sum <= M;
}

int main(void){
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&arr[i]);
        high=max(high, arr[i]);
    }
    scanf("%d",&M);
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid)){
            low=mid+1;
            ans=mid;
        }else high=mid-1;
    }
    printf("%d",ans);
}