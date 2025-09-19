#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 20

int set[MAX];

int main(void){
    int M;
    scanf("%d", &M);
    while(M-->0){
        char prom[10];
        int val=0;
        scanf("%s %d", prom, &val);
        val--;

        if(!strcmp(prom, "add")) set[val]=1;
        else if(!strcmp(prom, "remove")) set[val]=0;
        else if(!strcmp(prom, "check")) printf("%d\n", set[val]);
        else if(!strcmp(prom, "toggle")) if(set[val]) set[val]=0; else set[val]=1;
        else if(!strcmp(prom, "all")) for(int i=0; i<MAX; i++) set[i]=1;
        else if(!strcmp(prom, "empty")) for(int i=0; i<MAX; i++) set[i]=0;
    }
}