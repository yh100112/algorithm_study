#include<bits/stdc++.h>
using namespace std;
int n,k; // 2 <= n <= 100000, 1 < k < n
int arr[100004];

int main(){
    cin >> n >> k;
    int num;
    for(int i = 1; i <= n; i++){
        cin >> num;
        arr[i] = arr[i-1] + num;
    }

    int mx = -10000000;
    for(int i = 0; i < n; i++){
        if (i + k > n) break;
        int sum = arr[i + k] - arr[i];
        mx = max(mx, sum);
    }
    cout << mx << "\n";
}