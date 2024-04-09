#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, visited[10004], cnt[10004], mx = INT_MIN;
vector<int> v[10004];

int go(int node) {
    visited[node] = 1;

    int ret = 1; 
    for (auto& next : v[node]) {
        if (visited[next]) continue;
        ret += go(next);
    }
    return ret;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        cnt[i] = go(i);
        mx = max(mx, cnt[i]);
    }

    for (int i = 1; i <= n; i++)
        if (cnt[i] == mx)
            cout << i << " ";
}