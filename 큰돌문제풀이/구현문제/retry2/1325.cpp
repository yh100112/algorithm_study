#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, mx = -987654321, cnt[10001], visited[10001];
vector<int> v[10001], ret;

int go(int node){
    visited[node] = 1;

    int ans = 1;
    bool child = false;
    for(auto& next : v[node]){
        if(visited[next]) continue;
        child = true;
        ans += go(next);
    }
    if(child == false) return 1;
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        fill(&visited[0], &visited[0] + 10001, 0);
        int c = go(i);
        cnt[i] = c;
        mx = max(c, mx);
    }

    for(int i = 1; i <= n; i++){
        if(cnt[i] == mx) ret.push_back(i);
    }

    sort(ret.begin(), ret.end());
    for(auto& v : ret)
        cout << v << ' ';
    cout << '\n';
}