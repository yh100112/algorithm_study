#include<bits/stdc++.h>
using namespace std;
int t, n, m, num;

bool check(int num ,vector<int>& v) {
    int lo = 0;
    int hi = v.size() - 1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (v[mid] > num) hi = mid - 1;
        else if (v[mid] == num) return 1;
        else lo = mid + 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v1; // 수첩 1
        v1.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v1[i];
        sort(v1.begin(), v1.end());
        
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> num;
            cout << check(num, v1) << "\n";
        }
    }
}