#include<bits/stdc++.h>
using namespace std;
int n, a, b, root, visited[54];
vector<int> v[54];

int go(int node) {
    int flag = 0;
    int ret = 0;
    for (auto& next : v[node]) {
        if (visited[next] || next == b) continue;
        visited[next] = 1;
        ret += go(next);
        flag = 1;
    }

    if (flag == 0) return 1;
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a != -1) v[a].push_back(i);
        else root = i;
    }
    cin >> b;
    visited[root] = 1;
    if (b == root) cout << 0 << "\n";
    else cout << go(root) << "\n";;
}