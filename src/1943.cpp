#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001
int dp[MAX];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0;i<3;i++){
        int N,tot=0;cin>>N;
        vector<pair<int,int>> v(N);
        for(int i=0;i<N;i++){
            cin>>v[i].first>>v[i].second;
            tot+=v[i].first*v[i].second;
        }
        if(tot%2){
            cout<<"0\n";
            continue;
        }

        int target=tot/2;
        fill(dp, dp+target+1,-1);
        dp[0]=0;

        for(auto [val,cnt] : v){
            for(int i=0;i<=target;i++){
                if(dp[i]>=0) dp[i]=cnt;
                else if(i>=val && dp[i-val]>0) dp[i]=dp[i-val]-1;
            }
        }
        cout<<(dp[target]>=0 ? 1 :0)<<"\n";
    }
}