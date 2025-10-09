#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, ans=0; cin>>n;
    stack<int> s;
    while(n--){
        int x,y; cin>>x>>y;
        while(!s.empty() && s.top()>=y) {
            if(s.top()>y) ans++;
            s.pop();
        }
        s.push(y);
    }
    while(!s.empty() && s.top()) ans++,s.pop();
    cout<<ans;
}