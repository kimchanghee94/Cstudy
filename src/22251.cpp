#include <iostream>
using namespace std;

int graph[10][10]={
    {0,4,3,3,4,3,2,3,1,2},
    {4,0,5,3,2,5,6,1,5,4},
    {3,5,0,2,5,4,3,4,2,3},
    {3,3,2,0,3,2,3,2,2,1},
    {4,2,5,3,0,3,4,3,3,2},
    {3,5,4,2,3,0,1,4,2,1},
    {2,6,3,3,4,1,0,5,1,2},
    {3,1,4,2,3,4,5,0,4,3},
    {1,5,2,2,3,2,1,4,0,1},
    {2,4,3,1,2,1,2,3,1,0}
};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K,P,X; cin>>N>>K>>P>>X;
    int ans=0;
    for(int i=1; i<=N; i++){
        if(i==X) continue;
        int p_cnt=0;
        int ti=i, tx=X;

        while(ti>0 && tx>0){
            int tti=ti%10, ttx=tx%10;
            p_cnt+=graph[tti][ttx];
            ti/=10;
            tx/=10;
        }
        if(tx>0) ti=tx;
        while(ti>0){
            int tti=ti%10;
            p_cnt+=graph[tti][0];
            ti/=10;
        }
        if(p_cnt<=P) ans++;
    }
    cout<<ans;
}