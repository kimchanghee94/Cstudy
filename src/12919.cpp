#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S;
bool dfs(string T){
    if(T.length()==S.length()){
        if(S==T) return true;
    }
    else{
        int achk=0,bchk=0;
        if(T.back()=='A') achk=dfs(T.substr(0,T.length()-1));
        if(T.front()=='B'){
            string tmp=T.substr(1); reverse(tmp.begin(), tmp.end());
            bchk=dfs(tmp);
        }
        return achk||bchk;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string T;cin>>S>>T;
    cout<<dfs(T);
}