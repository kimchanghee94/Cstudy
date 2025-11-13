#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1){
        int n; cin>>n;
        ll ans=0;
        if(!n) break;
        stack<pair<ll,ll>> s;
        for(int i=0;i<n;i++){
            int h; cin>>h;
            int bi=i;
            while(!s.empty() && s.top().first>=h){
                ans=max(ans,s.top().first*(i-s.top().second));
                bi=s.top().second;
                s.pop();
            }
            s.push({h,bi});
        }
        
        while(!s.empty()){
            ans=max(ans,s.top().first*(n-s.top().second));
            s.pop();
        }
        cout<<ans<<"\n";
    }
}