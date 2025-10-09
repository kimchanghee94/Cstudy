#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 100005
int N;
string s,e;

void change(string &str, int idx){
    if(idx>0) str[idx-1]=='0' ? str[idx-1]='1' : str[idx-1]='0';
    str[idx]=='0' ? str[idx]='1' : str[idx]='0';
    if(idx<N-1) str[idx+1]=='0' ? str[idx+1]='1' : str[idx+1]='0';
}

int greedy(int si){
    string tmp = s;
    int cnt=0;
    if(si==1) change(tmp, 0),cnt++;
    for(int i=1; i<N; i++) if(tmp[i-1]!=e[i-1]) change(tmp, i), cnt++;
    return tmp==e ? cnt : MAX;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>s>>e;
    int ans=MAX;
    for(int i=0; i<2; i++) ans=min(ans,greedy(i));
    if(ans==MAX) cout<<-1;
    else cout<<ans;
}