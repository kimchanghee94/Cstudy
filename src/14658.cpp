#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

int main(){
    int N,M,L,K; scanf("%d%d%d%d",&N,&M,&L,&K);
    int arr[MAX][2], ans=0;
    for(int i=0; i<K; i++) scanf("%d%d",&arr[i][0],&arr[i][1]);
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            int fi=arr[i][0];
            int fj=arr[j][1];
            int cnt=0;
            for(int k=0; k<K; k++){
                int ni=arr[k][0];
                int nj=arr[k][1];
                if(fi<=ni&&ni<=fi+L&&fj<=nj&&nj<=fj+L) cnt++;
            }
            ans=ans<cnt?cnt:ans;
        }
    }
    printf("%d",K-ans);
}