#include<bits/stdc++.h>
using namespace std;
#define left aaa
#define right bbb
int h, w, arr[504], ret, result, left, right;

int main() {
    cin >> h >> w;
    for (int i = 0; i < w; i++)
        cin >> arr[i];
    
    for (int i = 1; i < w - 1; i++) {
        left = 0, right = 0;
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);
        for (int j = i + 1; j < w; j++)
            right = max(right, arr[j]);
        result = min(left, right) - arr[i];
        if (result > 0) ret += result;
    }
    cout << ret << "\n";
}