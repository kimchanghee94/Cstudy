#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main(void){
    scanf("%d", &N);
    for(int i=1; i<=N; i++) q.push(i);
    while(q.size()!=1){
        q.pop();
        int val=q.front();
        q.pop();
        q.push(val);
    }
    printf("%d",q.front());
}