#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define sp pair<string,int>
int N,M;
unordered_map<string,int> map;

bool comp(const sp &a, const sp &b){
    if(a.second!=b.second) return a.second>b.second;
    if(a.first.size()!=b.first.size()) return a.first.size()>b.first.size();
    return a.first<b.first;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string word; cin>>word;
        if(word.size()<M) continue;
        map[word]++;
    }
    vector<sp> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), comp);
    for(auto &tmp:vec) cout<<tmp.first<<"\n";
}