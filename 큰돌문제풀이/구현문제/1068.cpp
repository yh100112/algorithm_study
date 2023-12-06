#include<bits/stdc++.h>
using namespace std;
int n, a, b, root;
vector<int> v[54];

int dfs(int node){
    int ans = 0;
    int child = 0;
    for(auto i : v[node]){
        if(i == b)
            continue;
        ans += dfs(i);
        child++;
    }
    if(child == 0) return 1;
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){ // i : 노드 번호
        cin >> a;
        if(a == -1) root = i;
        else v[a].push_back(i);
    }
    cin >> b;
    if(b == root) cout << 0 << '\n';
    else cout << dfs(root) << '\n';
}