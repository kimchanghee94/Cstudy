#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int flag[26]={0};
    int N; cin>>N;
    cin.ignore();
    while(N--){
        string str,token; getline(cin,str);
        stringstream ss(str);

        int chk=0;
        str.clear();
        while(getline(ss, token, ' ')){
            if(!flag[tolower(token[0])-'a'] && !chk){
                flag[tolower(token[0])-'a']=1;
                token.insert(0,"[");
                token.insert(2,"]");
                chk=1;
            }
            str.append(token+" ");
        }
        str.pop_back();

        if(!chk){
            for(int i=0; i<str.length(); i++){
                if(str[i]==' ') continue;
                if(!flag[tolower(str[i])-'a']){
                    flag[tolower(str[i])-'a']=1;
                    str.insert(i,"[");
                    str.insert(i+2,"]");
                    break;
                }
            }
        }

        cout<<str+"\n";
    }
}