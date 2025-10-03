#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--){
        string str; cin>>str;
        int K,min_ans=str.length()+1,max_ans=0; cin>>K;
        vector<int> v[26];
        for(int i=0; i<str.length(); i++) v[str[i]-'a'].push_back(i);
        for(int i=0; i<26; i++){
            if(v[i].size()<K) continue;
            for(int j=0;j+K-1<v[i].size();j++){
                int val=v[i][j+K-1]-v[i][j]+1;
                min_ans=min(min_ans,val);
                max_ans=max(max_ans,val);
            }
        }
        if(!max_ans) cout<<"-1\n";
        else cout<<min_ans<<" "<<max_ans<<"\n";
    }
}