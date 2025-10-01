#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define pair_is pair<int,string>

bool comp(const pair_is &first, const pair_is &second){
    return first.second<second.second;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    vector<vector<pair_is>> v;
    int p,m; cin>>p>>m;
    while(p--){
        int l; string n; cin>>l>>n;
        bool chk=false;
        for(int i=0; i<v.size(); i++) 
        if(v[i][0].first-10<=l && l<=v[i][0].first+10 && v[i].size()<m){
            chk=true;
            v[i].push_back({l,n});
            break;
        }
        if(!chk) v.push_back({{l,n}});
    }
    for(int i=0; i<v.size(); i++){
        sort(v[i].begin(), v[i].end(), comp);
        if(v[i].size()==m) cout<<"Started!\n";
        else cout<<"Waiting!\n";

        for(auto &tmp:v[i]){
            cout<<tmp.first<<" "<<tmp.second<<"\n";
        }
    }
}