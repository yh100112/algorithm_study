#include<iostream>
#include<stdio.h>

using namespace std;

long dp[1000001][2];

long solution(int n){
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[2][0] = 7;
    dp[2][1] = 0;
    
    if(dp[n][0] != 0) return dp[n][0];
    
    for(int i = 3; i <= n; i++){
        dp[i][1] = (dp[i-3][0] + dp[i-1][1]) % 1000000007;
        dp[i][0] = (3 * dp[i-2][0] + 2 * dp[i-1][0] + 2 * dp[i][1]) % 1000000007;
    }

    return dp[n][0];
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%ld",solution(n));
}

/*
dp[i] = 2 * dp[i - 1] + 3 * dp[i-2]
        + 2 * dp[i-3]
        + 2 * dp[i-4]
        + 2 * dp[i-5]
        . . .
        + 2 * dp[0]

�� ���������� n�� 1000000�����̹Ƿ� 
���� ���� Ǯ�� �ð��ʰ� �߻� => O(N^2)

O(N)���� Ǯ ���� ������?
-> dp[i] = 2 * dp[i-1] + 3 * dp[i-2] + 2(dp[i-3] + dp[i-4] + ... dp[0]);
  dp[i-3]���� dp[0]������ ���� ����ϴ� DP�� �ϳ� �� ����� �ȴ�!!

*/