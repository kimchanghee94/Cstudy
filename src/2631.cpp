#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 201
int main(){
    int N,arr[MAX]; scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&arr[i]);
    int dp[MAX]={0}, ans=0;
    for(int i=1; i<N; i++){
        for(int j=0;j<i; j++){
            if(arr[j]<arr[i]) {
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }
    }
    printf("%d",N-(ans+1));
}