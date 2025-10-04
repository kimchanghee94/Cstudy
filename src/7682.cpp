#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(1){
        string str; cin>>str;
        if(str=="end") break;

        int ocnt=0,xcnt=0;
        for(int i=0; i<9; i++){
            if(str[i]=='O') ocnt++;
            else if(str[i]=='X') xcnt++;
        }

        unordered_map<char,int> map;
        for(int i=0;i<3;i++) if(str[0+(3*i)]!='.'&&str[0+(3*i)]==str[1+(3*i)]&&str[0+(3*i)]==str[2+(3*i)]) map[str[0+(3*i)]]++;
        for(int i=0;i<3;i++) if(str[0+i]!='.'&&str[0+i]==str[3+i]&&str[0+i]==str[6+i]) map[str[0+i]]++;
        if(str[0]!='.'&&str[0]==str[4]&&str[0]==str[8]) map[str[0]]++;
        if(str[2]!='.'&&str[2]==str[4]&&str[2]==str[6]) map[str[2]]++;

        if(map.size()==1 && ((map['O'] && xcnt==ocnt) || (map['X'] && (xcnt==ocnt+1)))) cout<<"valid\n";
        else if(map.size()==0 && xcnt==5 && ocnt==4) cout<<"valid\n";
        else cout<<"invalid\n";
    }
}