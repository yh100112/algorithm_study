#include<bits/stdc++.h>
using namespace std;
vector<int> v[50];
int n, node, d;
int root;

int dfs(int u){
    int cnt = 0;
    int child = 0;
    for(auto b : v[u]){
        if(b == d) continue;
        cnt += dfs(b);
        child++;
    }
    if(child == 0) return 1;
    return cnt;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> node;
        if (node == -1) root = i;
        else v[node].push_back(i);
    }
    cin >> d;
    if(d == root) {
        cout << 0 << endl;
        return 0;
    }
    cout << dfs(root) << endl;
    return 0;
}