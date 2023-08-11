#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,visited[10001],cnt;
vector<int> adj[10001];
vector<pair<int,int>> com;

void dfs(int u){
    visited[u] = 1;
    cnt++;
    for(auto v : adj[u]){
        if(visited[v] == 0)
            dfs(v);
    }
    return;
}

bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.second < b.second;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }

    int mx = 0;
    for(int i = 1; i <= n; i++){
        cnt = 0;
        fill(&visited[0], &visited[0] + 10001, 0);
        dfs(i);
        mx = max(mx, cnt);
        com.push_back({i,cnt});
    }
    sort(com.begin(), com.end(), cmp);
    for(auto v : com) {
        if(v.second == mx)
            cout << v.first << " ";
    }
    cout << "\n";
}