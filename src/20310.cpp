#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 502

int main(void){
    char str[MAX]; scanf("%s",str);
    int one=0,zero=0;
    for(int i=0; str[i]; i++){
        if(str[i]=='1') one++;
        else zero++;
    }
    int len = one+zero;
    one/=2,zero/=2;
    for(int i=0; str[i]; i++){
        if(str[i]=='1' && one-->0) str[i]='X';
        if(str[len-i-1]=='0' && zero-->0) str[len-i-1]='X';
    }
    for(int i=0; str[i]; i++) if(str[i]!='X') printf("%c", str[i]);
}