#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int A,B;
    scanf("%d %d", &A, &B);
    int tmpA=0, tmpB=0;
    while(A>0){
        tmpA+=A%10;
        tmpA*=10;
        A/=10;
    }
    
    while(B>0){
        tmpB+=B%10;
        tmpB*=10;
        B/=10;
    }
    tmpA/=10,tmpB/=10;
    printf("%d\n", tmpA > tmpB ? tmpA : tmpB);
}