#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

#define MAX 1005

int di[4]={1,0,-1,0};
int dj[4]={0,1,0,-1};
string graph[MAX];

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; i++) cin>>graph[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int chk=0;
            for(int d=0; d<4; d++){
                int ni=i+di[d], nj=j+dj[d];
                if(ni>=0&&ni<N&&nj>=0&&nj<N&&graph[i+di[d]][j+dj[d]]=='*') chk++;
            }
            if(chk==4){
                cout<<i+1<<" "<<j+1<<"\n";
                int cnt=0;
                for(int s=j-1; graph[i][s]=='*'; s--) cnt++; cout<<cnt<<" "; cnt=0;
                for(int s=j+1; graph[i][s]=='*'; s++) cnt++; cout<<cnt<<" "; cnt=0;
                for(int s=i+1; graph[s][j]=='*'; s++) cnt++; cout<<cnt<<" ";
                i+=(cnt+1); cnt=0;
                for(int s=i; graph[s][j-1]=='*'; s++) cnt++; cout<<cnt<<" "; cnt=0;
                for(int s=i; graph[s][j+1]=='*'; s++) cnt++; cout<<cnt;
                return 0;
            }
        }
    }
}