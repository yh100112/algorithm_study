#include<bits/stdc++.h>
using namespace std;
int n, k, num;
int arr[100004];
int mx = -10000000;

int main(){
    cin >> n >> k; // 1 < k < n
    for(int i = 1; i <= n; i++){ // 2 <= n <= 100,000
        cin >> num;
        arr[i] = arr[i - 1] + num;
    }
    for(int i = 0; i < n; i++){
        if(n - k + 1 <= i)
            break;
        mx = max(mx, arr[k + i] - arr[i]);
    }
    cout << mx << "\n";
}