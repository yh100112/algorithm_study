#include<bits/stdc++.h>
using namespace std;
int h, w, arr[504], max_h;

int main(){
    cin >> h >> w;
    for(int i = 0; i < w; i++)
        cin >> arr[i];
    
    int ans = 0;
    for(int i = 1; i < w - 1; i++){
        int left, right;
        left = right = 0;
        for(int j = 0; j < i; j++){
            left = max(left, arr[j]);
        }
        for(int j = i + 1; j < w; j++){
            right = max(right, arr[j]);
        }
        int now = min(left, right);
        int result = min(left, right) - arr[i];
        if(result >= 0) ans += result;
    }
    cout << ans << '\n';
}