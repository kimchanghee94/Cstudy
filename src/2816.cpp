#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_ANS 502
#define MAX_N 102
#define MAX_M 12

int main(void){
    int N, idx=0;
    char arr[MAX_N][MAX_M];
    char ans[MAX_ANS];
    memset(ans, 0, sizeof(ans));
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%s", arr[i]);

    int cnt, chk=0;
    for(cnt=0; cnt<N; cnt++){
        if(!strcmp(arr[cnt], "KBS2")) chk=1;
        if(!strcmp(arr[cnt],"KBS1")) break;
        ans[idx++]='1';
    }
    for(int i=0; i<cnt; i++) ans[idx++]='4';
    for(cnt=0-chk; cnt<N; cnt++){
        if(!strcmp(arr[cnt], "KBS2")) break;
        ans[idx++]='1';
    }
    for(int i=1-chk; i<cnt; i++) ans[idx++]='4';

    printf("%s", ans);
}