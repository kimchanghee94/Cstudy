#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K; cin>>N>>K;
    int arr[MAX*2]={0}, flag[MAX]={0};
    for(int i=0; i<N; i++) cin>>arr[i];
    int ans=0,l=0;
    for(int i=0; i<N; i++){
        int val=arr[i];
        if(++flag[val]>K) while(flag[val]>K) flag[arr[l++]]--;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}