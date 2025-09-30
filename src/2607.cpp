#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 102
#define MAX_A 26
char arr[MAX][MAX_A];
int main(void){
    int N,ans=0,fir_len; scanf("%d", &N);
    for(int i=0; i<N; i++){
        char word[11]; scanf("%s",word);
        int len=strlen(word);
        for(int j=0; j<len; j++) arr[i][word[j]-'A']++;
        if(i>0) {
            int diff=0;
            for(int j=0; j<MAX_A; j++) diff+=abs(arr[i][j]-arr[0][j]);
            if(diff<2) ans++;
            else if(fir_len==len && diff/2<2) ans++;
        }else fir_len=len;
    }
    printf("%d", ans);
}