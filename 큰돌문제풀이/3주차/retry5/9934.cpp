#include<bits/stdc++.h>
using namespace std;
int k;
vector<int> v;
vector<int> ret[12];

void go(int start, int end, int level){
    if(start > end) return;
    if(start == end){
        return;
    }

    int mid = (start + end) / 2;
    ret[level].push_back(v[mid]);

    go(start, mid, level + 1);
    go(mid + 1, end, level + 1);
}

int main(){
    cin >> k;
    int n = (int)pow(2,k) - 1;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    go(0, n, 0);
    for(int i = 0; i < k; i++){
        for(auto j : ret[i])
            cout << j << ' ';
        cout << '\n';
    }
}