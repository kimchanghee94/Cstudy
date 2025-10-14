#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, max_len=0; cin>>N;
    vector<pair<string,int>> v,c;
    set<int> ans;
    for(int i=0; i<N; i++){
        string str; cin>>str;
        v.push_back({str,i});
    }
    c=v;
    sort(v.begin(), v.end());
    for(int i=0; i<N-1; i++){
        string &a=v[i].first;
        string &b=v[i+1].first;
        int len=0;      
        while(len<a.length() && len<b.length() && a[len]==b[len]) len++;
        if(len && max_len<=len){
            if(max_len<len) ans.clear();
            max_len=len;
            if(v[i].second<v[i+1].second) ans.insert(v[i].second);
            else ans.insert(v[i+1].second);
        }
    }
    int idx=*ans.begin();
    for(int i=idx; i<c.size(); i++){
        if(i==idx) cout<<c[i].first<<"\n";
        else{
            int len=0;
            string &a=c[idx].first;
            string &b=c[i].first;
            while(len<a.length() && len<b.length() && a[len]==b[len]) len++;
            if(len==max_len){
                cout<<c[i].first;
                break;
            }
        }
    }
}