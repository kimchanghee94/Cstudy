#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    string arr; cin >> arr;
    int ans=1, idx=0;
    while(1){
        string ans_str=to_string(ans);
        for(int i=0; i<ans_str.length(); i++){
            if(ans_str[i]==arr[idx]) idx++;
            if(idx==arr.length()){
                cout << ans;
                return 0;
            }
        }
        ans++;
    }
}