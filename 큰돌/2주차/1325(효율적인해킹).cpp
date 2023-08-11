#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,visited[10001],cnt;
vector<int> adj[10001];
int dp[10001];

void dfs(int u){
    visited[u] = 1;
    cnt++;
    for(auto v : adj[u]){
        if(visited[v] == 0)
            dfs(v);
    }
    return;
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
        dp[i] = cnt;
    }
    for(int i = 1; i <= n; i++)
        if(dp[i] == mx)
            cout << i << " ";
}