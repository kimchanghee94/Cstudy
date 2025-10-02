#include <iostream>
#include <algorithm>
using namespace std;
#define N_MAX 30001
#define K_MAX 3001
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,d,k,c; cin>>N>>d>>k>>c;
    int arr[N_MAX+K_MAX], flag[K_MAX];
    for(int i=0; i<N; i++) cin>>arr[i];
    for(int i=0; i<k-1; i++) arr[i+N]=arr[i];
    int cnt=0, ans=0;
    for(int i=0; i<k; i++) if(!flag[arr[i]]++) cnt++;
    ans=max(ans, !flag[c]?cnt+1:cnt);
    for(int i=k; i<N+k-1; i++){
        if(!flag[arr[i]]++) cnt++;
        if(!(--flag[arr[i-k]])) cnt--;
        ans=max(ans, !flag[c]?cnt+1:cnt);
    }
    cout<<ans;
}