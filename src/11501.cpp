#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000005
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        int price[MAX]; for(int i=0; i<N; i++) cin>>price[i];
        int max_n=price[N-1];
        long long profit=0;
        for(int i=N-2; i>=0; i--){
            max_n=max(max_n, price[i]);
            profit+=max_n-price[i];
        }
        cout<<profit<<"\n";
    }
}