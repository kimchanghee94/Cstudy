#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    unordered_set<string> set;
    int N,M; cin>>N>>M;
    while(N--){
        string str; cin>>str;
        set.insert(str);
    }
    while(M--){
        string str;
        cin.ignore();
        while(getline(cin, str, ',')) set.erase(str);
        cout<<set.size();
    }
}