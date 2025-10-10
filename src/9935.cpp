#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string str,exp,ans; cin>>str>>exp;

    for(int i=0; i<str.length(); i++){
        ans.push_back(str[i]);
        if(ans.back()==exp.back() && ans.length()>=exp.length()){
            bool same=true;
            for(int j=0;j<exp.length();j++){
                if(ans[ans.size()-j-1]!=exp[exp.length()-j-1]) {
                    same=false;
                    break;
                }
            }
            if(same) for(int j=0; j<exp.size(); j++) ans.pop_back();
        }
    }
    if(ans.size()) cout<<ans;
    else cout<<"FRULA";
}