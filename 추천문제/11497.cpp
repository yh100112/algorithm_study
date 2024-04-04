#include<bits/stdc++.h>
using namespace std;
int n, t;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        int ret = INT_MIN;
        for (int i = 0; i < v.size() - 2; i++)
            ret = max(ret, abs(v[i] - v[i + 2]));
        cout << ret << "\n";
    }
}