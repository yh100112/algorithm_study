#include<iostream>
#include<stdio.h>

using namespace std;

int d[1000001];

int solution(int n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    if(d[n] != 0) return d[n];
    
    d[n] += solution(n-1) * 2 + solution(n-2) * 3;
    for(int i = n - 3; i >= 0; i = i - 1){
        d[n] += solution(i) * 2;
    }
    d[n] = d[n] % 1000000007;
    return d[n];
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",solution(n));
}