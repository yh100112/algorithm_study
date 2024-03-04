#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, mx = -987654321;
vector<int> v[10002];
int dist[10002], visited[10002];


int go(int node) {
    visited[node] = 1;
    int ans = 1;
    for (auto& next : v[node]) {
        if (visited[next]) continue;
        ans += go(next);
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        fill(&visited[0], &visited[0] + 10002, 0);
        dist[i] = go(i);
        mx = max(mx, dist[i]);
    }
    for (int i = 1; i <= n; ++i)
        if (dist[i] == mx)
            cout << i << " ";
    cout << "\n";
}