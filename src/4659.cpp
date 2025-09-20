#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 22

int chkVal(char val){
    if(val=='a' || val=='e' || val=='i' || val=='o' || val=='u') return 1;
    else return 0;
}

int main(void){
    char arr[MAX];
    while(true){
        scanf("%s", arr);
        if(!strcmp(arr, "end")) break;

        int len = strlen(arr);
        int chk=0, two=0, three=0;
        for(int i=0; i<len; i++){
            if(chkVal(arr[i])) chk++;
            if(i>1 && ((chkVal(arr[i-2]) && chkVal(arr[i-1]) && chkVal(arr[i]))||(!chkVal(arr[i-2]) && !chkVal(arr[i-1]) && !chkVal(arr[i])))) three=1;
            if(i>0 && arr[i-1]==arr[i] && arr[i]!='e' && arr[i]!='o') two=1;
        }

        if(!chk || two || three) printf("<%s> is not acceptable.\n", arr);
        else printf("<%s> is acceptable.\n", arr);
    }
}