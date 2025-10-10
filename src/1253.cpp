#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 2001
int main(){
    int N,arr[MAX],ans=0; scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&arr[i]); sort(arr, arr+N);
    for(int i=0;i<N;i++){
        int l=0,r=N-1;
        while(l<r){
            int val=arr[l]+arr[r];
            if(l==i) l++;
            else if(r==i) r--;
            else if(val<arr[i]) l++;
            else if(val>arr[i]) r--;
            else if(val==arr[i]){
                ans++;
                break;
            }
        }
    }
    printf("%d",ans);
}