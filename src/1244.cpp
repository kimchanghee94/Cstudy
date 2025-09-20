#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 102
int S,N,arr[MAX];

int main(void){
    scanf("%d", &S);for(int i=1; i<=S; i++) scanf("%d",&arr[i]);scanf("%d",&N);
    while(N-->0){
        int sex,idx; scanf("%d%d",&sex,&idx);
        if(sex==1) for(int i=idx; i<=S; i+=idx) arr[i]=!arr[i];
        else{
            if(idx==1 || idx==S) arr[idx]=!arr[idx];
            else{
                for(int i=1; i<S; i++){
                    if(arr[idx-i] != arr[idx+i]){
                        for(int j=idx-i+1; j<idx+i; j++) arr[j]=!arr[j];
                        break;
                    }else if(idx-i==1 || idx+i==S){
                        for(int j=idx-i; j<idx+i+1; j++) arr[j]=!arr[j];
                        break;
                    }
                }
            }
        } 
    }
    for(int i=1; i<=S; i++) {
        if(i%20) printf("%d ",arr[i]);
        else printf("%d\n",arr[i]);
    }
}