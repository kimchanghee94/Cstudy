#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 502

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int H,W,arr[MAX]; cin>>H>>W;
    for(int i=0;i<W;i++) cin>>arr[i];
    int l=0,r=W-1,lH=arr[l],rH=arr[r],ans=0;
    while(l<r){
        if(lH<rH){
            ans+=lH-arr[l++];
            lH=max(lH,arr[l]);
        }else{
            ans+=rH-arr[r--];
            rH=max(rH,arr[r]);
        }
    }
    cout<<ans;
}