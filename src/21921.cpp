#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 250005
int arr[MAX], N,X,ans,day,slide;
int main(void){
    scanf("%d %d",&N,&X);
    for(int i=0; i<X; i++) {
        scanf("%d",&arr[i]);
        slide+=arr[i];
    }
    ans=slide,day=1;
    for(int i=X; i<N; i++){
        scanf("%d",&arr[i]);
        slide+=arr[i]-arr[i-X];
        if(ans<slide) day=1,ans=slide;
        else if(ans==slide) day++;
    }
    if(ans==0) printf("SAD");
    else printf("%d\n%d",ans,day);
}