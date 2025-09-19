#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int A,B,C;

    while(true){
        scanf("%d%d%d",&A,&B,&C);
        if(!A&&!B&&!C) break;

        if(A==B && A==C) printf("Equilateral\n");
        else if(A>B && A>C && A>=B+C) printf("Invalid\n");
        else if(B>C && B>A && B>=A+C) printf("Invalid\n");
        else if(C>A && C>B && C>=A+B) printf("Invalid\n");
        else if(A!=B && A!=C && B!=C)printf("Scalene\n");
        else printf("Isosceles\n");
    }
}