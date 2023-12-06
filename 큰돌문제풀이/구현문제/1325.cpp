#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, cnt, visited[10004], dp[10004], mx = -987654321;
vector<int> v[10004];
vector<int> ret;

int dfs(int node){
    visited[node] = 1;
    int ans = 1;
    for(auto i : v[node]){
        if(visited[i] == 0) 
            ans += dfs(i);  
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        fill(visited, visited + 10004, 0);
        int num = dfs(i);
        mx = max(num, mx);
        dp[i] = num;
    }
    for(int i = 1; i <= 10000; i++){
        if(dp[i] == mx)
            cout << i << ' ';
    }
    cout << '\n';
}