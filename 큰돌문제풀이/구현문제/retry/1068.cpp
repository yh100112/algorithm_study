#include<bits/stdc++.h>
using namespace std;
vector<int> v[51];
int n, node, root, del;

int go(int node){
    if(v[node].size() == 0){
        return 1;
    }

    int ret = 0;
    for(auto i : v[node]){
        if(i == del) {
            if(v[node].size() == 1) ret += 1;
            continue;
        }
        ret += go(i);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> node;
        if(node != -1)
            v[node].push_back(i);
        else
            root = i;
    }
    cin >> del;
    if(del == root) cout << 0 << '\n';
    else cout << go(root) << '\n';
}