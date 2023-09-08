#include<iostream>
#include<stdio.h>

using namespace std;

int dp[35];


int solution(int n){
    if(n % 2 != 0){
        return 0;
    }
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    if(dp[n] != 0) return dp[n];
    if(n == 1) return 0;
    
    dp[n] += solution(n-2) * dp[2];
    for(int i = 4; i <= n; i = i + 2){
        dp[n] = dp[n] + solution(n-i) * 2;
    }
    
    return dp[n];
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",solution(n));
}
