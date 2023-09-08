#include<bits/stdc++.h>
using namespace std;
int temp[100004];
int n,k,m = -10000004;

int main(){
    cin >> n >> k;
    int a = 0;
    for(int i = 1; i <= n; i++){
        cin >> a;
        temp[i] = temp[i-1] + a;
    }
    for(int i = k; i <= n; i++){
        int sum = 0;
        sum = temp[i] - temp[i - k];
        m = max(m,sum);
    }
    cout << m << "\n";
}

// 최댓값 구할때  -> 최솟값부터 시작해서 최댓값 구하기
// 최솟값 구할때  -> 최댓값부터 시작해서 최솟값 구하기
// 최댓값을 구하는 문제이므로 최솟값을 범위를 기반으로 계산하여 찾은 후 그 값을 초기값으로 세팅하여 계산