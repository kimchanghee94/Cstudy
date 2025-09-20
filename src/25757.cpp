#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    char M;
    cin >> N >> M;
    unordered_set<string> set;

    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        set.insert(str);
    }
    if(M=='Y') cout<<set.size()/1;
    else if(M=='F') cout<<set.size()/2;
    else cout<<set.size()/3;
}