#include<bits/stdc++.h>
using namespace std;
const int n = 10;
vector<int> adj[n];
int visited[n];
int cnt;
void dfs(int u){
    visited[u] = 1;
    cnt++;
    cout << u << endl;
    for(int v : adj[u]){
        if(visited[v] == 0)
            dfs(v);
    }
    cout << u << "로부터 시작된 함수가 종료되었습니다." << endl;
    return;
}

int main() {
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    dfs(1);
}