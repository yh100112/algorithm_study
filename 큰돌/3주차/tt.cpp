#include<bits/stdc++.h>
using namespace std;
vector<int> adj[6];
int visited[6];

void dfs(int a){
    visited[a] = 1;
    cout << a << "\n";
    for(auto v : adj[a]){
        if(visited[v]) continue;
        dfs(v);
    }
    cout << a << "로부터 시작된 함수가 종료되었습니다." << "\n";
}

int main(){
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[4].push_back(2);
	adj[2].push_back(5);
    dfs(1);
}