#include<bits/stdc++.h>
using namespace std;
int t, n, m;

int main() {
    cin >> t;
    while(t--) {
        int a[1000004], b[1000004];

        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> m;
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n);

        int lo, hi;
        bool flag;
        for (int i = 0; i < m; i++) {
            lo = 0, hi = n - 1;
            flag = 0;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if (a[mid] > b[i]) {
                    hi = mid - 1;
                }
                else if (a[mid] == b[i]) {
                    flag = 1;
                    break;
                }
                else
                    lo = mid + 1;
            }
            if (flag) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}