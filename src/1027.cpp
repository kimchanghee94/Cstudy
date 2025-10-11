#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 51
int main(){
    int N,arr[MAX],ans=0; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    for(int i=0;i<N;i++){
        int tmp_ans=0;
        double s=1000000005;
        for(int j=i-1;j>=0;j--){
            double tmp_s=(double)(arr[i]-arr[j])/(i-j);
            if(s>tmp_s){
                s=tmp_s;
                tmp_ans++;
            }
        }
        s=-1000000005;
        for(int j=i+1;j<N;j++){
            double tmp_s=(double)(arr[i]-arr[j])/(i-j);
            if(s<tmp_s){
                s=tmp_s;
                tmp_ans++;
            }
        }
        if(ans<tmp_ans) ans=tmp_ans;
    }
    printf("%d",ans);
}