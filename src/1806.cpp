#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 100005
int main(){
    int N,S; scanf("%d%d",&N,&S);
    int ans=MAX,arr[MAX],sum=0,l=0;
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
        while(sum>=S){
            ans=min(ans,i-l+1);
            sum-=arr[l++];
        }
    }
    printf("%d",ans==MAX ? 0 : ans);
}