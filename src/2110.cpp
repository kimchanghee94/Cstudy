#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 200001
int main(){
    int N,C; scanf("%d %d",&N,&C);
    int arr[MAX]; for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    sort(arr,arr+N);
    int s=1,e=arr[N-1]-arr[0],ans=0;

    while(s<=e){
        int mid=(s+e)/2;
        int bef=arr[0];
        int cnt=1;
        for(int i=1;i<N;i++){
            if(arr[i]-bef>=mid){
                bef=arr[i];
                cnt++;
            }
        }
        if(cnt>=C){
            ans=max(ans,mid);
            s=mid+1;
        }else e=mid-1;
    }
    printf("%d",ans);
}