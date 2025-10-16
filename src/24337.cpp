#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,a,b;cin>>N>>a>>b;
    deque<int> dq;
    if(a<=b){
        for(int i=1;i<=b;i++) dq.push_front(i);
        for(int i=a-1;i>0;i--) dq.push_front(i);
    }else{
        for(int i=1;i<=a;i++) dq.push_back(i);
        for(int i=b-1;i>0;i--) dq.push_back(i);    
    }
    for(int i=dq.size(); i<N; i++){
        if(dq[0]==1) dq.push_front(1);
        else dq.insert(dq.begin()+1,1);
    }
    if(dq.size()>N) cout<<"-1";
    else for_each(dq.begin(), dq.end(), [](auto &tmp){cout<<tmp<<" ";});
}