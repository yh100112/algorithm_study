#include<bits/stdc++.h>
using namespace std;
vector<int> v[51];
int a, b, n, root, visited[51];

int go(int node){
    visited[node] = 1;

    bool flag = false;
    int ret = 0;
    for(auto& child : v[node]){
        if(!visited[child] && child != b){
            flag = true;
            ret += go(child);
        }
    }
    if(!flag) return 1;
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == -1) root = i;
        else v[a].push_back(i);
    }
    cin >> b;

    if(b == root) cout << 0 << '\n';
    else cout << go(root) << '\n';
}