#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 1000005

int main(void){
    char arr[MAX];
    int cnt[26];
    int maxC=0;
    char ans;
    memset(cnt, 0, sizeof(cnt));
    scanf("%s", arr);
    int len = strlen(arr);
    for(int i=0; i<len; i++){
        if(arr[i]<='Z') cnt[arr[i]-'A']++;
        else cnt[arr[i]-'a']++;
    }

    for(int i=0; i<26; i++){
        if(maxC==cnt[i]) ans='?';
        else if(maxC < cnt[i]) {
            maxC=cnt[i];
            ans=i+65;
        }
    }
    printf("%c", ans);
}