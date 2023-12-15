#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, a, b, ret[10001], visited[10001], mx = -INF, cnt;
vector<int> v[10001];

void go(int node){
    cnt++;
    visited[node] = 1;
    for(auto i : v[node]){
        if(visited[i] == 0)
            go(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        fill(&visited[0], &visited[0] + 10001, 0);
        cnt = 0;
        go(i);
        ret[i] = cnt;
        mx = max(mx, cnt);
    }

    for(int i = 1; i <= n; i++){
        if(ret[i] == mx)
            cout << i << ' ';
    }
    cout << '\n';
}