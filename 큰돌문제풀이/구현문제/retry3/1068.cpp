#include<bits/stdc++.h>
using namespace std;
int n, node, root, del, ret;
vector<int> v[52];
int visited[52];

int go(int node) {
    visited[node] = 1;
    int ret = 0;
    for (auto& i : v[node]) {
        if (visited[i] || i == del) continue;
        ret += go(i);
    }
    if (ret == 0)
        ret = 1;
    return ret;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> node;
        if (node == -1) {
            root = i;
            continue;
        }
        v[node].push_back(i);
    }
    cin >> del;
    if(del == root) cout << 0 << "\n";
    else cout << go(root) << "\n";
}