#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500001

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin>>N;
    int lb=0,rb=0,lr=0,rr=0;
    char str[MAX]; cin>>str;
    for(int i=0; i<N; i++) if(str[i]=='R') lr++;
    rr=lr;
    rb=lb=N-lr;
    for(int i=0; i<N && str[i]=='R'; i++) lr--;
    for(int i=0; i<N && str[i]=='B'; i++) lb--;
    for(int i=N-1; i>=0 && str[i]=='R'; i--) rr--;
    for(int i=N-1; i>=0 && str[i]=='B'; i--) rb--;
    cout<<min(min(lb,rb),min(lr,rr));
}