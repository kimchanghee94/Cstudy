#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string str; cin>>str;
    list<char> l;
    for(auto &c : str) l.push_back(c);
    int M; cin>>M;
    auto cur = l.end();
    while(M--){
        char prom; cin>>prom;
        if(prom=='P'){
            char val;cin>>val;
            cur=l.insert(cur, val);
            cur++;
        }
        else if(prom=='L' && cur!=l.begin()) cur--;
        else if(prom=='D' && cur!=l.end()) cur++;
        else if(prom=='B' && cur!=l.begin()) cur=l.erase(--cur);
    }
    for(auto &tmp:l) cout<<tmp;
}