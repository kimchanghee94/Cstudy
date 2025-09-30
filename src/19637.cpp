#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,M,count[MAX]; cin>>N>>M;
    char name[MAX][12];
    for(int i=0; i<N; i++) cin >> name[i] >> count[i];
    while(M-->0){
        int val; cin>>val;
        int ans=lower_bound(count,count+N,val)-count;
        printf("%s\n",name[ans]);
    }
}