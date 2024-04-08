#include<bits/stdc++.h>
using namespace std;
int n, a[1001], ret;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    int cnt[1001] = {0};
    for (int i = 0; i < n; i++) {
        int maxValue = 0;
        for (int j = 0; j < i; j++) { // 현재 위치 직전까지 탐색해서 LIS 찾음
            if (a[i] > a[j] && maxValue < cnt[j]) maxValue = cnt[j];
        }
        cnt[i] = maxValue + 1;
        ret = max(ret, cnt[i]);
    }
    cout << ret << "\n";
}