#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string str; cin>>str;
    int acnt=0, bcnt=0, ans=0;
    for(auto &c:str) if(c=='a') acnt++;
    str.append(str.substr(0,acnt-1));
    for(int i=0;i<acnt;i++) if(str[i]=='b') bcnt++;
    ans=bcnt;
    for(int i=acnt;i<str.length(); i++){
        if(str[i-acnt]=='b') bcnt--;
        if(str[i]=='b') bcnt++;
        ans=min(ans,bcnt);
    }
    cout<<ans;
}