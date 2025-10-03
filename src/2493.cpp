#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin>>N;
    string ans;
    stack<pair<int,int>> s;
    for(int i=0; i<N; i++){
        int val; cin>>val;
        while(!s.empty() && s.top().first<val) s.pop();
        if(s.empty()) ans.append("0 ");
        else ans.append(to_string(s.top().second)+ " ");
        s.push({val,i+1});
    }
    cout<<ans;
}