#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 55
int N,T,P;
int arr[MAX];

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N>>T>>P;for(int i=0; i<N; i++) cin>>arr[i];
    if(N==0) cout<<1;
    else if(N==P&&arr[N-1]>=T) cout<<-1;
    else for(int i=N-1; i>=0; i--){
        if(arr[i]>T) {
            cout<<i+2;
            break;
        }
        else if(i==0 && arr[i]<=T) cout<<1;
    }
}