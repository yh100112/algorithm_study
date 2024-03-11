#include<bits/stdc++.h>
using namespace std;
int n, m, ret;
vector<int> v;

int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    int l = 0;
    int r = 0;
    int sum = 0;
    while (true) {
        if (l == n) break;
        if (r < n && sum < m) {
            sum += v[r++];
        }
        else if (sum == m) {
            sum -= v[l++];
            ret++;
        }
        else {
            sum -= v[l++];
        }
    }
    cout << ret << "\n";
}