#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long
ll calc(ll val){
    ll sum=0;
    for(int i=0;i<55;i++){
        ll div=(ll)1<<(i+1);
        ll mul=(ll)1<<i;
        ll cnt=((val+1)/div)*mul;
        ll rem=(val+1)%div;
        sum+=cnt;
        if(rem>mul) sum+=rem-mul;
    }
    return sum;
}

int main(){
    ll A,B; scanf("%lld %lld",&A,&B);
    printf("%lld",calc(B)-calc(A-1));
}