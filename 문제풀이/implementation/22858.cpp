#include<bits/stdc++.h>
using namespace std;
int n, k;
int arr[10004];
int d[10004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k; // 카드 개수 n, 카드 섞은 횟수 k
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        cin >> d[i];
    }

    for(int i = 0; i < k; i++){
        int c[10004];
        copy(arr, arr+10004, c);
        for(int j = 0; j < n; j++){
            arr[d[j] - 1] = c[j];
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}